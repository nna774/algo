#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

// 割れた数, 商
std::pair<int, int> factor_imp(int n) {
  int max{std::sqrt(n)};
  for(int i{2}; i < max + 1; ++i) {
    if(n % i == 0) {
      return std::make_pair(i, n / i);
    }
  }
  return std::make_pair(n, 1);
}

// <素因数, 羃>
std::map<int, int> factor(int n) {
  std::map<int, int> map;
  do {
    auto v = factor_imp(n);
    ++map[v.first];
    n = v.second;
  } while(n != 1);
  return map;
}

// 奇数個の素数の積を渡されると勝ち。
// 偶数個なら負け。
// 1つだけn次、あとは全部1次のものを渡されると、勝ち。
// 全ての山の石の数のbitxorが0なら後手必勝 らしいよ。

int main(int, char**) {
  int N;
  std::cin >> N;

  auto map = factor(N);
  int f{};
  for(auto e: map) {
    f ^= e.second;
  }

  std::cout << (f ? "Alice" : "Bob") << std::endl;

  return 0;
}
