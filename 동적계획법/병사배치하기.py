#18353 병사배치하기 

a = int(input())

num = list(map(int,input().split()))

dp = [0] *a

for i in range(1,a):
    for j in range(i):
        if num[i]<num[j]:
            dp[i] = max(dp[i],dp[j]+1)

print(len(num) - max(dp))



n = int(input())

arr = list(map(int,input().split()))

dp = [1 for _ in range(n)]

for i in range(1,n):
    for j in range(i):
        if arr[i] < arr[j]:
            dp[i] = max(dp[i], dp[j]+1)

print(len(arr) - max(dp))