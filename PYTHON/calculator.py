import math
import sys
from datetime import datetime

print('-' * 50)
print('Maths Solving BOT!')
print(f'Time started: {str(datetime.now())}')
print('-' * 50)

print('\n[+] Are you here to find the root of a number? ')
ans = input('[+] Your answer (y/n): ')
if(ans == 'n'):
    print('\nOK, bye-bye!')
    sys.exit()

while(ans == 'y'): 
    class sqroot:
        def __init__(self, number):
            self.number = number
            self.sqrootno = math.sqrt(self.number)

        def displayno(self):
            print(f'[+] The root of the number you entered is: {self.sqrootno}')

        def fileWriting(self):
            with open('sqrootOutFile.txt', 'a') as f:
                f.write(f'\nThe root of {self.number} is: {self.sqrootno}')

        def fileReading(self):
            with open('sqrootOutFile.txt', 'r') as f:
                readingFile = f.read()
                print(f'\n[+]Your previously asked questions with answers are: {readingFile}')

    try:
        n = int(input('\n[+] Enter the number of which you want the root of: '))
        obj = sqroot(n)
        obj.displayno()
        obj.fileWriting()
        readingAns = input('\n[+] You want to know what previous questions you asked me? (yes/no): ')
        if(readingAns == 'yes'):
            obj.fileReading()
    except ValueError:
        print("You can't find the root of a string. :/ Enter a number please.")
    except:
        print('There is some kind of error in the BOT. Try again please.')
    
    ans = input('\n[+] Having some more questions that you want me to solve? (y/n): ')
    
    if(ans == 'n'):
        print('\nOK, bye-bye!')
        sys.exit()
