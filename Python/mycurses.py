from tkinter import *
import pyaudio

root = Tk()
root.grid()

C=Canvas(root,width=960,height=600)
C.pack()
C.create_rectangle(50, 25, 150, 75, fill="blue")
btnRecord=Button()
btnRecord["text"]="Record"
btnRecord.grid(row=2,column=4)
btnRecord.pack()
root.mainloop()