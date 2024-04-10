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
class Line :public Spot
{
public:
	Spot a;
public:
	Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Coulor();
	void Drawn();
	void Delete();
	Line(const Line& t2)
	{
		this->x = t2.x;
		this->y = t2.y;
		this->a = t2.a;
	}

};


