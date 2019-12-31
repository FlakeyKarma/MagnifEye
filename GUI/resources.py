from tkinter import *
from tkinter import filedialog, messagebox
from PIL import ImageTk, Image
import os
import subprocess
import re

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
        self.slFLocation = None
        self.storage = {'ThNeedle':{}, 'RedCheck':{}, 'Comparison':{}, 'DoCo':{}}
        self.idxStrg = []
        self.dictList = ['ThNeedle', 'RedCheck', 'Comparison', 'DoCo']

    def tempWriter(self, x):
        file=open(self.tmpLocation, "w")
        file.write(x)
        file.close()

    def varReset(self):
        self.slFLocation = None
        self.storage = {'ThNeedle':{}, 'RedCheck':{}, 'Comparison':{}, 'DoCo':{}}
        self.idxStrg = []

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

        #FUNCTION CREATION

        #Var adjustment
        def MFYcall():
            if(hlp.slFLocation is not None or txt.get('1.0', END) != '\n' and hlp.slFLocation != ""):
                hlp.varReset()
                #Create command to run on command
                file0 = (broPth[0]["text"]).replace('\n', '')
                bitSet = [ThNeedle.get(), RedCheck.get(), weBI.get(), DoCo.get()]
                magOpt = [hlp.dirLocation+"linux-safe/MagnifEye", "-o"]
                fileTXT = txt.get(1.0, END)
                hlp.tempWriter(fileTXT)
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
                #Work on function based on whether bit is set in bitSet
                if(bitSet[0]):
                    ME_ThNeedle(fileTXT)

            else:
                messagebox.showerror("ERROR", "No File Selected")

        def browseWindow():
            hlp.slFLocation = filedialog.askopenfilename(initialdir = hlp.filLocation,title = "Browsed file",filetypes = (("text files","*.txt"),))
            if(hlp.slFLocation != ()):
                broPth.append(Label(master, text=hlp.slFLocation))
                broPth[1].pack()
                broPth[1].place(x=int(hlp.X*.01), y=int(hlp.Y*.63))
                fP = open(hlp.slFLocation, "r")
                txt.delete("1.0", END)
                TEXTread = fP.read()
                fP.close()
                txt.insert(INSERT,TEXTread)
                broPth[0].destroy()
                del broPth[0]

        #Set up dictionaries with data from MagnifEye
        def dictSet():
            tmpRead = (open("temp.txt").read().split("\n"))
            tmpRead.remove('')
            tmpRead = [i.split('=') for i in tmpRead]
            for i in tmpRead:
                for j in hlp.dictList:
                    dSplit = i[1].split(">")
                    if i[0] == j:
                        hlp.storage[j][dSplit[0]] = int(dSplit[1])

        #Return list of words and corresponding number in document
        def lstRet(x):
            x = [i for i in x.split(" ") if i != '' and i != '\n' and i != '\t']
            y = []
            x = [re.sub('[^A-Za-z0-9]+', '', i).lower() for i in x]
            for i in hlp.dictList:
                for j in x:
                    if(len(hlp.storage[i]) > 0):
                        y.append(hlp.storage[i][j])

            y.reverse()
            return y

        #Color Preparation
        def clrPrp(x):
            for i in hlp.dictList:
                if(len(hlp.storage[i]) > 0):
                    for j in hlp.storage[i]:
                        hlp.idxStrg.append([["1." + str(k.start()), "1." + str(k.start()+len(j))] for k in re.finditer(j, ' '.join(x))])

        #String coloring
        def strColor():
            count = 0
            color = ['green', 'red', 'blue']
            for strng in hlp.idxStrg:
                for word in range(len(strng)):
                    print(word)
                    txt.tag_add("here"+str(count), strng[word][0], strng[word][1])
                    txt.tag_config("here"+str(count), background = color[word])
                    count += 1

        #ThNeedle function
        def ME_ThNeedle(x):
            dictSet()
            #List of enumeration of corresponding words
            numLst = lstRet(x)
            #List of strings under analysis
            strLst = [''.join([j for j in i if j.isalpha() or j == '\n' or j == '\t']) for i in x.split(" ")]
            #Prepare coordinates for coloring
            clrPrp([i.lower() for i in strLst])
            #Color words
            strColor()

        #SETUP

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

#DOCO:Pop up window
class POPWINDOW(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.master = master
        #Left side
        self.WINDOW(self.master)
