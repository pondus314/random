import itertools
counter = 1
for i in itertools.permutations([0,1,2,3,4,5,6,7,8,9]):
	if counter == 10**6+1:		
		print(i)
		break
	else: 
		counter+=1