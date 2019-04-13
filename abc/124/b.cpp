#include <iostream>
#include <vector>
#include <utility>

int main(int, char**) {
  int n;
  std::cin >> n;

  std::vector<int> hs(n);
  for(int i{}; i < n; ++i) {
    std::cin >> hs[i];
  }

  int ans{};
  int max{-1};
  for(int i{}; i < n; ++i) {
    if(hs[i] >= max) {
      max = hs[i];
      ++ans;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
