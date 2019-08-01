#include <algorithm>
#include <iostream>
#include <vector>
// ...
#include <range/v3/all.hpp>

int main() {
  std::vector<int> v{5, 4, 3, 2, 1};
  // takes the container, not iterator pair
  ranges::sort(v);
  // has equivalent algorithms
  ranges::for_each(v, [](int i) {std::cout << i << '\n';});

  // can be composed neatly - by piping or passing
  std::cout << ranges::accumulate(
    ranges::view::ints(1, ranges::unreachable)
    |ranges::view::take(10)
    |ranges::view::remove_if(
      [](int i){ return i % 4 == 0; }
     ), 10) << '\n';

  std::cout << ranges::accumulate(
    v |ranges::view::take(3)
      |ranges::view::remove_if(
        [](int i){ return i % 2 == 0; }
     ), 0) << '\n';
}
