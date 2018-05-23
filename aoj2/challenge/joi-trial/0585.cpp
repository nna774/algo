#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<cmath>
#include<complex>
#include<limits>

using std::begin;
using std::end;

using Compl = std::complex<float>;

auto comp_x = [](Compl const& l, Compl const& r) { return std::real(l) < std::real(r); };
auto comp_y = [](Compl const& l, Compl const& r) { return std::imag(l) < std::imag(r); };

using It = std::vector<Compl>::iterator;

int closest_pair(It begin, It end) {
  if (end - begin <= 1) return std::numeric_limits<int>::max();

  auto mid{begin + (end - begin) / 2};
  int x{static_cast<int>(std::real(*mid))};
  int d{std::min(closest_pair(begin, mid), closest_pair(mid, end))};
  std::inplace_merge(begin, mid, end, comp_y);
  std::vector<Compl> t;
  for(auto it{begin}; it != end; ++it) {
    if(std::abs(std::real(*it) - x) >= d) continue;

    for(int i{static_cast<int>(t.size()) - 1}; i >= 0; --i) {
      int dx{static_cast<int>(std::real(*it) - std::real(t[i]))};
      int dy{static_cast<int>(std::imag(*it) - std::imag(t[i]))};
      if(dy >= d) break;

      d = std::min(d, dx * dx + dy * dy);
    }
    t.push_back(*it);
  }
  return d;
}

int main(int, char**) {
  int n;
  std::cin >> n;
  std::vector<Compl> v;
  std::vector<int> rs;

  for(int i{0}; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    v.emplace_back(x, y);
  }

  std::sort(begin(v), end(v), comp_x);
  std::cout << closest_pair(begin(v), end(v)) << std::endl;

  return 0;
}
