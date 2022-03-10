import cv2
import time
import os
import pyautogui as p 
import Trackinghandmod as htm
import pyttsx3
import datetime
import speech_recognition as sr
from random import randint
import playsound


wcam,hcam=640,480

cap=cv2.VideoCapture(0)
cap.set(3,wcam)
cap.set(4,hcam)

engine = pyttsx3.init("sapi5")
voices=engine.getProperty("voices")
engine.setProperty("voice",voices[1].id)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()
    
def wishMe():
    hour=int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good Morning")
    elif hour>=12 and hour <18:
        speak("Good Afternoon")
    else:
        speak("Good Evening")
    
    speak("Hello I am Scaler... How can I help U?")

def takeCommand():
    r=sr.Recognizer()
    with sr.Microphone() as source:
        print("Input in pogress.....")
        r.pause_threshold=1
        #r.energy_threshold=200
        audio=r.listen(source)

    try:
        print("\nRecognising....\n")
        query=r.recognize_google(audio,language="en-in")
        print(f"User Said {query}")
    except Exception as e:
        print(f"{e}")
        print("\nSay that again please\n")
        return "None"
    return query


folderpath="fingers"
mylist=os.listdir(folderpath)
overlaylist=[]
ptime=0
tipidd=[4,8,12,16,20]

detector=htm.handdetector(detectionconfi=0.7)

for impath in mylist:
    image=cv2.imread(f"{folderpath}/{impath}")
    overlaylist.append(image)


profiles={
    "robot" : "12345",
    "cat" : "54321"
}
wishMe()
speak("Speak the profile name")
playsound.playsound("mixkit-bell-notification-933.wav")
query=takeCommand().lower()

print(query)


if query in profiles:
    sampcount=0
    passwordlist=""
    while True:
        _,img=cap.read()
        img=detector.findhand(img)
        lmlist=detector.findposition(img,draw=False)
        #print(lmlist)

        if(len(lmlist)!=0):  
            fingers=[]       
            #For thumb
            if lmlist[tipidd[0]][1]<lmlist[tipidd [0]-1]  [1]    :
                fingers.append(0)
            else:
                fingers.append(1)
            
            #for remaining fingers 
            for id in range(1,5):
                if lmlist[tipidd[id]][2]< lmlist[tipidd[id]-2][2]:
                    fingers.append(1)
                else:
                    fingers.append(0)
            
            totfinger=fingers.count(1)
        
            if(sampcount!=5):
                if(totfinger==1):
                    p.press("1",presses=1,interval=2)
                    passwordlist+="1"
                    sampcount+=1

                if(totfinger==2):
                    p.press("2",presses=1,interval=2)
                    passwordlist+="2"
                    sampcount+=1

                if(totfinger==3):
                    p.press("3",presses=1,interval=2)
                    passwordlist+="3"
                    sampcount+=1

                if(totfinger==4):
                    p.press("4",presses=1,interval=2)
                    passwordlist+="4"
                    sampcount+=1

                if(totfinger==5):
                    p.press("5",presses=1,interval=2)
                    passwordlist+="5"
                    sampcount+=1
            
            if(passwordlist in profiles.values()):
                speak("Welcome to the profile")
                print("WElcome to the Profile")
                exit()
            elif(sampcount==5):
                speak("Access Denied")
                print("Access Denied")
                exit()

            print(totfinger)

        ctime=time.time()
        fps=1/(ctime-ptime)
        fps=round(fps)
        ptime=ctime

        #img[0:200,0:200]=overlaylist[0]
        cv2.putText(img,str(fps),(500,50),cv2.FONT_HERSHEY_COMPLEX_SMALL,3,(235,150,56),4)
        cv2.imshow("Image",img)

else:
    print("\n\nProfile not found Sorry\n\n")
    speak("Profile not found Sorry")