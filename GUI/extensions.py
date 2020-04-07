from tkinter import *

class outer_window(Frame):
    def __init__(self,master=None):
        self.master = master

    def metric_config(self, master):
        pass

    class function_pop(Frame):
        def __init__(self, master=None):
            self.master = master
            self.display_text = tk.Label(self, text="Hover over me")
            self.hidden_text = tk.Label(self, text="", width=40)
            self.display_text.pack(side="top")
            self.hidden_text.pack(side="top", fill="x")

            self.display_text.bind("<Enter>", self.on_enter)
            self.display_text.bind("<Leave>", self.on_leave)

        def on_enter(self, event):
            self.hidden_text.configure(text="Hello world")

        def on_leave(self, enter):
            self.hidden_text.configure(text="")
