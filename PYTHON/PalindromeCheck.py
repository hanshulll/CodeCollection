# Template for P23

def main():
    # Write your code below
    statement = str(input())
    statement_ = statement[::-1]

    # Take input of the string

    # Check for palindrome


    # Print the output. Note that the printed strings should have the exact same case as given in the problem statement in order to pass the test cases
    print('{} {}'.format(statement , statement == statement_))

# This is required to ensure that we can import your solve function without activating other parts of code
if __name__ == "__main__":
    main()