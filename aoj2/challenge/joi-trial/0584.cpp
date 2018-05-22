#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<cmath>

using std::begin;
using std::end;

int concat(int m, int n) {
  int d{1};
  for(int i{n}; i > 0; i /= 10, d *= 10);

  return m * d + n;
}

int main(int, char**) {
  int n;
  std::vector<int> v;
  std::cin >> n;

  for(int i{0}; i < n; ++i) {
    int t;
    std::cin >> t;
    v.push_back(t);
  }

  std::vector<int> rs;
  for(int i{0}; i < n; ++i) {
    for(int j{0}; j < n; ++j) {
      if(i != j)
        rs.push_back(concat(v[i], v[j]));
    }
  }
  std::sort(begin(rs), end(rs));

  std::cout << rs[2] << std::endl;

  return 0;
}
