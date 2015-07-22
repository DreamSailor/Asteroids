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

#include "spaceShip.h"
#include "spaceRock.h"
#include "game.h"
#include "bullet.h"

/***************************************************
 * Game :: CONSTRUCTOR
 * 
 * 
 ***************************************************/
Game::Game() : refresh(0), score(0)
{ 
   
   #ifdef DEBUG 
      cout << "Calling Constructor\n";
   #endif

   //Set ship  starting position center of the screen
   spaceShip.setX(0); 
   spaceShip.setY(0);
   spaceShip.setDirection(270);
   spaceShip.setSpeed(.2);
   spaceShip.resurrect();
   this->createAsteroidField();       
}

/********************************************
 * Game :: createNewAsteroid
 * Sets up a large asteroid 
 *******************************************/
void Game::createNewAsteroid()
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
}

/********************************************
 * Game :: createAsteroidField
 * Creates a new asteroid field
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
   }
}
/********************************************
 * Game :: update
 * Move the elements on the screen 
 *******************************************/
void Game::update(int left, int right, int up, bool spacebar)

{
      //update space ship
      if (right)
         spaceShip.changeDirection(-10);
      if (left)
         spaceShip.changeDirection(10);
      if (up)
         spaceShip.updateCourse();
     if (spacebar)
      {
         Bullet bullet;
         bullet.setPoint(spaceShip.getX(), spaceShip.getY());
         bullet.setDX(spaceShip.getDX());
         bullet.setDY(spaceShip.getDY());
         bullet.setDirection(spaceShip.getDirection());
         bullet.updateCourse();
         bullets.push_back(bullet);
      }

      spaceShip.updatePos();

   
   
      //update position of each bullet
      for (int i = 0; i < bullets.size(); i++)
      {
         bullets[i].updatePos();
         if (bullets[i].getIsDead())
         {
            bullets.erase(bullets.begin() + i);
         }
      }
      //checks if shot hits, and creates resulting asteroids
      for (int i = 0; i < spaceRocks.size(); i++)
      {
         spaceRocks[i].updatePos();
         for (int j = 0; j < bullets.size(); j++)
         {
            if(spaceRocks[i].isHit(bullets[j].getX(), bullets[j].getY()))
            {
               bullets.erase(bullets.begin() + j);
               switch (spaceRocks[i].getSize())
               {
                  case BIGROCK:
                  {
                     SpaceRock spaceRock = spaceRocks[i];
   		             spaceRock.setSize(MEDROCK);
  		             spaceRock.setRotation(MEDROTATION);
		             spaceRock.setPoints(MEDPOINTS);
                     spaceRock.setDY(1.0);
                     spaceRocks.push_back(spaceRock);
                     spaceRock.setDY(-1.0);
                     spaceRocks.push_back(spaceRock);
                     spaceRock.setSize(SMROCK);
                     spaceRock.setRotation(SMROTATION);
                     spaceRock.setDY(0.0);
                     spaceRock.setDX(2.0);
                     spaceRocks.push_back(spaceRock);
                     spaceRocks.erase(spaceRocks.begin() + i);
                     score += BIGSCORE;
                     break;
                  }
                  case MEDROCK:
                  {
                     SpaceRock spaceRock = spaceRocks[i];
		             spaceRock.setSize(SMROCK);
		             spaceRock.setRotation(SMROTATION);
		             spaceRock.setPoints(SMPOINTS);
                     spaceRock.setDX(3.0);
                     spaceRocks.push_back(spaceRock);
                     spaceRock.setDY(-3.0);
                     spaceRocks.push_back(spaceRock);
                     spaceRocks.erase(spaceRocks.begin() + i);
                     score += MEDSCORE;
                     break;
                  }
                  case SMROCK:
                  {
                     spaceRocks.erase(spaceRocks.begin() + i);
                     score += SMSCORE;
                     break;
                  }
               }
            }
         }
      }
      //adds additional asteroids if there are less than 4
      if(spaceRocks.size()<4)
      {
         this->createNewAsteroid();
      }

      //What's the matta, those asteroids get ya?
      for (int i = 0; i < spaceRocks.size(); i++)
      {
         if(spaceRocks[i].isHit(spaceShip.getX(), spaceShip.getY()))
         {
            //spaceShip.kill();
;
         }
      }
   
   //you died!
   if (spaceShip.isDead())
   {
      spaceRocks.clear();
      bullets.clear();
   }


      //update debug counter on the lower left side of screen
      refresh++;  //tracks we are doing something

 
}

/*************************************************
 * Asteroid : DRAW
 * Draw the stuff
 ************************************************/
void Game::draw()
{
   //draw the spaceship
   if(!spaceShip.isDead())
      drawShip(spaceShip.getPoint(),spaceShip.getDirection());
   else
   {
      Point dead(-150, 10);
      drawText(dead, "No one can hear you scream in space");
   } 

   //draw the asteroid field
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

   //draw bullets
   for (int i = 0; i < bullets.size(); i++)
   {
      drawDot(bullets[i].getPoint());
   }
      
   //draw the score
   Point pointScoreText(XMIN + 5, YMAX - 50);
   drawText(pointScoreText, "SCORE:");
   Point pointScore(XMIN + 5, YMAX - 20);
   drawNumber(pointScore, score);


//draw refresh
#ifdef DEBUG
   {
      Point pointDebug(frameCount.getXMin() + 5, frameCount.getYMin() + 15);
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
    
   // advance the game
   pGame->update(pUI->isLeft(), pUI->isRight(), pUI-> isUp(), pUI->isSpace());
 
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

