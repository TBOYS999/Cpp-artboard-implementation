#include<iostream>
#include<graphics.h>
#include<fstream>
#include<conio.h>
#include<algorithm>
#include<iomanip>
#include <time.h>
#include <mmsystem.h>   
#include"button.h"
#include"Spot.h"
#include"Line.h"
#include"TwoLine.h"
#include"Circle.h"
#include"Polygon.h"
#include"myRectangle.h"
#include"myEllipse.h"
#pragma comment(lib,"Winmm.lib")//引用静态库
#define MAXSTAR 2000	// 星星总数
using namespace std;
int D;/*使用说明：该画板的操作流程，可以在一开始就选择线的样式，也可以不选择，不选则默认黑实线，该画板的起
始位置为150，50，请根据画板大小和需求画图，由于编者能力有限，图形不可以重叠，但是可以画在一起，不过会遮住
原来的一点部分，画点，线，折线这些无需填充的图形时，操作流程为先输入点的坐标，然后你可以上下移动，移动好了
后，记得按esc键退出，如果你觉得需要进行缩放请按+=，- ——，如果不需要，切记，按esc键退出，退出后可以填充的
图形会让你选择填充等等功能，可以按照提示完成，填充完后，如果觉得不满意可以按backspace删除，如果需要复制，
请改为英文模式后按v键便可，复制后的图形具有移动功能，其余功能可自行探索，感谢您的使用----作者呈上*/
struct STAR
{
	double	x;
	int		y;
	double	step;
	int		color;
};

STAR star[MAXSTAR];

// 初始化星星
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 880;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

// 移动星星
void MoveStar(int i)
{
	// 擦掉原来的星星
	putpixel((int)star[i].x, star[i].y, 5);

	// 计算新位置
	star[i].x += star[i].step;
	if (star[i].x > 1880)	InitStar(i);

	// 画新星星
	putpixel((int)star[i].x, star[i].y, YELLOW);
}

// 主函数
	int main()
	{
		srand((unsigned)time(NULL));	// 随机种子
	initgraph(1880, 830);
	setbkmode(TRANSPARENT);// 创建绘图窗口
	TCHAR s0[50] = "点击开始作画";
	button a;
	a.build(600, 350,200, 80, YELLOW, s0);
	a.drawbutton();
	ExMessage msg1;
	// 初始化所有星星
	for(int i = 0; i < MAXSTAR; i++)
	{
		InitStar(i);
		star[i].x = rand() % 830;
	}

	// 绘制星空，按任意键退出
	while (1)
	{
		for (int i = 0; i < MAXSTAR; i++)
			MoveStar(i);
		Sleep(20);
		if (peekmessage(&msg1, EM_MOUSE) && msg1.message && WM_LBUTTONDOWN&&msg1.x >= 600 && msg1.x <= 600 + 200 && msg1.y >= 350 && msg1.y <= 350 + 80)
		{
			break;
			
		}
	}
	
		initgraph(1880, 830,SHOWCONSOLE);    // 创建绘图窗口，大小为 1880*830像素
		setbkcolor(WHITE);
		setbkmode(TRANSPARENT);
		cleardevice();
		TCHAR s[50] = "音乐";
		TCHAR s1[50] = "点";
		TCHAR s2[50] = "线";
		TCHAR s3[50] = "折线";
		TCHAR s4[50] = "圆";
		TCHAR s5[50] = "椭圆";
		TCHAR s6[50] = "矩形";
		TCHAR s7[50] = "多边形";
		TCHAR s8[50] = "样式和颜色";
		TCHAR s9[50] = "引入图片";
		TCHAR s10[50] = "保存";
		TCHAR s11[50] = "灵魂画笔";
		TCHAR s13[50] = "橡皮擦";
		TCHAR s12[50] = "全清";
		button b[14];
		b[0].build(0, 0, 100, 50,RGB(192,192,192),s);
		b[1].build(100, 0, 100, 50, RGB(192, 192, 192), s1);
		b[2].build(200, 0, 100,50, RGB(192, 192, 192), s2);
		b[3].build(300,0, 100, 50, RGB(192, 192, 192), s3);
		b[4].build(400, 0, 100, 50, RGB(192, 192, 192), s4);
		b[5].build(500, 0, 100, 50, RGB(192, 192, 192), s5);
		b[6].build(600, 0, 100, 50, RGB(192, 192, 192), s6);
		b[7].build(700, 0, 100, 50, RGB(192, 192, 192), s7);
		b[8].build(0, 50, 100, 50, RGB(192, 192, 192), s8);
		b[9].build(0, 100, 100, 50, RGB(192, 192, 192), s9);
		b[10].build(0, 150, 100, 50, RGB(192, 192, 192), s10);
		b[11].build(0, 200, 100, 50, RGB(192, 192, 192), s11);
		b[12].build(0, 250, 100, 50, RGB(192, 192, 192), s13);
		b[13].build(0, 300, 100, 50, RGB(192, 192, 192), s12);
		setlinecolor(BLACK);
		rectangle(100, 50, 1880, 830);
		line(0, 50, 1880, 50);
		line(100, 0, 100, 830);
		ExMessage msg;
		while (true) 
		{
			FlushBatchDraw();
			b[0].drawbutton();
			b[1].drawbutton();
			b[2].drawbutton();
			b[3].drawbutton();
			b[4].drawbutton();
			b[5].drawbutton();
			b[6].drawbutton();
			b[7].drawbutton();
			b[8].drawbutton();
			b[9].drawbutton();
			b[10].drawbutton();
			b[11].drawbutton();
			b[12].drawbutton();
			b[13].drawbutton();//画按钮
			if (peekmessage(&msg, EM_MOUSE)) 
			{

				switch (msg.message)
				{
					case WM_LBUTTONDOWN://按下鼠标左键
					if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{
						cout << "请欣赏" << endl;

						mciSendString("open ./Iamyour.MP3", 0, 0, 0);//将音乐文件放在与源文件同一目录下，alias  music的意思就是将这个音乐文件重新命名为music
						mciSendString("play ./Iamyour.MP3 ", 0, 0, 0);//播放音乐，play意为播放，同样可换做pause:暂停，stop:停止，close:关闭，Resume:继续。Repeat意为重复播放。
						int key = _getch();
						if (key == 32)
						{
							mciSendString("stop ./Iamyour.MP3", 0, 0, 0);
						}//暂停播放音乐。




					}
					if (msg.x >= 100 && msg.x <= 100 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{
						Spot a;
						a.Drawn();

						//在此处写下按钮点击时要执行的函数，实现相应的功能  
					}
					if (msg.x >= 200 && msg.x <= 200 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{

						Line b;
						b.Drawn();
						Line T = b;
						int c;
						c = T.a.x-T.x;
						int bey = _getch();
						if (bey == 118)
						{
							T.x += (c + 10);
							T.a.x += (c + 10);

							while (1)
							{
								
								line(T.x, T.y, T.a.x, T.a.y);
								FlushBatchDraw();
								if (GetAsyncKeyState(VK_UP))//上键
								{
									T.y -= 1;
									T.a.y -= 1;

								}
								if (GetAsyncKeyState(VK_DOWN))//下键
								{
									T.y += 1;
									T.a.y += 1;

								}
								if (GetAsyncKeyState(VK_LEFT))
								{
									T.x -= 1;
									T.a.x -= 1;

								}
								if (GetAsyncKeyState(VK_RIGHT))
								{
									T.x += 1;
									T.a.x += 1;

								}
								int key = _getch();
								if (key == 27)
								{
									break;
								}
								T.Delete();
							}
						}
						if (bey == 8)
						{
							T.Delete();
						}
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					if (msg.x >= 300 && msg.x <= 300 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{
						TwoLine c;
						c.Drawn();
						TwoLine T = c;
						int b;
						b =T.l1.a.x-T.x;
						int bey = _getch();
						if (bey == 118)
						{
							T.x += (b + 10);
							T.a.x += (b + 10);
							T.l1.a.x += (b + 10);

							while (1)
							{

								line(T.x, T.y, T.a.x, T.a.y);
								line(T.a.x, T.a.y, T.l1.a.x, T.l1.a.y);
								FlushBatchDraw();
								if (GetAsyncKeyState(VK_UP))//上键
								{
									T.y -= 1;
									T.a.y -= 1;
									T.l1.a.y -= 1;

								}
								if (GetAsyncKeyState(VK_DOWN))//下键
								{
									T.y += 1;
									T.a.y += 1;
									T.l1.a.y += 1;

								}
								if (GetAsyncKeyState(VK_LEFT))
								{
									T.x -= 1;
									T.a.x -= 1;
									T.l1.a.x -= 1;

								}
								if (GetAsyncKeyState(VK_RIGHT))
								{
									T.x += 1;
									T.a.x += 1;
									T.l1.a.x += 1;

								}
								int key = _getch();
								if (key == 27)
								{
									break;
								}
								int e[3] = { T.x,T.a.x,T.l1.a.x };
								int f[3] = { T.y,T.a.y,T.l1.a.y };
								sort(e, e + 3);
								sort(f, f + 3);
								clearrectangle(e[0] - 1 - D, e[0] - 1 - D, f[2] + 1 + D, f[2] + D + 1);
							}
							
						}
						if (bey == 8)
						{
							T.Delete();
						}

						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					if (msg.x >= 400 && msg.x <= 400 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{
						Circle d;
						d.Drawn();
						cout << "0：填充，1：无需操作" << endl;
						int k;
						cin >> k;
						switch (k)
						{
						case 0:
							d.fill();
							break;
						case 1:
							break;
						}
						Circle T = d;
						int a;
						a = T.R*2;
						int bey = _getch();
						if (bey == 118)
						{
							T.x += (a + 10);
							while (1)
							{
								if (k == 0)
								{
									solidcircle(T.x, T.y, T.R);
								}
								if (k == 1)
								{
									circle(T.x, T.y,T.R);
								}
								FlushBatchDraw();
								if (GetAsyncKeyState(VK_UP))//上键
								{
									T.y -= 1;
									
								}
								if (GetAsyncKeyState(VK_DOWN))//下键
								{
									T.y += 1;
									
								}
								if (GetAsyncKeyState(VK_LEFT))
								{
									T.x -= 1;
									
								}
								if (GetAsyncKeyState(VK_RIGHT))
								{
									T.x += 1;
									
								}
								int key = _getch();
								if (key == 27)
								{
									break;
								}
								clearrectangle(T.x - T.R - 1 - D, T.y - 1 - T.R - D, T.x + T.R + 1 + D, T.y + T.R + D + 1);
							}
						}
						if (bey == 8)
						{
							T.Delete();
						}

						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					if (msg.x >= 500 && msg.x <= 500 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{
						myEllipse e;
						e.Drawn();
						cout << "0：填充，1：无需操作" << endl;
						int k;
						cin >> k;
						switch (k)
						{
						case 0:
							e.fill();
							break;
						case 1:
							break;
						}
						myEllipse T = e;
						int a;
						a = T.t.x - T.x;
						int bey = _getch();
						if (bey == 8)
						{
							T.myEllipse::Delete();
						}
						if (bey == 118)
						{
							T.x += (a + 10);
							T.t.x = T.x + a;
							while (1)
							{
								if (k == 0)
								{
									solidellipse(T.x, T.y, T.t.x, T.t.y);
								}
								if (k == 1)
								{
									ellipse(T.x, T.y, T.t.x, T.t.y);
								}
								FlushBatchDraw();
								if (GetAsyncKeyState(VK_UP))//上键
								{
									T.y -= 1;
									T.t.y -= 1;
								}
								if (GetAsyncKeyState(VK_DOWN))//下键
								{
									T.y += 1;
									T.t.y += 1;
								}
								if (GetAsyncKeyState(VK_LEFT))
								{
									T.x -= 1;
									T.t.x -= 1;
								}
								if (GetAsyncKeyState(VK_RIGHT))
								{
									T.x += 1;
									T.t.x += 1;
								}
								int key = _getch();
								if (key == 27)
								{
									break;
								}
								
									T.myEllipse::Delete();
							}
						
							
						}
					}
				
							if (msg.x >= 600 && msg.x <= 600 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
							{

								myRectangle f;
								f.Drawn();
								cout << "0：填充，1：无需操作" << endl;
								int k;
								cin >> k;
								switch (k)
								{
								case 0:
									f.fill();
									break;
								case 1:
									break;
								}
								myRectangle T = f;
								int a;
								a = T.t.x - T.x;
								int bey = _getch();
								if (bey == 8)
								{
									T.myRectangle::Delete();
								}
								if (bey == 118)
								{
									T.x += (a + 10);
									T.t.x = T.x + a;

									while (1)
									{
										if (k == 0)
										{
											fillrectangle(T.x, T.y, T.t.x, T.t.y);
										}
										if (k == 1)
										{
											rectangle(T.x, T.y, T.t.x, T.t.y);
										}
										FlushBatchDraw();
										if (GetAsyncKeyState(VK_UP))//上键
										{
											T.y -= 1;
											T.t.y -= 1;
										}
										if (GetAsyncKeyState(VK_DOWN))//下键
										{
											T.y += 1;
											T.t.y += 1;
										}
										if (GetAsyncKeyState(VK_LEFT))
										{
											T.x -= 1;
											T.t.x -= 1;
										}
										if (GetAsyncKeyState(VK_RIGHT))
										{
											T.x += 1;
											T.t.x += 1;
										}
										int key = _getch();
										if (key == 27)
										{
											break;
										}
										clearrectangle(T.x - 1 - D, T.y - 1 - D, T.t.x + 1 + D, T.t.y + 1 + D);

										int ley = _getch();
										if (ley == 27)
										{
											break;
										}
									}

									
								}
								

								//在此处写下按钮点击时要执行的函数，实现相应的功能
							}
							if (msg.x >= 700 && msg.x <= 700 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
							{
								Polyon g;
								g.Drawn();
								cout << "0：填充，1：无需操作" << endl;
								int k;
								cin >> k;
								switch (k)
								{
								case 0:
									g.fill();
									break;
								case 1:
									break;
								}
							   Polyon T = g;
							   int* c;
							   c = new int[T.n];
							   for (int i = 0; i < T.n; i++)
							   {
								   c[i] = T.a[i].x;
							   }
							   sort(c, c + T.n);
								int b;
								b = c[T.n - 1] - c[0];
								int bey = _getch();
								if (bey == 8)
								{
									T.Polyon::Delete();
								}
								if (bey == 118)
								{
									for (int i = 0; i < T.n; i++)
									{
										T.a[i].x += b;
									}

									while (1)
									{
										if (k == 0)
										{
											fillpolygon(T.a, T.n);
										}
										if (k == 1)
										{
											polygon(T.a, T.n);
										}
										FlushBatchDraw();
										if (GetAsyncKeyState(VK_UP))//上键
										{
											for (int i = 0; i < T.n; i++)
											{
												T.a[i].y -= 1;
											}
										}
										if (GetAsyncKeyState(VK_DOWN))//下键
										{
											for (int i = 0; i < T.n; i++)
											{
												T.a[i].y += 1;
											}
										}
										if (GetAsyncKeyState(VK_LEFT))
										{
											for (int i = 0; i < T.n; i++)
											{
												T.a[i].x -= 1;
											}
										}
										if (GetAsyncKeyState(VK_RIGHT))
										{
											for (int i = 0; i < T.n; i++)
											{
												T.a[i].x += 1;
											}
										}
										int* m;
										int* r;
										m = new int[T.n];
										r = new int[T.n];
										for (int i = 0; i < T.n; i++)
										{
											m[i] = T.a[i].x;
										}
										for (int i = 0; i < T.n; i++)
										{
											r[i] = T.a[i].y;
										}
										sort(m, m + T.n);
										sort(r, r + T.n);
										int ley = _getch();
										if (ley == 27)
										{
											break;
										}clearrectangle(m[0] - D-1, r[0] - D - 1, m[T.n - 1] + D + 1, r[T.n - 1] + D + 1);

									}
								}
								
								delete[]c;

								//在此处写下按钮点击时要执行的函数，实现相应的功能
							}
							if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 50 && msg.y <= 50 + 50)
							{
								int c;
								cout << "请输入你要选择的线的种类：0.实线 1：----- 2 ：....... 3:-.-.-.-.-和粗细大小" << endl;
								cin >> c >> D;
								setlinestyle(c, D);
								int R, G, B;
								cout << "请输入色度" << endl;
								cin >> R >> G >> B;
								setlinecolor(RGB(R, G, B));


								//在此处写下按钮点击时要执行的函数，实现相应的功能
							}
							if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 100 && msg.y <= 100 + 50)
							{

								IMAGE img;
								int c = 300; int d = 300;
								int a =220, b = 220; loadimage(&img, "C:\\Users\\DELL\\Pictures\\证书\\111.jpg", c, d, true);
								while (true)
								{
									
									putimage(a, b, &img);
									if (GetAsyncKeyState(VK_UP))//上键
									{
										b -= 1;
									}
									if (GetAsyncKeyState(VK_DOWN))//下键
									{
										b += 1;
									}
									if (GetAsyncKeyState(VK_LEFT))
									{
										a -= 1;
									}
									if (GetAsyncKeyState(VK_RIGHT))
									{
										a += 1;
									}
									int key = _getche();
									if (key == 27)
									{
										break;
									}FlushBatchDraw();//防止屏幕闪；
									clearrectangle(a-2, b-2, a + c+2, b + d+2);
								}
									while(true)
									{
										loadimage(&img, "C:\\Users\\DELL\\Pictures\\证书\\1111.jpg", c, d, true);
										putimage(a, b, &img);
										int key = _getche();
									if (key == 61)
									{
										c += 5;
										d += 5;
									}
									else if (key == 45)
									{
										FlushBatchDraw();
										clearrectangle(a, b, a + c,b + d);
										c -= 5;
										d -= 5;
									}
									if(key==27)
									{
										break;
									}
						

								    }
									int bey = _getche();
									if (bey == 8)
									{
										clearrectangle(a, b, a + c, b + d);
									}
								//在此处写下按钮点击时要执行的函数，实现相应的功能*/
							}
							if (msg.x >= 0 && msg.x <= 100 && msg.y >= 150 && msg.y <= 150 + 50)
							{
								cout << "shanb1" << endl;
								saveimage("D:\\UJS housework\\house work\\课设\\课设\\Rhoto.bmp");
								//在此处写下按钮点击时要执行的函数，实现相应的功能
							}
							if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 200 && msg.y <= 200 + 50)
							{
								int x = 250; int y = 250; int R = 10;
								setfillcolor(RGB(255,255,255));
								while (1)
								{
									circle(x, y, R);
									FlushBatchDraw();
									if (GetAsyncKeyState(VK_UP))//上键
									{
										y -= 3;

									}
									if (GetAsyncKeyState(VK_DOWN))//下键
									{
										y += 3;

									}
									if (GetAsyncKeyState(VK_LEFT))//左键
									{
										x -= 3;

									}
									if (GetAsyncKeyState(VK_RIGHT))//右键
									{
										x += 3;

									}
									int key = _getch();
									if (key == 27)
									{
										clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
										break;
									}
									clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
								}
								//本功能实现比较简陋，使用的方法是将绘图颜色调回和背景板颜色一样
		//接着将绘图函数的画线的粗细参数调大一些


								//在此处写下按钮点击时要执行的函数，实现相应的功能
							}
							
							if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 250 && msg.y <= 250 + 50)
							{
								int x = 250; int y = 250; int R = 10;
								setfillcolor(RGB(255, 255, 255));
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
										clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
										break;
									}
									clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
								}
								//在此处写下按钮点击时要执行的函数，实现相应的功能
							}if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 300 && msg.y <= 300 + 50)
							{
								clearrectangle(100, 50, 1880, 830);
								//在此处写下按钮点击时要执行的函数，实现相应的功能
							}

							break;
						default:
							break;
				}
			}

		}


				return 0;
	}