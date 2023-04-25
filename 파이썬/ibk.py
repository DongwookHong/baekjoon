
def board(n, count, str):
    screen = ["_"] * n
    for c in str:
        screen.append(c)
    cur_count = 0
    while cur_count < count:
        for i in range(n):
            screen[i] = screen[(i+1) % len(screen)]
        cur_count += 1
    return "".join(screen)

