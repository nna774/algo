#include<iostream>
#include<tuple>
#include<algorithm>

using std::begin;
using std::end;

std::tuple<int, int, int> sort(int a, int b, int c) {
  int xs[] = {a, b, c};
  std::sort(begin(xs), end(xs));
  return std::make_tuple(xs[0], xs[1], xs[2]);
}

int main(int, char**) {
  int a, b, c;
  int cnt{0}, ei{0}, cho{0}, don{0};

  while(std::cin >> a >> b >> c) {
    auto t = sort(a, b, c);
    {
      int a, b, c;
      std::tie(a, b, c) = t;
      if(a + b <= c) break;
      ++cnt;
      int m2 = a * a + b * b;
      if(m2 == c * c) ++cho;
      else if(m2 > c * c) ++ei;
      else ++don;
    }
  }

  std::cout << cnt << ' ' << cho << ' ' << ei << ' ' << don << std::endl;
}
