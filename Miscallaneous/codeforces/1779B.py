def solve():
    n = int(input())
    if n == 3:
        out = "NO"
    else:
        out = "YES\n"
        a, b = 1, -1
        if n%2 != 0:
            a = int((n-1)/2-1)
            b = int((1-n)/2)
        for i in range(0, n):
            if i%2 == 0:
                out += str(a)
            else:
                out += str(b)
            out += ' '
    print(out)

t = int(input())
for i in range(0, t):
    solve()