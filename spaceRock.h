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


#ifndef SPACEROCK_H
#define SPACEROCK_H
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "point.h"

#define deg2rad(value) ((M_PI / 180) * (value))

using namespace std;

/*****************************************
 * SPACEROCK
 * The spaceRock class.  
 * 
 *****************************************/
class SpaceRock: public Point
{
public:

   SpaceRock() : size(1) {this->point.setCheck(true);}
   int getSize()                    {return size;}
   int getDirection()               {return direction;}
   int getSpeed()                   {return speed;}
   int getRotation()                {return rotation;}
   float getX()                     {return this->point.getX();}
   float getY()                     {return this->point.getY();}
   float getDX()                    {return dx;}
   float getDY()                    {return dy;}
   Point getPoint()                 {return point;}
   int getPoints()                  {return points;}
   int getTotalRotation()           {return totalRotation;}
   void setSize(int size)           {this->size = size;}
   void setDX(float dx)             {this->dx = dx;}
   void setDY(float dy)             {this->dy = dy;}
   void addDX(float dx)             {this->dx +=dx;}
   void addDY(float dy)             {this->dy +=dy;}
   void setSpeed(int speed)         {this->speed = speed;}
   void setRotation(int rotation)   {this->rotation = rotation;}
   void setDirection(int direction) {this->direction = direction;}
   void setPoint(float x, float y)  {point.setX(x);
                                     point.setY(y);}
   void setPoints (int points)      {this->points = points;}
   void setTotalRotation(int r)     {this->totalRotation = r;}
   void updatePos()
{   
   this->point.addX((sin(deg2rad(direction))*speed) + dx);
   this->point.addY((cos(deg2rad(direction))*speed) + dy);
   this->totalRotation += this->rotation; 
}
   const SpaceRock & operator = (const SpaceRock & rhs) //   const Point & operator = (const Point & rhs);
{
	this->point = rhs.point;
    this->size = rhs.size;
    this->dx = rhs.dx;
    this->dy = rhs.dy;
    this->points = rhs.points;
    this->direction = rhs.direction;
    this->speed = rhs.speed;
    this->rotation = rhs.rotation;
    this->totalRotation = rhs.totalRotation;
    return *this;
}

   bool isHit(float x2, float y2)
{
   bool hit;
   float distance;
   float x1 = this->getX();
   float y1 = this->getY();
   distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
   if (distance <= (this->getSize() / 2))
      return true;
}
protected:
	Point point;
    float dx;
    float dy;
	int size;
    int points;
	int direction;
	int speed;
    int rotation;
    int totalRotation;


};




#endif	/* SPACEROCK.H */
