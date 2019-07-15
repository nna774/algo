#include <iostream>
#include <vector>
#include <cmath>

bool nat(std::vector<int> const& p, std::vector<int> const& q) {
  int sum{};
  for(int i{}; i < p.size(); ++i) {
    sum += std::pow(p[i] - q[i], 2);
  }

//  std::cout << "###" << sum << std::endl;
  return sum == std::pow(static_cast<int>(std::sqrt(sum)), 2);
}

int main(int, char**) {
  int n, d;
  std::cin >> n >> d;

  std::vector<std::vector<int>> xs(n);
  for(int i{}; i < n; ++i) {
    for(int j{}; j < d; ++j) {
      int t;
      std::cin >> t;
      xs[i].push_back(t);
    }
  }

  int ans{};
  for(int i{}; i < n; ++i) {
    for(int j{i + 1}; j < n; ++j) {
      if(nat(xs[i], xs[j])) {
        ++ans;
      }
    }
  }

  std::cout << ans << std::endl;
}
