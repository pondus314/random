import sys
a = input()
if ord('z')-ord(a[0])>25:
    print("Error!")
    sys.exit()
capitals = False
underscores = False
for i in range(len(a)):
    if ord('z')-ord(a[i])>27:
        capitals = True
    elif ord('z')-ord(a[i])==27:
        underscores = True
if underscores and capitals:
    print("Error!")
elif underscores:
    if a[-1]=="_":
        print("Error!")
        sys.exit()
    ans = ""
    for i in range(1,len(a)):
        if a[i]=="_" and a[i-1]=="_":
            print("Error!")
            sys.exit()
    a = a.split("_")
    for i in range(len(a)):
        for j in range(len(a[i])):
            if j==0 and i!=0:
                ans+=a[i][j].upper()
            else:
                ans+=a[i][j]
    print(ans)
elif capitals:
    ans = ""
    for i in range(len(a)):
        if ord('z')-ord(a[i])> 25:
            ans+="_"
            ans+=a[i].lower()
        else:
            ans+=a[i]
    print(ans)
else:
    print("same")
