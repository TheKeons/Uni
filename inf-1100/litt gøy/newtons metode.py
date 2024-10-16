import math

def der(f, h=10**-6):
    return lambda x: (f(x+h) - f(x)) / h

def f(x):
    return 2*x - math.e**(-x**2)

xn = 0

for i in range(6):
    xn = xn - (f(xn)/der(f)(xn))

print(xn)