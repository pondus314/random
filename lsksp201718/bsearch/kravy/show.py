# import sys
# for k in range(100):
#     sys.stdin = open("{}.in".format(k), "r")
#     sys.stdout = open("{}.bf".format(k), "w")
n,f = map(int, input().split())
kravy = list(map(int,input().split()))
prefixove = [0,kravy[0]]
for i in range(n-1):
    prefixove.append(prefixove[i+1]+kravy[i+1])
ans = 0
for i in range(1,n+1):
    for j in range(i+f-1,n+1):
        print(ans, 1000*(prefixove[j]-prefixove[i-1])//(j-i+1), i, j)
        ans = max(ans, 1000*(prefixove[j]-prefixove[i-1])//(j-i+1))
# print(prefixove)
print(ans)
