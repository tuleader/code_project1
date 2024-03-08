from math import gcd

def solve(a, b, c):
    x, y = 0, 0
    steps = 0
    if c > max(a, b) or c % gcd(a, b) != 0:
        return -1

    while x != c and y != c:
        if x == 0:
            x = a
            steps += 1
        elif y == b:
            y = 0
            steps += 1
        else:
            transfer = min(x, b - y)
            x -= transfer
            y += transfer
            steps += 1

    return steps

a, b, c = map(int, input().split())
result = min(solve(a, b, c),solve(b,a,c))
print(result)
