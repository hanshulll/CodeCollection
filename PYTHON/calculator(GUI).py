from tkinter import *
import math

window = Tk()

window.title("Calculator")


#-------------Display Screen-----------
expression = Entry(window,width = 33, borderwidth = 5)
expression.grid(column = 0, row = 0, columnspan = 5)


#____________Making the buttons work_____________
def button_allclear():
	expression.delete(0,END)

def button_oneclear():
	expression.delete(0 ,1)

def button_click(number):
	first_number = expression.get()
	expression.delete(0,END)
	expression.insert(0, str(first_number) + str(number))


def button_addition():
	global first_number
	first_number = expression.get()
	first_number = float(first_number)
	expression.delete(0, END)
	global operator
	operator = "addition"

def button_subtraction():
	global first_number
	first_number = expression.get()
	first_number = float(first_number)
	expression.delete(0, END)
	global operator
	operator = "subtraction"

def button_multiplication():
	global first_number
	first_number = expression.get()
	first_number = float(first_number)
	expression.delete(0, END)
	global operator
	operator = "multiplication"

def button_divison():
	global first_number
	first_number = expression.get()
	first_number = float(first_number)
	expression.delete(0, END)
	global operator
	operator = "division"	


def button_equal():
	second_number = expression.get()
	second_number = float(second_number)
	expression.delete(0, END)
	if operator == "addition":
		expression.insert(0, first_number + second_number)
	elif operator == "subtraction":	
		expression.insert(0, first_number - second_number)
	elif operator == "multiplication":
		expression.insert(0, first_number * second_number)
	elif operator == "division":
		expression.insert(0, first_number / second_number)	
	elif operator == "sqaureroot":
		expression.insert(0, sqrt(first_number))		



#----------Creating Buttons---------
button_1 = Button(window,text = '1', padx = 20,pady = 10,command = lambda:button_click(1))
button_2 = Button(window,text = '2', padx = 20,pady = 10,command = lambda:button_click(2))
button_3 = Button(window,text = '3', padx = 20,pady = 10,command = lambda:button_click(3))
button_4 = Button(window,text = '4', padx = 20,pady = 10,command = lambda:button_click(4))
button_5 = Button(window,text = '5', padx = 20,pady = 10,command = lambda:button_click(5))
button_6 = Button(window,text = '6', padx = 20,pady = 10,command = lambda:button_click(6))
button_7 = Button(window,text = '7', padx = 20,pady = 10,command = lambda:button_click(7))
button_8 = Button(window,text = '8', padx = 20,pady = 10,command = lambda:button_click(8))
button_9 = Button(window,text = '9', padx = 20,pady = 10,command = lambda:button_click(9))
button_0 = Button(window,text = '0', padx = 47.4,pady = 10,command = lambda:button_click(0))
button_point = Button(window,text ='.', padx =21, pady = 10,command = lambda:button_click('.'))

button_addition = Button(window,text= "+", padx = 19, pady = 10, command = button_addition)
button_subtraction = Button(window,text= "-", padx = 20, pady = 10, command = button_subtraction)
button_multiplication = Button(window,text= "x", padx = 20, pady = 10, command = button_multiplication)
button_divison = Button(window,text= "/", padx = 20, pady = 10, command = button_divison)

button_equal = Button(window, text = '=', padx = 73, pady = 10, command = button_equal)
button_allclear = Button(window, text = 'AC', padx = 42.5, pady =10, command = button_allclear)
button_oneclear = Button(window,text = 'C', padx = 19, pady = 10, command = button_oneclear)



#----------Arranging the buttons--------------



button_1.grid(row = 4, column = 0)
button_2.grid(row = 4, column = 1)
button_3.grid(row = 4, column = 2)
button_4.grid(row = 3, column = 0)
button_5.grid(row = 3, column = 1)
button_6.grid(row = 3, column = 2)
button_7.grid(row = 2, column = 0)
button_8.grid(row = 2, column = 1)
button_9.grid(row = 2, column = 2)
button_0.grid(row = 5, column = 0, columnspan = 2)

button_addition.grid(row = 5,column = 3)
button_subtraction.grid(row = 4,column = 3)
button_multiplication.grid(row = 3,column = 3)
button_divison.grid(row = 2,column = 3)

button_equal.grid(row = 6,column = 0,columnspan = 3)
button_allclear.grid(row = 1,column = 0,columnspan = 2)
button_oneclear.grid(row = 1, column = 2)
button_point.grid(row = 5,column = 2)



window.mainloop()