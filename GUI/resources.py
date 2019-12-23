from tkinter import *
from tkinter import filedialog
from PIL import ImageTk, Image
import os
import subprocess

class HELPERS:
    def __init__(self, master=None):
        self.master = master
        self.X = self.master.winfo_screenwidth()
        self.Y = self.master.winfo_screenheight()
        self.textBoxX = self.X/2
        self.textBoxY = self.Y/1.5
        self.dirLocation = str(os.path.dirname(__file__)).split("MagnifEye")[0]+str('MagnifEye/')
        self.filLocation = "/"
    def tempWriter(x):
        file=open("temP.txt", "w+")
        file.write(x)
        file.close()

class MFEGUI(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.master = master
        #Left side
        self.WINDOW(self.master)

    def WINDOW(self, master=None):
        #LEFT SIDE
        #Var set
        hlp = HELPERS(master)
        bitSet = 0
        ThNeedle = IntVar()
        RedCheck = IntVar()
        weBI = IntVar()
        DoCo = IntVar()
        #Var adjustment
        def MFYcall():
            bitSet = [ThNeedle.get(), RedCheck.get(), weBI.get(), DoCo.get()]
            magOpt = [hlp.dirLocation+"linux-safe/MagnifEye", "-o"]
            if(bitSet[1]==1):
                magOpt.append("-red")
            if(bitSet[2]==1):
                magOpt.append("-w")
            if(bitSet[3]==1):
                magOpt.append("-dc")
            magOpt.append(hlp.dirLocation+"GUI/asdf.txt")
            #subprocess.run(magOpt)
        def browseWindow():
            filename = filedialog.askopenfilename(initialdir = hlp.filLocation,title = "Browsed file",filetypes = (("text files","*.txt")))
            pathlabel.config(text=filename)
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
        Button(master, text="Submit", font="Helvetica 10 bold", command=MFYcall, width=int(hlp.X*.0075)).place(x=int(hlp.X*.01), y=int(hlp.Y*.35))
        #Display current file selected
        broPth = Text(master, width=int(hlp.X*.0082), height=1)
        broPth.pack()
        broPth.place(x=int(hlp.X*.01), y=int(hlp.Y*.4))
        #Button to browse for file
        broBtn = Button(master, text="Browse", command=browseWindow)
        broBtn.pack()
        broBtn.place(x=int(hlp.X*.01), y=int(hlp.Y*.421))
        #RIGHT SIDE
        #Text box
        txt = Text(master, width=int(hlp.textBoxX/10), height=int(hlp.textBoxY/19))
        scrl = Scrollbar(master, command=txt.yview)
        txt.configure(yscrollcommand=scrl.set)
        txt.pack()
        scrl.pack(side=RIGHT, fill=Y)
        txt.place(x = int(hlp.X/12), y=int(hlp.Y*.025))
