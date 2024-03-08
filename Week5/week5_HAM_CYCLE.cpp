#include <bits/stdc++.h> 
using namespace std;
class Graph {
public:
    int n; 
    vector<vector<int>> adjlist;
    Graph(int n) {
        this->n = n;
        adjlist.resize(n);
    }
    void addCanh(int u, int v) {
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    bool check() {
        vector<int> path;
        vector<bool> visited(n, false);
        path.push_back(0);
        return duyet_hamiton(path, visited);
    }
    bool duyet_hamiton(vector<int>& path, vector<bool>& visited) {
        if (path.size() == n) {
            if (adjlist[path.back()][0] == path[0]) {
                return true;
            }
            return false;
        }
        int u = path.back();
        for (int v : adjlist[u]) {
            if (!visited[v]) {
                path.push_back(v);
                visited[v] = true;
                if (duyet_hamiton(path, visited)) {
                    return true;
                }
                path.pop_back();
                visited[v] = false;
            }
        }
        return false;
    }
};
int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        int n, m;
        cin >> n >> m;
        Graph g(n);
        for (int i = 0; i < m; i++) {
            int u,v;
            cin>>u>>v;
            g.addCanh(u-1,v-1);
        }
        if (g.check()==true) {
            cout<<"1"<<endl;
        } else {
            cout<<"0"<<endl;
        }
    }
    return 0;
}
