n, k = map(int, input().split())
a = list(map(int, input().split()))
s = [0] * n
count = 0

for i in range(n):
    if i == 0:
        s[i] = a[i]
    else:
        s[i] = s[i - 1] + a[i]

for i in range(n - k + 1):
    if i == 0:
        sum = s[i + k - 1]
    else:
        sum = s[i + k - 1] - s[i - 1]

    if sum % 2 == 0:
        count += 1

print(count)
