#include<iostream>
#include<queue>
#include<string>

using std::begin;
using std::end;

int main() {
  int n, q;
  std::cin >> n >> q;
  std::queue<std::pair<std::string, int>> queue;
  for(int i{0}; i < n; ++i) {
    std::string name;
    int t;
    std::cin >> name >> t;
    queue.emplace(name, t);
  }

  int time{0};
  while(!queue.empty()) {
    auto p = queue.front();
    queue.pop();
    if(p.second <= q) {
      time += p.second;
      std::cout << p.first << ' ' << time << std::endl;
    }
    else {
      time += q;
      queue.emplace(p.first, p.second - q);
    }
  }

  return 0;
}
