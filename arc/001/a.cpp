#include<iostream>
#include<vector>
#include<algorithm>

using std::begin;
using std::end;

int main(int, char**) {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(int i(0); i < n; ++i) {
    char t;
    std::cin >> t;
    v.push_back(t - '0');
  }
  int max(0), min(n);
  for(int i(0); i < 4; ++i) {
    int c = std::count(begin(v), end(v), i + 1);
    max = std::max(max, c);
    min = std::min(min, c);
  }
  std::cout << max << ' ' << min << std::endl;
  return 0;
}
