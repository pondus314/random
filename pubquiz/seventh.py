def is_prime(n):
  if n == 2 or n == 3: return True
  if n < 2 or n%2 == 0: return False
  if n < 9: return True
  if n%3 == 0: return False
  r = int(n**0.5)
  f = 5
  while f <= r:
    if n%f == 0: return False
    if n%(f+2) == 0: return False
    f +=6
  return True


ans = []
possibles = []

for i in range(10**8):
	possibles.append(i**2+(i+1)**2)
	if possibles[-1] > 10**15:
		break
	#if i%(10**6) == 0:
	#	print(i//(10**6))
#print(possibles)
count = 0
for i in possibles:
	if is_prime(i):
		ans.append(i)
		count+=1
		#print(i)
print(count, ans)