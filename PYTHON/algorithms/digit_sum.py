print("Enter a number")
try:
	t = int(input())
	
	for i  in range(t):
		n = int(input())
		a = n
		sum = 0
		while n!=0:
			a = n%10
			sum+=0
			n//=10
		print(sum)
except:
	pass
