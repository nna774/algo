#include <iostream>
#include <utility>
#include <string>

int main(int, char**) {
  std::string s;
  std::cin >> s;
  int diff{};

  for(int i{}; i < s.length(); ++i) {
    if(s[i] - '0' != i % 2) ++diff;
  }
  if(diff > s.length() / 2) {
    diff = s.length() - diff;
  }

  std::cout << diff << std::endl;

  return 0;
}
