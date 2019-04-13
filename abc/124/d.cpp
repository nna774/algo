#include <iostream>
#include <utility>
#include <string>
#include <vector>

int main(int, char**) {
  int n, K;
  std::string s;
  std::cin >> n >> K >> s;

  std::vector<int> is;
  char pre{};
  for(int i{}; i < n; ++i) {
    if(pre != s[i]) is.push_back(i);

    pre = s[i];
  }

  int ans{-1}; 
  size_t r{is.size()};
  for(int k{}; k < r; ++k) {
    int x;
    if(s[is[k]] == '0') {
      x = ((k + 2 * K >= r) ? n : is[k + 2 * K]) - is[k];
    } else {
      x = ((k + 2 * K + 1 >= r) ? n : is[k + 2 * K + 1]) - is[k];
    }

    ans = std::max(x, ans);
  }

  std::cout << ans << std::endl;

  return 0;
}
