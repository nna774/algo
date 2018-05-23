#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<cmath>
#include<complex>

using std::begin;
using std::end;

int main(int, char**) {
  int n;
  std::cin >> n;
  std::vector<std::complex<float>> v;
  std::vector<int> rs;

  for(int i{0}; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    v.emplace_back(x, y);
  }

  std::vector<int> candidates;

  for(int i{0}; i < n; ++i) {
    for(int j{0}; j < n; ++j) {
      if(i != j) {
        auto c = v[i] - v[j];
        int t = std::real(c) * std::real(c) + std::imag(c) * std::imag(c);
        rs.push_back(t);
      }
    }
  }
  for(int i{0}; i < n/2; ++i) {
    for(int j{0}; j < n/2; ++j) {
      if(i != j) {
        auto c = v[i] - v[j];
        int t = std::real(c) * std::real(c) + std::imag(c) * std::imag(c);
        rs.push_back(t);
      }
    }
  }
  std::sort(begin(rs), end(rs));
  for(int i{0}; i < 3; ++i) {
    candidates.push_back(rs[i]);
  }
  rs.clear();

  for(int i{0}; i < n/2; ++i) {
    for(int j{n/2}; j < n; ++j) {
      if(i != j) {
        auto c = v[i] - v[j];
        int t = std::real(c) * std::real(c) + std::imag(c) * std::imag(c);
        rs.push_back(t);
      }
    }
  }
  std::sort(begin(rs), end(rs));
  for(int i{0}; i < 3; ++i) {
    candidates.push_back(rs[i]);
  }
  rs.clear();

  for(int i{n/2}; i < n; ++i) {
    for(int j{0}; j < n/2; ++j) {
      if(i != j) {
        auto c = v[i] - v[j];
        int t = std::real(c) * std::real(c) + std::imag(c) * std::imag(c);
        rs.push_back(t);
      }
    }
  }
  std::sort(begin(rs), end(rs));
  for(int i{0}; i < 3; ++i) {
    candidates.push_back(rs[i]);
  }
  rs.clear();

  for(int i{n/2}; i < n; ++i) {
    for(int j{n/2}; j < n; ++j) {
      if(i != j) {
        auto c = v[i] - v[j];
        int t = std::real(c) * std::real(c) + std::imag(c) * std::imag(c);
        rs.push_back(t);
      }
    }
  }
  std::sort(begin(rs), end(rs));
  for(int i{0}; i < 3; ++i) {
    candidates.push_back(rs[i]);
  }
  rs.clear();

  std::sort(begin(candidates), end(candidates));
  std::cout << candidates[0] << std::endl;

  return 0;
}
