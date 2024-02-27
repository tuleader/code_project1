#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>> > adjacency_list(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> min_weight(n + 1, 999999);
    long long total_weight = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacency_list[u].push_back({v, w});
        adjacency_list[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_heap;
    min_heap.push({0, 1});

    while (!min_heap.empty()) {
        int current_node = min_heap.top().second;
        int current_weight = min_heap.top().first;
        min_heap.pop();

        if (visited[current_node]) continue;
        visited[current_node] = true;
        total_weight += current_weight;

        for (pair<int, int> edge : adjacency_list[current_node]) {
            int neighbor = edge.first;
            int edge_weight = edge.second;
            if (!visited[neighbor] && edge_weight < min_weight[neighbor]) {
                min_weight[neighbor] = edge_weight;
                min_heap.push({edge_weight, neighbor});
            }
        }
    }

    cout << total_weight << endl;

    return 0;
}
