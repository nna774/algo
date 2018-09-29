#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

bool less(std::pair<int, int> lhs, std::pair<int, int> rhs) {
  if(lhs.first == rhs.first) {
    return lhs.second < rhs.second;
  }
  return lhs.first < rhs.first;
}

bool less2(std::pair<int, int> lhs, std::pair<int, int> rhs) {
  if(lhs.second == rhs.second) {
    return lhs.first < rhs.first;
  }
  return lhs.second < rhs.second;
}

bool less3(std::pair<int, int> lhs, std::pair<int, int> rhs) {
  if(lhs.second == rhs.second) {
    return lhs.first < rhs.first;
  }
  return lhs.second < rhs.second;
}

std::pair<int, int> plus(std::pair<int, int> lhs, std::pair<int, int> rhs) {
  return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

static int const INF{100000000};

int main(int, char**) {
  int N, C, V;
  std::cin >> N >> C >> V;

  std::vector<int> ss(V), ts(V), ys(V),ms(V);
  for(int i{0}; i < V; ++i) {
    std::cin >> ss[i];
  }
  for(int i{0}; i < V; ++i) {
    std::cin >> ts[i];
  }
  for(int i{0}; i < V; ++i) {
    std::cin >> ys[i];
  }
  for(int i{0}; i < V; ++i) {
    std::cin >> ms[i];
  }

  std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> vs(V);
  for(int i{0}; i < V; ++i) {
    vs[i] = std::make_pair(std::make_pair(ss[i] - 1, ts[i] - 1), std::make_pair(ms[i], ys[i]));
  }

  std::sort(begin(vs), end(vs), [](auto x, auto y){ return less(x.first, y.first); });

  std::vector<std::vector<std::pair<int, int>>> ns(N, std::vector<std::pair<int, int>>(1, std::make_pair(INF, INF)));
  ns[0] = std::vector<std::pair<int, int>>(1, std::make_pair(0, 0));

  for(int i{0}; i < V; ++i) {
    auto const v = vs[i].first;
    int const s = v.first;
    int const t = v.second;
    auto const vc = vs[i].second;

    auto& n = ns[t];
    for(auto c: ns[s]) {
      std::vector<std::pair<int, int>> new_n;
      auto new_cost = plus(c, vc);
      n.push_back(new_cost);
      auto it = std::remove_if(begin(n), end(n), [C, new_cost](auto x) { return x.second > C; });
      std::sort(begin(n), it, less);
      auto a1 = std::unique(begin(n), it, [](auto x, auto y) { return x.first == y.first; });
      int m1{INF};
      for(auto it = begin(n); it != a1; ++it) {
        if(it->second < m1) {
          m1 = it->second;
          new_n.push_back(*it);
        }
      }
      std::sort(begin(n), it, less2);
      auto a2 = std::unique(begin(n), it, [](auto x, auto y) { return x.second == y.second; });
      int m2{INF};
      for(auto it = begin(n); it != a2; ++it) {
        if(it->first < m2) {
          m2 = it->first;
          new_n.push_back(*it);
        }
      }
      n = new_n;
      // for(auto e: n) {
      //   std::cout << e.first << ',' << e.second << std::endl;
      // }
      // std::cout << "#####" << ns[s].size() << std::endl;
    }
    // std::cout << "--------------" << std::endl;
  }

  auto& n = ns[N - 1];
  std::sort(begin(n), end(n), less);
  // for(auto e: n) {
  //   std::cout << e.first << ',' << e.second << std::endl;
  // }
  if(begin(n) == end(n) || n[0].first == INF) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << n[0].first << std::endl;
  }

  return 0;
}
