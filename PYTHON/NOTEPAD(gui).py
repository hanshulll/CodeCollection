from tkinter import *
from tkinter.messagebox import showinfo
from tkinter.filedialog import askopenfilename,asksaveasfilename
import os
def newFile():
    global file
    root.title("Untitled - Notepad")
    file = None
    TextArea.delete(1.0,END)
def openFile():
    global file
    file = askopenfilename(defaultextension=".txt", filetypes=[("All files","*.*"),
                                                               ("Text Documents","*.txt")])
    if file == "":
        file =None
    else:
        root.title(os.path.basename(file) + "- Notepad")
        TextArea.delete(1.0,END)
        f = open(file,"r")
        TextArea.insert(1.0,f.read())
        f.close()

def saveFile():
    global file
    if file == None:
        file =asksaveasfilename(initialfile = 'Untitled.txt',defaultextension=".txt", filetypes=[("All files","*.*"),("Text Documents","*.txt")])
        if file == "":
            file =None
        else:
            #save as a now file
           f= open(file,"w")
           f.write(TextArea.get(1.0,END))
           f.close()

           root.title(os.path.basename(file) + " - Notepad")
           print("file saved")
    else:
        # save the file
        f = open(file, "w")
        f.write(TextArea.get(1.0, END))
        f.close()


def quitapp():
    root.destroy()

def cut():
    TextArea.event_generate("<<Cut>>")

def copy():
    TextArea.event_generate("<<Copy>>")

def paste():
    TextArea.event_generate("<<Paste>>")

def about():
     showinfo("Help","Notepad by Sarthak Nirala")
if __name__ == '__main__':
    root =Tk()
    root.title("Untitled-Notepad")
    root.wm_iconbitmap("1.ico")
    root.geometry("644x788")
    # Add text area
    TextArea = Text(root,font="lucida 13")
    file = None
    TextArea.pack(expand=True,fill=BOTH)
    # menu bar
    MenuBar = Menu(root)
    # File menu start
    FileMenu = Menu(MenuBar,tearoff=0)
    # to open a new file
    FileMenu.add_command(label ="New",command=newFile)
    # to open an already existing file
    FileMenu.add_command(label ="Open",command=openFile)
    # to save the current file
    FileMenu.add_command(label ="Save",command=saveFile)
    FileMenu.add_separator()
    FileMenu.add_command(label= "Exit", command=quitapp)
    MenuBar.add_cascade(label="File" ,menu =FileMenu)
    # File menu start

    # Edit menu start
    EditMenu = Menu(MenuBar,tearoff=0)
    # to give a feature of cut
    EditMenu.add_command(label="Cut",command=cut)
    # to give a feature of copy
    EditMenu.add_command(label="Copy", command=copy)
    # to give a feature of paste
    EditMenu.add_command(label="Paste", command=paste)

    MenuBar.add_cascade(label="Edit",menu= EditMenu)

    # Edit menu ends


    # help menu starts
    HelpMenu = Menu(MenuBar,tearoff=0)

    HelpMenu.add_command(label=" About Notepad",command = about)
    MenuBar.add_cascade(label="Help",menu=HelpMenu)
    # help menu ends
    root.config(menu =MenuBar)

    #Adding scroll bar
    Scrollbar = Scrollbar(TextArea)
    Scrollbar.pack(fill=Y,side=RIGHT)
    Scrollbar.config(command = TextArea.yview)
    TextArea.config(yscrollcommand = Scrollbar.set)







    root.mainloop()