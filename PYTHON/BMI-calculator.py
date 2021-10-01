#define variables
height = 0
weight = 0
bmi = 0
runAgain = ""

#display welcome message
print("\n------ BMI CALCULATOR ------\n")

#starting infinite loop for keep asking same question if use enter invalid input and repeat the program
while (True):
    try:
        #take user inputs
        height = float(input("Enter your height (m): "))
        weight = float(input("Enter your weight (kg): "))

        #display error when user input negative numbers
        if (height<0 or weight<0):
            print("\nPlease enter only positive values\n")
            continue #ignore below statements and go to next cycle of loop

        #display error when user input negative numbers
        if(height==0 or weight==0):
            print("\nHeight and Weight cannot be zero\n")
            continue

        #calculate and display bmi
        bmi = weight/height**2
        print("\nYour BMI is: ",round(bmi, 2))

        #display body type according to the bmi
        if(bmi<18.5):
            print("You are Underweight!")
        elif(bmi<24.9):
            print("You are Normal!")
        elif(bmi<29.9):
            print("You are Overweight!")
        else:
            print("You are Obese!")

        #display end message
        print("\nProgram Ended.")

        #starting infinite loop for keep asking same question if use enter invalid input
        while(True):

            #take user inputs
            runAgain = input("Do you want to rerun the program (yes/no): ")

            #rerun, stop, or display error message based on user input
            if(runAgain.lower().strip()=="yes"):
                print("\nRestarting Program")
                print("\n------ BMI CALCULATOR ------\n")
                break
            elif(runAgain.lower().strip()=="no"):
                print("\n------- GOOD BYE -------")
                break #break second while loop
            else:
                print("INVALID INPUT\n")
        
        if(runAgain.lower().strip()=="no"):
            break #break first while loop

    except ValueError:
        #display error when user input letters or symbols
        print("\nPlease enter only numbers\n")