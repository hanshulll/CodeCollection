from tkinter import *
import math

class Application(Frame):
	def __init__(self, master):
		super().__init__(master)
		self.master = master
		self.create_widget()
		self.grid()

	def create_widget(self):

		#-------------Display Screen-----------
		self.expression = Entry(self,width = 33, borderwidth = 5)
		self.expression.grid(column = 0, row = 0, columnspan = 5)

		#----------Creating Buttons---------
		self.button_1 = Button(self,text = '1', padx = 20,pady = 10,command = lambda:self.button_click(1))
		self.button_2 = Button(self,text = '2', padx = 20,pady = 10,command = lambda:self.button_click(2))
		self.button_3 = Button(self,text = '3', padx = 20,pady = 10,command = lambda:self.button_click(3))
		self.button_4 = Button(self,text = '4', padx = 20,pady = 10,command = lambda:self.button_click(4))
		self.button_5 = Button(self,text = '5', padx = 20,pady = 10,command = lambda:self.button_click(5))
		self.button_6 = Button(self,text = '6', padx = 20,pady = 10,command = lambda:self.button_click(6))
		self.button_7 = Button(self,text = '7', padx = 20,pady = 10,command = lambda:self.button_click(7))
		self.button_8 = Button(self,text = '8', padx = 20,pady = 10,command = lambda:self.button_click(8))
		self.button_9 = Button(self,text = '9', padx = 20,pady = 10,command = lambda:self.button_click(9))
		self.button_0 = Button(self,text = '0', padx = 47.4,pady = 10,command = lambda:self.button_click(0))
		self.button_point = Button(self,text ='.', padx =21, pady = 10,command = lambda:self.button_click('.'))

		self.button_addition = Button(self,text= "+", padx = 19, pady = 10, command = self.button_addition)
		self.button_subtraction = Button(self,text= "-", padx = 20, pady = 10, command = self.button_subtraction)
		self.button_multiplication = Button(self,text= "x", padx = 20, pady = 10, command = self.button_multiplication)
		self.button_divison = Button(self,text= "/", padx = 20, pady = 10, command = self.button_divison)

		self.button_equal = Button(self, text = '=', padx = 73, pady = 10, command = self.button_equal)
		self.button_allclear = Button(self, text = 'AC', padx = 42.5, pady =10, command = self.button_allclear)
		self.button_oneclear = Button(self,text = 'C', padx = 19, pady = 10, command = self.button_oneclear)


		self.button_1.grid(row = 4, column = 0)
		self.button_2.grid(row = 4, column = 1)
		self.button_3.grid(row = 4, column = 2)
		self.button_4.grid(row = 3, column = 0)
		self.button_5.grid(row = 3, column = 1)
		self.button_6.grid(row = 3, column = 2)
		self.button_7.grid(row = 2, column = 0)
		self.button_8.grid(row = 2, column = 1)
		self.button_9.grid(row = 2, column = 2)
		self.button_0.grid(row = 5, column = 0, columnspan = 2)

		self.button_addition.grid(row = 5,column = 3)
		self.button_subtraction.grid(row = 4,column = 3)
		self.button_multiplication.grid(row = 3,column = 3)
		self.button_divison.grid(row = 2,column = 3)

		self.button_equal.grid(row = 6,column = 0,columnspan = 3)
		self.button_allclear.grid(row = 1,column = 0,columnspan = 2)
		self.button_oneclear.grid(row = 1, column = 2)
		self.button_point.grid(row = 5,column = 2)


	#____________Making the buttons work_____________

	def button_allclear(self):
		self.expression.delete(0,END)

	def button_oneclear(self):
		self.expression.delete(0 ,1)

	def button_click(self, number):
		self.first_number = self.expression.get()
		self.expression.delete(0,END)
		self.expression.insert(0, str(self.first_number) + str(number))
	
	def button_addition(self):
		self.first_number = self.expression.get()
		self.first_number = float(self.first_number)
		self.expression.delete(0, END)
		self.operator = "addition"

	def button_subtraction(self):
		self.first_number
		self.first_number = self.expression.get()
		self.first_number = float(self.first_number)
		self.expression.delete(0, END)
		self.operator = "subtraction"

	def button_multiplication(self):
		self.first_number
		self.first_number = self.expression.get()
		self.first_number = float(self.first_number)
		self.expression.delete(0, END)
		self.operator = "multiplication"

	def button_divison(self):
		self.first_number
		self.first_number = self.expression.get()
		self.first_number = float(self.first_number)
		self.expression.delete(0, END)
		self.operator = "division"	


	def button_equal(self):
		second_number = self.expression.get()
		second_number = float(second_number)
		self.expression.delete(0, END)
		if self.operator == "addition":
			self.expression.insert(0, self.first_number + second_number)
		elif self.operator == "subtraction":	
			self.expression.insert(0, self.first_number - second_number)
		elif self.operator == "multiplication":
			self.expression.insert(0, self.first_number * second_number)
		elif self.operator == "division":
			self.expression.insert(0, self.first_number / second_number)	
		elif self.operator == "sqaureroot":
			self.expression.insert(0, math.sqrt(self.first_number))	


if __name__ == '__main__':
	root = Tk()
	root.title('Calculator')
	app = Application(root)
	app.mainloop()
