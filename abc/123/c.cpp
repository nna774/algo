#include <iostream>
#include <array>
#include <algorithm>

int main(int, char**) {
  long long n;
  std::array<long long, 5> arr;

  std::cin >> n;
  for(int i{}; i < 5; ++i) {
    std::cin >> arr[i];
  }
  std::sort(begin(arr), end(arr));

  std::cout << 4 + n / arr[0] + (n % arr[0] == 0 ? 0 : 1) << std::endl;

  return 0;
}
