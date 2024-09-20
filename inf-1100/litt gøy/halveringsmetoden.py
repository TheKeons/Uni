def f(x):
    return x*x-5

high = 50
low = -2
nullpunkt = (high+low)/2
print(f(nullpunkt))
while 0.0001 < f(nullpunkt):
    print('work')
    nullpunkt = (high+low)/2
    if f(low)*f(nullpunkt) < 0:
        high = nullpunkt

    else:
        low = nullpunkt

    

print(f'Nullpunktet er {nullpunkt}')