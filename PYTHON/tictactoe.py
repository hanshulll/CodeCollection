#function with appropriate format for printing the board 
def printCanvas(canvas):
    print(canvas[1]+" | "+canvas[2]+" | "+canvas[3]+"        "+"1"+" | "+"2"+" | "+"3")
    print(canvas[4]+" | "+canvas[5]+" | "+canvas[6]+"  <==>  "+"4"+" | "+"5"+" | "+"6")
    print(canvas[7]+" | "+canvas[8]+" | "+canvas[9]+"        "+"7"+" | "+"8"+" | "+"9")
    print("\n")

   

#function to check if position on canvas is empty
def emptyPos(pos):
    if (canvas[pos]=='*'):
        return True
    else:
        return False
#function to insert letter at entered position. It also calls winCheck() and drawCheck() to see if there is a win or draw
def letterPos(l,pos):
    if emptyPos(pos):
        canvas[pos]=l
        printCanvas(canvas)
        if winCheck():
            if l=='X':
                print("X wins!")
                exit()
            else:
                print("O wins!")
                exit() 
        if(drawCheck()):
           print("It's a draw!")
           exit() 
        return
    else:
        print("Position is already full!")
        pos= int(input("Enter a different position: "))
        letterPos(l,pos)
        return    
#fucntion to check all possibilities of winning the game
def winCheck():
    #horizontally
    if   (canvas[1] == canvas[2] and canvas[1] == canvas[3] and canvas[1] != '*'):
        return True
    elif (canvas[4] == canvas[5] and canvas[4] == canvas[6] and canvas[4] != '*'):
        return True
    elif (canvas[7] == canvas[8] and canvas[7] == canvas[9] and canvas[7] != '*'):
        return True
    #vertically    
    elif (canvas[1] == canvas[4] and canvas[1] == canvas[7] and canvas[1] != '*'):
        return True
    elif (canvas[2] == canvas[5] and canvas[2] == canvas[8] and canvas[2] != '*'):
        return True
    elif (canvas[3] == canvas[6] and canvas[3] == canvas[9] and canvas[3] != '*'):
        return True
    #diagonally    
    elif (canvas[1] == canvas[5] and canvas[1] == canvas[9] and canvas[1] != '*'):
        return True
    elif (canvas[7] == canvas[5] and canvas[7] == canvas[3] and canvas[7] != '*'):
        return True
    else:
        return False 
#function with letter argument which checks win , necessary for engine
def letterwinCheck(let):
    if   (canvas[1] == canvas[2] and canvas[1] == canvas[3] and canvas[1] == let):
        return True
    elif (canvas[4] == canvas[5] and canvas[4] == canvas[6] and canvas[4] == let):
        return True
    elif (canvas[7] == canvas[8] and canvas[7] == canvas[9] and canvas[7] == let):
        return True
    elif (canvas[1] == canvas[4] and canvas[1] == canvas[7] and canvas[1] == let):
        return True
    elif (canvas[2] == canvas[5] and canvas[2] == canvas[8] and canvas[2] == let):
        return True
    elif (canvas[3] == canvas[6] and canvas[3] == canvas[9] and canvas[3] == let):
        return True
    elif (canvas[1] == canvas[5] and canvas[1] == canvas[9] and canvas[1] == let):
        return True
    elif (canvas[7] == canvas[5] and canvas[7] == canvas[3] and canvas[7] == let):
        return True
    else:
        return False 
#function which checks draw condition
def drawCheck():
    for y in range(1,10):
        if canvas[y]=='*':
          return False  
    return True


#function to input user move
def userMove():
    pos=int(input("Enter the position for {} : ".format(user)))
    letterPos(user,pos)
    return
#function to enter engine move
def engineMove():
    topScore= -500
    bestPos= 0
    
    for y in range(1,10):
       if (canvas[y]=='*'):
           canvas[y]= engine  ##check
           score= minimaxAlgo(canvas,False)
           canvas[y] = '*'
           if (score > topScore):
              topScore = score
              bestPos = y 
    letterPos(engine,bestPos)
    return   
#minimax algorithm to calculate high score engine move
def minimaxAlgo(canvas,maximizer):

    if (letterwinCheck(engine)):#checks win for engine
       return 1
    elif (letterwinCheck(user)):#checks win for user
       return -1
    elif (drawCheck()):#checks draw
       return 0
    #maximizing engine move
    if (maximizer):
        topScore= -500 #assigning any value as base topscore
    
    
        for y in range(1,10): #traversing the canvas
            if (canvas[y]=='*'):
                canvas[y]= engine #placing engine move at the checked empty position
                score= minimaxAlgo(canvas,False)
                canvas[y] = '*' #undoing the move so board does not get filled and all conditions are checked
                if (score>topScore): #if score is more than topscore we get a new topscore to compare with
                    topScore=score
        return topScore             
    #minimizing user move
    else:
        topScore=500

        for y in range(1,10): 
            if (canvas[y]=='*'):
                canvas[y]= user #placing user move at the checked empty position
                score= minimaxAlgo(canvas,True)
                canvas[y] = '*'
                if (score<topScore):
                    topScore=score
        return topScore  
canvas = ['*' for _ in range(10)]

printCanvas(canvas) #prints canvas once so user can understand

user='O' 
engine='X' 

print("Computer plays first!")
print("Enter your letter: ",end=" ")
user=input() #lets user select the letter he wants to play with
if user=='X'or user=='x':
    engine='O'
    user='X'
elif user=='O' or user=='o':
    engine='X'
    user='O'
else:
    print("Wrong letter selected! Please choose between 'X' & 'O'! Please run the program again.")
    exit()   #exits if the letter selected is not X or O



while not winCheck(): #main game loop 
    engineMove()
    userMove()
