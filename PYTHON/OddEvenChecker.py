# Created by Bigyan Rijal (Github - theoptimist76)

# Simple Try Catch block for odd even checker in python
# Try Block
try:
    # User is asked to enter any random number to check
    number = int(input("Enter a random number: "))
    # If-else condition
    if number % 2 == 0:
        print(number, "is even number.")
    else:
        print(number, "is odd number.")

# Exception block    
except ValueError:
    # Print error message if user enters wrong values
    print("Please enter a numeric value.")
