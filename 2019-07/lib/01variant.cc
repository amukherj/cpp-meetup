#include <bits/stdc++.h>
#include <variant>
using namespace std;

struct Foo {
  int bar;
  string baz;
};

using value_t = variant<int, double, string, Foo>;

struct ValueVisitor {
  template <typename T>
  void operator()(T val) const {
    cout << val << '\n';
  }

  template <>
  void operator()(Foo f) const {
    cout << '{' << f.bar << ',' << f.baz << '}' << '\n';
  }
};

int main() {
  vector<value_t> values;
  values.push_back(10);
  values.push_back(3.14159259);
  values.push_back("Hello");
  Foo f{1, "hello"};
  values.push_back(f);

  ValueVisitor visitor;
  for (auto v: values) {
    visit(visitor, v);
  }
}
