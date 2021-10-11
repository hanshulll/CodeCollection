# This program will help you a lot while setting a strong password.
# Just provide number of alphabets, numbers and symbols required in your password, and then,
# you have your strong password.

import random

print("Welcome to the PyPassword Generator!")
total_letters = int(input("How many letters would you like in your password?\n"))
total_symbols = int(input("How many symbols would you like in your password?\n"))
total_numbers = int(input("How many numbers would you like in your password?\n"))

letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

password = []

for i in range(total_letters):
    password += random.choice(letters)
for i in range(total_symbols):
    password += random.choice(symbols)
for i in range(total_numbers):
    password += random.choice(numbers)
random.shuffle(password)

print(f'Here is your password: {"".join(password)}')