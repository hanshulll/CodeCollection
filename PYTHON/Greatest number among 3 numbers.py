firstnumber,secondnumber,thirdnumber = list(map(int, input("Enter the number: ").split( )))
def greatestnumber(firstnumber,secondnumber,thirdnumber):
    if firstnumber>secondnumber and firstnumber>thirdnumber:
        return firstnumber
    elif secondnumber>firstnumber and secondnumber>thirdnumber:
        return secondnumber
    elif thirdnumber>firstnumber and thirdnumber>secondnumber:
        return thirdnumber
print("Greatest number:",greatestnumber(firstnumber,secondnumber,thirdnumber))
