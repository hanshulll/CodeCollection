#!/bin/python3

kandidaten = {}
result = {}

def open_liste():
    return open("candidate.txt", "r")

def create_dict():
    counter = 0
    kandidaten[counter] = '>> END <<'
    foo = open_liste()
    for i in foo:
        i = i.strip()
        counter = counter + 1
        kandidaten[counter] = i 
        result[i] = 0 
    return kandidaten

def input_value():
    auflistung()
    foo = input(f"\nPlease vote your choice. : ")
    foo = check_num(foo)
    return foo

def check_num(foo):
    try:
        foo = int(foo)
        if foo == 0:
            run = True
        elif foo > 0 and foo < len(kandidaten):
            return foo
        elif foo >= len(kandidaten):
            print(f"We dont have this candidate.")
            foo = input_value()
            return foo
    except:
        print(f"You must vote the number from the candidate.\n")
        foo = input_value()
        return foo

def auflistung():