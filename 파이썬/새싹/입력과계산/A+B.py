#1000 A+B

a,b = map(int,input().split())

sum = lambda k,r : k+r
result = sum(a,b)
print(result)