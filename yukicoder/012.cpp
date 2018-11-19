#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<bitset>

static int const MAX = 5000000 + 1;

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

void stage(std::array<int, 10>& digs, int n, int direction) {
  while(n > 0) {
    digs[n % 10] += direction;
    n /= 10;
  }
}

int main(int, char**) {
  int N;
  std::cin >> N;
  std::array<int, 10> as{};
  for(int i{}; i < N; ++i) {
    int t;
    std::cin >> t;
    as[t] = 1;
  }
  std::vector<int> ps = primes();

  int ans{-1};
  int last{};
  std::array<int, 10> nums{};
  for(int i{}; i < ps.size(); ++i) {
    stage(nums, ps[i], 1);
    for(int j{}; j < 10; ++j) {
      if(as[j]) continue;
      while(nums[j] > 0) {
        stage(nums, ps[last++], -1);
      }
    }
    // std::cout << "### i=" << i << ", ps[i]=" << ps[i] << ", last=" << last << std::endl;

    bool flg{true};
    for(int j{}; j < 10; ++j) {
      if(!as[j]) continue;
      if(nums[j] == 0) {
        flg = false;
      }
    }
    if(i >= last && flg) {
      // std::cout << "enter i=" << i << std::endl;
      int k, l;
      k = last == 0 ?
        1 :
        ps[last - 1] + 1;
      l = i == (ps.size() - 1) ?
        MAX - 1 :
        ps[i + 1] - 1;
      ans = std::max(ans, l - k);
    }
  }
  std::cout << ans << std::endl;
}
