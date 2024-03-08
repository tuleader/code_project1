#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> g; 
vector<bool> visited;
void ttbfs(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (q.empty()==false) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        set<int> adjnodes; 
        for (int adjnode : g[node]) {
            if (visited[adjnode]==false) {
                q.push(adjnode);
                visited[adjnode] = true;
                adjnodes.insert(adjnode);
            }
        }
        for (int adjnode : adjnodes) {
            if (visited[adjnode]==false) {
                cout << adjnode << " ";
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    int u,v;
    g.resize(n+1);
    visited.assign(n+1,false);
    for (int i=0;i<m; i++) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        sort(g[i].begin(),g[i].end());
    }
    for(int i=1;i<=n;i++)
       if(visited[i]==false) ttbfs(i);
    return 0;
}
