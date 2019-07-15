#include <iostream>

int main(int, char**) {
  int n, a, b;
  std::cin >> n >> a >> b;
  std::cout << std::min(n * a, b) << std::endl;

  return 0;
}
