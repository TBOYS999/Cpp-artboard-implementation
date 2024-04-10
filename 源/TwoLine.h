#pragma once
#include "Line.h"
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
class TwoLine :public Line
{
public:
	Line l1;
public:
	TwoLine(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x3 = 0, int y3 = 0);
	void Coulor();
	void Drawn();
	void Delete();
	TwoLine(const TwoLine& t2)
	{
		this->l1 = t2.l1;
		this->x = t2.x;
		this->y = t2.y;
		this->a = t2.a;
	}

};
