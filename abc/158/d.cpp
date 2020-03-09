#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<variant>
 
class Reverse{} reverse;
using Operations = std::variant<Reverse, char>;
 
int main(int, char**) {
  std::string s;
  std::cin >> s;
  int qs;
  std::cin >> qs;
  std::vector<Operations> ops;
 
  for(int i{}; i < qs; ++i) {
    int q;
    std::cin >> q;
    if(q == 1) {
      // reverse
      ops.push_back(reverse);
    } else {
      int f;
      char c;
      std::cin >> f >> c;
      if(f == 1) {
        // c:s
        ops.push_back(reverse);
        ops.push_back(c);
        ops.push_back(reverse);
      } else {
        // s ++ [c]
        // == 1; (2 1 c); 1;
        ops.push_back(c);
      }
    }
  }
 
  for(auto e: ops) {
    if(std::holds_alternative<Reverse>(e)) {
      std::reverse(begin(s), end(s));
    } else {
      auto c = std::get<char>(e);
      s += c;
    }
  }
 
  std::cout << s << std::endl;
 
  return 0;
}
