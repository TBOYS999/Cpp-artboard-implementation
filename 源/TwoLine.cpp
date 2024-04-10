#include "TwoLine.h"
TwoLine::TwoLine(int x1, int y1, int x2, int y2, int x3, int y3) :Line(x1, y1, x2, y2), l1(x2, y2, x3, y3)
{
	cout << "请输入坐标x,y,x1,y1,x3,y3" << endl;
	cin >> x >> y >> a.x >> a.y >> l1.a.x >> l1.a.y;
	while (1)
	{
		line(this->x, this->y, a.x, a.y);
		line(a.x, a.y, l1.a.x, l1.a.y);
		FlushBatchDraw();
		if (GetAsyncKeyState(VK_UP))//上键
		{
			y -= 1;
			a.y -= 1;
			l1.a.y -= 1;

		}
		if (GetAsyncKeyState(VK_DOWN))//下键
		{
			y += 1;
			a.y += 1;
			l1.a.y += 1;

		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			x -= 1;
			a.x -= 1;
			l1.a.x -= 1;

		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			x += 1;
			a.x += 1;
			l1.a.x += 1;

		}
		int key = _getch();
		if (key == 27)
		{
			break;
		}
		int b[3] = { x,a.x,l1.a.x };
		int c[3] = { y,a.y,l1.a.y };
		sort(b, b + 3);
		sort(c, c + 3);
		clearrectangle(b[0] - 1 - D, c[0] - 1 - D, b[2] + 1 + D, c[2] + 1 + D);
	}
	while (true)
	{
		double k1, k2;
		double x3 = (double)(a.y - y), x4 = (double)(a.x - x), x5 = (double)(a.y - l1.a.y), x6 = (double)(a.x - l1.a.x);
		k1 = 1.0 * x3 / x4;
		k2 = 1.0 * x5 / x6;
		int b[3] = { x,a.x,l1.a.x };
		int c[3] = { y,a.y,l1.a.y };
		sort(b, b + 3);
		sort(c, c + 3);
		int key = _getch();
		if (key == 61)
		{
			clearrectangle(b[0] - 1 - D, c[0] - 1 - D, b[2] + 1 + D, c[2] + 1 + D);
			if (x < a.x)
			{
				x -= 5;
			}
			else
			{
				x += 5;
			}
			if (y < a.y)
			{
				y -= 5 * fabs(k1);
			}
			else
			{
				y += 5 * fabs(k1);
			}
			if (l1.a.x < a.x)
			{
				l1.a.x -= 5;
			}
			else
			{
				l1.a.x += 5;
			}
			if (l1.a.y < a.y)
			{
				l1.a.y -= 5 * fabs(k2);
			}
			else
			{
				l1.a.y += 5 * fabs(k2);
			}
		}

		else if (key == 45)
		{
			FlushBatchDraw();
			clearrectangle(b[0] - 1 - D, c[0] - 1 - D, b[2] + 1 + D, c[2] + 1 + D);
			if (x > a.x)
			{
				x -= 5;
			}
			else
			{
				x += 5;
			}
			if (y > a.y)
			{
				y -= 5 * fabs(k1);
			}
			else
			{
				y += 5 * fabs(k1);
			}
			if (l1.a.x > a.x)
			{
				l1.a.x -= 5;
			}
			else
			{
				l1.a.x += 5;
			}
			if (l1.a.y > a.y)
			{
				l1.a.y -= 5 * fabs(k2);
			}
			else
			{
				l1.a.y += 5 * fabs(k2);
			}
		}line(this->x, this->y, a.x, a.y);
		line(a.x, a.y, l1.a.x, l1.a.y);
		if (key == 27)
		{
			break;
		}

	}

}
void TwoLine::Coulor()
{
	Line::Coulor();
}
void TwoLine::Drawn()
{

}
void TwoLine::Delete()
{
	int b[3] = { x,a.x,l1.a.x };
	int c[3] = { y,a.y,l1.a.y };
	sort(b, b + 3);
	sort(c, c + 3);
	clearrectangle(b[0] - 1 - D, c[0] - 1 - D, b[2] + 1 + D, c[2] + 1 + D);
}


