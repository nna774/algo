#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<tuple>
#include<iomanip>
#include<cmath>

using std::begin;
using std::end;

bool isdivday(std::tuple<int, int, int> const& day) {
  int y = std::get<0>(day);
  int m = std::get<1>(day);
  int d = std::get<2>(day);
  if(y % m != 0) {
    return false;
  }
  if((y / m) % d != 0) {
    return false;
  }
  return true;
}

bool isuruu(int y) {
  if(y % 400 == 0) return true;
  else if(y % 100 == 0) return false;
  else if(y % 4 == 0) return true;
  else return false;
}

std::tuple<int, int, int> next(std::tuple<int, int, int> const& day) {
  // 2 4 6 9 11
  int y = std::get<0>(day);
  int m = std::get<1>(day);
  int d = std::get<2>(day);
  if(m == 12) {
    if(d == 31) return std::make_tuple(y + 1, 1, 1);
    return std::make_tuple(y, 12, d + 1);
  }

  if(m == 1 ||
     m == 3 ||
     m == 5 ||
     m == 7 ||
     m == 8 ||
     m == 10) {
    if(d == 31) return std::make_tuple(y, m + 1, 1);
    return std::make_tuple(y, m, d + 1);
  }

  if(m == 4 ||
     m == 6 ||
     m == 9 ||
     m == 11) {
    if(d == 30) return std::make_tuple(y, m + 1, 1);
    return std::make_tuple(y, m, d + 1);
  }
  if(isuruu(y)) {
    if(d == 29) return std::make_tuple(y, 3, 1);
    return std::make_tuple(y, m, d + 1);
  } else {
    if(d == 28) return std::make_tuple(y, 3, 1);
    return std::make_tuple(y, m, d + 1);
  }
}

int main(int, char**) {
  int y, m , d;
  char _;
  std::cin >> y;
  std::cin >> _;
  std::cin >> m;
  std::cin >> _;
  std::cin >> d;
  std::tuple<int, int, int> day = std::make_tuple(y, m, d);

  while(!isdivday(day)) {
     day = next(day);
  }
  std::cout << std::get<0>(day) << '/' <<
    std::setfill('0') << std::setw(2) << std::get<1>(day) << '/' <<
    std::setfill('0') << std::setw(2) << std::get<2>(day) << std::endl;
}
