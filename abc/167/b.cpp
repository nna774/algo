#include <iostream>

int main(int, char**) {
  int a, b, c, k;
  std::cin >> a >> b >> c>> k;
  if(k <= a ) {
    std::cout << k << std::endl;;
  } else if(k <= a + b) {
    std::cout << a << std::endl;;
  } else {
    std::cout << a - (k - (a + b)) << std::endl;
  }
}
