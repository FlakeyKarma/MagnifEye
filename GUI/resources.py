from tkinter import *
from PIL import ImageTk, Image
import os

class HELPERS:
    def __init__(self, master=None):
        self.master = master
        self.X = self.master.winfo_screenwidth()
        self.Y = self.master.winfo_screenheight()
        self.textBoxX = self.X/2
        self.textBoxY = self.Y/1.5

class MFEGUI(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.master = master
        #Left side
        self.left(self.master)
        #Right side
        self.right(self.master)

    def left(self, master=None):
        #Var set
        hlp = HELPERS(master)
        ThNeedle = IntVar()
        RedCheck = IntVar()
        weBI = IntVar()
        DoCo = IntVar()
        def MFY():
            print("%d, %d, %d, %d" % (ThNeedle.get(), RedCheck.get(), weBI.get(), DoCo.get()))
        #Logo Set
        logo = "imgs/MagnifEyeLogo.png"
        imgX, imgY = Image.open(logo).size
        img = ImageTk.PhotoImage(Image.open(logo).resize((int(imgX*.25), int(imgY*.25)), resample=0))
        block = Label(master, image=img)
        block.image = img
        block.pack()
        block.place(x=imgX*.035, y=imgY*.05)
        #Profile name set
        profName = Label(master, text="FlakeyKarma", font="Helvetica 10 bold")
        profName.pack()
        profName.place(x=int(hlp.X*.01), y=int(hlp.Y*.025))
        #Program name set
        progName = Label(master, text="MagnifEye v1.15.8", font="Helvetica 10 bold")
        progName.pack()
        progName.place(x=int(hlp.X*.01), y=int(hlp.Y*.19))
        #Options
        opts = Label(master, text="Options:", font="Helvetica 10 bold")
        opts.pack()
        opts.place(x=int(hlp.X*.01), y=int(hlp.Y*.22))
        #CheckBoxes
        Checkbutton(master, text="ThNeedle", font="Helvetica 10 bold", variable=ThNeedle).place(x=int(hlp.X*.01), y=int(hlp.Y*.25))
        Checkbutton(master, text="RedCheck", font="Helvetica 10 bold", variable=RedCheck).place(x=int(hlp.X*.01), y=int(hlp.Y*.27))
        Checkbutton(master, text="weBI", font="Helvetica 10 bold", variable=weBI).place(x=int(hlp.X*.01), y=int(hlp.Y*.29))
        Checkbutton(master, text="DoCo", font="Helvetica 10 bold", variable=DoCo).place(x=int(hlp.X*.01), y=int(hlp.Y*.31))
        #Submission button
        Button(master, text="Submit", font="Helvetica 10 bold", command=MFY, width=int(hlp.X*.0075)).place(x=int(hlp.X*.01), y=int(hlp.Y*.35))

    def right(self, master=None):
        #Var setting
        hlp = HELPERS(master)
        #Text box
        txt = Text(master, width=int(hlp.textBoxX/10), height=int(hlp.textBoxY/19))
        scrl = Scrollbar(master, command=txt.yview)
        txt.configure(yscrollcommand=scrl.set)
        txt.pack()
        scrl.pack(side=RIGHT, fill=Y)
        txt.place(x = int(hlp.X/12), y=int(hlp.Y*.025))
