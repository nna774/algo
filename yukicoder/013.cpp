#include <iostream>
#include <vector>
#include <algorithm>

int main(int, char**) {
  int W, H;
  std::cin >> W >> H;

  std::vector<std::vector<int>> vec(H, std::vector(W, 0));
  std::vector<std::vector<bool>> map(H, std::vector(W, false));
  for(int i{}; i < H; ++i) {
    for(int j{}; j < W; ++j) {
      std::cin >> vec[i][j];
    }
  }

  bool found{};
  for(int i{}; i < H; ++i) {
    for(int j{}; j < W; ++j) {
      if(map[i][j]) continue;

      map[i][j] = true;
      int const m{vec[i][j]};
      using Point = std::pair<int, int>;
      std::vector<Point> stack;
      stack.emplace_back(i, j);
      int last{};
      int const up{1}, right{2}, down{3}, left{4};
      std::vector<int> stack_of_last{last};

      while(!stack.empty()) {
        Point const current{stack.back()};
        int const h = current.first;
        int const w = current.second;
//        std::cout << "## " << h << ' ' << w << std::endl;

        if(last != up && h != 0) {
          if(vec[h - 1][w] == m) {
//            std::cout << h - 1 << ' ' << w << std::endl;

            auto it = find(begin(stack), end(stack),std::make_pair(h - 1, w));
            if(it != end(stack)) {
              found = true;
              goto exit;
            }
            if(!map[h - 1][w]) {
              stack.emplace_back(h - 1, w);
              stack_of_last.push_back(last);
              map[h - 1][w] = true;
              last = down;
              continue;
            }
          }
        }
        if(last != right && w + 1 != W) {
          if(vec[h][w + 1] == m) {
//            std::cout << h << ' ' << w + 1 << std::endl;

            auto it = find(begin(stack), end(stack),std::make_pair(h, w + 1));
            if(it != end(stack)) {
              found = true;
              goto exit;
            }
            if(!map[h][w + 1]) {
              stack.emplace_back(h, w + 1);
              stack_of_last.push_back(last);
              map[h][w + 1] = true;
              last = left;
              continue;
            }
          }
        }
        if(last != down && h + 1 != H) {
          if(vec[h + 1][w] == m) {
//            std::cout << h + 1 << ' ' << w << std::endl;

            auto it = find(begin(stack), end(stack),std::make_pair(h + 1, w));
            if(it != end(stack)) {
              found = true;
              goto exit;
            }
            if(!map[h + 1][w]) {
              stack.emplace_back(h + 1, w);
              stack_of_last.push_back(last);
              map[h + 1][w] = true;
              last = up;
              continue;
            }
          }
        }
        if(last != left && w != 0) {
          if(vec[h][w - 1] == m) {
//            std::cout << h << ' ' << w - 1 << std::endl;

            auto it = find(begin(stack), end(stack),std::make_pair(h, w - 1));
            if(it != end(stack)) {
              found = true;
              goto exit;
            }
            if(!map[h][w - 1]) {
              stack.emplace_back(h, w - 1);
              stack_of_last.push_back(last);
              map[h][w - 1] = true;
              last = right;
              continue;
            }
          }
        }
//        std::cout << "pop!" << std::endl;
        stack.pop_back();
        last = stack_of_last.back();
        stack_of_last.pop_back();
      }
//      std::cout << "next !!" << std::endl;
    }
  }
  exit:

  std::cout << (found ? "possible" : "impossible") << std::endl;

//  for(int i{}; i < H; ++i) {
//    for(int j{}; j < W; ++j) {
//      std::cout << vec[i][j] << ' ';
//    }
//    std::cout << std::endl;
//  }
//
  return 0;
}
