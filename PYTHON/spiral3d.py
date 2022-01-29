from turtle import *
import turtle
from random import randint

bgcolor("black")

wn=turtle.Screen()
wn.bgcolor("black")

t=turtle.Turtle()
x=1
t.speed(0)
t.shape("turtle")
t.lt(90)
while x<400:
	r=randint(0,255)	
  g=randint(0,255)
	b=randint(0,255)
	wn.colormode(255)
	t.pencolor(r,g,b)
	t.fd(5+x)
	t.rt(90.91)
	x=x+1
wn.exitonclick()
