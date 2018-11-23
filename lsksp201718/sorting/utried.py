a = int(input())
queens = []
hor = []
ans = 0
vert = []
diag1 = []
diag2 = []
for i in range(a):
    b = list(map(int, input().split()))
    queens.append(b)
    hor.append([b[0],i])
    vert.append([b[1],i])
    diag1.append([sum(b),i])
    diag2.append([b[0]-b[1],i])
hor.sort()
vert.sort()
diag1.sort()
diag2.sort()
for i in range(1,a):
    if hor[i][0]==hor[i-1][0]:
        ans+=1
    if vert[i][0]==vert[i-1][0]:
        ans+=1
    if diag1[i][0]==diag1[i-1][0]:
        ans+=1
    if diag2[i][0]==diag2[i-1][0]:
        ans+=1
print(ans)
