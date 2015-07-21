/***********************************************************************
* Program:
*    Project 4, Asteroids
*    Brother McCracken, CS165
* Author:
*    Jeffry Simpson, Sam Koontz 
* Summary: 
*    This driver program will help us test the spaceRock classes
************************************************************************/

#include <iostream>
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include <stdio.h>
#include <math.h>
#include "spaceRock.h"
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

float Point::xMin = XMIN;
float Point::xMax =  XMAX;
float Point::yMin = YMIN;
float Point::yMax =  YMAX;

int getRand(int min, int max)
{
   return (rand() % (max-min+1)+min);
}

int getRand(double min, double max)
{
	return (int)(rand() % ((int)max - (int)min + 1) + (int)min);
}

int main()
{
	srand(time(NULL));
	vector <SpaceRock> spaceRocks;
	//set up initial
    for (int i = 0; i < 4; i++)
	{
				
		SpaceRock spaceRock;
		spaceRock.setSize(BIGROCK);
		spaceRock.setRotation(BIGROTATION);
		spaceRock.setSpeed(getRand(STARTSPEEDMIN,STARTSPEEDMAX));


		if (getRand(0,1))
			spaceRock.setX(XMAX);
		else
			spaceRock.setX(XMIN);
		spaceRock.setY(getRand(YMIN, YMAX));
		if ((spaceRock.getX() >= XAVG) && (spaceRock.getY() >= YAVG)) //1st quadrant, needs to go down and left
			spaceRock.setDirection(getRand(180,270));
		else if (spaceRock.getX() < XAVG && spaceRock.getY() >= YAVG) //2nd quadrant, needs to go down and right
			spaceRock.setDirection(getRand(270, 364));
		else if (spaceRock.getX() < XAVG && spaceRock.getY() < YAVG) //3rd quadrant, needs to go up and right
			spaceRock.setDirection(getRand(0,90));
		else //4th quadrant, needs to go up and left
			spaceRock.setDirection(getRand(90, 180));

		spaceRocks.push_back(spaceRock);
	}
	char x = 'a';
	while (x != 'q')
	{
		cout << "a-add\nd-delete";
        cin >> x;		
		switch (x)
		{
			case 'a':
			{
				SpaceRock spaceRock;
				spaceRock.setSize(MEDROCK);	
				spaceRock.setRotation(MEDROTATION);			
				spaceRocks.push_back(spaceRock);
				break;
			}
			case 'd':
			{
				cout << "which: ";
				int i;
				cin >> i;
				spaceRocks.erase(spaceRocks.begin() + i);
				break;
			}
		}
	
cout << "XAVG: " << XAVG << " YAVG: " << YAVG << endl;

		for (int i = 0; i < spaceRocks.size(); i++)
		{
			cout << "rock " << i
       	         << ": Size: " << spaceRocks[i].getSize() 
                 << " Position: (" << spaceRocks[i].getX() 
                 <<"," << spaceRocks[i].getY() 
                 << ") Direction: " <<spaceRocks[i].getDirection() 
                 << " Speed: " << spaceRocks[i].getSpeed()
                 << " Rotation: " <<spaceRocks[i].getRotation()
                 << endl;
		}
	}


return 0;
}
