#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int optimal_weight_dp(int W, const vector<int> &w) {
    std::vector< std::vector<int> > opt;
    int maxW = 0;
    for(int i = 0; i <= w.size(); i++) {
        vector<int> temp;
        for(int j = 0; j <= W; j++) {
            temp.push_back(0);
        }
        opt.push_back(temp);
    }
    for(int i = 1; i <= w.size(); i ++) {
        for(int j = 1; j <= W; j++) {
            if(opt[i-1][j] || w[i-1] == j) {
                opt[i][j] = 1;
                continue;
            }
            if(w[i-1] > j) {
                continue;
            }
            opt[i][j] = opt[i-1][j-w[i-1]];
            if(opt[i][j]) {
                maxW = std::max(maxW, j);
            }
        }
    }/*
    for(int i = 0; i <= w.size(); i++) {
        std::cout << "\n";
        for(int j = 0; j <= W; j++) {
            std::cout << opt[i][j] << " ";
        }
    }*/
    return maxW;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight_dp(W, w) << '\n';
}
