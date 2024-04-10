#include "myEllipse.h"
myEllipse::myEllipse(const myEllipse& t1)
{
	this->x = t1.x;
	this->y = t1.y;
	this->t = t1.t;
}
myEllipse::myEllipse(int x1, int y1, int x2, int y2) :Spot(x1, y1), t(x2, y2)
{
}
void myEllipse::Coulor()
{
	int R, G, B;
	cout << "请输入色度" << endl;
	cin >> R >> G >> B;
	setlinecolor(RGB(R, G, B));
}
void myEllipse::Drawn()
{
	cout << "请输入左上角坐标x1,y1,右上角坐标x2,y2" << endl;
	cin >> x >> y >> t.x >> t.y;

	while (1)
	{

		ellipse(x, y, t.x, t.y);
		FlushBatchDraw();
		if (GetAsyncKeyState(VK_UP))//上键
		{
			y -= 1;
			t.y -= 1;
		}
		if (GetAsyncKeyState(VK_DOWN))//下键
		{
			y += 1;
			t.y += 1;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			x -= 1;
			t.x -= 1;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			x += 1;
			t.x += 1;
		}
		int key = _getch();
		if (key == 27)
		{
			break;
		}
		int c[2] = { x,t.x };
		int d[2] = { y,t.y };
		sort(c, c + 2);
		sort(d, d + 2);
		clearrectangle(c[0] - D - 1, d[0] - D - 1, c[1] + 1 + D, d[1] + 1 + D);
	}
	while (true)
	{
		int key = _getche();
		if (key == 61)
		{
			x -= 5;
			y -= 5;
			t.x += 5;
			t.y += 5;
			int c[2] = { x,t.x };
			int d[2] = { y,t.y };
			sort(c, c + 2);
			sort(d, d + 2);
			clearrectangle(c[0] - D - 1, d[0] - D - 1, c[1] + 1 + D, d[1] + 1 + D);
		}
		else if (key == 45)
		{
			FlushBatchDraw();
			int c[2] = { x,t.x };
			int d[2] = { y,t.y };
			sort(c, c + 2);
			sort(d, d + 2);
			clearrectangle(c[0] - D - 2, d[0] - D - 2, c[1] + 2 + D, d[1] + 2 + D);
			x += 5;
			y += 5;
			t.x -= 5;
			t.y -= 5;

		}

		if (key == 27)
		{
			break;
		}
		ellipse(x, y, t.x, t.y);



	}

}
void  myEllipse::fill()
{
	cout << "0：无边框，1：有边框填充" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 0:
		int r, g, b;
		cout << "请输入色度" << endl;
		cin >> r >> g >> b;
		setfillcolor(RGB(r, g, b));
		fillellipse(x, y, t.x, t.y);
		break;
	case 1:
		int R, G, B;
		cout << "请输入色度" << endl;
		cin >> R >> G >> B;
		setfillcolor(RGB(R, G, B));
		solidellipse(x, y, t.x, t.y);
		break;


	}
}
void  myEllipse::Delete()
{
	int c[2] = { x,t.x };
	int d[2] = { y,t.y };
	sort(c, c + 2);
	sort(d, d + 2);
	clearrectangle(c[0] - D - 1, d[0] - D - 1, c[1] + 1 + D, d[1] + 1 + D);
}


