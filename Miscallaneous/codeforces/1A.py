import math
nma = input().split(' ')
n = int(nma[0])
m = int(nma[1])
a = int(nma[2])
print(math.ceil(n/a)*math.ceil(m/a))