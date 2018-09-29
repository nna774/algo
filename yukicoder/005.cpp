#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

static int const INF{100000000};

int v(auto const& ws, int i, int w) {
  if(i == ws.size() || w == 0) return 0;
  
  if(ws[i] > w) return v(ws, i + 1, w);

  return 1 + v(ws, i + 1, w - ws[i]);
}

int main(int, char**) {
  int l, n;
  std::cin >> l >> n;
  std::vector<int> ws(n);
  for(int i{}; i < n; ++i) {
    std::cin >> ws[i];
  }

  std::sort(begin(ws), end(ws));

  std::cout << v(ws, 0, l) << std::endl;
}
