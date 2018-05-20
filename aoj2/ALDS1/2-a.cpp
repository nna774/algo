#include<iostream>
#include<vector>

using std::begin;
using std::end;

int main() {
  int n;
  std::vector<int> v;
  std::cin >> n;
  for(int i{0}; i < n; ++i) {
    int t;
    std::cin >> t;
    v.push_back(t);
  }
  
  bool e{true};
  int cnt{0};
  while(e) {
    e = false;
    for(int i{n - 1}; i > 0; --i) {
      if(v[i] < v[i - 1]) {
        e = true;
        ++cnt;
        int t{v[i]};
        v[i] = v[i - 1];
        v[i - 1] = t;
      }
    }
  }
  bool f{true};
  for(int e: v) {
    if(f) {
      f = false;
    } else {
      std::cout << ' ';
    }
    std::cout << e;
  }

  std::cout << std::endl << cnt << std::endl;

  return 0;
}
