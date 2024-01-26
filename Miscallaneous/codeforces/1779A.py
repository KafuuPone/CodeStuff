def solve():
    n = int(input())
    lamp = input()
    output = -1
    for i in range(1, n):
        substr = lamp[i-1:i+1]
        if substr == "LR":
            output = i
            break
        elif substr == "RL":
            output = 0
            break
    print(output)

t = int(input())
for i in range(0, t):
    solve()
