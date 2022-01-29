import os
import time
b = int(input("Enter the time in seconds: "))
a = b
while a > 0:
    os.system("cls")
    print(f"Timer for {b} seconds")
    print('You have \033[1m' + str(a) + "\033[0m", 'seconds left')
    a -= 1
    time.sleep(1)
    os.system("cls")

print("Time Up")
