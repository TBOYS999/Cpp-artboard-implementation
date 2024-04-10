#pragma once
#include"Spot.h"
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
class myEllipse :public Spot
{
public:
	Spot t;
public:
	myEllipse(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	myEllipse(const myEllipse& t1);
	void Coulor();
	void Drawn();
	void Delete();
	void fill();


};

