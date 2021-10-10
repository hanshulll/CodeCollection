import random
name = input("Enter your name:")
print("Hey",name+'! Good Luck.')
words = ['star', 'guess', 'computer', 'chocolate', 'friends', 'games' , 'movies', 'day', 'date', 'joey', 'phoebe', 'ross', 'chandler', 'monica', 'rachel', 'gunther', 'richard', 'central', 'perk', 'emma', 'ben']
word = random.choice(words)

print('Guess the characters')
guesses = ''

turns = 12
while turns > 0:
    failed = 0

    for char in word:
        if char in guesses:
            print(char)
        else:
            print("_")

            failed += 1

    if failed == 0:
        print('You Win!')
        print('The word is:', word)
        break

    guess = input('Guess a character:')
    guesses += guess

    if guess not in word:
        turns -= 1
        print('Wrong!')
        print('You have', turns, 'more guesses.')

        if turns == 0:
            print("You Lose!")
            print("Try Again Next Time!")
