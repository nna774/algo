#include <iostream>
#include <array>
#include <algorithm>

int main(int, char**) {
  std::array<int, 5> arr;
  int time{};
  int cnt{};

  for(int i{}; i < 5; ++i) {
    std::cin >> arr[i];
    if(arr[i] % 10 == 0) {
      time += arr[i];
      arr[i] = 0;
      ++cnt;
    }
  }

  if(cnt != 5) {
    auto it = std::remove_if(begin(arr), end(arr), [](int n){ return n == 0; });
    std::sort(begin(arr), it, [](int lhs, int rhs){ return lhs % 10 > rhs % 10; });
    for(auto jt = begin(arr); jt != std::prev(it); ++jt) {
      time += (*jt / 10 + 1) * 10;
    }
    time += *std::prev(it);
  }

  std::cout << time << std::endl;

  return 0;
}
