#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

using std::begin;
using std::end;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v;

  for(int i{0}; i < n; ++i) {
    int t;
    std::cin >> t;
    v.push_back(t);
  }

  int min{v[0]};
  int diff{std::numeric_limits<int>::min()};
  for(int i{1}; i < n; ++i) {
    diff = std::max(diff, v[i] - min);
    min = std::min(min, v[i]);
  }

  std::cout << diff << std::endl;

  return 0;
}
