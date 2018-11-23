a = input()
ans = int(input())
b = a.split("*")
if b[0] == a:
    c = list(map(int,a.split("+")))
    if sum(c)==ans:
        print("oba")
    else:
        print("ziaden")
else:
    ans1 = 0
    b = a.split("+")
    for i in range(len(b)):
        if len(b[i])==1:
            ans1+=int(b[i])
        else:
            temp = 1
            for j in range(0,len(b[i]),2):
                temp = temp*int(b[i][j])
            ans1+=temp
    # print(ans1)
    ans2 = int(a[0])
    for i in range(2,len(a),2):
        if a[i-1]=="+":
            ans2+=int(a[i])
        else:
            ans2 = ans2*int(a[i])
    # print(ans2)
    if (ans1==ans):
        if (ans2==ans):
            print("oba")
        else:
            print("spravny")
    elif (ans2==ans):
        print("nespravny")
    else:
        print("ziaden")
