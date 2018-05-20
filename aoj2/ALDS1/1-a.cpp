#include<iostream>
#include<vector>

using std::begin;
using std::end;

int main() {
  int n;
  std::vector<int> l;
  std::cin >> n;
  for(int i{0}; i < n; ++i) {
    int t;
    std::cin >> t;
    l.push_back(t);
  }
  
  for(int i{0}; i < n; ++i) {
    int v{l[i]};
    int j{i - 1};
    while(j >= 0 && l[j] > v) {
      l[j + 1] = l[j];
      --j;
    }
    l[j + 1] = v;

    bool lastp{false};
    for(auto const e: l){
      if(!lastp) {
        lastp = true;
      } else {
        std::cout << ' ';
      }
      std::cout << e;
    }
    std::cout << std::endl;
  }
  return 0;
}
