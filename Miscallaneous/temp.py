def foo1():
    i = 0
    result = 0 
    while i < 10:
       result += i
       i += 1
    return result
print(foo1())


def foo2():
    i = 0
    result = 0
    while i < 10:
        if i == 3:
            break
        result += i
        i += 1
    return result
print(foo2())


def bar1():
    result = 0
    for i in range(10):
        result += i
    return result
print(bar1())


def bar2():
    result = 0
    for i in range(10):
        if i % 3 == 1:
            continue
        result += i
    return result
print(bar2())