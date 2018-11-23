fib = [0,1]
for i in range(10000):
	fib.append(fib[-1]+fib[-2])
sum = 0
for j in range(36):
	print(fib[j])
	if fib[j]>=4*10**6:
		break
	if fib[j]%2 ==0:
		sum+=fib[j]

print("fib[9999]")
print(sum)