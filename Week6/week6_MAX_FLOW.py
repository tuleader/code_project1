from collections import defaultdict

class MaxFlow:
    def __init__(self, n):
        self.graph = defaultdict(dict)
        self.n = n

    def add_edge(self, u, v, capacity):
        self.graph[u][v] = capacity
        self.graph[v][u] = 0

    def ford_fulkerson(self, source, sink):
        parent = [-1] * self.n
        max_flow = 0

        def bfs(source, sink):
            visited = [False] * self.n
            queue = [source]
            visited[source] = True

            while queue:
                u = queue.pop(0)
                for v, capacity in self.graph[u].items():
                    if not visited[v] and capacity > 0:
                        queue.append(v)
                        parent[v] = u
                        visited[v] = True
            return visited[sink]

        while bfs(source, sink):
            path_flow = float("inf")
            s = sink
            while s != source:
                path_flow = min(path_flow, self.graph[parent[s]][s])
                s = parent[s]
            max_flow += path_flow
            v = sink
            while v != source:
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = u

        return max_flow

if __name__ == "__main__":
    n, m = map(int, input().split())
    s, t = map(int, input().split())
    max_flow_solver = MaxFlow(n)

    for _ in range(m):
        u, v, capacity = map(int, input().split())
        max_flow_solver.add_edge(u - 1, v - 1, capacity)

    max_flow = max_flow_solver.ford_fulkerson(s - 1, t - 1)
    print(max_flow)
