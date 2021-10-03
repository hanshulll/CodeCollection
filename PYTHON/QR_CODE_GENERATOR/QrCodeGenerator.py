import pyqrcode 
import os 
import tkinter as tk
from tkinter.messagebox import showerror
  
def make_qr():
    try:
        str_data = data.get()
        if str_data != '' and str_data != 'Insert Text Here':
            # Generate QR code 
            img = pyqrcode.create(str_data) 

            #  Saving the Generated QR Code
            img.png('img.png', scale = 6)
            data.delete(0,tk.END) 
            os.startfile('img.png')
        else:
            showerror('Error!','Please Enter Data')
    except:
        showerror('Error','Something Went Wrong,\nPlease try later')

root = tk.Tk()
root.title('Qr Code Generator @load_thecode')
root.geometry('300x500+500+150')
root.iconbitmap('image.ico')

bg = tk.PhotoImage(file='bg_image1.png')
bg_lab = tk.Label(root,image=bg,bg='white')
bg_lab.place(x=0,y=0,relwidth=1,relheight=1)

data = tk.Entry(root,font=('Comic Sans MS',18),bg='Black',fg='White')
data.place(x=0,y=240)

data.insert(tk.END,'Insert Text Here')

button = tk.Button(root,text='Generate QR',font=('Comic Sans MS',13),relief=tk.RAISED,command=make_qr)
button.place(x=90,y=300)


root.mainloop()


