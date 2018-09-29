#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

static int const INF{100000000};

int main(int, char**) {
  int N, C, V;
  std::cin >> N >> C >> V;

  std::vector<int> ss(V), ts(V), ys(V),ms(V);
  for(int i{0}; i < V; ++i) {
    std::cin >> ss[i]; --ss[i];
  }
  for(int i{0}; i < V; ++i) {
    std::cin >> ts[i]; --ts[i];
  }
  for(int i{0}; i < V; ++i) {
    std::cin >> ys[i];
  }
  for(int i{0}; i < V; ++i) {
    std::cin >> ms[i];
  }

  std::vector<std::vector<std::tuple<int, int, int>>> e(N);
  for(int i{0}; i < V; ++i) {
    e[ss[i]].push_back(std::make_tuple(ts[i], ys[i], ms[i]));
  }

  std::vector<std::vector<int>> dp(N, std::vector(C + 1, INF));
  dp[0][C] = 0; // start: node 0, C cost ある。

  for(int i{}; i < N; ++i) {
    for(int j{}; j < C + 1; ++j) {
      if(dp[i][j] == INF) continue;
      for(auto k: e[i]) {
        int t{std::get<0>(k)}; // 移動先
        int nj{j - std::get<1>(k)}; // 残りcost
        int nd{dp[i][j] + std::get<2>(k)}; // 経過時間
        if(nj < 0) continue;
        dp[t][nj] = std::min(dp[t][nj], nd);
      }
    }
  }

  int ans{INF};
  for(int i{}; i < C + 1; ++i) {
    ans = std::min(ans, dp[N - 1][i]);
  }
  std::cout << ((ans == INF) ? -1 : ans) << std::endl;

  return 0;
}
