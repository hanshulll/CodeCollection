def sum(x):
	if x==0:
		return 0 
	elif x==1:
		return 1
	else:
		return x+sum(x-1)
	
	
	
def main():
	x=input("This program is create for find the sum of n elements\nEnter the value:")
	try:
		x=int(x)
		print("The sum of first",x,"numbers is:",sum(x))
		
		
		option =input("1.Run again 2.Quit")
		if option=="1":
			main()
		else:
			print("Thankyou.../")
			quit()
	except:
		print("The value is not an integer:Try again()")
		main()
main()