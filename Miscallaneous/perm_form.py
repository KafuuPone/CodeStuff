def perms(n, k):
    out = (2**(n-k-1))*(n-k+2)
    r=k
    while r<n-k:
        out -= perms(r, k)*(2**(n-k-1-r))
        r += 1
    return int(out)

n = int(input())+1
f = open('perm_list.csv', 'w')
for i in range(0, n):
    for j in range(0, n):
        if i == 0:
            f.write(str(j)+',')
        elif j == 0:
            f.write(str(i)+',')
        elif i < j:
            break
        else:
            f.write(str(perms(i, j))+',')
    f.write('\n')
f.close()