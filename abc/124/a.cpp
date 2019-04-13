#include <iostream>
#include <utility>

int main(int, char**) {
  int a, b, ans;
  std::cin >> a >> b;
  if(a > b) std::swap(a, b);

  if(b - a >= 2) {
    ans = b * 2 - 1;
  } else {
    ans = a + b;
  }

  std::cout << ans << std::endl;

  return 0;
}
