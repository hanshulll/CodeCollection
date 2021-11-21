def gcd(a,b):
	if(b==0):
		return a
	else:
		return gcd(b,a%b)

a = 60
b= 48
print ("The gcd of 60 and 48 is : ",end="")
print (gcd(60,48))
