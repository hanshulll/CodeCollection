import os
import random
randInt = random.randint(1, 100)
userGuess = None
Gussess = 0
highScore=None
while(userGuess != randInt):
    userGuess = int(input("Enter Your Guess: "))
    if(userGuess == randInt):
        print("You Guessed it Right")
    else:
        if userGuess > randInt:
            print("Your guesss it Wrong! You have made the larger guess")
        else:
            print("Your guess it wrong! You have made the smaller guess")

        Gussess += 1

print(f"The Number of Gusssess for the Right answer the user made  is {Gussess}")

with open("highScore.txt", "r") as f:
    highScore = f.read()
    if(Gussess < int(highScore)):
        with open("highScore.txt","w") as f:
            f.write(str(Gussess))
        print(f"You have broken the high Score and the updated high Score for the Number of gussess is {Gussess}")
    else:
        print(f"The highest Number of the Guessess the user made for the right answer is :{highScore} ")




