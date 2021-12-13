from tkinter import *
from tkinter import messagebox #Always import messagebox seperately as it a sub module
import sqlite3
top = Tk()

L1 = Label(top, text="Title") 
L1.grid(row = 1, column = 1)
E1 = Entry(top, bd =5) #Attach text box to root frame. bd refers size of the border. default is 2 pixels
E1.grid(row = 1, column = 2)

L2 = Label(top, text="Last Name") 
L2.grid(row = 2, column = 1) 
E2 = Entry(top, bd =5) 
E2.grid(row = 2, column = 2)

L3 = Label(top, text="First Name") 
L3.grid(row = 3, column = 1) 
E3 = Entry(top, bd =5) 
E3.grid(row = 3, column = 2)

L4 = Label(top, text="Share with") 
L4.grid(row = 4, column = 1)
E4 = Entry(top, bd =5) 
E4.grid(row = 4, column = 2)

L5 = Label(top, text="Buisness Number") 
L5.grid(row = 5, column = 1)
E5 = Entry(top, bd =5) 
E5.grid(row = 5, column = 2)


L6 = Label(top, text="Mobile Number") 
L6.grid(row = 6, column = 1)
E6 = Entry(top, bd =5) 
E6.grid(row = 6, column = 2)

L7 = Label(top, text="Email Number") 
L7.grid(row = 7, column = 1)
E7 = Entry(top, bd =5) 
E7.grid(row = 7, column = 2)

L8 = Label(top, text="Date of arrival") 
L8.grid(row = 8, column = 1)
E8 = Entry(top, bd =5) 
E8.grid(row = 8, column = 2)

L9 = Label(top, text="Date of Departure") 
L9.grid(row = 9, column = 1)
E9 = Entry(top, bd =5) 
E9.grid(row = 9, column = 2)

L10 = Label(top, text="Name on Credit Card") 
L10.grid(row = 10, column = 1)
E10 = Entry(top, bd =5) 
E10.grid(row = 10, column = 2)

L11 = Label(top, text="Credit card number") 
L11.grid(row = 11, column = 1)
E11 = Entry(top, bd =5) 
E11.grid(row = 11, column = 2)

L12 = Label(top, text="Expiry Date") 
L12.grid(row = 12, column = 1)
E12 = Entry(top, bd =5) 
E12.grid(row = 12, column = 2)

L13= Label(top, text="CVV Number") 
L13.grid(row = 13, column = 1)
E13 = Entry(top, bd =5) 
E13.grid(row = 13, column = 2)

L14= Label(top, text="Password") 
L14.grid(row = 14, column = 1)

def upi(): 
    print('U are choosed UPI') 
def cp(): print('U are choosed chash payment')
def net_banking(): print('U are choosed net banking')
def debit(): print('U are choosed debit')
def special_card(): print("Yors special card have some benifical to that")
 
    
mb= Menubutton ( top, text="Credict card", relief=RAISED )
choices = Menu ( mb) 
mb.config(menu=choices)
choices.add_command(label="UPI",command = upi())
choices.add_command(label="CP",command = cp())  
mb.grid(row = 14, column = 2)

mb= Menubutton ( top, text="Direct Bank Transfer", relief=RAISED )
choices = Menu ( mb) 
mb.config(menu=choices)
choices.add_command(label="NET BANKING",command = net_banking())
choices.add_command(label="Debit bank",command = debit())
choices.add_command(label="Special card",command = special_card())  
mb.grid(row = 14, column = 3)

o = Label(top ,text = "Negotiated Rates:-").grid(row = 15,column = 1)
n3=IntVar()
Checkbutton(top, text="Deluxe Room Single    Rs1700", variable=n3).grid(row=16, column=2)
n4=IntVar()
Checkbutton(top, text="Deluxe Room Double    Rs1700", variable=n4).grid(row=16, column=3)

n5=IntVar()
Checkbutton(top, text="Suites Room Single    Rs1700", variable=n5).grid(row=17, column=2)
n6=IntVar()
Checkbutton(top, text="Suites Room Double    Rs1700", variable=n6).grid(row=17, column=3)



p = Label(top ,text = "Room Preference").grid(row = 18,column = 1)
n7=IntVar()
Checkbutton(top, text="King Bed", variable=n7).grid(row=19, column=2)
n8=IntVar()
Checkbutton(top, text="Twin - Two Single Beds", variable=n8).grid(row=19, column=3)

w = Canvas(top, bg="blue") 
w.create_line(0, 100, 200,400,fill="yellow") 


line0 = Label(top,text="*************************************************************************************************************************************************************************************************************************").grid(row=20,column=0,columnspan=4)
line1 = Label(top, text="The above rates are quoted per room, per night. The rates include breakfast, 14% vat, and Excludes 1% Tourism Levy\n and a voluntary R10 donation to the Arabella Community Trust that will be levies onto your account.").grid(row = 21,column = 0,columnspan=4)
line2 = Label(top, text="Total amount payable      ZAR_____ x______ nights = ZAR______ due to Arabella\n Hotel and Spa").grid(row = 22,column = 0,columnspan=4)
    
line3 = Label(top, text="Credit Card will be charged on receipt of this form and details will also be used to settle all incidentals not settle on\n departure. A copy of the final folio will be sent to you should there be any unsettled charges.").grid(row = 23,column = 0,columnspan=4)
    
line4 = Label(top, text="In order to qualify for the above rates, your booking needs to be made on or before 15th January 2016").grid(row = 24,column = 0,columnspan=4)
    
line5 = Label(top, text="Terms and conditions can be found on the next page.").grid(row = 25,column = 0,columnspan=4)
    
line6 = Label(top, text="The rate is valid for seven days before and after the conference dates. Check in time is 14:00 & check out time is 11:00").grid(row = 26,column = 0,columnspan=4)
    
line7 = Label(top, text="By your signature hereto, you are accepting all terms and conditions specified on this form and confirm that all information\n given is current and accurate.").grid(row = 27,column = 0,columnspan=4)
    
L21 = Label(top, text="Signature..................") 
L21.grid(row = 28, column = 1) 

L22 = Label(top, text="Print Name..................") 
L22.grid(row = 28, column = 3) 


L23 = Label(top, text="Date........................") 
L23.grid(row = 29, column = 1) 

top.mainloop()

