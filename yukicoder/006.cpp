#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

int hash(int n) {
  if(n < 10) return n;
  int h{};
  while(n > 0) {
    h += n % 10;
    n /= 10;
  }
  return hash(h);
}

int main(int, char**) {
  int k, n;
  std::cin >> k >> n;

  std::vector<bool> primes(n + 1, true);
  primes[0] = primes[1] = false;
  for(int i{2}; i < std::sqrt(n) + 1; ++i) {
    if(!primes[i]) continue;

    for(int j{i * 2}; j < n + 1; j += i) {
      primes[j] = false;
    }
  }

  std::vector<std::pair<int, int>> ps;
  for(int i{}; i < n + 1; ++i) {
    if(i >= k && primes[i]) ps.push_back(std::make_pair(i, hash(i)));
  }

  // for(auto e: ps) {
  //   std::cout << e.first << ',' << e.second << std::endl;
  // }
  // std::cout << ps.size() << std::endl;
  int window_size = std::min(10, static_cast<int>(ps.size()));
  while(window_size) {
    std::vector<int> map(10);
    
    for(int i{ps.size() - window_size}; i < ps.size(); ++i) {
      ++map[ps[i].second];
    }

    auto isOK = [](auto const& v) { return all_of(begin(v), end(v), [](int x) { return x < 2; }); };

    if(isOK(map)) {
      std::cout << ps[ps.size() - window_size].first << std::endl;
      // std::cout << window_size << "here";
      return 0;
    }

    for(int i{ps.size() - window_size - 1}; i >= 0; --i) {
      --map[ps[i + window_size].second];
      ++map[ps[i].second];
      if(isOK(map)) {
        std::cout << ps[i].first << std::endl;
        // std::cout << window_size;
        return 0;
      }
    }

    --window_size;
  }

  return 0;
}
