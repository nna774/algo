#include<iostream>

using std::begin;
using std::end;

int gcd(int n, int m) {
  if(n < m) return gcd(m, n);
  if(m == 0) return n;

  return gcd(m, n % m);
}

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << gcd(x, y) << std::endl;

  return 0;
}
