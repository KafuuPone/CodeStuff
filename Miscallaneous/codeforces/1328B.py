def solve():
    n_k = input().split(' ')
    n = int(n_k[0])
    k = int(n_k[1])
    b = 1
    while k>0:
        k -= b
        b += 1
    k = -k
    b -= 1
    for i in range(1, n+1):
        if i==n-b or i==n-b+k+1:
            print('b', end = '')
        else:
            print('a', end = '')
    print('')

t = int(input())
for i in range(0, t):
    solve()