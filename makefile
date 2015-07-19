###############################################################
# Program:
#     Project 4, Asteroids
#    Brother McCracken, CS165
# Author:
#     Jeffry Simpson 50%
#     Samuel Koontz  50%
# Summary:
#     Enter a brief description of your program here! If you do any
#     extra credit, this would be a good place to describe it.
#
#     Estimated:  0.0 hrs
#     Actual:     0.0 hrs
#       Please describe briefly what was the most difficult part

###############################################################
# Programs:
#    pong:         The playable game
#    uiTest:       Simple driver program for the drawing interface
###############################################################
a.out : game.o uiInteract.o uiDraw.o point.o spaceRock.o
	g++ -o a.out game.o uiInteract.o uiDraw.o point.o spaceRock.o -lGL -lglut -lGLU -lm -lstdc++ 
#	#-L/System/Library/Frameworks -framework GLUT -L/System/Library/Frameworks -framework OpenGL
#	tar -cf prj4.tar *.cpp *.h makefile

spaceRockTest.out : spaceRockTest.o point.o
	g++ -o spaceRock.out spaceRockTest.o point.o -lGL -lglut -lGLU -lm -lstdc++ 
	
uiTest : uiTest.o uiDraw.o uiInteract.o point.o
	g++ -o uiTest uiTest.o uiDraw.o uiInteract.o point.o -lGL -lglut -lGLU -lm -lstdc++ 
	#-L/System/Library/Frameworks -framework GLUT -L/System/Library/Frameworks -framework OpenGL

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    uiTest.o      Driver program for uiDraw and uiTest
#    pong.o        Only the greatest game ever! (and it was for 20 years)  
###############################################################
uiInteract.o : uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

uiDraw.o : uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

point.o : point.cpp point.h
	g++ -c point.cpp

spaceRock.o : spaceRock.cpp spaceRock.h
	g++ -c spaceRock.cpp
	
spaceRockTest.o : spaceRockTest.cpp spaceRock.o point.o
	g++ -c spaceRockTest.cpp spaceRock.cpp point.cpp
	
game.o : game.cpp point.h uiDraw.h uiInteract.h
	g++ -c game.cpp

uiTest.o : uiTest.cpp point.h uiDraw.h uiInteract.h
	g++ -c uiTest.cpp



###############################################################
# General rules
###############################################################
clean :
	rm a.out *.o *.tar

all :  uiTest a.out

