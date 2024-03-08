# def hoanvi(arr,k,n):
#     if k == n:
#         print(' '.join(map(str,arr)))
#     else:
#         for i in range(k,n+1):
#             arr[k], arr[i] = arr[i], arr[k]
#             hoanvi(arr,k+1,n)
#             arr[k], arr[i] = arr[i], arr[k]
# n = int(input())
# arr=list(range(1,n+1))
# hoanvi(arr,0,n-1)

def backtrack(arr, k, n):
    for i in range(1, n+1):
        if check(arr, k, i):
            arr[k] = i
            if k == n-1:
                ans = ""
                for j in range(n):
                    ans += str(arr[j])+ " "
                print(ans)
            else:
                backtrack(arr, k + 1, n)

def check(arr, k, i):
    return i not in arr[:k]
n = int(input())
arr = [0 for i in range(n)]
backtrack(arr, 0, n)
