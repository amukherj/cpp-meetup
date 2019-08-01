#include <bits/stdc++.h>
using namespace std;

// class template type argument deduction
template <typename T, typename U>
class Pair {
public:
  Pair(T arg1, U arg2) : arg1(arg1), arg2(arg2) {}
 
  void print() {
    cout << arg1 << " " << arg2 << '\n';
  }

private:
  T arg1;
  U arg2;
};

int main() {
  Pair p{"hello", 1};
  p.print();

  vector v{10, 20, 30};
  for (auto& e: v) {
    cout << e << '\n';
  }

  std::tuple trio{10, "Downing", "Street"};
  cout << get<0>(trio) << " " << get<1>(trio) << " " << get<2>(trio) << '\n';
}
