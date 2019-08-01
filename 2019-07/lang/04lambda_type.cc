#include <bits/stdc++.h>
using namespace std;

template <typename F>
class CallWrapper {
public:
  CallWrapper(F func) : func_(func) {
  }

  template <typename... T>
  void call(T... args) {
    func_(args...);
  }

private:
  F func_;
};

int main() {
  // CallWrapper<std::function<void(const char*,const char*)>> cw(
  //   [](auto n1, auto n2) { cout << n1 << ' ' << n2 << '\n'; }
  // );
  CallWrapper cw([](
    auto n1, auto n2) { cout << n1 << ' ' << n2 << '\n'; }
  );
  cw.call("Hello", "World");
}
