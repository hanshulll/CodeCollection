#A Pythagorean theorem solver that accounts for whether the hypotenuse is known or not

def main():

    def is_right():
        righty = input("Do you have a right triangle (meaning one of the angles is 90 degrees)? (Y/N) ")
        if y_or_n(righty) == "Y":
            get_angles()
        else:
            not_right()

    def get_angles():
        hype = input("Do you know the length of the hypotenuse, the line that is opposite the right angle? (Y/N) ")
        if y_or_n(hype) == "Y":
            yes_hype()
        else:
            no_hype()
            
    def yes_hype():
        c = int(input("What is the length of the hypotenuse? "))
        a = int(input("What is the length of the other side you know? "))
        solver_hype(a,c)
    
    def no_hype():
        a = int(input("What is the length of one side? "))
        b = int(input("What is the length of the other side? "))
        solver_no(a,b)
    
    def solver_hype(x,c):
        squares = (c * c) - (x * x)
        y = squares ** 0.5
        print(f"The missing side is {y} units long.")

    def solver_no(a,b):
        squares = (a * a) + (b * b)
        c = squares ** 0.5
        print(f"The hypotenuse is {c} units long.")

    def not_right():
        print("I'm sorry, the Pythagorean theorum only works with right triangles.")
    
    def y_or_n(x):
        if(x.upper() == 'Y'):
            return("Y")
        elif(x.upper() == 'N'):
            return("N")
        else:
            print("I'm sorry, I can't understand that input. Please use 'Y' or 'N'.")
            y_or_n()

    print("The Pythagorean theorem is used to solve for an unknown side of a right triangle.")
    is_right()

if __name__ == "__main__":
    main()
else:
    print("Pythagorean theorem solver")
    main()