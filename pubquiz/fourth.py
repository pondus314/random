def ispal(x):
	a = str(x)
	for i in range(len(a)):
		if a[i]!=a[len(a)-i-1]:
			return False
	return True

#print(ispal(595), ispal(42), ispal(1), ispal(4223224))
squares = []
counter = 1
while counter < 10**4:
	squares.append(counter**2)
	counter+=1

anss = []
for i in range(9999):
	for j in range(i+2, 10000):
		b = sum(squares[i:j])
		if (b > 10**8):
			break
		else:
			if ispal(b):
				anss.append(b)
anss.sort()
print(anss)
print(anss[:11])
print(sum(anss))