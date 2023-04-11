# 14720 우유축제문제 

shop = int(input())
flavour = list(map(int , input().split()))


cnt =0
for i in range(shop):
    if flavour[i] == cnt % 3:
        cnt+= 1
print(cnt)

    