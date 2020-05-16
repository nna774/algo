#include <iostream>
#include <vector>
#include <algorithm>

int find(std::vector<std::pair<int, std::vector<int>>> const& books, int cost, std::vector<int> const& xs, int x, int depth, int max_depth) {
  /*
  std::cout << "x: ";
  for(auto e: xs) {
    std::cout << e << ", ";
  }
  std::cout << std::endl;
  */
  if(std::all_of(begin(xs), end(xs), [x](int n) { return n >= x; })) {
    return cost;
  }
  // std::cout << "here2: " << depth << std::endl;
  if(depth >= max_depth) return -1;
  std::vector<int> my_xs(xs);
  std::pair<int, std::vector<int>> const& the_book = books[depth];
  for(int i{}; i < xs.size(); ++i) {
    my_xs[i] += the_book.second[i];
  }
  // std::cout << "here3: " << depth << std::endl;
  int res1 = find(books, cost + the_book.first, my_xs, x, depth + 1, max_depth);
  int res2 = find(books, cost + 0             , xs   , x, depth + 1, max_depth);
  // std::cout << "depth: " << depth << " " << res1 << ", " << res2 << std::endl;
  if(res1 == -1) return res2;
  if(res2 == -1) return res1;
  // std::cout << "DDDDDdepth: " << depth << " " << res1 << ", " << res2 << std::endl;

  return std::min(res1, res2);
}

int main(int, char**) {
  int n, m, x;
  std::cin >> n >> m >> x;
  std::vector<std::pair<int, std::vector<int>>> books(n);

  for(int i{}; i < n; ++i) {
    int c;
    std::cin >> c;
    books[i].first = c;
    for(int j{}; j < m; ++j) {
      int a;
      std::cin >> a;
      books[i].second.push_back(a);
    }
  }
  std::sort(begin(books), end(books));
  /*
  for(auto e: books) {
    std::cout << e.first << ": ";
    for(auto e2: e.second) {
      std::cout << e2 << ", ";
    }
    std::cout << std::endl;
  }
  */

  std::vector<int> xs(m);
  auto result = find(books, 0, xs, x, 0, n);

  std::cout << result << std::endl;

  return 0;
}
