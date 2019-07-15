#include <iostream>

int main(int, char**) {
  int l, r;
  std::cin >> l >> r;
  int end = std::min(l + 2019, r);

  int min{2018};
  for(int i{l}; i <= end; ++i) {
    for(int j{i + 1}; j <= end; ++j) {
      min = std::min<int>(min, (static_cast<long long>(i) * j) % 2019);
    }
  }

  std::cout << min << std::endl;

  return 0;
}
