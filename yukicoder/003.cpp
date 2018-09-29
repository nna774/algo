#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

static int const INF{100000000};

int main(int, char**) {
  int N;
  std::cin >> N;
  std::vector<int> v(N + 1);
  for(unsigned int i{1}; i <= N; ++i) {
    v[i] = __builtin_popcount(i);
  }

  std::vector<int> dp(N + 1, INF);
  dp[1] = 1;

  for(int j{}; j < N + 1; ++j) {
  for(int i{1}; i < N + 1; ++i) {
    if(dp[i] == INF) continue;

    int front = i + v[i];
    if(front <= N) {
      dp[front] = std::min(dp[front], dp[i] + 1);
    }

    int back = i - v[i];
    if(back >= 0) {
      dp[back] = std::min(dp[back], dp[i] + 1);
    }
  }
  }

  std::cout << (dp[N] == INF ? -1 : dp[N]) << std::endl;
}
