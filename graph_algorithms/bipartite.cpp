#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  std::queue<int> queueForBfs;
  vector<int> color (adj.size(), 0);
  for(int i = 0; i < adj.size(); i++) {
    if(!color[i]) {
        // bfs for this node
        queueForBfs.push(i);
        color[i] = 1;
        while(!queueForBfs.empty()) {
            int node = queueForBfs.front();
            queueForBfs.pop();
            for(int j = 0; j < adj[node].size(); j++) {
                if(color[adj[node][j]] == color[node]) {
                    return 0;
                }
                if(!color[adj[node][j]]) {
                    queueForBfs.push(adj[node][j]);
                    color[adj[node][j]] = (color[node] == 1) ? 2 : 1;
                }
            }
        }
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
