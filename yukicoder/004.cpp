#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

static int const INF{100000000};

int solve(auto b, auto e, int w) {
  if(b == e || w == 0) return 0;

  if(w < *b) return solve(next(b), e, w);

  return solve(next(b), e, w - *b) + *b;
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

  std::sort(begin(ws), end(ws), std::greater<int>());
  int v = solve(begin(ws), end(ws), sum);

  std::cout << (sum == v ? "possible" : "impossible") << std::endl;

  return 0;
}



