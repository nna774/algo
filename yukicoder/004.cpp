#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

static int const INF{100000000};

int solve(auto const& ws, auto& memo, int i, int w) {
  if(i == ws.size()) return 0;
  if(w < ws[i]) {
    return memo[i][w] = solve(ws, memo, i + 1, w);
  }

  if(memo[i][w]) return memo[i][w];
  int v1 = solve(ws, memo, i + 1, w);
  int v2 = solve(ws, memo, i + 1, w - ws[i]) + ws[i];

  memo[i][w] = std::max(v1, v2);
  return memo[i][w];
}

int main(int, char**) {
  int n;
  std::cin >> n;
  std::vector<int> ws(n);
  int sum{};
  for(int i{}; i < n; ++i) {
    int t;
    std::cin >> t;
    ws[i] = t;
    sum += t;
  }

  if(sum % 2) {
    std::cout << "impossible" << std::endl;
    return 0;
  }

  sum /= 2;
  std::vector<std::vector<int>> memo(n + 1, std::vector(sum + 1, 0));

  std::sort(begin(ws), end(ws), std::greater<int>());
  int v = solve(ws, memo, 0, sum);

  std::cout << (sum == v ? "possible" : "impossible") << std::endl;

  return 0;
}



