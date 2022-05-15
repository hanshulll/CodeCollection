import cv2
import mediapipe as mp
import time

cap=cv2.VideoCapture(0)

mphands=mp.solutions.hands
hands=mphands.Hands()
mpdraw=mp.solutions.drawing_utils
ptime=0

while True:

    success,img=cap.read()
    imgRGB=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    results=hands.process(imgRGB)

    if results.multi_hand_landmarks:
        for handLmarks in results.multi_hand_landmarks:
            for id,lm in enumerate(handLmarks.landmark):
                #print(id)
                h,w,c=img.shape
                cx,cy=int(lm.x*w),int(lm.y*h)
                print(id,cx,cy)
                
                if(id==0):
                    cv2.circle(img,(cx,cy),(30),(255,253,0),cv2.FILLED)


            mpdraw.draw_landmarks(img,handLmarks,mphands.HAND_CONNECTIONS) 

    ctime=time.time()
    fps=1/(ctime-ptime)
    fps=round(fps)
    ptime=ctime

    cv2.putText(img,str(fps),(10,70),cv2.FONT_HERSHEY_COMPLEX,3,(255,0,0),3)

    cv2.imshow("Image",img)

    if (cv2.waitKey(1)& 0xFF==ord("q")):
        break