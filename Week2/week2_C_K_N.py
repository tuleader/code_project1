k, n = map(int, input().split())

solve_C = [[0 for i in range(n + 1)] for j in range(k + 1)]
for i in range(k+1):
    for j in range(n+1):
        if i == 0 or i == j:
            solve_C[i][j] = 1
        else:
            solve_C[i][j] = solve_C[i - 1][j - 1] + solve_C[i][j - 1]

print(solve_C[k][n] % (1000000007))
