#pragma once
#include<iostream>
#include<graphics.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include <mmsystem.h> 
using namespace std;
extern int D;
class Spot
{
	public:
		int x;
		int y;
	public:
		Spot(int X = 0, int Y = 0)
		{
			x = X;
			y = Y;
		}virtual void Coulor()
		{

		}
		virtual void Drawn()
		{
			cout << "请输入坐标x,y" << endl;
		cin >> x >> y;putpixel(x, y, RED);
		}
		virtual void Delete()
		{

		}
		Spot(const Spot& t2)
		{
			
				this->x = t2.x;
				this->y = t2.y;
			
		}
	};
	/*void Spot::Drawn()
	{
		//cout << "请输入坐标x,y" << endl;
		//cin >> x >> y;
		ExMessage m;
		m = getmessage();
		if (m.message == WM_RBUTTONDOWN)
		{
			x = m.x;
			y = m.y;
			is_Down = false;
			cout << x << " " << y << endl;
		}
		m = getmessage();
		if (m.message == WM_RBUTTONUP)
		{
			is_Down = true;
			cout << x << " " << y << endl;
		}


		putpixel(x, y, RED);
	}*/

