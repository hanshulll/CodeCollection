# A game of Snake V/s Water V/s Gun
import random

def GameWin(Computer, Player):
    # Tie if Both Player & Computer choose same
    if Computer == Player:
        return None
    # Check for all possiblites when computer choose 's'
    elif Computer == 's':
        if Player == 2:
            return False
        elif Player == 3:
            return True
    # Check for all possiblites when computer choose 'w'
    elif Computer == 'w':
        if Player == 3:
            return False
        elif Player == 1:
            return True
    # Check for all possiblites when computer choose 'g'
    elif Computer == 'g':
        if Player == 1:
            return False
        elif Player == 2:
            return True


print("Computer's Turn: Snake(s) / Water(r) / Gun(g)?\n")
randNo = random.randint(1,3)
if randNo == 1:
    Computer = 's'
elif randNo == 2:
    Computer = 'w'
elif randNo == 3:
    Computer = 'g'

Player = int(input("Your Turn:Press 1->(Snake),2->(Water),3->(Gun)\n"))
if (Player==1 or Player==2 or Player==3):
    a = GameWin(Computer, Player)
    print(f"Computer Choose {Computer}")
    print(f"Player Choose {Player}")
    if a == None:
        print("The Game Is Tie !!!")
    elif a == True:
        print("Wow ! You Win ")
    else:
        print("Ohoo ! You Loose")    
else:
    print("Wrong Option Choosen")
    
