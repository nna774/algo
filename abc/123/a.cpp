#include <iostream>
#include <array>

int main(int, char**) {
  std::array<int, 5> arr;
  int k;

  for(int i{}; i < 5; ++i) {
    std::cin >> arr[i];
  }
  std::cin >> k;

  // a b
  // a c
  // a d
  // a e
  // b c
  if(arr[1] - arr[0] > k
  || arr[2] - arr[0] > k
  || arr[3] - arr[0] > k
  || arr[4] - arr[0] > k
  || arr[2] - arr[1] > k) {
    std::cout << ":(" << std::endl;
  } else {
    std::cout << "Yay!" << std::endl;
  }

  return 0;
}
