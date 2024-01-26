def add_carry(num, carry):
    if num+carry == 2:
        return 0, 1
    else:
        return num+carry, 0

n, r = int(input()), int(input())
data = ''
for i in range(0, n):
    data += '0'
while True:
    carry = 1
    for i in range(0, n):
        data[i] = add_carry(int(data[i]), carry)[0]
        carry = add_carry[1]
        if carry == 0:
            break
    if carry == 1:
        break
    print(data)
