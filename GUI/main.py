from resources import *

if __name__ == '__main__':
	root = Tk()

	#Set Vars
	otherz = HELPERS(root)

	otherz.colSet()

	#Window setting
	MG = MFEGUI(root)
	root.title("MagnifEye By FlakeyKarma")
	root.geometry(str(int(otherz.textBoxX))+"x"+str(int(otherz.textBoxY)))
	root.mainloop()
