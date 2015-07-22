/***********************************************************************
* Program:
*    Project 3, Chess            
*    Brother McCracken, CS165
* Author:
*    Jeffry Simpson, Samuel Koontz
* Summary: 
*    spaceRock class header file
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/


#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include <cassert>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include "point.h"

#define deg2rad(value) ((M_PI / 180) * (value))

using namespace std;

/*****************************************
 * Bullet
 * The ship class.  
 * 
 *****************************************/
class Bullet: public Point
{
public:

   Bullet() : speed(0.0) {this->point.setWrap(false);
                          this->point.setCheck(true);}
   
   int getDirection()                  {return direction;}
   float getSpeed()                    {return speed;}
   float getX()                        {return this->point.getX();}
   float getY()                        {return this->point.getY();}
   float getDX()                       {return dx;}
   float getDY()                       {return dy;}
   Point getPoint()                    {return point;}
   bool getIsDead()                    {return this->point.isDead();}
   void setSize(int size)              {this->size = size;}
   void setDX(int dx)                  {this->dx = dx;}
   void setDY(int dy)                  {this->dy = dy;}
   void addDX(float dx)                {this->dx +=dx;}
   void addDY(float dy)                {this->dy +=dy;}
   void setSpeed(float speed)          {this->speed = speed;}
   void addSpeed(float increase)       {this->speed += increase;}
   void setDirection(int direction)    {this->direction = direction;}
   void changeDirection(int direction) {this->direction += direction;}
   void kill()                         {this->point.kill();}
   void setPoint(float x, float y)     {this->point.setX(x);
                                        this->point.setY(y);}
    void updateCourse()
    {

        this->setDX(3 * cos(deg2rad(direction - 180)));
        this->setDY(3 * sin(deg2rad(direction - 180)));
    } 

   void updatePos()
{
      
   this->point.addX(this->dx);
   this->point.addY(this->dy);
}
   
   
   const Bullet & operator = (const Bullet & rhs) 
{
	this->point = rhs.point;
    this->size = rhs.size;
    this->dx = rhs.dx;
    this->dy = rhs.dy;
    this->direction = rhs.direction;
    this->speed = rhs.speed;
    return *this;
}

protected:
    Point point;
    float dx;
    float dy;
    int size;
    int direction;
    float speed;
};




#endif	/* SPACESHIP.H */
