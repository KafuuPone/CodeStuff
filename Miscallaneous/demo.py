def func(x):
    return x**3+2*x**2+7*x

f = open('plot.csv', 'w')
i = -3
while i <= 3:
    f.write(str(i)+','+str(func(i)))
    i += 0.01
    f.write('\n')
f.close()