from math import *

y = []
a = 0
b = pi
koef = []

def f(x):
    return(sin(x))

def integruj(s, n, a, b):
    if n == 0:
        s.append(((f(a)+f(b))/2)*(b-a))
    else:
        d = (b-a)/(2**n)
        suma = 0
        for i in range(2**n):
            suma += d*(f(a+i*d+d/2))
        s.append((s[n-1]+suma)/2)

def zrataj(val):
    ans = 0
    for i in range(t):
        loc = koef[i][-1]
        for j in range(i):
            loc = loc*(val-x[j])
        ans+=loc
    return(ans) 

t = int(input())
for i in range(t):
    integruj(y, i, a, b)
    print(y[i])

x = [4**(-i)*(b-a) for i in range(t)]
print(x)

koef = [[0 for j in range(i+1)] for i in range(t)]
for i in range(t):
    koef[i][0] = y[i]

for i in range(1,t):
    for j in range(i,t):
        koef[j][i] = (koef[j][i-1]-koef[j-1][i-1])/(x[j]-x[j-i])

print(zrataj(0))
# for(int i = 0; i < x.size(); i++){
#     koeficient[i].resize(i+1);
#     koeficient[i][0] = y[i];
# }
# for(int i = 1; i < x.size(); i++){
#     for(int j = i; j < x.size(); j++){
#         if(koeficient[j][i] == 0) koeficient[j][i] = (koeficient[j][i-1]-koeficient[j-1][i-1])/(x[j]-x[j-i]);
#     }
# }
