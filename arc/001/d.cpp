// fail

#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<tuple>
#include <iomanip>
#include<cmath>

using std::begin;
using std::end;

double seppen(int s, int e, int n, int i) {
  return s + static_cast<double>(e - s) * i / n;
}

double len(int s, int top, int g, int tail) {
  return std::pow((s-g)*(s-g) + (tail-top)*(tail-top), 0.5);
}

double solve(std::vector<std::pair<int, int>> const& v, int start, int goal, int top, int tail) {
  if(top == tail) return 0;

  bool found(false);
  int mytail(tail);
  int mygoal(goal);
  while(!found) {
    bool fail(false);
    for(int i(top + 1); i < mytail; ++i) {
      auto w = v[i];
      double s = seppen(start, mygoal, mytail - 1, i);
      if(!(w.first <= s && s <= w.second)) {
        mytail = i;
        mygoal = (s < w.first) ?
          w.first :
          w.second;
        fail = true;
      }
    }
    if(!fail) found = true;
  }
  double current = len(start, top, mygoal, mytail);
  return current + solve(v, mygoal, goal, mytail, tail);
}

int main(int, char**) {
  int n;
  int start, goal;
  std::cin >> n >> start >> goal;
  std::vector<std::pair<int, int>> v;
  for(int i(0); i < n + 1; ++i) {
    int l, r;
    std::cin >> l >> r;
    v.push_back(std::make_pair(l, r));
  }

  std::cout << std::setprecision(16) << solve(v, start, goal, 0, n) << std::endl;
  return 0;
}
