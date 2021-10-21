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

    def findhand(self,img,draw=True):      

        imgRGB=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
        self.results=self.hands.process(imgRGB)

        if self.results.multi_hand_landmarks:
            for handLmarks in self.results.multi_hand_landmarks:
                if draw:            
                    self.mpdraw.draw_landmarks(img,handLmarks,self.mphands.HAND_CONNECTIONS) 

        return img
    
    def findposition(self,img,handno=0,draw=True):
        lmlist=[]
        if self.results.multi_hand_landmarks:
            myhand=self.results.multi_hand_landmarks[handno]

            for id,lm in enumerate(myhand.landmark):
                h,w,c=img.shape
                cx,cy=int(lm.x*w),int(lm.y*h)

                lmlist.append([id,cx,cy])
                if draw:
                    cv2.circle(img,(cx,cy),(5),(255,253,0),cv2.FILLED)

        return lmlist
    
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