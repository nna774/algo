#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

int main(int, char**) {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> as(n);
  std::vector<int> bs(n);
  for(int i{}; i < n; ++i) {
    int a;
    std::cin >> a;
    as[i] = std::make_pair(a, 0);
  }
  for(int i{}; i < n; ++i) {
    std::cin >> bs[i];
  }

  int min{10000000};
  make_heap(begin(as), end(as), std::greater<std::pair<int, int>>());
  for(int i{}; i < n; ++i) {
    std::vector<std::pair<int, int>> nas = as;
    for(int j{}; j < n; ++j) {
      int vsl = bs[(j + i) % n];
      nas[0].first += vsl / 2;
      nas[0].second += 1;
      pop_heap(begin(nas), end(nas), std::greater<std::pair<int, int>>());
      push_heap(begin(nas), end(nas), std::greater<std::pair<int, int>>());
    }
    sort(begin(nas), end(nas), [](auto x, auto y){ return x.second > y.second; });
    min = std::min(min, nas[0].second);
  }
  std::cout << min <<std::endl;

  return 0;
}

