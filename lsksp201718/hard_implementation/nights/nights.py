a = list(map(int,input().split(":")))
b = list(map(int,input().split(":")))
b[0]+=12
# print(a,"b",b)
ansh = (b[0]-a[0])
ansm = (b[1]-a[1])
# print(ansh, ansm)

if ansm<0:
    ansm+=60
    ansh-=1
ansh = ansh%12
# print(ansh, ansm)
if (ansh and ansm):
    print("Misof slept for {} hour{} and {} minute{}.".format(ansh,"s" if ansh>1 else "",ansm,"s" if ansm>1 else ""))
elif (ansh and not ansm):
    print("Misof slept for {} hour{}.".format(ansh,"s" if ansh>1 else ""))
elif (ansm and not ansh):
    print("Misof slept for {} minute{}.".format(ansm,"s" if ansm>1 else ""))
else:
    print("Misof slept for 12 hours.")
