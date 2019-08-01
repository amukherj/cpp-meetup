#include <bits/stdc++.h>
using namespace std;

/* void baz() {
  map<string, int> stuff{{"hello", 1}, {"hola", 2}, {"hi", 3}};
  cout << stuff["hello"] << '\n';
  cout << stuff["hola"] << '\n';
  cout << stuff["hi"] << '\n';

  if (auto ret = stuff.insert({"hello", 1}); ret.second) {
    cout << "Insert of hello succeeded\n";
  } else if (auto ret0 = stuff.insert({"hola", 2}); ret0.second) {
    cout << "Insert of hola succeeded\n";
  } else if (auto ret1 = stuff.insert({"hi", 3}); ret1.second) {
    cout << "Insert of hi succeeded\n";
  }
} */

int main() {
  map<string, int> index;

  bool present = false;
  while (!present) {
    if (auto&& [it, ok] = move(index.insert({"hello", 1})); !ok) {
      present = true;
      cout << "Present\n";
    } else {
      cout << "Not present\n";
    }
  }

  int i = 0;
  if (++i; i < 2) {
    cout << "Works\n";
  }

  //baz();
}
