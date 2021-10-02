import string
import random

#Characters List to Generate Password
characters = list(string.ascii_letters + string.digits + "!@#$%^&*()")

def password_gen():
	#Length of Password from the User
	length = int(input("Password length: "))

	#Shuffling the Characters
	random.shuffle(characters)

	#Picking random Characters from the given List
	password = []
	for i in range(length):
		password.append(random.choice(characters))

	#Shuffling the Resultant Password
	random.shuffle(password)

	#Converting the List to String
	#Printing the List
	print("".join(password))

#Invoking the function
password_gen()
