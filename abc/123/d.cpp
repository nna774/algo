#include <iostream>
#include <vector>
#include <algorithm>

int main(int, char**) {
  int x, y, z, K;
  std::cin >> x >> y >> z >> K;

  std::vector<long long> as(x), bs(y), cs(z);
  for(int i{}; i < x; ++i) {
    std::cin >> as[i];
  }
  for(int i{}; i < y; ++i) {
    std::cin >> bs[i];
  }
  for(int i{}; i < z; ++i) {
    std::cin >> cs[i];
  }

  std::sort(begin(as), end(as), std::greater<long long>());
  std::sort(begin(bs), end(bs), std::greater<long long>());
  std::sort(begin(cs), end(cs), std::greater<long long>());

  std::vector<long long> ans;
  for(int i{}; i < x; ++i) {
    for(int j{}; j < y; ++j) {
      for(int k{}; k < z; ++k) {
        if((i + 1) * (j + 1) * (k + 1) <= K) { ans.push_back(as[i] + bs[j] + cs[k]); }
        else { break; }
      }
    }
  }
  std::sort(begin(ans), end(ans), std::greater<long long>());
  for(int i{}; i < K; ++i) {
    std::cout << ans[i] << std::endl;
  }

  return 0;
}
