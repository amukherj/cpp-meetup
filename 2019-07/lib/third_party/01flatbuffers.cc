#include <bits/stdc++.h>
#define FLATBUFFERS_DEBUG_VERIFICATION_FAILURE
#include <flatbuffers/flatbuffers.h>
#include <flatbuffers/idl.h>
#include <flatbuffers/util.h>
#include "01address_generated.h"
using namespace std;
using namespace Meetup::Address;

string readFile(const string& file_name) {
  ifstream ifs;
  ifs.open(file_name, std::ios::in);
  ifs.seekg(0, std::ios::end);
  int size = ifs.tellg();

  string buffer(size + 1, '\0');
  ifs.read(&buffer[0], size);
  ifs.close();

  return buffer;
}

void printPerson(const Person* person) {
  cout << person->name()->str() << '\n';
  cout << person->age() << '\n';
  cout << person->addresses()->Get(0)->apartment()->str() << '\n';
  cout << person->addresses()->Get(0)->building()->str() << '\n';
  cout << person->addresses()->Get(0)->streetAddress()->str() << '\n';
  cout << person->addresses()->Get(0)->city()->str() << '\n';
  cout << person->addresses()->Get(0)->country()->str() << '\n';
  cout << person->addresses()->Get(0)->postalCode()->str() << '\n';
  cout << person->phones()->Get(0)->str() << '\n';
}

int main() {
  flatbuffers::FlatBufferBuilder builder(1024);

  auto name = builder.CreateString("John Doe");

  // construct address fields
  auto apartment = builder.CreateString("A304");
  auto building = builder.CreateString("Emerald Suites");
  auto streetAddress = builder.CreateString("MurphyStreet AJ16");
  auto city = builder.CreateString("Shannon");
  auto country = builder.CreateString("Ireland");
  auto postalCode = builder.CreateString("V14");

  // construct address
  AddressBuilder address_builder(builder);
  address_builder.add_apartment(apartment);
  address_builder.add_building(building);
  address_builder.add_streetAddress(streetAddress);
  address_builder.add_city(city);
  address_builder.add_country(country);
  address_builder.add_postalCode(postalCode);
  auto address = address_builder.Finish();
  builder.Finish(address);

  vector<flatbuffers::Offset<Address>> address_list;
  address_list.push_back(address);
  auto addresses = builder.CreateVector(address_list);

  // construct phones
  auto phone1 = builder.CreateString("+353 1 403 2124");
  vector<flatbuffers::Offset<flatbuffers::String>> phones_list;
  phones_list.push_back(phone1);
  auto phones = builder.CreateVector(phones_list);
 
  // construct person
  auto person = CreatePerson(builder, name, 37, addresses, phones);
  builder.Finish(person);

  // Read back
  cout << "Occupies " << builder.GetSize() << " bytes\n";

  auto person1 = GetPerson(builder.GetBufferPointer());
  printPerson(person1);
  /* cout << person1->name()->str() << '\n';
  cout << person1->age() << '\n';
  cout << person1->addresses()->Get(0)->apartment()->str() << '\n';
  cout << person1->addresses()->Get(0)->building()->str() << '\n';
  cout << person1->addresses()->Get(0)->streetAddress()->str() << '\n';
  cout << person1->addresses()->Get(0)->city()->str() << '\n';
  cout << person1->addresses()->Get(0)->country()->str() << '\n';
  cout << person1->addresses()->Get(0)->postalCode()->str() << '\n';
  cout << person1->phones()->Get(0)->str() << '\n'; */

  // JSON s11n
  string json;
  flatbuffers::Parser parser;
  // auto fbs = readFile("01address.fbs");
  string schema;
  if (!flatbuffers::LoadFile("01address.fbs", false, &schema)) {
    cerr << "Schema load failed\n";
    return 1;
  }

  if (!parser.Parse(schema.c_str())) {
    cerr << "Schema parse failed\n";
    return 1;
  }

  if (!GenerateText(parser, builder.GetBufferPointer(), &json)) {
    cerr << "Failed to generate JSON\n";
    return 1;
  }
  cout << "Serialized:\n" << json << '\n';

  // JSON des11n
  string json1 = R"({
  name: "John Doe",
  age: 37,
  addresses: [
    {
      apartment: "A304",
      building: "Emerald Suites",
      streetAddress: "MurphyStreet AJ16",
      city: "Shannon",
      country: "Ireland",
      postalCode: "V14"
    }
  ],
  phones: [
    "+353 1 403 2124"
  ]
}
)";

  if (!parser.Parse(json1.c_str())) {
    cerr << "JSON parse failed\n";
    return 1;
  }

  auto* buf = parser.builder_.GetBufferPointer();
  auto* person0 = GetPerson(buf);
  cout << "Deserialized:\n";
  printPerson(person0);
}
