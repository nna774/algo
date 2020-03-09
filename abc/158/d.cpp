#include<algorithm>
#include<iostream>
#include<string>

int main(int, char**) {
  std::string s, heads;
  std::cin >> s;
  int qs;
  std::cin >> qs;
  bool reverse{};

  for(int i{}; i < qs; ++i) {
    int q;
    std::cin >> q;
    if(q == 1) {
      // reverse
      reverse = !reverse;
    } else {
      int f;
      char c;
      std::cin >> f >> c;
      if(f == 1) {
        // c:s
        if(reverse) {
          s += c;
        } else {
          heads += c;
        }
      } else {
        if(!reverse) {
          s += c;
        } else {
          heads += c;
        }
      }
    }
  }

  std::reverse(begin(heads), end(heads));
  s = heads + s;
  if(reverse) {
    std::reverse(begin(s), end(s));
  } else {
  }
  std::cout << s << std::endl;

  return 0;
}
