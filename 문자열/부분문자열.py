#6550 부분문자열 실버 5

while True :
  try :
    s, t = input().split()
    
    value = 0
    flag = 0
    for i in range(len(t)) :
      if t[i] == s[value] :
        value += 1
        if value == len(s) :
          flag = 1
          break

    if flag == 1 :
      print('Yes')
    else :
      print('No')

  except :
    break

from collections import deque

while True:
    try:
        s, t = input().split()

        s_deque = deque(s)
        t_deque = deque(t)

        value = 0
        flag = False

        while t_deque:
            if t_deque[0] == s_deque[value]:
                value += 1
                t_deque.popleft()

                if value == len(s_deque):
                    flag = True
                    break
            else:
                t_deque.popleft()

        if flag:
            print('Yes')
        else:
            print('No')

    except EOFError:
        break