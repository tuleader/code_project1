#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> g;
vector<bool> visited;
void ttdfs(int n) {
    visited[n] = true;
    cout << n << " ";
    set<int> adjnodes;
    for (int adjnode : g[n]) {
        if (visited[adjnode]==false) {
            adjnodes.insert(adjnode);
        }
    }
    for (int adjnode : adjnodes) {
        if (visited[adjnode]==false) {
            ttdfs(adjnode);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    int u, v;
    g.resize(n + 1);
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ttdfs(1);
    return 0;
}
