#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

int main(int, char**) {
  int n;
  std::cin >> n;

  std::vector<bool> primes(n + 1, true);
  primes[0] = primes[1] = false;
  for(int i{2}; i < std::sqrt(n) + 1; ++i) {
    if(!primes[i]) continue;

    for(int j{i * 2}; j < n + 1; j += i) {
      primes[j] = false;
    }
  }

  std::vector<int> ps;
  for(int i{}; i < n + 1; ++i) {
    if(primes[i]) ps.push_back(i);
  }

  // 2 or 3をもらうと負け。

  std::vector<int> results(n + 1, -1);
  results[2] = results[3] = 0; // 0 まけ 1 かち

  for(int i{4}; i <= n; ++i) {
    bool atta{};
    for(int j{}; j < i; ++j) {
      if(ps[j] > i) break;

      if(results[i - ps[j]] == 0) {
        atta = true;
        break;
      }
    }
    if(atta) {
      results[i] = 1;
    } else {
      results[i] = 0;
    }
  }

  std::cout << (results[n] ? "Win" : "Lose") << std::endl;

  return 0;
}
