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


#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "point.h"

#define deg2rad(value) ((M_PI / 180) * (value))

using namespace std;

/*****************************************
 * SHIP
 * The ship class.  
 * 
 *****************************************/
class SpaceShip: public Point
{
public:

   SpaceShip() : speed(0.0) {}
   
   int getDirection() {return direction;}
   int getHeading() {return heading;}
   float getSpeed() {return speed;}
   int getDX() {return dx;}
   int getDY() {return dy;}
   Point getPoint() {return point;}
   void setSize(int size) {this->size = size;}
   void setDX(int dx) {this->dx = dx;}
   void setDY(int dy) {this->dy = dy;}
   void addDX(float dx) {this->dx +=dx;}
   void addDY(float dy) {this->dy +=dy;}
   void setSpeed(float speed) {this->speed = speed;}
   void addSpeed(float increase) {this->speed += increase;}
   void setDirection(int direction) {this->direction = direction;}
   void changeDirection(int direction) {this->direction += direction;}
   void setHeading(int heading) {this->heading = heading;}
   void changeHeading(int change) {this->heading += change;} 
   void setPoint(float x, float y) {point.setX(x);
                                    point.setY(y);}
   void updateCourse()
{
   this->addDX(0*speed);
   this->addDY((1)*speed);  
} 

   void updatePos()
{
      
   this->point.addX(this->dx);
   this->point.addY(this->dy);
}
   const SpaceShip & operator = (const SpaceShip & rhs) //   const Point & operator = (const Point & rhs);
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
    int heading;
	float speed;
};




#endif	/* SPACESHIP.H */
