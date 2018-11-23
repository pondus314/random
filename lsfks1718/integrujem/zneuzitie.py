from math import *
from decimal import Decimal

y = []
a = 0
b = pi
koef = []

def f(x):
    return(Decimal(sin(x)))

def integruj(s, n, a, b):
    if n == 0:
        s.append(((f(a)+f(b))/2)*Decimal(b-a))
    else:
        d = Decimal(b-a)/(2**n)
        suma = 0
        for i in range(2**n):
            suma += d*(f(a+i*d+d/2))
        s.append((s[n-1]+suma)/2)

def zrataj(val,h):
    ans = Decimal(0)
    for i in range(h):
        loc = Decimal(koef[i][-1])
        for j in range(i):
            loc = loc*(val-x[j])
        ans+=loc
    return(ans)

t = int(input())
r = int(input())
for i in range(t):
    integruj(y, i, a, b)
    print(y[i])

x = [Decimal(4)**Decimal(-i)*Decimal(b-a) for i in range(t)]
print(x)

for i in range(r):
    koef = [[Decimal(0) for k in range(j+1)] for j in range(t+i)]
    for j in range(t+i):
        koef[j][0] = Decimal(y[j])

    for j in range(1,t+i):
        for k in range(j,t+i):
            koef[k][j] = Decimal(koef[k][j-1]-koef[k-1][j-1])/(x[k]-x[k-j])

    y.append(zrataj(0,t+i))
    x.append(Decimal(4)**Decimal(-len(x))*Decimal(b-a))

koef = [[Decimal(0) for k in range(j+1)] for j in range(t+r)]
for j in range(t+r):
    koef[j][0] = Decimal(y[j])

for j in range(1,t+r):
    for k in range(j,t+r):
        koef[k][j] = Decimal(koef[k][j-1]-koef[k-1][j-1])/(x[k]-x[k-j])



print(zrataj(0,t+r))
# for(int i = 0; i < x.size(); i++){
#     koeficient[i].resize(i+1);
#     koeficient[i][0] = y[i];
# }
# for(int i = 1; i < x.size(); i++){
#     for(int j = i; j < x.size(); j++){
#         if(koeficient[j][i] == 0) koeficient[j][i] = (koeficient[j][i-1]-koeficient[j-1][i-1])/(x[j]-x[j-i]);
#     }
# }
