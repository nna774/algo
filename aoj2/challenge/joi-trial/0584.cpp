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

  std::vector<int> candidates;
  std::vector<int> rs;

  for(int i{0}; i < n/2; ++i) {
    for(int j{0}; j < n/2; ++j) {
      if(i != j)
        rs.push_back(concat(v[i], v[j]));
    }
  }
  std::sort(begin(rs), end(rs));
  for(int i{0}; i < 3; ++i) {
    candidates.push_back(rs[i]);
  }
  rs.clear();

  for(int i{0}; i < n/2; ++i) {
    for(int j{n/2}; j < n; ++j) {
      if(i != j)
        rs.push_back(concat(v[i], v[j]));
    }
  }
  std::sort(begin(rs), end(rs));
  for(int i{0}; i < 3; ++i) {
    candidates.push_back(rs[i]);
  }
  rs.clear();

  for(int i{n/2}; i < n; ++i) {
    for(int j{0}; j < n/2; ++j) {
      if(i != j)
        rs.push_back(concat(v[i], v[j]));
    }
  }
  std::sort(begin(rs), end(rs));
  for(int i{0}; i < 3; ++i) {
    candidates.push_back(rs[i]);
  }
  rs.clear();

  for(int i{n/2}; i < n; ++i) {
    for(int j{n/2}; j < n; ++j) {
      if(i != j)
        rs.push_back(concat(v[i], v[j]));
    }
  }
  std::sort(begin(rs), end(rs));
  for(int i{0}; i < 3; ++i) {
    candidates.push_back(rs[i]);
  }
  rs.clear();

  std::sort(begin(candidates), end(candidates));
  std::cout << candidates[2] << std::endl;

  return 0;
}
