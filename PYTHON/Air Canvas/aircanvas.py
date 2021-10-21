import cv2
import time 
import os
import numpy as np
import Trackinghandmod as htm

folderpath="myoptions"
mylist=os.listdir(folderpath)

overlayList=[]
for impath in mylist:
    image=cv2.imread(f"{folderpath}/{impath}")
    overlayList.append(image)

print(len(overlayList))

header= overlayList[0]
drawColor=(0,0,255)
brushthickness=15
eraserthickness=140

cap=cv2.VideoCapture(0)
cap.set(3,1280)
cap.set(4,720)

image_drawing_canvas=np.zeros((720,1280,3),np.uint8)

detector=htm.handdetector(detectionconfi=.85)
xp,yp=0,0

while True:
    success,img=cap.read() # importing our cameras and frames 
    img=cv2.flip(img,1) # to prevent from drawing on a mirror cam 

    img=detector.findhand(img) #finding the landmarks on our image as we move 
    lmlist=detector.findposition(img,draw=False)

    if(len(lmlist)!=0):
        #print(lmlist)

        x1,y1=lmlist[8][1:]  #tip of our index finger 
        x2,y2=lmlist[12][1:] #tip of the middle finger [12,534,245] grabs only the last two values

        fingers=detector.finggersup_rev() #checking weather the fingers are up 
        #print(fingers)

        #checking of weather it is selection or drawing
            #1 1 finger up for drawing 
            #2 2 fingers up for selection 

        if fingers[1] and fingers[2]:
            print("Selection Mode")
            #checking for the color change 
            if y1<110:
                if 250<x1<450:
                    header=overlayList[0] 
                    drawColor=(0,0,255)
                elif 550<x1<750:
                    header=overlayList[1] 
                    drawColor=(255,0,0)
                elif 800<x1<950:
                    header=overlayList[2] 
                    drawColor=(0,255,0)
                elif 1050<x1<1200:
                    header=overlayList[3]
                    drawColor=(0,0,0)
                elif 0<x1<200:
                    drawColor=(0,0,0)
                    header=overlayList[4]
                    cv2.line(img,(xp,yp),(x1,y1),drawColor,1920)
                    cv2.line(image_drawing_canvas,(xp,yp),(x1,y1),drawColor,1920)


            cv2.rectangle(img,(x1,y1-25),(x2,y2+25),drawColor,cv2.FILLED) #color change according to the color selected on the screen 

        if fingers[1] and fingers[2]==False:
            cv2.circle(img,(x1,y1),15,drawColor,cv2.FILLED)
            print("Drawing Mode")

            #Drawing on the screen

            if xp==0 and yp==0:
                xp,yp=x1,y1
            
            if(brushthickness==(0,0,0)):
                cv2.line(img,(xp,yp),(x1,y1),drawColor,eraserthickness)
                cv2.line(image_drawing_canvas,(xp,yp),(x1,y1),drawColor,eraserthickness)
            else:
                cv2.line(img,(xp,yp),(x1,y1),drawColor,brushthickness)
                cv2.line(image_drawing_canvas,(xp,yp),(x1,y1),drawColor,brushthickness)

            xp,yp=x1,y1 
        
    imggray=cv2.cvtColor(image_drawing_canvas,cv2.COLOR_BGR2GRAY)
    _,imginv= cv2.threshold(imggray,255,255,cv2.THRESH_BINARY_INV)
    imginv=cv2.cvtColor(imginv,cv2.COLOR_GRAY2BGR)
    img=cv2.bitwise_and(img,imginv)
    img=cv2.bitwise_or(img,image_drawing_canvas)


    img[0:110, 0:1280]= header
    img=cv2.addWeighted(img,0.5,image_drawing_canvas,0.5,0)
    cv2.imshow("Image",img)
    cv2.imshow("Image2",image_drawing_canvas)
    cv2.waitKey(1)