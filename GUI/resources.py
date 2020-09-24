from tkinter import *
from tkinter import filedialog, messagebox
from PIL import ImageTk, Image
import os
import subprocess
import re
from pathlib import Path

global file0, file1

class HELPERS:
    def __init__(self, master=None):
        self.master = master
        self.X = self.master.winfo_screenwidth()
        self.Y = self.master.winfo_screenheight()
        #Width of main content textbox
        self.textBoxX = self.X/2
        #Height of main content textbox
        self.textBoxY = self.Y/1.5
        #Location to look for files needed to run MagnifEye GUI menu
        self.dirLocation = str(os.path.dirname(__file__)).split("MagnifEye")[0]+str('MagnifEye/')
        #Default location that the browse window will be at
        self.filLocation = "/" + os.getcwd()
        #Location of temporary file used to hold text needed to be ran through MagnifEye driver
        self.tmpLocation = self.dirLocation + "temP.txt"
        self.slFLocation = None
        #Storage of text in each string per the function
        self.storage = {'ThNeedle':{}, 'RedCheck':{}}
        #Storage of the index that each string has in given text document
        self.idxStrg = {'ThNeedle':{}, 'RedCheck':{}}
        #Each category for the content to be stored
        self.dictList = ['ThNeedle', 'RedCheck']
        self.TXT_LST = []
        #Default colors used for display
        self.color = ['green', 'blue', 'red']
        #Default measurement values
        self.mtrec = [5, 10]
        #
        self.colSet()

    #Write text from box to temp document for analysis
    def tempWriter(self, x):
        file=open(self.tmpLocation, "w")
        file.write(x)
        file.close()

    #Reset each variable after the runthrough of a single file
    def varReset(self):
        self.slFLocation = None
        self.storage = {'ThNeedle':{}, 'RedCheck':{}}
        self.idxStrg = {'ThNeedle':{}, 'RedCheck':{}}

    def TXT_LSTBuild(self, x):
        TEMP = ""
        LNG = 0
        NUM = int(self.textBoxX/10)
        for i in x:
            if i != '\n' and LNG <= int(self.textBoxX):
                LNG += 1
                TEMP += i
            else:
                if i != '\n':
                    TEMP += i
                if len(TEMP) != 0:
                    self.TXT_LST.append(TEMP)
                LNG = 0
                TEMP = ""

    #Set up word-count measurements and colors
    def colSet(self):
        if Path(str('%s/color.conf' % (os.getcwd()))).is_file():
            with open(str('%s/color.conf' % (os.getcwd()))) as FIL:
                FirstString = FIL.read()
            if FirstString != '':
                LST = FirstString.split(',')
                i = -1
                while(i < len(LST)):
                    if LST[i] == '':
                        LST.pop(i)
                        i-=1
                        continue
                    try:
                        LST[i] = int(LST[i])
                        i += 1
                    except ValueError:
                        i += 1
                        continue
                i = 0
                j = 0
                while(i < len(LST)):
                    if isinstance(LST[i], str):
                        self.color[j] = LST[i]
                        j += 1
                    i+=1
                i = 0
                j = 0
                while(i < len(LST)):
                    if isinstance(LST[i], int):
                        self.mtrec[i] = LST[i]
                        j += 1
                    i+=1

#MagnifEye GUI
class MFEGUI(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.master = master
        #Left side
        self.WINDOW(self.master)
        self.hlp = HELPERS(master=self.master)

    #Configure menu
    def CONF(self):
        outer_window()

    #Main window
    def WINDOW(self, master=None):

        #LEFT SIDE
        #Var set
        broPth = []
        hlp = HELPERS(master)
        bitSet = 0
        FUNCTION_CHOICE = IntVar()

        #FUNCTION CREATION

        #Var adjustment
        def MFYcall():
            if(hlp.slFLocation is not None or txt.get('1.0', END) != '\n' and hlp.slFLocation != ""):
                hlp.varReset()
                #Create command to run on command
                file0 = (broPth[0]["text"]).replace('\n', '')
                bitSet = FUNCTION_CHOICE.get()
                magOpt = [hlp.dirLocation+"linux-safe/MagnifEye", "-o"]
                fileTXT = txt.get(1.0, END)
                hlp.TXT_LSTBuild(fileTXT)
                hlp.tempWriter(fileTXT)
                if(bitSet==1):
                    magOpt.append("-th")
                if(bitSet==2):
                    magOpt.append("-red")
                magOpt.append(hlp.tmpLocation)
                subprocess.run(magOpt)
                #Run through each function for coordinates and color
                ME_RunThrough(fileTXT)
                #Delete temp file created
                os.remove(hlp.tmpLocation)

            else:
                messagebox.showerror("ERROR", "No File Selected")

        #Window used to browse for file to select
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

        #Adjust newline string
        def newlineAdjust(x):
            TMP_CONTAINER = list(x)
            TMP_WORD = ''
            TMP_RETURN = []
            for i in TMP_CONTAINER:
                if i == '\n':
                    if TMP_WORD != '':
                        TMP_RETURN.append(TMP_WORD)
                    TMP_RETURN.append(i)
                    TMP_WORD = ''
                    continue
                TMP_WORD += i
            TMP_RETURN.append(TMP_WORD)
            return TMP_RETURN

        #Return full list of text with newline
        def fullListReturn(x):
            LISTING = list(x)
            TMP_RETURN = []
            for i in range(len(LISTING)):
                if '\n' in LISTING[i]:
                    TMP_ARY = newlineAdjust(LISTING[i])
                    for j in TMP_ARY:
                        TMP_RETURN.append(j)
                else:
                    TMP_RETURN.append(LISTING[i])
            return TMP_RETURN

        #Prepare for coloring text
        def ColorPreparation(x):
            #All characters removed except capital,lowercase,',-,\n
            LST = [chr(i+65) for i in range(26)] + [chr(i+97) for i in range(26)] + ['\'', '-','\n']
            x = [i for i in x.split(' ')]
            DOC = fullListReturn(x)
            TXT_ROW = 0
            TXT_SNT = 0
            TXT_SENTENCE = ''
            for FUNC in hlp.dictList:
                if hlp.storage[FUNC] != {}:
                    for j in hlp.storage[FUNC]:
                        hlp.idxStrg[FUNC][j] = []
                    for i in DOC:
                        if '\n' in i:
                            TXT_ROW += 1
                            TXT_SNT = 0
                            for ITEM in hlp.storage:
                                for ITEM_KEY in hlp.storage[ITEM]:
                                    TEMPORARY = re.finditer(r'\b%s\b' % re.escape(ITEM_KEY), TXT_SENTENCE.lower())
                                    if TEMPORARY != None:
                                        for OCCURRANCE in TEMPORARY:
                                            if TXT_ROW > 1:
                                                hlp.idxStrg[FUNC][ITEM_KEY].append([str('%d.%d' % (TXT_ROW, OCCURRANCE.start()-2)),str('%d.%d' % (TXT_ROW,OCCURRANCE.start()+len(ITEM_KEY)-2))])
                                            else:
                                                hlp.idxStrg[FUNC][ITEM_KEY].append([str('%d.%d' % (TXT_ROW, OCCURRANCE.start())),str('%d.%d' % (TXT_ROW,OCCURRANCE.start()+len(ITEM_KEY)))])
                            TXT_SENTENCE = ''
                        if TXT_SENTENCE == '':
                            TXT_SENTENCE += str('%s' %(i.lower()))
                        else:
                            TXT_SENTENCE += str(' %s' %(i.lower()))

                        TXT_SNT = len(TXT_SENTENCE)

            return hlp

        #String coloring
        def strColor():
            hlp.colSet()
            count = -1
            for SECTION in hlp.idxStrg:
                for strng in hlp.idxStrg[SECTION]:
                    count += 1
                    for word in hlp.idxStrg[SECTION][strng]:
                        txt.tag_add("here"+str(count), str(word[0]), str(word[1]))
                        if(hlp.storage[SECTION][strng] <= hlp.mtrec[0]):
                            txt.tag_config("here"+str(count), foreground = hlp.color[0])

                        if(hlp.storage[SECTION][strng] > hlp.mtrec[0] and hlp.storage[SECTION][strng] <= hlp.mtrec[1]):
                            txt.tag_config("here"+str(count), foreground = hlp.color[1])

                        if(hlp.storage[SECTION][strng] > hlp.mtrec[1]):
                            txt.tag_config("here"+str(count), foreground = hlp.color[2])


        #Get Coordinates and color line(s)
        def ME_RunThrough(x):
            #Set up dictionary to hold data from temp.txt file
            dictSet()
            #Prepare coordinates for coloring
            hlp = ColorPreparation(x)
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
        progName = Label(master, text="MagnifEye v2.20.10", font="Helvetica 10 bold")
        progName.pack()
        progName.place(x=int(hlp.X*.01), y=int(hlp.Y*.19))

        #Options
        opts = Label(master, text="Options:", font="Helvetica 10 bold")
        opts.pack()
        opts.place(x=int(hlp.X*.01), y=int(hlp.Y*.22))

        #RadioButtons
        Radiobutton(master, text="ThNeedle", font="Helvetica 10 bold", variable=FUNCTION_CHOICE, value=1).place(x=int(hlp.X*.01), y=int(hlp.Y*.25))
        Radiobutton(master, text="RedCheck", font="Helvetica 10 bold", variable=FUNCTION_CHOICE, value=2).place(x=int(hlp.X*.01), y=int(hlp.Y*.27))

        #Submission button
        Button(master, text='Configure', font="Helvetica 10 bold", command=self.CONF).place(x=int(hlp.X*.01), y=int(hlp.Y*.32))
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
        txt = Text(master, width=int(hlp.textBoxX/10), height=int(hlp.textBoxY/19), wrap=WORD)
        scrl = Scrollbar(master, command=txt.yview)
        txt.configure(yscrollcommand=scrl.set)
        txt.pack()
        scrl.pack(side=RIGHT, fill=Y)
        txt.place(x = int(hlp.X/12), y=int(hlp.Y*.025))

#Pop up window that allows for configuration per the user
class outer_window(Frame):
    def __init__(self):
        self.master = Tk()

        #Helpers variable
        hlp = HELPERS(self.master)

        self.metric_config(hlp)

        self.title_creation(hlp)

        txtBx = self.txtBx_creation(hlp)

        clrBx = self.dropD_creation(hlp)

        self.Submission(hlp, [txtBx, clrBx])

        self.Var_Labeling(hlp)

        self.Cancel(hlp)

        self.master.mainloop()

    #Dimensions of window
    def metric_config(self, hlp):
        self.master.title("Configuration")
        self.master.configure(height=int(hlp.X*.15), width=int(hlp.Y*.29))

    #Algebra used to explain each field
    def title_creation(self, hlp):
        LVL = ['A < X', 'X <= A and A < Y', 'Y <= A']
        for i in range(3):
            Label(self.master, text='%s' % (LVL[i])).place(x=(hlp.X*.02), y=(hlp.Y*((i + .05)*(hlp.Y*.00003))+(hlp.Y*.027)))

    #Make entry fields
    def txtBx_creation(self, hlp):
        txtBx = []
        for i in range(2):
            txtBx.append(None)
            txtBx[i] = Entry(self.master, width=10)
            txtBx[i].place(x=(hlp.X*.08)+(hlp.X*.0065), y=(hlp.Y*((i + 1) * .025))+(hlp.Y*.137))
        return txtBx

    #Create labels for variables used to explain each entry field
    def Var_Labeling(self, hlp):
        Label(self.master, text='Amount').place(x=(hlp.X*.08)+(hlp.X*.0065), y=(hlp.Y*.137))
        Label(self.master, text='A').place(x=(hlp.X*.02), y=(hlp.Y*((5 + .05)*(hlp.Y*.00002504))))
        #First number
        Label(self.master, text='X').place(x=(hlp.X*.02), y=(hlp.Y*((6 + .05)*(hlp.Y*.00002505))))
        #VALUE
        Label(self.master, text=str(hlp.mtrec[0])).place(x=(hlp.X*.07), y=(hlp.Y*((6 + .05)*(hlp.Y*.00002505))))
        #Second number
        Label(self.master, text='Y').place(x=(hlp.X*.02), y=(hlp.Y*((7 + .05)*(hlp.Y*.00002506))))
        #VALUE
        Label(self.master, text=str(hlp.mtrec[1])).place(x=(hlp.X*.07), y=(hlp.Y*((7 + .05)*(hlp.Y*.00002506))))

    #Create dropdown menus
    def dropD_creation(self, hlp):
        clrBx = []
        for i in range(3):
            clrBx.append(None)
            clrBx[i] = StringVar(self.master)
            clrBx[i].set("%s" % (hlp.color[i]))

            T = OptionMenu(self.master, clrBx[i], 'Red', 'Blue', 'Green', 'Orange', 'Yellow', 'Gray')
            T.place(x=(hlp.X*.08) + 10, y=(hlp.Y*((i + .05)*(hlp.Y*.00003))+25))
        return clrBx

    def Submission(self, hlp, P):
        Button(self.master, text='Done', command=lambda:self.write(P, hlp)).place(y=(hlp.Y*.225), x=(hlp.X*.01))

    #Cancel new metric configuration
    def Cancel(self, hlp):
        Button(self.master, text='Cancel', command=self.destr).place(y=(hlp.Y*.225), x=(hlp.X*.05))

    #Destroy new window
    def destr(self):
        self.master.destroy()

    #Write metris to color.conf
    def write(self, P, hlp):
        with open('color.conf', 'w') as FIL:
            #Write numbers to file
            for i in range(len(P[0])):
                if P[0][i].get() == '':
                    FIL.write(str('%s,' % (hlp.mtrec[i])))
                else:
                    FIL.write(str('%s,' % (P[0][i].get())))
            #Write colors to file
            for i in range(len(P[1])):
                FIL.write(str('%s,' % (P[1][i].get())))

        self.destr()
