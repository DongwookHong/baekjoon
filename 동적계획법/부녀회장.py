#k n k 층 n 호 
t = int(input())

dp= [0]*15
sum =0
for _ in range(t):
    k=int(input())
    n=int(input())
    for i in range(1,n+1):
        sum +=i
    dp[0] =0
    dp[1] = 1
    dp[2] = 2
    for i in range(2,k+1):
        dp[i]= dp[i-1]+sum
    print(dp[k])