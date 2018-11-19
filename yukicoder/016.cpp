#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<bitset>

static int const mod = 1000003;

int pow(int x, int n) {
  if(n == 0) {
    return 1;
  } else if(n % 2 == 1) {
    return ((x % mod) * pow(x, n - 1)) % mod;
  } else {
    long long t = pow(x, n / 2);
    return (t * t) % mod;
  }
}

int main(int, char**) {
  int x, N;
  std::cin >> x >> N;
  int sum{};
  for(int i{}; i < N; ++i) {
    int an;
    std::cin >> an;
    sum += pow(x, an);
  }

  std::cout << (sum % mod) << std::endl;
}
