/***********************************************************************
* Program:
*    Project 4, Asteroids            
*    Brother McCracken, CS165
* Author:
*    Jeffry Simpson, Samuel Koontz
* Summary: 
*    game.h 
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#ifndef GAME_H
#define	GAME_H

#define DEBUG


// set the bounds of the game

#include <iostream>
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include <stdio.h>
#include <math.h>
#include "spaceRock.h"
#include "spaceShip.h"
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

#define XMIN -200.0
#define XMAX 200.0
#define YMIN -200.0
#define YMAX 200.0
#define XAVG (((XMAX-XMIN)/2)+XMIN)
#define YAVG (((YMAX-YMIN)/2)+YMIN)
#define BIGROCK 80
#define MEDROCK 40
#define SMROCK 20
#define BIGROTATION 2
#define MEDROTATION 5
#define SMROTATION 10
#define STARTSPEEDMIN 3
#define STARTSPEEDMAX 6
#define BIGPOINTS 10
#define MEDPOINTS 12
#define SMPOINTS 16

float Point::xMin = XMIN;
float Point::xMax =  XMAX;
float Point::yMin = YMIN;
float Point::yMax =  YMAX;


/************************************
 * Game class
 ***********************************/
class Game
{
   public:
      Game();
	  void createAsteroidField();         
      void update(int left, int right, int up, bool spacebar);
      void draw();
	  int getRand(int min, int max) {return (rand() % (max-min+1)+min);}
      int getRand(double min, double max) {return (int)(rand() % ((int)max - (int)min + 1) + (int)min);}

      
    private:      
        vector<SpaceRock> spaceRocks;
        Point ship;         // Ship 
		SpaceShip spaceShip; // spaceship class
        int orientation;     //ship orientation
        float dx;     // horizontal velocity of the spaceShip
        float dy;     // vertical velocity of the spaceShip
      
        int refresh;      // screen refresh for debug
      
};

#endif	/* GAME_H */

