import pygame
import random
import math
from pygame import mixer
import cv2
import time
import mediapipe
import os 
import Trackinghandmod as htm

# from playsound import playsound
pygame.init()  # initialization of the pygame
mixer.init()

screen = pygame.display.set_mode((800, 600))  # creation of the screen

# creating the title and the icon for the game
pygame.display.set_caption("Vader's Revenge")

icon = pygame.image.load('villian model.png')
pygame.display.set_icon(icon)

#background
background = pygame.image.load("background.png")
mixer.music.load("Star Wars Main Theme (Full).mp3")
mixer.music.play(-1)



# player..... KAKASHI
playerImg = pygame.image.load("hero model2.png")
playerx = 370
playery = 480
playerx_change = 0

# enemy------------ naruto
enemyImg = []
enemyx = []
enemyy = []
enemyx_change = []
enemyy_change = []
num_of_enemies = 6

for i in range(num_of_enemies):
    enemyImg.append(pygame.image.load("villian model2.png"))
    enemyx.append(random.randint(0, 735))
    enemyy.append(random.randint(50, 150))
    enemyx_change.append(3)
    enemyy_change.append(40)

# Sharingan activate
sharinganImg = pygame.image.load("bullet.png")
sharinganx = 0
sharingany = 480
sharingany_change = 10
sharingan_state = "ready"


#score

score_value=0
font=pygame.font.Font("freesansbold.ttf",32)

textx=10
texty=10

#gameover

over_font= pygame.font.Font("freesansbold.ttf",64)


def showscore(x,y):
    score= font.render("Score: "+ str(score_value),True,(255,255,255))
    screen.blit(score,(x,y))

def game_over_text():
    over_text = over_font.render("GAME OVER",True,(255,255,255))
    screen.blit(over_text,(200,250))

def player(x, y):
    screen.blit(playerImg,
                (x, y))  # blit is used to draw.... basically we are drawing an image of player on our game window


def enemy(x, y, i):
    screen.blit(enemyImg[i], (x, y))


def sharingan(x, y):
    global sharingan_state
    sharingan_state = "fire"
    screen.blit(sharinganImg, (x + 16, y + 10))


def isCollision(enemyx, enemyy, sharinganx, sharingany):
    distance = math.sqrt(math.pow((enemyx - sharinganx), 2) + (math.pow((enemyy - sharingany), 2)))
    if distance < 27:
        return True
    else:
        return False

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

# GAME LOGIC::::::::::::------------------::::::::::
running = True
while running:
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
        if totfinger!=0: 

            if totfinger==2:
                playerx_change = -5
            elif totfinger==3:
                playerx_change = 5
            elif totfinger==1:
                if sharingan_state is "ready":
                    sharinganx = playerx
                    sharingan(sharinganx, sharingany)
                    # sharingan_sound=mixer.Sound("Star Wars stardestroyer blaster sound effect 3.mp3")
                    # sharingan_sound.play()

        #if event.type == pygame.KEYUP:
        if totfinger==0:
            #if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                playerx_change = 0

    playerx += playerx_change

    # boundaries so kakashi does no go out of bound
    if playerx <= 0:
        playerx = 0
    elif playerx >= 736:
        playerx = 736
        print(totfinger)

        h,w,c=overlaylist[totfinger-1].shape
        img[0:h,0:w]=overlaylist[totfinger-1]

    ctime=time.time()
    fps=1/(ctime-ptime)
    fps=round(fps)
    ptime=ctime

    img[0:200,0:200]=overlaylist[0]
    cv2.putText(img,str(fps),(500,50),cv2.FONT_HERSHEY_COMPLEX_SMALL,3,(235,150,56),4)
    cv2.imshow("Image",img)

    if(cv2.waitKey(1) & 0xFF == ord("q")):
        break

    screen.fill((255, 255, 0))  # color selection suing RGB color codes

    screen.blit(background, (0, 0))
    for event in pygame.event.get():  # GETS ALL THE EVENTS IN THE PYGAME EVENT. EVEN THE CONTROLS THAT WILL BE USED TO PLAY THE GAME
        if event.type == pygame.QUIT:  # QUIT IS THE CROSS BUTTON THAT WILL BE USE TO CLOSE THE PROGRAM
            running = False

        # checking key stroke for right or left
        

    # boundaries so naruto does no go out of bound

    for i in range(num_of_enemies):

        #game over logic
        if(enemyy[i]>440):
            for j in range(num_of_enemies):
                enemyy[j]=2000
            game_over_text()
            break

        enemyx[i] += enemyx_change[i]
        if enemyx[i] <= 0:
            enemyx_change[i] = 3
            enemyy[i] += enemyy_change[i]
        elif enemyx[i] >= 736:
            enemyx_change[i] = -3
            enemyy[i] += enemyy_change[i]

        collision = isCollision(enemyx[i], enemyy[i], sharinganx, sharingany)
        if collision:
            sharingany = 480
            sharingan_state = "ready"
            score_value+=1
            enemyx[i] = random.randint(0, 735)
            enemyy[i] = random.randint(50, 150)
            # explosion_sound = mixer.Sound("Star Wars Blaster Sound Effect.mp3")
            # explosion_sound.play()


        enemy(enemyx[i], enemyy[i], i)

    # sharingamovement
    if sharingany <= 0:
        sharingany = 480
        sharingan_state = "ready"
    if sharingan_state is "fire":
        sharingan(sharinganx, sharingany)
        sharingany -= sharingany_change

    # increasing the coordinates to make our spaceship moving
    player(playerx, playery)  # calling the player function  #basically naruto's summoning jutsu
    showscore(textx,texty)
    pygame.display.update()  # display is updating just the game window we are working on