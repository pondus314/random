def rising(x):
	l = list(map(int, " ".join(str(x)).split() ))
	#print(l)
	for i in range(1,len(l)):
		if l[i]<l[i-1]:
			return(False)
	return(True)
		

def falling(x):
	l = list(map(int, " ".join(str(x)).split() ))
	#print(l)
	for i in range(1,len(l)):
		if l[i]>l[i-1]:
			return(False)
	return(True)

nonbouncy = 0
bouncy = 0
counter = 1
print(rising(1123), falling(132))
while bouncy < nonbouncy * 99 or bouncy == 0:
	if rising(counter) or falling(counter):
		nonbouncy+=1
	else:
		bouncy+=1
	counter+=1
	if counter%100 == 0: print(bouncy, nonbouncy)
print(counter)