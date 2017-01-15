#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
struct Compare {
    bool operator() (pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }
}Com;
int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  std::vector<int> dist(adj.size(), 10000);
  std::priority_queue< pair<int, int>, vector< pair<int, int> >, Compare > knownNodes;
  knownNodes.push(pair<int, int> (s, 0));
  dist[s] = 0;
  while(!knownNodes.empty()) {
    int nextNode = knownNodes.top().first;
    knownNodes.pop();
    for(int i = 0; i < adj[nextNode].size(); i++) {
        int neighbor = adj[nextNode][i];
        if(dist[neighbor] > dist[nextNode] + cost[nextNode][i]) {
            dist[neighbor] = dist[nextNode] + cost[nextNode][i];
            knownNodes.push(pair<int, int> (neighbor, dist[neighbor]));
            //std::cout << "\nrelaxed and pushing " << neighbor << ", with value " << dist[neighbor];
        }
    }
  }
  if(dist[t] < 10000) {
    return dist[t];
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
