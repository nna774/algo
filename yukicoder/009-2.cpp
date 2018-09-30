#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<numeric>

static int const INF{100000000};

int main(int, char**) {
  int n;
  std::cin >> n;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> as{};
  std::vector<int> bs(n);
  for(int i{}; i < n; ++i) {
    int a;
    std::cin >> a;
    as.emplace(a, 0);
  }
  for(int i{}; i < n; ++i) {
    std::cin >> bs[i];
  }

  int min{10000000};
  for(int i{}; i < n; ++i) {
    auto nas = as;
    for(int j{}; j < n; ++j) {
      int vsl = bs[(j + i) % n];
      auto nt = nas.top();
      nas.pop();
      nt.first += vsl / 2;
      nt.second += 1;
      nas.push(nt);
    }

    int m{};
    for(int i{}; i < n; ++i) {
      m = std::max(m, nas.top().second);
      nas.pop();
    }
    
    min = std::min(min, m);
  }
  std::cout << min <<std::endl;

  return 0;
}

