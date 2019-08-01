#include <bits/stdc++.h>
#include <restclient-cpp/connection.h>
#include <restclient-cpp/restclient.h>


int main(int argc, char** argv) {
  auto response = RestClient::post("http://localhost:18080/object/5/car",
      "application/json", "{}");
  std::cout << response.code << '\n'
    << response.body << '\n';
}
