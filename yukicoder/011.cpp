#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<numeric>
#include<bitset>
#include<set>

static int const INF{100000000};

int main(int, char**) {
  long long w, h, n;
  std::cin >> w >> h >> n;
  std::set<int> ss;
  std::set<int> ks;
  for(int i{}; i < n; ++i) {
    int s, k;
    std::cin >> s >> k;
    ss.insert(s);
    ks.insert(k);
  }

  long long ans{};
  ans += ss.size() * h;
  ans += ks.size() * w;
  ans -= ss.size() * ks.size();
  ans -= n;
  std::cout << ans  << std::endl;
  
  return 0;
}
