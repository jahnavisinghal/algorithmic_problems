#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  vector<int> visited;
  for(int i = 0; i < adj.size(); i++) {
    visited.push_back(0);
  }
  for(int i = 0; i < adj.size(); i++) {
    if(visited[i]) {
        continue;
    }
    std::stack<int> st;
    st.push(i);
    visited[i] = 1;
    while(!st.empty()) {
        int t = st.top();
        st.pop();
        for(int j = 0; j < adj[t].size(); j++) {
            if(!visited[adj[t][j]]) {
                st.push(adj[t][j]);
                visited[adj[t][j]] = 1;
            }
        }
    }
    res++;
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
