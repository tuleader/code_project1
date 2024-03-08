n = int(input())
arr = list(map(int, input().split()))
set = set()
for i in arr:
    if i in set:
        print(1)
    else:
        set.add(i)
        print(0)
