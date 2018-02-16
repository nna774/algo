#include<iostream>
#include<vector>
#include<algorithm>

using std::begin;
using std::end;

int main(int, char**) {
  int a, b;
  std::cin >> a >> b;
  int cnt(0);
  while(a != b) {
    if(a > b) {
      std::swap(a, b);
    }
    if(b - a >= 8) {
      ++cnt;
      a += 10;
      continue;
    }
    if(b - a >= 4) {
      ++cnt;
      a += 5;
      continue;
    }
    ++cnt;
    ++a;
  }
  std::cout << cnt << std::endl;
  return 0;
}
