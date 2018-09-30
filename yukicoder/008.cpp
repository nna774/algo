#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

int main(int, char**) {
  int p;
  std::cin >> p;
  for(int _i{}; _i < p; ++_i) {
    int n, k;
    std::cin >> n >> k;

    std::cout << ((n - 1) % (k + 1) == 0 ? "Lose" : "Win") << std::endl;
  }

  return 0;
}
