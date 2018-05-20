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
  
  int cnt{0};
  for(int i{0}; i < n; ++i) {
    int min{i};
    for(int j{i}; j < n; ++j) {
      if(v[j] < v[min]) {
        min = j;
      }
    }
    if(i != min) {
      ++cnt;
      int t{v[i]};
      v[i] = v[min];
      v[min] = t;
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
