#include<iostream>
#include<cmath>

using std::begin;
using std::end;

bool isPrime(int n) {
  int r = std::sqrt(n);

  for(int i{2}; i <= r; ++i) {
    if(n % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  std::cin >> n;
  int cnt{0};

  for(int i{0}; i < n; ++i) {
    int t;
    std::cin >> t;
    if(isPrime(t)) ++cnt;
  }

  std::cout << cnt << std::endl;

  return 0;
}
