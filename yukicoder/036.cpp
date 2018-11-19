#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<bitset>

static int const MAX = 10000000 + 1;

std::vector<int> primes() {
  std::vector<int> rs;
  std::bitset<MAX> ps;
  ps.set();
  ps[0] = ps[1] = 0;
  for(int i{2}; i < MAX; ++i) {
    if(!ps[i]) continue;

    rs.push_back(i);
    for(int j{i * 2}; j < MAX; j += i) {
      ps[j] = 0;
    }
  }
  return rs;
}

bool ok(std::vector<int> const& ps, long long n, int depth) {
  for(auto e: ps) {
    if(n == e) {
      return false;
    }
    if(n % e == 0) {
      if(depth > 0) return true;
      return ok(ps, n / e, 1);
    }
  }
  return false;
}

int main(int, char**) {
  long long n;
  std::cin >> n;

  auto ps = primes();
  if(!ok(ps, n, 0)) {
    std::cout << "NO" << std::endl;
  } else {
    std::cout << "YES" << std::endl;
  }
}
