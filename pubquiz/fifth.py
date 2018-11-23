import math
def sumofdig(x):
	ans = 0	
	for i in list(map(int, " ".join(str(x)).split())):
		ans+=i
	return ans

def getlog(x,y,z):
	if x == 1: 
		return True
	if y == 1 and x != 1:
		return False
	if x == y:
		return True	
	elif x % (y**z) == 0:
		return getlog(x//(y**z),y,z)
	else: 
		if z == 1: 
			return False
		else:
			return(getlog(x,y,z-1))

#print(sumofdig(614656))
a = []
print(getlog(81,9,4))

for i in range(10**8,5*10**8):
	#print(i)
	if getlog(i,sumofdig(i),max(math.ceil(math.log( i,max(2,sumofdig(i)) ) ),20) ):
		print(i)
		a.append(i)
	#if i%10 == 0:
		#print(i)
print(*a)