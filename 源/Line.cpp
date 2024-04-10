#include "Line.h"
Line::Line(int x1, int y1, int x2, int y2) :Spot(x1, y1), a(x2, y2)
{

}
void Line::Coulor()
{
	int R, G, B;
	cout << "请输入色度" << endl;
	cin >> R >> G >> B;
	setlinecolor(RGB(R, G, B));
}
void Line::Drawn()
{
	cout << "请输入坐标x,y,x1,y1" << endl;
	cin >> x >> y >> a.x >> a.y;
	while (1)
	{
		line(this->x, this->y, a.x, a.y);

		FlushBatchDraw();
		if (GetAsyncKeyState(VK_UP))//上键
		{
			y -= 1;
			a.y -= 1;

		}
		if (GetAsyncKeyState(VK_DOWN))//下键
		{
			y += 1;
			a.y += 1;

		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			x -= 1;
			a.x -= 1;

		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			x += 1;
			a.x += 1;

		}
		int key = _getch();
		if (key == 27)
		{
			break;
		}
		int c[2] = { x,a.x };
		int d[2] = { y,a.y };
		sort(c, c + 2);
		sort(d, d + 2);
		clearrectangle(c[0] - D - 1, d[0] - D - 1, c[1] + 1 + D, d[1] + 1 + D);
	}
	while (true)
	{
		int c[2] = { x,a.x };
		int d[2] = { y,a.y };
		sort(c, c + 2);
		sort(d, d + 2);
		int key = _getch();
		if (key == 61)
		{
			if (x < a.x)
			{
				x -= 5;
				a.x += 5;
			}
			else
			{
				x += 5;
				a.x -= 5;
			}
			if (y < a.y)
			{
				y -= 5;
				a.y += 5;
			}
			else
			{
				y += 5;
				a.y -= 5;
			}
			clearrectangle(c[0] - D - 1, d[0] - D - 1, c[1] + 1 + D, d[1] + 1 + D);
		}
		else if (key == 45)
		{
			FlushBatchDraw();
			clearrectangle(c[0] - D - 1, d[0] - D - 1, c[1] + 1 + D, d[1] + 1 + D);
			if (x < a.x)
			{
				x += 5;
				a.x -= 5;
			}
			else
			{
				x -= 5;
				a.x += 5;
			}
			if (y < a.y)
			{
				y += 5;
				a.y -= 5;
			}
			else
			{
				y -= 5;
				a.y += 5;
			}
		}

		if (key == 27)
		{
			break;
		}
		line(x, y, a.x, a.y);

	}
}

void Line::Delete()
{
	int c[2] = { x,a.x };
	int d[2] = { y,a.y };
	sort(c, c + 2);
	sort(d, d + 2);
	clearrectangle(c[0] - D - 1, d[0] - D - 1, c[1] + 1 + D, d[1] + 1 + D);

}
