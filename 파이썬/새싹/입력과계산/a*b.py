#100998 a*b

a, b = map(int , input().split())

times = lambda r,k : r*k

result = times(a,b)
print(result)