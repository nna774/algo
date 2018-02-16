#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<tuple>

using std::begin;
using std::end;

int main(int, char**) {
  // migi ue kara hidari shita
  // {0}, {1, 8}, {2, 9, 16}, {3, 10, 17, 24} .. {7, .., 56}, {15, 22, .., 57}, .. {55, 62}, {63}
  {
    std::array<bool, 64> m;
    for(int i(0); i < 64; ++i) m[i] = false;
    for(int i(0); i < 64; ++i) {
      bool e(false);
      if(m[i]) continue; 
      for(int j(i); j < 64; j += 7) {
        std::cout << j << ' ';
        m[j] = true;
        if(j % 8 == 0) break;
      }
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;

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
        std::cout << j << ' ';
      }
      std::cout << std::endl;
    }
  }

  return true;
}
