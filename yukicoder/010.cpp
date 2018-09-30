#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<numeric>
#include<bitset>

static int const INF{100000000};

int main(int, char**) {
  int n;
  std::cin >> n;
  int total;
  std::cin >> total;
  std::vector<int> as(n);
  for(int i{}; i < n; ++i) {
    std::cin >> as[i];
  }

  static long long const nil = 1LL << 60;
  std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(total + 1, nil));
  dp[0][as[0]] = 0;
  for(int i{1}; i < n; ++i) {
    for(int j{1}; j <= total; ++j) {
      if(dp[i - 1][j] == nil) continue;
      if(j + as[i] <= total) {
        dp[i][j + as[i]] = std::min(dp[i][j + as[i]], dp[i - 1][j] * 2);
      }
      if(j * as[i] <= total) {
        dp[i][j * as[i]] = std::min(dp[i][j * as[i]], dp[i - 1][j] * 2 + 1);
      }
    }
  }

  long long ans{dp[n - 1][total]};
  // if(ans == nil) throw "okasii";
  std::vector<char> anss;
  for(int i{}; i < n - 1; ++i) {
    if(ans % 2) {
      anss.push_back('*');
    } else {
      anss.push_back('+');
    }
    ans /= 2;
  }

  for(int i{n - 2}; i >= 0; --i) {
    std::cout << anss[i];
  }
  std::cout << std::endl;

  return 0;
}
