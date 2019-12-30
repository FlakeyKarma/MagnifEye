from tkinter import *
from tkinter import filedialog
from PIL import ImageTk, Image
import os
import subprocess

global file0, file1

class HELPERS:
    def __init__(self, master=None):
        self.master = master
        self.X = self.master.winfo_screenwidth()
        self.Y = self.master.winfo_screenheight()
        self.textBoxX = self.X/2
        self.textBoxY = self.Y/1.5
        self.dirLocation = str(os.path.dirname(__file__)).split("MagnifEye")[0]+str('MagnifEye/')
        self.filLocation = "/"
        self.tmpLocation = self.dirLocation + "temP.txt"
    def tempWriter(self, x):
        file=open(self.tmpLocation, "w")
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
        broPth = []
        hlp = HELPERS(master)
        bitSet = 0
        ThNeedle = IntVar()
        RedCheck = IntVar()
        weBI = IntVar()
        DoCo = IntVar()
        filename = "E"

        #Var adjustment
        def MFYcall():
            file0 = (broPth[0]["text"]).replace('\n', '')
            bitSet = [ThNeedle.get(), RedCheck.get(), weBI.get(), DoCo.get()]
            magOpt = [hlp.dirLocation+"linux-safe/MagnifEye", "-o"]
            hlp.tempWriter(txt.get('1.0', END))
            if(bitSet[0]==1):
                magOpt.append("-th")
            if(bitSet[1]==1):
                magOpt.append("-red")
            if(bitSet[2]==1):
                magOpt.append("-w")
            if(bitSet[3]==1):
                magOpt.append("-dc")
            magOpt.append(hlp.tmpLocation)
            subprocess.run(magOpt)
            os.remove(hlp.tmpLocation)

        def browseWindow():
            file0 = filedialog.askopenfilename(initialdir = hlp.filLocation,title = "Browsed file",filetypes = (("text files","*.txt"),))
            if(file0 != ()):
                broPth.append(Label(master, text=file0))
                broPth[1].pack()
                broPth[1].place(x=int(hlp.X*.01), y=int(hlp.Y*.63))
                fP = open(file0, "r")
                txt.delete("1.0", END)
                txt.insert(INSERT,fP.read())
                broPth[0].destroy()
                del broPth[0]

        #Logo Set
        logo = "imgs/MagnifEyeLogo.png"
        imgX, imgY = Image.open(logo).size
        img = ImageTk.PhotoImage(Image.open(logo).resize((int(imgX*.25), int(imgY*.25)), resample=0))
        block = Label(master, image=img)
        block.image = img
        block.pack()
        block.place(x=imgX*.035, y=imgY*.05)

        #Maker name set
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

        #Button to browse for file
        broBtn = Button(master, text="Browse", command=browseWindow)
        broBtn.pack()
        broBtn.place(x=int(hlp.X*.01), y=int(hlp.Y*.585))

        #Display current file selected
        broPth.append(Label(master))
        broPth[0].pack()
        broPth[0].place(x=int(hlp.X*.01), y=int(hlp.Y*.63))


        #RIGHT SIDE

        #Text box
        txt = Text(master, width=int(hlp.textBoxX/10), height=int(hlp.textBoxY/19))
        scrl = Scrollbar(master, command=txt.yview)
        txt.configure(yscrollcommand=scrl.set)
        txt.pack()
        scrl.pack(side=RIGHT, fill=Y)
        txt.place(x = int(hlp.X/12), y=int(hlp.Y*.025))
