#pragma once
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
class Polyon
{
public:
	int n;
	POINT* a;
public:
	Polyon(int N = 3);
	void Coulor();
	void Drawn();
	void fill();
	void Delete();
	~Polyon();
	Polyon(const Polyon& t2)
	{
		this->n = t2.n;
		this->a = t2.a;
	}

};
