#include <iostream>
#include <vector>

int main(int, char**) {
  int n;
  std::cin >> n;
  std::vector<long long> as(n);

  long long sum{};
  for(int i{}; i < n; ++i) {
    std::cin >> as[i];
    sum += as[i];
  }
  sum /= 2;

  long long v{sum};
  for(int i{1}; i < n; i += 2) {
    v -= as[i];
  }
  std::cout << 2 * v << std::endl;

  for(int i{0}; i < n - 1; ++i) {
    v = as[i] - v;
    std::cout << 2 * v << std::endl;
  }

  return 0;
}
