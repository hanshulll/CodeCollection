import cv2
import time
import mediapipe
import os 
import Trackinghandmod as htm

wcam,hcam=640,480

cap=cv2.VideoCapture(0)
cap.set(3,wcam)
cap.set(4,hcam)

folderpath="fingers"
mylist=os.listdir(folderpath)
overlaylist=[]
ptime=0
tipidd=[4,8,12,16,20]

detector=htm.handdetector(detectionconfi=0.7)

for impath in mylist:
    image=cv2.imread(f"{folderpath}/{impath}")
    #print(f"{folderpath}/{impath}")
    overlaylist.append(image)

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
        print(totfinger)

        h,w,c=overlaylist[totfinger-1].shape
        img[0:h,0:w]=overlaylist[totfinger-1]

    ctime=time.time()
    fps=1/(ctime-ptime)
    fps=round(fps)
    ptime=ctime

    #img[0:200,0:200]=overlaylist[0]
    cv2.putText(img,str(fps),(500,50),cv2.FONT_HERSHEY_COMPLEX_SMALL,3,(235,150,56),4)
    cv2.imshow("Image",img)

    if(cv2.waitKey(1) & 0xFF == ord("q")):
        break