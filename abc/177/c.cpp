#include <iostream>
#include <vector>

long long const MOD = 1000000000LL + 7;

int main(int, char**) {
  int n;
  std::cin >> n;
  long long sum{}, taikaku2{};
  for(int i{}; i < n; ++i) {
    long long e;
    std::cin >> e;
    sum += e;
    sum %= MOD;
    taikaku2 += e * e;
    taikaku2 %= MOD;
  }

  std::cout << ((sum * sum - taikaku2 + MOD)) % MOD * ((MOD+1)/2) % MOD << std::endl;
}
