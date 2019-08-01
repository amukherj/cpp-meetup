#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> nameAge = {
    {"Chico", 30},
    {"Harpo", 29},
    {"Groucho", 27},
    {"Zeppo", 16},
  };

  for (auto [name, age]: nameAge) {
    cout << name << ":" << age << '\n';
    age += 1;
    cout << name << ":" << nameAge[name] << '\n';
  }
}
