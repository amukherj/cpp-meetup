#include <bits/stdc++.h>
#include <string_view>
using namespace std;

string_view get_prefix(string_view str, char separator = ':') {
  if (auto pos = str.find(separator); pos != string_view::npos) {
    return string_view(&str[0], pos);
  }

  return str;
}

int main() {
  // C-style string
  cout << get_prefix("https://nutanix.com") << '\n';

  // basic_string
  string s("http://google.com");
  cout << get_prefix(s) << '\n';

  // vector
  vector vec{'h', 't', 't', 'p', 's', ':', '/', '/', 'x', 'i', '.',
    'n', 'u', 't', 'a', 'n', 'i', 'x', '.', 'c', 'o', 'm'};
  cout << get_prefix(string_view(&vec[0], vec.size())) << '\n';
}
