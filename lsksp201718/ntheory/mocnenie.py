from math import log
t = int(input())
for i in range(t):
    a,b,c = map(int,input().split())
    print(pow(a,b)%c)
