#include <bits/stdc++.h> 
using namespace std;
const int INF = numeric_limits<int>::max();

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back(Edge(v - 1, w));
    }

    int start, target;
    cin >> start >> target;
    start--; 
    target--;

    vector<int> distance(n, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distance[u]) {
            continue;
        }

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    if (distance[target] == INF) {
        cout << -1 << endl;
    } else {
        cout << distance[target] << endl;
    }

    return 0;
}
