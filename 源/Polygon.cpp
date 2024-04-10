#include "Polygon.h"
void Polyon::Delete()
{
	int* m;
	int* r;
	m = new int[n];
	r = new int[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = a[i].x;
	}
	for (int i = 0; i < n; i++)
	{
		r[i] = a[i].y;
	}
	sort(m, m + n);
	sort(r, r + n);
	int ley = _getch();
	clearrectangle(m[0] - D, r[0] - D - 1, m[n - 1] + D + 1, r[n - 1] + D + 1);

}
Polyon::~Polyon()
{
	delete[]a;
}
Polyon::Polyon(int N)
{
	n = N;
	a = NULL;
}
void Polyon::Coulor()
{
	int R, G, B;
	cout << "请输入色度" << endl;
	cin >> R >> G >> B;
	setlinecolor(RGB(R, G, B));

}
void Polyon::Drawn()
{
	cout << "请输入需要几边形" << endl;
	cin >> n;
	cout << "输入每一个坐标" << endl;
	a = new POINT[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y;
	}
	while (true)
	{
		polygon(a, n);
		FlushBatchDraw();
		if (GetAsyncKeyState(VK_UP))//上键
		{
			for (int i = 0; i < n; i++)
			{
				a[i].y -= 1;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))//下键
		{
			for (int i = 0; i < n; i++)
			{
				a[i].y += 1;
			}
		}
		if (GetAsyncKeyState(VK_LEFT))//左键
		{
			for (int i = 0; i < n; i++)
			{
				a[i].x -= 1;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))//右键
		{
			for (int i = 0; i < n; i++)
			{
				a[i].x += 1;
			}
		}
		int* m;
		int* r;
		m = new int[n];
		r = new int[n];
		for (int i = 0; i < n; i++)
		{
			m[i] = a[i].x;
		}
		for (int i = 0; i < n; i++)
		{
			r[i] = a[i].y;
		}
		sort(m, m + n);
		sort(r, r + n);
		int ley = _getch();
		if (ley == 27)
		{
			break;
		}clearrectangle(m[0] - D, r[0] - D - 1, m[n - 1] + D + 1, r[n - 1] + D + 1);

	}

}
void Polyon::fill()
{
	cout << "0：无边框，1：有边框填充" << endl;
	int b;
	cin >> b;
	switch (b)
	{
	case 0:
		int r, g, b;
		cout << "请输入色度" << endl;
		cin >> r >> g >> b;
		setfillcolor(RGB(r, g, b));
		fillpolygon(a, n);
		break;
	case 1:
		int R, G, B;
		cout << "请输入色度" << endl;
		cin >> R >> G >> B;
		setfillcolor(RGB(R, G, B));
		solidpolygon(a, n);
	}

}

