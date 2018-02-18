#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<tuple>
#include<iomanip>
#include<cmath>

using std::begin;
using std::end;

int main(int, char**) {
  int y;
  std::cin >> y;
  if(y % 400 == 0) std::cout << "YES" << std::endl;
  else if(y % 100 == 0) std::cout << "NO" << std::endl;
  else if(y % 4 == 0) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;
  return 0;
}
