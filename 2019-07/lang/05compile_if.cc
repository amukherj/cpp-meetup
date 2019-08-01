#include <bits/stdc++.h>
using namespace std;

template <typename T>
string asString(T input) {
  int i = 0;

  if constexpr(is_same_v<T, string> || is_convertible_v<T, string>) {
    cout << "Is same\n";
    return input;
  } else if constexpr(is_arithmetic_v<T>) {
    cout << "Is numeric\n";
    return to_string(input);
  } else if (i <= 0) {
    cout << "Works\n";
  } else {
    cout << "Others\n";
    return "";
  }
}

struct Foo {
  int bar;

  operator string() const {
    return to_string(bar);
  }
};

int main() {
  Foo f{100};

  cout << asString("hello") << '\n';
  cout << asString(12.4) << '\n'
       << asString(10) << '\n'
       << asString(true) << '\n';
  cout << asString(f) << '\n';
}
