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

class Circle :public Spot
{
public:
	int R;
public:
	Circle(int x1 = 0, int y1 = 0, int r = 0);
	void Coulor();
	void Drawn();
	void Delete();
	void fill();
	Circle(const Circle& t2)
	{
		this->x = t2.x;
		this->y = t2.y;
		this->R = t2.R;
	}

};
