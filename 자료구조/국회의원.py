#후보 n 
#주민 m

N  = int(input())

s = [0]*55
for i in range(N):
    s[i] = int(input())

cnt =0
big_num =-999
k =1
while True:
    if big_num <s[k]:
        big_num = s[k]
    if big_num >s[0]:
        s[0] +=1
        s[k] -=1
        cnt+=1
    elif big_num <s[0]:
        print( cnt)
        break
    k+=1

