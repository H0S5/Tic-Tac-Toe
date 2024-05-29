from tkinter import *
from random import *
def botButton():
    global bot_status,Bot,count,label_winner
    if Bot['text'] == "Bot Is Off":
        bot_status = True
        Bot.config(text="Bot Is On",bg="green3")
        button1['text'] = ""
        button2['text'] = ""
        button3['text'] = ""
        button4['text'] = ""
        button5['text'] = ""
        button6['text'] = ""
        button7['text'] = ""
        button8['text'] = ""
        button9['text'] = ""
        button1.config(bg="grey53")
        button2.config(bg="grey53")
        button3.config(bg="grey53")
        button4.config(bg="grey53")
        button5.config(bg="grey53")
        button6.config(bg="grey53")
        button7.config(bg="grey53")
        button8.config(bg="grey53")
        button9.config(bg="grey53")
        Label(window,text="                      ",font=('Helvetica',15)).grid(row=3,column=1)
        count = 0
        botPlays()
    else:
        Bot.config(text="Bot Is Off",bg="red3")
        bot_status = False
        count = 0
        Buttons()
def botPlays():
    global thePlayer,count
    if thePlayer == True:
        
        place = randrange(1,10)
        if(place == 1 and button1['text'] == ""):
            button1['text'] = "O"
            count+= 1
            thePlayer = not thePlayer
        elif(place == 2 and button2['text'] == ""):
            button2['text'] = "O"
            count+= 1
            thePlayer = not thePlayer
        elif(place == 3 and button3['text'] == ""):
            count+= 1
            thePlayer = not thePlayer
            button3['text'] = "O"
        elif(place == 4 and button4['text'] == ""):
            count+= 1
            thePlayer = not thePlayer
            button4['text'] = "O"
        elif(place == 5 and button5['text'] == ""):
            count+= 1
            thePlayer = not thePlayer
            button5['text'] = "O"
        elif(place == 6 and button6['text'] == ""):
            count+= 1
            thePlayer = not thePlayer
            button6['text'] = "O"
        elif(place == 7 and button7['text'] == ""):
            count+= 1
            thePlayer = not thePlayer
            button7['text'] = "O"
        elif(place == 8 and button8['text'] == ""):
            count+= 1
            thePlayer = not thePlayer
            button8['text'] = "O"
        elif(place == 9 and button9['text'] == ""):
            count+= 1
            thePlayer = not thePlayer
            button9['text'] = "O"
    winner_check()
def play(theButton):
    global thePlayer,count
    if thePlayer == False and theButton['text']== "":
        theButton['text'] = "X"
        thePlayer = not thePlayer
        count+=1
        winner_check()
    elif thePlayer == True and theButton['text']== "":
        theButton['text'] = "O"
        count+=1
        thePlayer = not thePlayer
        winner_check()
    else:
        Label(window,text="Wrong Place!",font=('Helvetica',15),bg='red3').grid(row=3,column=1)
def disable_all_buttons():
    button1.config(state=DISABLED)
    button2.config(state=DISABLED)
    button3.config(state=DISABLED)
    button4.config(state=DISABLED)
    button5.config(state=DISABLED)
    button6.config(state=DISABLED)
    button7.config(state=DISABLED)
    button8.config(state=DISABLED)
    button9.config(state=DISABLED)
def winner_check():
    global count,bot_status
    if button1["text"] == "X" and button2["text"] == "X" and button3["text"] == "X":
        button1.config(bg='green3')
        button2.config(bg='green3')
        button3.config(bg='green3')
        winner_label = Label(window,text="X is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button4["text"] == "X" and button5["text"] == "X" and button6["text"] == "X":
        button4.config(bg='green3')
        button5.config(bg='green3')
        button6.config(bg='green3')
        bot_status = False
        winner_label = Label(window,text="X is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        disable_all_buttons()
        
    elif button7["text"] == "X" and button8["text"] == "X" and button9["text"] == "X":
        button7.config(bg='green3')
        button8.config(bg='green3')
        button9.config(bg='green3')
        bot_status = False
        winner_label = Label(window,text="X is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        disable_all_buttons()
        
    elif button1["text"] == "X" and button4["text"] == "X" and button7["text"] == "X":
        button1.config(bg='green3')
        button4.config(bg='green3')
        button7.config(bg='green3')
        bot_status = False
        winner_label = Label(window,text="X is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        disable_all_buttons()
        
    elif button2["text"] == "X" and button5["text"] == "X" and button8["text"] == "X":
        button2.config(bg='green3')
        button5.config(bg='green3')
        button8.config(bg='green3')
        winner_label = Label(window,text="X is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button3["text"] == "X" and button6["text"] == "X" and button9["text"] == "X":
        button3.config(bg='green3')
        button6.config(bg='green3')
        button9.config(bg='green3')
        winner_label = Label(window,text="X is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button1["text"] == "X" and button5["text"] == "X" and button9["text"] == "X":
        button1.config(bg='green3')
        button5.config(bg='green3')
        button9.config(bg='green3')
        winner_label = Label(window,text="X is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button7["text"] == "X" and button5["text"] == "X" and button3["text"] == "X":
        button7.config(bg='green3')
        button5.config(bg='green3')
        button3.config(bg='green3')
        winner_label = Label(window,text="X is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button1["text"] == "O" and button2["text"] == "O" and button3["text"] == "O":
        button1.config(bg='green3')
        button2.config(bg='green3')
        button3.config(bg='green3')
        winner_label = Label(window,text="X is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button4["text"] == "O" and button5["text"] == "O" and button6["text"] == "O":
        button4.config(bg='green3')
        button5.config(bg='green3')
        button6.config(bg='green3')
        winner_label = Label(window,text="O is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button7["text"] == "O" and button8["text"] == "O" and button9["text"] == "O":
        button7.config(bg='green3')
        button8.config(bg='green3')
        button9.config(bg='green3')
        winner_label = Label(window,text="O is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button1["text"] == "O" and button4["text"] == "O" and button7["text"] == "O":
        button1.config(bg='green3')
        button4.config(bg='green3')
        button7.config(bg='green3')
        winner_label = Label(window,text="O is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button2["text"] == "O" and button5["text"] == "O" and button8["text"] == "O":
        button2.config(bg='green3')
        button5.config(bg='green3')
        button8.config(bg='green3')
        winner_label = Label(window,text="O is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button3["text"] == "O" and button6["text"] == "O" and button9["text"] == "O":
        button3.config(bg='green3')
        button6.config(bg='green3')
        button9.config(bg='green3')
        winner_label = Label(window,text="O is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif button1["text"] == "O" and button5["text"] == "O" and button9["text"] == "O":
        button1.config(bg='green3')
        button5.config(bg='green3')
        button9.config(bg='green3')
        winner_label = Label(window,text="O is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        disable_all_buttons()
        bot_status = False
        
    elif button7["text"] == "O" and button5["text"] == "O" and button3["text"] == "O":
        button7.config(bg='green3')
        button5.config(bg='green3')
        button3.config(bg='green3')
        winner_label = Label(window,text="O is the winner",font=('Helvetica',15),bg='green3').grid(row=3,column=1)
        bot_status = False
        disable_all_buttons()
        
    elif count == 9:
        Label(window,text="Draw!",font=('Helvetica',15),bg='red3').grid(row=3,column=1)
        disable_all_buttons()
    if bot_status == True and thePlayer == True:
        botPlays()
    

def Buttons():
    global button1,button2,button3,button4,button5,button6,button7,button8,button9,thePlayer,count,bot_status,Bot,label_winner
    thePlayer = True
    count = 0
    bot_status = False
    Bot = Button(window,text="Bot Is Off",height=1,font=('Helvetica', 12), width=10,bg="red3" ,command = lambda: botButton())
    Bot.grid(row=3, column=0)
    
    button1 = Button(window,text="",height=6,font=('Helvetica', 12),bg="grey53" ,width=13,command= lambda : play(button1))
    button2 = Button(window,text='',height=6,font=('Helvetica', 12),bg="grey53" , width=13,command= lambda : play(button2))
    button3 = Button(window,text="",height=6,font=('Helvetica', 12), bg="grey53" ,width=13,command= lambda : play(button3))
    button4 = Button(window,text="",height=6,font=('Helvetica', 12), bg="grey53" ,width=13,command= lambda : play(button4))
    button5 = Button(window,text="",height=6,font=('Helvetica', 12), bg="grey53" ,width=13,command= lambda : play(button5))
    button6 = Button(window,text="",height=6,font=('Helvetica', 12), bg="grey53" ,width=13,command= lambda : play(button6))
    button7 = Button(window,text="",height=6,font=('Helvetica', 12), bg="grey53" ,width=13,command= lambda : play(button7))
    button8 = Button(window,text="",height=6,font=('Helvetica', 12), bg="grey53" ,width=13,command= lambda : play(button8))
    button9 = Button(window,text="",height=6,font=('Helvetica', 12), bg="grey53" ,width=13,command= lambda : play(button9))
    reset = Button(window,text="Reset",height=1,font=('Helvetica', 12), width=10,bg="grey80" ,command = lambda: Buttons())
    label_winner = Label(window,text="                      ",font=('Helvetica',15)).grid(row=3,column=1)

    reset.grid(row=3, column=2)
    button1.grid(row=0, column=0)
    button2.grid(row=1, column=0)
    button3.grid(row=2, column=0)
    button4.grid(row=0, column=1)
    button5.grid(row=1, column=1)
    button6.grid(row=2, column=1)
    button7.grid(row=0, column=2)
    button8.grid(row=1, column=2)
    button9.grid(row=2, column=2)
    window.resizable(0, 0)
    window.mainloop()
window = Tk()
window.title("XO")
window.geometry("393x400")
Buttons()