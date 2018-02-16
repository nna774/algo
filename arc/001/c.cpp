#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<tuple>

using std::begin;
using std::end;

void print(std::array<bool, 64> const& b) {
  for(int i(0); i < 8; ++i) {
    for(int j(0); j < 8; ++j) {
      std::cout << (b[i*8+j] ? 'Q' : '.');
    }
    std::cout << std::endl;
  }
}

bool ok(std::array<bool, 64> const& b) {
  // yoko
  for(int i(0); i < 8; ++i) {
    bool e(false);
    for(int j(0); j < 8; ++j) {
      if(e && b[i*8+j]) return false;
      if(b[i*8+j]) e = true;
    }
  }

  // tate
  for(int j(0); j < 8; ++j) {
    bool e(false);
    for(int i(0); i < 8; ++i) {
      if(e && b[i*8+j]) return false;
      if(b[i*8+j]) e = true;
    }
  }

  // migi ue kara hidari shita
  // {0}, {1, 8}, {2, 9, 16}, {3, 10, 17, 24} .. {7, .., 56}, {15, 22, .., 57}, .. {55, 62}, {63}
  {
    std::array<bool, 64> m;
    for(int i(0); i < 64; ++i) m[i] = false;
    for(int i(0); i < 64; ++i) {
      bool e(false);
      if(m[i]) continue; 
      for(int j(i); j < 64; j += 7) {
        m[j] = true;
        if(e && b[j]) return false;
        if(b[j]) e = true;
        if(j % 8 == 0) break;
      }
    }
  }

  // hirari ue kara migi shita
  // {0, 9, 18, .. , 63}, {1, 10, ..},..
  {
    std::array<bool, 64> m;
    for(int i(0); i < 64; ++i) m[i] = false;
    for(int i(0); i < 64; ++i) {
      bool e(false);
      if(m[i]) continue;
      for(int j(i); j < 64; j += 9) {
        if((0 < i && i < 8) && j % 8 == 0) break;
        m[j] = true;
        if(e && b[j]) return false;
        if(b[j]) e = true;
      }
    }
  }

  return true;
}

std::array<bool, 64> put(std::array<bool, 64> const& b, int pos) {
  std::array<bool, 64> m(b);
  m[pos] = true;
  return m;
}

std::tuple<bool, std::array<bool, 64>> solve_impl(std::array<bool, 64> const& b, int depth) {
  if(!ok(b)) {
    return make_tuple(false, b);
  }
  if(depth > 4) {
    return make_tuple(true, b);
  }
  for(int i(0); i < 64; ++i) {
    if(b[i]) continue;
    std::array<bool, 64> m = put(b, i);
    auto n = solve_impl(m, depth + 1);
    if(std::get<0>(n)) return n;
  }
  return make_tuple(false, b);
}

void solve(std::array<bool, 64> const& b) {
  auto n = solve_impl(b, 0);
  if(std::get<0>(n)) print(std::get<1>(n));
  else std::cout << "No Answer" << std::endl;
}

int main(int, char**) {
  std::array<bool, 64> b;
  for(int i(0); i < 64; ++i) {
    char t;
    std::cin >> t;
    b[i] = t == 'Q';
  }
  solve(b);
}
