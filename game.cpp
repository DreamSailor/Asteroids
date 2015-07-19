/***********************************************************************
* Program:
*    Project 4, Asteroids            
*    Brother McCracken, CS165
* Author:
*    Jeffry Simpson, Samuel Koontz
* Summary: 
*    The driver program for the game of Asteroids
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include "game.h"

/***************************************************
 * Game :: CONSTRUCTOR
 * 
 * 
 ***************************************************/
Game::Game() : dx(0.0), 
               dy(0.0),
               refresh(0),
               orientation(270)  //facing up
{ 
     
   //Set ship  starting position center of the screen
   ship.setX(0); 
   ship.setY(0);
   this->createAsteroidField(); 
   
   // set the skeet start position
   #ifdef DEBUG 
      cout << "Calling Constructor\n";
   #endif
}

/********************************************
 * Game :: update
 * Move the elements on the screen 
 *******************************************/
void Game::createAsteroidField()
{
for (int i = 0; i < 4; i++)
	{
		float x;
        float y;		
		SpaceRock spaceRock;
		spaceRock.setSize(BIGROCK);
		spaceRock.setRotation(BIGROTATION);
		spaceRock.setSpeed(getRand(STARTSPEEDMIN,STARTSPEEDMAX));
        spaceRock.setPoints(BIGPOINTS);


		if (getRand(0,1))
			x = XMAX;
		else
			x = XMIN;
		y = getRand(YMIN, YMAX);
		if ((x >= XAVG) && (y >= YAVG)) //1st quadrant, needs to go down and left
			spaceRock.setDirection(getRand(180,270));
		else if (x < XAVG && y >= YAVG) //2nd quadrant, needs to go down and right
			spaceRock.setDirection(getRand(270, 364));
		else if (x < XAVG && y < YAVG) //3rd quadrant, needs to go up and right
			spaceRock.setDirection(getRand(0,90));
		else //4th quadrant, needs to go up and left
			spaceRock.setDirection(getRand(90, 180));
        spaceRock.setPoint(x,y);

		spaceRocks.push_back(spaceRock);
#ifdef DEBUG
			cout << "rock " << i
       	         << ": Size: " << spaceRocks[i].getSize() 
                 << " Point: (" << spaceRocks[i].getPoint() 
                 << ") Direction: " <<spaceRocks[i].getDirection() 
                 << " Speed: " << spaceRocks[i].getSpeed()
                 << " Rotation: " <<spaceRocks[i].getRotation()
                 << endl;
   #endif		
	}
}

/********************************************
 * Game :: update
 * Move the elements on the screen 
 *******************************************/
void Game::update(int left, int right, bool spacebar)
{
   if (right)
      orientation -= 5;
   if (left)
      orientation += 5;

for (int i = 0; i < spaceRocks.size(); i++)
{
   spaceRocks[i].updatePos();
}
   
#ifdef DEBUG      //update debug counter on the lower left side of screen
      refresh++;  //tracks we are doing something
#endif
 
}

/*************************************************
 * Asteroid : DRAW
 * Draw the stuff
 ************************************************/
void Game::draw()
{

   //drawCircle(ship, SKEETRADIUS);
  // drawPolygon(ship, 3, 16, 15);
   drawShip(ship,orientation);
   for (int i = 0; i < spaceRocks.size(); i++)
   {
      //drawCircle(spaceRocks[i].getPoint(), 20);
      drawPolygon(spaceRocks[i].getPoint(),
                 (spaceRocks[i].getSize() / 2),
                 spaceRocks[i].getPoints(),
                 spaceRocks[i].getTotalRotation());

#ifdef DEBUG
			//cout << "rock " << i
       	    //     << ": Size: " << spaceRocks[i].getSize() 
           //      << " Point: (" << spaceRocks[i].getPoint() 
           //      << ") Direction: " <<spaceRocks[i].getDirection() 
           //      << " Speed: " << spaceRocks[i].getSpeed()
           //      << " Rotation: " <<spaceRocks[i].getRotation()
           //      << endl;
   #endif	
   
   }

      //draw refresh
#ifdef DEBUG
   {
      Point pointDebug(ship.getXMin() + 5, ship.getYMin() + 15);
      drawNumber(pointDebug, refresh); 
   }
#endif

}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
   
 
   
   Game * pGame = (Game *)p;  // cast the void pointer into a known type
     
   // advance the ball
   pGame->update(pUI->isLeft(), pUI->isRight(), pUI->isSpace());
 
   // draw it
   pGame->draw();
}
   
/********************************************
 * Main
 * Main driver function
 *******************************************/
int main(int argc, char** argv)
{
   //vector <SpaceRock> spaceRocks;   
   srand(time(NULL));
   Interface ui(argc, argv, "Asteroids Classic the Beginning");    // initialize OpenGL
   Game game;                           // initialize the game state
   ui.run(callBack, &game);             // set everything into action

   return 0;
}

