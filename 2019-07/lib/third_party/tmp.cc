#include <bits/stdc++.h>
using namespace std;

using intvec = vector<int>;

int main() {
  intvec v{1, 2, 3, 4, 5};
  for_each(v.begin(), v.end(), [](int n) { cout << n << ','; });
}
