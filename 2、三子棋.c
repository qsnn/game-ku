#include"ku.h"




void szqversion();//版本号
void szqmenu(char qizi[9], int data[9]);//菜单
void szqgame(char qizi[9], int data[9]);//游戏主体
int szqman(char qizi[9], int data[9]);//人下棋
int szqmachine(char qizi[9], int data[9]);//机器下棋
void szqdesktop(char qizi[9]);//棋盘局面
int szqcheck(int data[9]);//检查胜负平结果


//三子棋主入口---------------------------****-------------------------------------
int mainszq()
{
	system("cls");
	printf("正在初始化三子棋游戏");
	for (int i = 1; i <= 6; i++)
	{
		Sleep(200);
		printf(".");
	}
	Sleep(800);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
	Sleep(100);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	SetConsoleTextAttribute(hConsole, color);
	char qizi[9] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
	int data[9] = { 9,9,9,9,9,9,9,9,9 };
	szqmenu(qizi, data);
	return 2666;
}
//三子棋主入口---------------------------****-------------------------------------



//版本
void szqversion()
{
	printf("1.0：三子棋游戏上新，快来体验！！！\n");
}


//菜单
void szqmenu(char qizi[9], int data[9])
{
	while(1)
	{
		system("cls");
		printf("版权所有：qsnn\n版本：1.0\n");
		printf(" ________________________ \n");
		printf("||----------------------||\n");
		printf("||        三子棋        ||\n");
		printf("||______________________||\n");
		printf(" ------------------------ \n");
		printf("\n请输入数字来确定游戏是否要开始:\n");
		printf("数字1 *> 开始\n");
		printf("数字2 *> 结束\n");
		printf("数字3 *> 查看更新日志\n");
		printf(" *>");
		char choose1[100];
		scanf("%s", &choose1);

		if (strcmp(choose1, "1") == 0)
		{
			szqgame(qizi, data);
		}
		else if (strcmp(choose1, "2") == 0)
		{
			printf("\n真遗憾,后面很好玩呢\n");
			system("pause");
			break;
		}
		else if (strcmp(choose1, "3") == 0)
		{
			system("cls");
			szqversion();
		}
		else
		{
			printf("请输入正确的数字\n1秒后重来！");
			Sleep(1000);
		}
	}

}


//游戏主体
void szqgame(char qizi[9], int data[9])
{
	printf("下面是初始棋盘，下棋时输入两个值，用逗号隔开\n数值为所下棋子的坐标，第一个坐标是(0，0)\n");
	szqdesktop(qizi, data);
	for (int i = 0; i < 9; i++)
	{
		int decide;
		if (i % 2 == 0)
		{
			decide = szqman(qizi, data);
		}
		else if (i % 2 == 1)
		{
			decide = szqmachine(qizi, data);
		}
		//下面是检查结果
		if ((decide == 200)||(decide == 201))
		{
			break;
		}
	}
	if (!((data[0] == 0 && data[1] == 0 && data[2] == 0) ||
		(data[3] == 0 && data[4] == 0 && data[5] == 0) ||
		(data[6] == 0 && data[7] == 0 && data[8] == 0) ||
		(data[0] == 0 && data[3] == 0 && data[6] == 0) ||
		(data[1] == 0 && data[4] == 0 && data[7] == 0) ||
		(data[2] == 0 && data[5] == 0 && data[8] == 0) ||
		(data[0] == 0 && data[4] == 0 && data[8] == 0) ||
		(data[2] == 0 && data[4] == 0 && data[6] == 0) ||
		(data[0] == 1 && data[1] == 1 && data[2] == 1) ||
		(data[3] == 1 && data[4] == 1 && data[5] == 1) ||
		(data[6] == 1 && data[7] == 1 && data[8] == 1) ||
		(data[0] == 1 && data[3] == 1 && data[6] == 1) ||
		(data[1] == 1 && data[4] == 1 && data[7] == 1) ||
		(data[2] == 1 && data[5] == 1 && data[8] == 1) ||
		(data[0] == 1 && data[4] == 1 && data[8] == 1) ||
		(data[2] == 1 && data[4] == 1 && data[6] == 1))
		)
	{
		printf("这是一次和平的棋局！");
	}

	//数组初始化

	for (int i = 0; i < 9; i++)
	{
		qizi[i] = ' ';
		data[i] = 9;
	}
	system("pause");
}


//人下棋
int szqman(char qizi[9], int data[9])
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
	printf("请输入你下棋的坐标(0,0)-(2,2)\n");
	while (1)
	{
		int x, y;
		scanf("%d,%d", &x, &y);
		if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
		{
			int format = x + 3 * y;
			if (qizi[format] == ' ')
			{
				qizi[format] = '*';
				data[format] = 1;
				break;
			}
			else
			{
				printf("不能把棋下在已经被填充的位置!\n");
			}
		}
		else
		{
			printf("请输入正确的坐标!\n");
		}
	}
	szqdesktop(qizi, data);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	int temp = szqcheck(data);
	return temp;
}


//机器下棋
int szqmachine(char qizi[9], int data[9])
{
	srand(time(NULL));
	while(1)

	{
		int x = rand() % 3;
		int y = rand() % 3;
		int format = x + 3 * y;
		if (qizi[format] == ' ')
		{
			qizi[format] = 'o';
			data[format] = 0;
			break;
		}
	}
	printf("机器人思考中\n");
	for (int i = 1; i <= 6; i++)
	{
		Sleep(200);
		printf(".");
	}
	printf("\n");
	szqdesktop(qizi, data);
	int temp = szqcheck(data);
	return temp;
}


//棋盘局面
void szqdesktop(char qizi[9])
{
	printf(" __________________\n");
	printf("|  %c  |  %c  |  %c  |\n", qizi[0], qizi[1], qizi[2]);
	printf("|_____|_____|_____|\n");
	printf("|  %c  |  %c  |  %c  |\n", qizi[3], qizi[4], qizi[5]);
	printf("|_____|_____|_____|\n");
	printf("|  %c  |  %c  |  %c  |\n", qizi[6], qizi[7], qizi[8]);
	printf("|_____|_____|_____|\n");
}


//检查结果
int szqcheck(int data[9])
{
	if ((data[0] == 0 && data[1] == 0 && data[2] == 0) ||
		(data[3] == 0 && data[4] == 0 && data[5] == 0) ||
		(data[6] == 0 && data[7] == 0 && data[8] == 0) ||
		(data[0] == 0 && data[3] == 0 && data[6] == 0) ||
		(data[1] == 0 && data[4] == 0 && data[7] == 0) ||
		(data[2] == 0 && data[5] == 0 && data[8] == 0) ||
		(data[0] == 0 && data[4] == 0 && data[8] == 0) ||
		(data[2] == 0 && data[4] == 0 && data[6] == 0)
		)
	{
		printf("哦，真遗憾！您输了。\n");
		return 200;
	}
	else if ((data[0] == 1 && data[1] == 1 && data[2] == 1) ||
			 (data[3] == 1 && data[4] == 1 && data[5] == 1) ||
			 (data[6] == 1 && data[7] == 1 && data[8] == 1) ||
			 (data[0] == 1 && data[3] == 1 && data[6] == 1) ||
			 (data[1] == 1 && data[4] == 1 && data[7] == 1) ||
			 (data[2] == 1 && data[5] == 1 && data[8] == 1) ||
			 (data[0] == 1 && data[4] == 1 && data[8] == 1) ||
			 (data[2] == 1 && data[4] == 1 && data[6] == 1)
		)
	{
		printf("恭喜！！！您胜利了！！！\n");
		return 201;
	}
	else
	{
		return 20;
	}
}