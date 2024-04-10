#pragma once
#include "Spot.h"
#include<iostream>
#include<graphics.h>
#include<fstream>
#include<conio.h>
#include<algorithm>
#include<iomanip>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")//ÒýÓÃ¾²Ì¬¿â
using namespace std;
extern int D;
class myRectangle :public Spot
{
public:
	Spot t;
public:
	myRectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Coulor();
	void Drawn();
	void Delete();
	void fill();
	myRectangle(const myRectangle& t1)
	{
		this->x = t1.x;
		this->y = t1.y;
		this->t = t1.t;
	}


};
