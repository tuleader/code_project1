import sys

def matrix(n):
    d = [[-1 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        d[i][i] = 0
    return d

def xuly(n, edges):
    d = matrix(n)
    
    for u, v, w in edges:
        d[u - 1][v - 1] = w

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if d[i][k] != -1 and d[k][j] != -1:
                    if d[i][j] == -1 or d[i][j] > d[i][k] + d[k][j]:
                        d[i][j] = d[i][k] + d[k][j]

    return d

if __name__ == "__main__":
    n, m = map(int, input().split())
    edges = []

    for _ in range(m):
        u, v, w = map(int, input().split())
        edges.append((u, v, w))

    result = xuly(n, edges)

    for i in range(n):
        for j in range(n):
            if j > 0:
                print(" ", end="")
            print(result[i][j], end="")
        print()
