#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::vector;
using std::pair;

int coun = 1;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  used[x] = coun++;
  for(int j = 0; j < adj[x].size(); j++) {
    if(!used[adj[x][j]]) {
        dfs(adj, used, order, adj[x][j]);
    }
  }
  used[x] = coun++;
  order.push_back(x);
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  for(int i = 0; i < adj.size(); i++) {
    if(!used[i]) {
        // dfs for this node
        dfs(adj, used, order, i);
    }
  }
  std::reverse(order.begin(), order.end());
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
