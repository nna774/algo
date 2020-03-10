#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int, char**) {
  int n, p;
  std::string s;
  std::cin >> n >> p >> s;

  if(p == 2 || p == 5) {
    unsigned long long cnt{};
    for(int i{}; i < n; ++i) {
      if((s[i] - '0') % p == 0) {
        cnt += i + 1;
      }
    }
    std::cout << cnt << std::endl;
    return 0;
  }

  std::vector<int> us(n);
  int uMod{};
  int pow10Mod{1};
  for(int i{n-1}; i >= 0; --i) {
    int at{s[i] - '0'};
    if(i != n - 1) {
      pow10Mod *= 10;
      pow10Mod %= p;
    }
    uMod = at * pow10Mod + uMod;
    uMod %= p;
    us[i] = uMod;
  }

  /*
  for(auto e: us) std::cout << e << ", ";
  std::cout << std::endl;
  */

  unsigned long long cnt{};
  for(int i{}; i < p; ++i) {
    unsigned long long c = count(begin(us), end(us), i);
    if(i == 0) {
      cnt += c;
    }
    cnt += c * (c - 1) / 2;
 //   std::cout << "i: " << i << ", c: " << c << ", *" << ": " << (c * (c - 1) / 2) << std::endl;
  }
  std::cout << cnt << std::endl;

  return 0;
}
