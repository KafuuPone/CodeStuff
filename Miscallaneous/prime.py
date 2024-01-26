def prime(x):
    for i in range(2, x):
        if x%i == 0:
            return False
    return True

def min_prime_div(num):
    for i in range(2, num+1):
        if num%i == 0:
            if prime(i):
                return i

def print_factor(n):
    print(str(n)+' = ', end='')
    while n != 1:
        factor = min_prime_div(n)
        n //= factor
        print(factor, end='')
        if n != 1:
            print('*', end = '')
    print('')

n = int(input())
print_factor(n)