#2720 백준

import sys
sys.stdin=open("abc.txt","rt")

T = int(input())
money = [25, 10, 5, 1]
rest = [0]*4

for _ in range(T):
    C = int(input())

    for j in range(len(money)):
        rest[j] = C // money[j]
        C = C % money[j]

    print(' '.join(map(str, rest)))