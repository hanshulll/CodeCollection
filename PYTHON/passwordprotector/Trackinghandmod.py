import cv2
import mediapipe as mp
import time

class handdetector():
    def __init__(self,mode=False,maxHands=2,detectionconfi=0.5,trackconfi=0.5):
        self.mode=mode
        self.maxhands=maxHands
        self.detec=detectionconfi
        self.track=trackconfi

        self.mphands=mp.solutions.hands
        self.hands=self.mphands.Hands(self.mode,self.maxhands,self.detec,self.track)
        self.mpdraw=mp.solutions.drawing_utils

        self.tipidd=[4,8,12,16,20]

    def findhand(self,img,draw=True):      

        imgRGB=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
        self.results=self.hands.process(imgRGB)

        if self.results.multi_hand_landmarks:
            for handLmarks in self.results.multi_hand_landmarks:
                if draw:            
                    self.mpdraw.draw_landmarks(img,handLmarks,self.mphands.HAND_CONNECTIONS) 

        return img
    
    def findposition(self,img,handno=0,draw=True):
        self.lmlist=[]
        if self.results.multi_hand_landmarks:
            myhand=self.results.multi_hand_landmarks[handno]

            for id,lm in enumerate(myhand.landmark):
                h,w,c=img.shape
                cx,cy=int(lm.x*w),int(lm.y*h)

                self.lmlist.append([id,cx,cy])
                if draw:
                    cv2.circle(img,(cx,cy),(5),(120,253,0),cv2.FILLED)

        return self.lmlist
    
    def finggersup(self):
        fingers=[]       
        #For thumb
        
        if self.lmlist[self.tipidd[0]][1]<self.lmlist[self.tipidd [0]-1]  [1]    :
            fingers.append(0)
        else:
            fingers.append(1)
          
        #for remaining fingers 
        for id in range(1,5):
            if self.lmlist[self.tipidd[id]][2]< self.lmlist[self.tipidd[id]-2][2]:
                fingers.append(1)
            else:
                fingers.append(0)
        return fingers

    def finggersup_rev(self):
        fingers=[]       
        #For thumb
        
        if self.lmlist[self.tipidd[0]][1]>self.lmlist[self.tipidd [0]-1]  [1]    :
            fingers.append(0)
        else:
            fingers.append(1)
          
        #for remaining fingers 
        for id in range(1,5):
            if self.lmlist[self.tipidd[id]][2]< self.lmlist[self.tipidd[id]-2][2]:
                fingers.append(1)
            else:
                fingers.append(0)
        return fingers

def main():
    ptime=0
    ctime=0
    cap=cv2.VideoCapture(0)
    detector=handdetector()

    while True:

        success,img=cap.read()
        img=detector.findhand(img)
        lmlist=detector.findposition(img)
                
        if len(lmlist)!=0:
         print(lmlist[0])

        ctime=time.time()
        fps=1/(ctime-ptime)
        fps=round(fps)
        ptime=ctime

        cv2.putText(img,str(fps),(10,70),cv2.FONT_HERSHEY_COMPLEX,3,(255,0,0),3)

        cv2.imshow("Image",img)

        if (cv2.waitKey(1)& 0xFF==ord("q")):
            break


if __name__ == '__main__':
    main()