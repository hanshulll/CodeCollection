from tkinter import * 
from tkinter import ttk
from tkinter import messagebox

root=Tk()
root.geometry("790x200")
root.title("Unit Converter")
root.config(bg="black")
style=ttk.Style()
style.theme_use('alt')
style.configure('TButton', font=('American typewriter', 14), background='#232323', foreground='white')
style.map('TButton',
                background=[('active', 'grey'), ('disabled', 'whitr')]
                )

def check(a):
    set1={'0','1','2','3','4','5','6','7','8','9','.','-'}
    return set(a).issubset(set1)

def T1():
    t1=Toplevel(root)
    t1.geometry("400x240")
    t1.config(bg="black")
    l=Label(t1,text="MASS",font="timesnewroman 18 bold",bg="black",fg="white").place(x=0,y=0,relwidth=1)
    lst=[" ","mili gm","centi gm","deci gm","gm","deca gm","hecto gm","kilo gm","pound","ton","Quantal"]
    var1=StringVar()
    var2=StringVar()
    var3=StringVar()
    var4=StringVar()
    def cal():
        if(var1.get()=="Select" or var3.get()=="Select"):
            messagebox.showerror("INVALID","Select unit!!!")
        elif(not(check(var2.get()))):
            messagebox.showerror("INVALID","Enter proper number!!!")
        else:
            d={"mili gm":0.001,"centi gm":0.01,"deci gm":0.1,"gm":1,"deca gm":10,"hecto gm":100,"kilo gm":1000,"pound":453.59,"ton":1000000,"Quantal":100000}
            a=d.get(var1.get())
            b=d.get(var3.get())
            var4.set(str(eval(str(eval(var2.get())*(a/b)))))

    o1=ttk.OptionMenu(t1,var1,*lst).place(x=5,y=50,width=150,height=40)
    var1.set("Select")
    e1=ttk.Entry(t1,textvariable=var2,font="timesnewroman 18 bold").place(x=180,y=50,width=200)
    o2=ttk.OptionMenu(t1,var3,*lst).place(x=5,y=120,width=150,height=40)
    var3.set("Select")
    e1=ttk.Entry(t1,textvariable=var4,font="timesnewroman 18 bold").place(x=180,y=120,width=200)
    b=ttk.Button(t1,text="calculate",command=cal).place(x=250,y=170)

    t1.mainloop()


def T2():
    t2=Toplevel(root)
    t2.geometry("400x240")
    t2.config(bg="black")
    l=Label(t2,text="LENGTH",font="timesnewroman 18 bold",bg="black",fg="white").place(x=0,y=0,relwidth=1)
    lst=[" ","mili meter","centi meter","deci meter","meter","deca meter","hecto meter","kilo meter","foot","inch","yard"]
    var1=StringVar()
    var2=StringVar()
    var3=StringVar()
    var4=StringVar()
    def cal():
        if(var1.get()=="Select" or var3.get()=="Select"):
            messagebox.showerror("INVALID","Select unit!!!")
        elif(not(check(var2.get()))):
            messagebox.showerror("INVALID","Enter proper number!!!")
        else:
            d={"mili meter":0.001,"centi meter":0.01,"deci meter":0.1,"meter":1,"deca meter":10,"hecto meter":100,"kilo meter":1000,"foot":3.28084,"inch":39.3701,"yard":1.09361}
            a=d.get(var1.get())
            b=d.get(var3.get())
            var4.set(str(eval(str(eval(var2.get())*(a/b)))))

    o1=ttk.OptionMenu(t2,var1,*lst).place(x=5,y=50,width=150,height=40)
    var1.set("Select")
    e1=ttk.Entry(t2,textvariable=var2,font="timesnewroman 18 bold").place(x=180,y=50,width=200)
    o2=ttk.OptionMenu(t2,var3,*lst).place(x=5,y=120,width=150,height=40)
    var3.set("Select")
    e1=ttk.Entry(t2,textvariable=var4,font="timesnewroman 18 bold").place(x=180,y=120,width=200)
    b=ttk.Button(t2,text="calculate",command=cal).place(x=250,y=170)

    t2.mainloop()


def T3():
    t3=Toplevel(root)
    t3.geometry("400x240")
    t3.config(bg="black")
    l=Label(t3,text="TIME",font="timesnewroman 18 bold",bg="black",fg="white").place(x=0,y=0,relwidth=1)
    lst=[" ","milisecond","second","minute","hour","day","week","month","year","decades"]
    var1=StringVar()
    var2=StringVar()
    var3=StringVar()
    var4=StringVar()
    def cal():
        if(var1.get()=="Select" or var3.get()=="Select"):
            messagebox.showerror("INVALID","Select unit!!!")
        elif(not(check(var2.get()))):
            messagebox.showerror("INVALID","Enter proper number!!!")
        else:
            d={"milisecond":0.001,"second":1,"minute":60,"hour":3600,"day":86400,"week":604800,"month":2628000,"year":31557600,"decades":315360000}
            a=d.get(var1.get())
            b=d.get(var3.get())
            var4.set(str(eval(str(eval(var2.get())*(a/b)))))

    o1=ttk.OptionMenu(t3,var1,*lst).place(x=5,y=50,width=150,height=40)
    var1.set("Select")
    e1=ttk.Entry(t3,textvariable=var2,font="timesnewroman 18 bold").place(x=180,y=50,width=200)
    o2=ttk.OptionMenu(t3,var3,*lst).place(x=5,y=120,width=150,height=40)
    var3.set("Select")
    e1=ttk.Entry(t3,textvariable=var4,font="timesnewroman 18 bold").place(x=180,y=120,width=200)
    b=ttk.Button(t3,text="calculate",command=cal).place(x=250,y=170)

    t3.mainloop()


def T4():
    t4=Toplevel(root)
    t4.geometry("400x240")
    t4.config(bg="black")
    l=Label(t4,text="DATA",font="timesnewroman 18 bold",bg="black",fg="white").place(x=0,y=0,relwidth=1)
    lst=[" ","bit","nibble","byte","KB","MB","GB","TB","PB","EB","ZB","YB"]
    var1=StringVar()
    var2=StringVar()
    var3=StringVar()
    var4=StringVar()
    def cal():
        if(var1.get()=="Select" or var3.get()=="Select"):
            messagebox.showerror("INVALID","Select unit!!!")
        elif(not(check(var2.get()))):
            messagebox.showerror("INVALID","Enter proper number!!!")
        else:
            d={"bit":0.0001220703125,"nibble":0.00048828125,"byte":0.0009765625,"KB":1,"MB":1024,"GB":1048576,"TB":1073741824,"PB":1073741824*(1024**1),"EB":1073741824*(1024**2),"ZB":1073741824*(1024**3),"YB":1073741824*(1024**4)}
            a=d.get(var1.get())
            b=d.get(var3.get())
            var4.set(str(eval(str(eval(var2.get())*(a/b)))))

    o1=ttk.OptionMenu(t4,var1,*lst).place(x=5,y=50,width=150,height=40)
    var1.set("Select")
    e1=ttk.Entry(t4,textvariable=var2,font="timesnewroman 18 bold").place(x=180,y=50,width=200)
    o2=ttk.OptionMenu(t4,var3,*lst).place(x=5,y=120,width=150,height=40)
    var3.set("Select")
    e1=ttk.Entry(t4,textvariable=var4,font="timesnewroman 18 bold").place(x=180,y=120,width=200)
    b=ttk.Button(t4,text="calculate",command=cal).place(x=250,y=170)

    t4.mainloop()


def T5():
    t5=Toplevel(root)
    t5.geometry("400x240")
    t5.config(bg="black")
    l=Label(t5,text="Temperature",font="timesnewroman 18 bold",bg="black",fg="white").place(x=0,y=0,relwidth=1)
    lst=[" ","Celcius","Kelvin","Fahrenheit"]
    var1=StringVar()
    var2=StringVar()
    var3=StringVar()
    var4=StringVar()
    def cal():
        if(var1.get()=="Select" or var3.get()=="Select"):
            messagebox.showerror("INVALID","Select unit!!!")
        elif(not(check(var2.get()))):
            messagebox.showerror("INVALID","Enter proper number!!!")
        else:
            a=var1.get()
            b=var3.get()
            if(a==b):
                var4.set(var2.get())
            elif(a=="Celcius" and b=="Kelvin"):
                var4.set(str(eval(str(eval(var2.get())+273.15))))
            elif(b=="Celcius" and a=="Kelvin"):
                var4.set(str(eval(str(eval(var2.get())-273.15))))
            elif(a=="Celcius" and b=="Fahrenheit"):
                var4.set(str(eval(str((eval(var2.get())-32)*5/9))))
            elif(b=="Celcius" and a=="Fahrenheit"):
                var4.set(str(eval(str(eval(var2.get())*1.8+32))))
            elif(a=="Kelvin" and b=="Fahrenheit"):
                var4.set(str(eval(str((eval(var2.get())-273.15)*1.8+32))))
            elif(b=="Kelvin" and a=="Fahrenheit"):
                var4.set(str(eval(str((eval(var2.get())-32)*5/9+273.15))))
                
    o1=ttk.OptionMenu(t5,var1,*lst).place(x=5,y=50,width=150,height=40)
    var1.set("Select")
    e1=ttk.Entry(t5,textvariable=var2,font="timesnewroman 18 bold").place(x=180,y=50,width=200)
    o2=ttk.OptionMenu(t5,var3,*lst).place(x=5,y=120,width=150,height=40)
    var3.set("Select")
    e1=ttk.Entry(t5,textvariable=var4,font="timesnewroman 18 bold").place(x=180,y=120,width=200)
    b=ttk.Button(t5,text="calculate",command=cal).place(x=250,y=170)

    t5.mainloop()


def T6():
    t6=Toplevel(root)
    t6.geometry("400x240")
    t6.config(bg="black")
    l=Label(t6,text="AREA",font="timesnewroman 18 bold",bg="black",fg="white").place(x=0,y=0,relwidth=1)
    lst=[" ","mm2","cm2","dm2","m2","deca m2","hecto m2","Km2"]
    var1=StringVar()
    var2=StringVar()
    var3=StringVar()
    var4=StringVar()
    def cal():
        if(var1.get()=="Select" or var3.get()=="Select"):
            messagebox.showerror("INVALID","Select unit!!!")
        elif(not(check(var2.get()))):
            messagebox.showerror("INVALID","Enter proper number!!!")
        else:
            d={"mm2":10**(-6),"cm2":10**(-4),"dm2":10**(-2),"m2":1,"deca m2":10**(2),"hecto m2":10**(4),"Km2":10**(6)}
            a=d.get(var1.get())
            b=d.get(var3.get())
            var4.set(str(eval(str(eval(var2.get())*(a/b)))))

    o1=ttk.OptionMenu(t6,var1,*lst).place(x=5,y=50,width=150,height=40)
    var1.set("Select")
    e1=ttk.Entry(t6,textvariable=var2,font="timesnewroman 18 bold").place(x=180,y=50,width=200)
    o2=ttk.OptionMenu(t6,var3,*lst).place(x=5,y=120,width=150,height=40)
    var3.set("Select")
    e1=ttk.Entry(t6,textvariable=var4,font="timesnewroman 18 bold").place(x=180,y=120,width=200)
    b=ttk.Button(t6,text="calculate",command=cal).place(x=250,y=170)

    t6.mainloop()


def T7():
    t7=Toplevel(root)
    t7.geometry("400x240")
    t7.config(bg="black")
    l=Label(t7,text="VOLUME",font="timesnewroman 18 bold",bg="black",fg="white").place(x=0,y=0,relwidth=1)
    lst=[" ","mm3","cm3","dm3","m3","litre","barrel","gallon","pint"]
    var1=StringVar()
    var2=StringVar()
    var3=StringVar()
    var4=StringVar()
    def cal():
        if(var1.get()=="Select" or var3.get()=="Select"):
            messagebox.showerror("INVALID","Select unit!!!")
        elif(not(check(var2.get()))):
            messagebox.showerror("INVALID","Enter proper number!!!")
        else:
            d={"mm3":10**(-6),"cm3":10**(-3),"dm3":1,"m3":10**3,"litre":1,"barrel":158.987,"gallon":3.78541,"pint":0.473}
            a=d.get(var1.get())
            b=d.get(var3.get())
            var4.set(str(eval(str(eval(var2.get())*(a/b)))))

    o1=ttk.OptionMenu(t7,var1,*lst).place(x=5,y=50,width=150,height=40)
    var1.set("Select")
    e1=ttk.Entry(t7,textvariable=var2,font="timesnewroman 18 bold").place(x=180,y=50,width=200)
    o2=ttk.OptionMenu(t7,var3,*lst).place(x=5,y=120,width=150,height=40)
    var3.set("Select")
    e1=ttk.Entry(t7,textvariable=var4,font="timesnewroman 18 bold").place(x=180,y=120,width=200)
    b=ttk.Button(t7,text="calculate",command=cal).place(x=250,y=170)

    t7.mainloop()


def T8():
    t8=Toplevel(root)
    t8.geometry("400x240")
    t8.config(bg="black")
    l=Label(t8,text="No. System",font="timesnewroman 18 bold",bg="black",fg="white").place(x=0,y=0,relwidth=1)
    lst=[" ","Decimal","Binary","Octal","Hexadecimal"]
    var1=StringVar()
    var2=StringVar()
    var3=StringVar()
    var4=StringVar()
    def cal():
        if(var1.get()=="Select" or var3.get()=="Select"):
            messagebox.showerror("INVALID","Select unit!!!")
        else:
            a=var1.get()
            b=var3.get()
            if(a==b):
                var4.set(var2.get())
            elif(a=="Decimal" and b=="Binary"):
                if(not(check(var2.get()))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(str(bin(eval(var2.get())))[2:])
            elif(a=="Decimal" and b=="Octal"):
                if(not(check(var2.get()))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(str(oct(eval(var2.get())))[2:])
            elif(a=="Decimal" and b=="Hexadecimal"):
                if(not(check(var2.get()))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(str(hex(eval(var2.get())))[2:])
            elif(a=="Binary" and b=="Decimal"):
                if(not(set(var2.get()).issubset({'1','0'}))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(int(var2.get(),2))
            elif(a=="Binary" and b=="Octal"):
                if(not(set(var2.get()).issubset({'1','0'}))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(str(oct(eval("0b"+var2.get())))[2:])
            elif(a=="Binary" and b=="Hexadecimal"):
                if(not(set(var2.get()).issubset({'1','0'}))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(str(hex(eval("0b"+var2.get())))[2:])
            elif(a=="Octal" and b=="Decimal"):
                if(not(set(var2.get()).issubset({'0','1','2','3','4','5','6','7'}))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(int(var2.get(),8))
            elif(a=="Octal" and b=="Binary"):
                if(not(set(var2.get()).issubset({'0','1','2','3','4','5','6','7'}))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(str(bin(eval("0o"+var2.get())))[2:])
            elif(a=="Octal" and b=="Hexadecimal"):
                if(not(set(var2.get()).issubset({'0','1','2','3','4','5','6','7'}))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(str(hex(eval("0o"+var2.get())))[2:])
            elif(a=="Hexadecimal" and b=="Decimal"):
                if(not(set(var2.get()).issubset({'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'}))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(int(var2.get(),16))
            elif(a=="Hexadecimal" and b=="Binary"):
                if(not(set(var2.get()).issubset({'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'}))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(str(bin(eval("0x"+var2.get())))[2:])
            elif(a=="Hexadecimal" and b=="Octal"):
                if(not(set(var2.get()).issubset({'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'}))):
                    messagebox.showerror("INVALID","Enter proper number!!!")
                var4.set(str(oct(eval("0x"+var2.get())))[2:])
                    
    o1=ttk.OptionMenu(t8,var1,*lst).place(x=5,y=50,width=150,height=40)
    var1.set("Select")
    e1=ttk.Entry(t8,textvariable=var2,font="timesnewroman 18 bold").place(x=180,y=50,width=200)
    o2=ttk.OptionMenu(t8,var3,*lst).place(x=5,y=120,width=150,height=40)
    var3.set("Select")
    e1=ttk.Entry(t8,textvariable=var4,font="timesnewroman 18 bold").place(x=180,y=120,width=200)
    b=ttk.Button(t8,text="calculate",command=cal).place(x=250,y=170)

    t8.mainloop()


def T9():
    t9=Toplevel(root)
    t9.geometry("400x240")
    t9.config(bg="black")
    var1=StringVar()
    var2=StringVar()
    def cal():
        if(not(check(var1.get()) )or not(check(var2.get())) or eval(var2.get())>100):
            messagebox.showerror("INVALID","Enter prober amount or discount")
        else:
            a=eval(var1.get())*(eval(var2.get())*0.01)
            b=eval(str(eval(var1.get())-a))
            l3["text"]=f"Your current ammount is {b} Rs."
            l4["text"]=f"You got discount of Rs.   {a}"

    l=Label(t9,text="Discount",font="timesnewroman 18 bold",bg="black",fg="white").place(x=0,y=0,relwidth=1)
    l1=Label(t9,text="Enter value",font="timesnewroman 15").place(x=20,y=50,width=150)
    e1=ttk.Entry(t9,textvariable=var1,font="timesnewroman 15 bold").place(x=180,y=50,width=200)
    l2=Label(t9,text="Enter Discount",font="timesnewroman 15").place(x=20,y=90,width=150)
    e2=ttk.Entry(t9,textvariable=var2,font="timesnewroman 15 bold").place(x=180,y=90,width=200)
    l3=Label(t9,text=" ",fg="white",bg="black",font="timesnewroman 15 bold")
    l3.place(x=20,y=170)
    l4=Label(t9,text=" ",fg="white",bg="black",font="timesnewroman 15 bold")
    l4.place(x=20,y=200)
    b=ttk.Button(t9,text="calculate",command=cal).place(x=250,y=130)
    
    t9.mainloop()




l=Label(root,text="Welcome to our Unit Converter Programme".title(),font="timesnewroman 18 bold",bg="black",fg="white").grid(row=0,columnspan=10)

b=ttk.Button(root,text="Mass",command=T1,width=22).grid(row=1,column=0,padx=5,pady=5)
b=ttk.Button(root,text="Length",command=T2,width=22).grid(row=1,column=1,padx=5,pady=5)
b=ttk.Button(root,text="Time",command=T3,width=22).grid(row=1,column=2,padx=5,pady=5)

b=ttk.Button(root,text="Data",command=T4,width=22).grid(row=2,column=0,padx=5,pady=5)
b=ttk.Button(root,text="Temperature",command=T5,width=22).grid(row=2,column=1,padx=5,pady=5)
b=ttk.Button(root,text="Area",command=T6,width=22).grid(row=2,column=2,padx=5,pady=5)

b=ttk.Button(root,text="Volume",command=T7,width=22).grid(row=3,column=0,padx=5,pady=5)
b=ttk.Button(root,text="No. system",command=T8,width=22).grid(row=3,column=1,padx=5,pady=5)
b=ttk.Button(root,text="Discount",command=T9,width=22).grid(row=3,column=2,padx=5,pady=5)


root.mainloop()