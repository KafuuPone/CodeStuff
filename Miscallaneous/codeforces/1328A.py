t = int(input())
for i in range(0, t):
    inp = input().split(' ')
    a, b = int(inp[0]), int(inp[1])
    print((b-a%b)%b)