n = int(input())

print(int((n)*(n+1)*(n+2))//6)

sum = 0
for i in range(1,n+1):
    sum += (n+1-i)*i

print(sum)
