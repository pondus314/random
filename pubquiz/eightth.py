import itertools
a = [1,2,3,4,5,6,7,8,9]

for i in itertools.permutations(a):
	suma = 1000*i[1]+100*i[2]+10*i[3]+i[4]
	sumb = 1000*i[5]+100*i[6]+10*i[7]+i[2]
	sumc = 10000*i[5]+1000*i[6]+100*i[3]+10*i[2]+i[8]
	if suma+sumb == sumc:
		print(*i) 


# 	S1	E2	N3	D4
# 	M5	O6	R7	E2
#--------------------------------
# M5	O6	N3	E2	Y8