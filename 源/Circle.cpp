#include "Circle.h"
Circle::Circle(int x1, int y1, int r) :Spot(x1, y1)
{
	R = r;
}
void Circle::Coulor()
{
	int R, G, B;
	cout << "请输入色度" << endl;
	cin >> R >> G >> B;
	setlinecolor(RGB(R, G, B));

}
void Circle::Drawn()
{
	cout << "请输入坐标x,y,半径r" << endl;
	cin >> x >> y >> R;


	while (1)
	{
		circle(x, y, R);
		FlushBatchDraw();
		if (GetAsyncKeyState(VK_UP))//上键
		{
			y -= 1;

		}
		if (GetAsyncKeyState(VK_DOWN))//下键
		{
			y += 1;

		}
		if (GetAsyncKeyState(VK_LEFT))//左键
		{
			x -= 1;

		}
		if (GetAsyncKeyState(VK_RIGHT))//右键
		{
			x += 1;

		}
		int key = _getch();
		if (key == 27)
		{
			break;
		}
		clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
	}
	while (true)
	{
		int key = _getch();
		if (key == 61)//按+=键放大
		{
			R += 5;
			clearrectangle(x - R - D, y - R - D, x + R + D, y + R + D);
		}
		else if (key == 45)//按-，——键缩小
		{
			FlushBatchDraw();
			clearrectangle(x - R - D, y - R - D, x + R + D, y + R + D);
			R -= 5;
		}
		if (key == 27)//按esc键退出
		{
			break;
		}
		circle(x, y, R);
	}
}
void Circle::fill()
{
	cout << "0：无边框，1：有边框填充" << endl;//选择填充样式
	int a;
	cin >> a;
	int key = _getch();
	switch (a)
	{
	case 0:
		int r, g, b;
		cout << "请输入色度" << endl;
		cin >> r >> g >> b;
		setfillcolor(RGB(r, g, b));
		fillcircle(x, y, R);
		
		break;
	case 1:
		int a, c, d;
		cout << "请输入色度" << endl;
		cin >> a >> c >> d;
		setfillcolor(RGB(a, c, d));
		solidcircle(x, y, R);
		
		break;


	}
}
void Circle::Delete()
{
	clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
}

