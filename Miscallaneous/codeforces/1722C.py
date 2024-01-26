#1722C
for x in range(0, int(input())):
    input()
    a = set(input().split(' '))
    b = set(input().split(' '))
    c = set(input().split(' '))
    print(len(a)+2*len(a-(b|c))-len(a&b&c), len(b)+2*len(b-(a|c))-len(a&b&c), len(c)+2*len(c-(b|a))-len(a&b&c))