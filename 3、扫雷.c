#include"ku.h"

void saoleiversion();
void saoleimenu();
void saoleigame();
void saoleicreate(char overdesktop[11][11], char desktop[11][11], int underdesktop[11][11], int inputx, int inputy);
int saoleiinput(char overdesktop[11][11],char desktop[11][11], int underdesktop[11][11]);
void autoOpen(char overdesktop[11][11], char desktop[11][11], int underdesktop[11][11], int inputx, int inputy);
void saoleioverdesktop(char overdesktop[11][11]);
int saoleicheck(char overdesktop[11][11]);



int mainsaolei()
{
	system("cls");
	printf("正在初始化扫雷游戏");
	for (int i = 1; i <= 6; i++)
	{
		Sleep(200);
		printf(".");
	}
	Sleep(800);
	music(3);
	Sleep(100);
	saoleimenu();
	return 3666;
}


void saoleimenu()
{
	while (1)
	{
		system("cls");
		printf("版权所有：qsnn\n版本：2.0\n");
		printf(" ________________________ \n");
		printf("||----------------------||\n");
		printf("||         扫雷         ||\n");
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
			system("cls");
			saoleigame();
		}
		else if (strcmp(choose1, "2") == 0)
		{
			printf("\n真遗憾,后面很好玩呢\n");
			system("pause");
			break;
		}
		else if (strcmp(choose1, "3") == 0)
		{
			saoleiversion();
		}
		else
		{
			printf("请输入正确的数字\n1秒后重来！");
			Sleep(1000);
		}
	}
}


void saoleigame()
{
	char overdesktop[11][11];
	char desktop[11][11];
	int underdesktop[11][11];

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			overdesktop[i][j] = '*';
		}
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			desktop[i][j] = '0';
		}
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			underdesktop[i][j] = 0;
		}
	}
	printf("这是个简易的扫雷游戏\n");
	saoleioverdesktop(overdesktop);
	saoleiinput(overdesktop, desktop, underdesktop);
}


void saoleicreate(char overdesktop[11][11], char desktop[11][11], int underdesktop[11][11], int inputx, int inputy)
{
	//生成10个雷
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int x;
		int y;
		while (1)
		{
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
			if ((desktop[x][y] == '0') && (x != inputx) && (y != inputy))
			{
				desktop[x][y] = '!';
				underdesktop[x][y] = 999;
				break;
			}
		}
	}

	//布局,考虑了边界
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (desktop[i][j] == '0')
			{
				if (desktop[i + 1][j] == '!')
				{
					underdesktop[i][j]++;
				}
				if (desktop[i + 1][j - 1] == '!')
				{
					underdesktop[i][j]++;
				}
				if (desktop[i + 1][j + 1] == '!')
				{
					underdesktop[i][j]++;
				}
				if (desktop[i - 1][j] == '!')
				{
					underdesktop[i][j]++;
				}
				if (desktop[i - 1][j - 1] == '!')
				{
					underdesktop[i][j]++;
				}
				if (desktop[i - 1][j + 1] == '!')
				{
					underdesktop[i][j]++;
				}
				if (desktop[i][j - 1] == '!')
				{
					underdesktop[i][j]++;
				}
				if (desktop[i][j + 1] == '!')
				{
					underdesktop[i][j]++;
				}
				//以上是赋值，以下是转移
				if (underdesktop[i][j] == 1)
				{
					desktop[i][j] = '1';
				}
				if (underdesktop[i][j] == 2)
				{
					desktop[i][j] = '2';
				}
				if (underdesktop[i][j] == 3)
				{
					desktop[i][j] = '3';
				}
				if (underdesktop[i][j] == 4)
				{
					desktop[i][j] = '4';
				}
				if (underdesktop[i][j] == 5)
				{
					desktop[i][j] = '5';
				}
				if (underdesktop[i][j] == 6)
				{
					desktop[i][j] = '6';
				}
				if (underdesktop[i][j] == 7)
				{
					desktop[i][j] = '7';
				}
				if (underdesktop[i][j] == 8)
				{
					desktop[i][j] = '8';
				}
			}
		}
	}
}


int saoleiinput(char overdesktop[11][11], char desktop[11][11], int underdesktop[11][11])
{
	int round = 0;
	while (1)
	{
		round++;
		int inputx, inputy;
		printf("总共10个雷\n");
		printf("请输入你认为不是地雷的地方的坐标\n");
		if (scanf("%d", &inputx) != 1)
		{
			printf("请输入正确的序号！\n");
			while (getchar() != '\n');
			continue;
		}
		if (scanf("%d", &inputy) != 1)
		{
			printf("请输入正确的序号！\n");
			while (getchar() != '\n');
			continue;
		}
		if (round == 1)
		{
			saoleicreate(overdesktop, desktop, underdesktop ,inputx, inputy);
		}
		if ((overdesktop[inputx][inputy] != '*') || inputx > 9 || inputx < 1 || inputy > 9 || inputy < 1)
		{
			printf("不能输入已经打开的格子或不存在的格子\n请重试\n");
			continue;
		}
		if (underdesktop[inputx][inputy] == 999)
		{
			for (int i = 1; i < 10; i++)
			{
				for (int j = 1; j < 10; j++)
				{
					overdesktop[inputx][inputy] = desktop[inputx][inputy];
				}
			}
			printf("\033[31m");
			for (int i = 1; i < 10; i++)
			{
				for (int j = 1; j < 10; j++)
				{
					overdesktop[i][j] = desktop[i][j];
				}
			}
			saoleioverdesktop(overdesktop);
			printf("恭喜你中奖了！\033[0m\n");
			system("pause");
			return 1;
		}
		else
		{
			overdesktop[inputx][inputy] = desktop[inputx][inputy];
			autoOpen(overdesktop, desktop, underdesktop,inputx,inputy);
			saoleioverdesktop(overdesktop);
			if (saoleicheck(overdesktop) == 666)
			{
				printf("\033[32m");
				printf("恭喜您通关了！！！\n");
				for (int i = 1; i < 10; i++)
				{
					for (int j = 1; j < 10; j++)
					{
						if (desktop[i][j] == '!')
						{
							overdesktop[i][j] = '!';
						}
					}
				}
				saoleioverdesktop(overdesktop);
				printf("\033[0m");
				system("pause");
				return 666;
			}
		}

	}
}


void autoOpen(char overdesktop[11][11], char desktop[11][11], int underdesktop[11][11], int inputx, int inputy)
{
	if ((desktop[inputx][inputy] != '!') && (overdesktop[inputx][inputy] != '*'))
	{
		if (desktop[inputx][inputy] == '0')
		{
			overdesktop[inputx][inputy] = ' ';
		}
		if (desktop[inputx + 1][inputy] == '0')
		{
			overdesktop[inputx + 1][inputy] = ' ';
		}
		if (desktop[inputx - 1][inputy] == '0')
		{
			overdesktop[inputx - 1][inputy] = ' ';
		}
		if (desktop[inputx][inputy + 1] == '0')
		{
			overdesktop[inputx][inputy + 1] = ' ';
		}
		if (desktop[inputx][inputy - 1] == '0')
		{
			overdesktop[inputx][inputy - 1] = ' ';
		}
	}
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if ((desktop[i][j] == '0') && (overdesktop[i][j] == ' '))
			{
				if (desktop[i + 1][j] == '0')
				{
					overdesktop[i + 1][j] = ' ';
				}
				else if ((underdesktop[i + 1][j] > 0) && (underdesktop[i + 1][j] < 10))
				{
					overdesktop[i + 1][j] = desktop[i + 1][j];
				}
				if (desktop[i - 1][j] == '0')
				{
					overdesktop[i - 1][j] = ' ';
				}
				else if ((underdesktop[i - 1][j] > 0) && (underdesktop[i - 1][j] < 10))
				{
					overdesktop[i - 1][j] = desktop[i - 1][j];
				}
				if (desktop[i][j + 1] == '0')
				{
					overdesktop[i][j + 1] = ' ';
				}
				else if ((underdesktop[i][j + 1] > 0) && (underdesktop[i][j + 1] < 10))
				{
					overdesktop[i][j + 1] = desktop[i][j + 1];
				}
				if (desktop[i][j - 1] == '0')
				{
					overdesktop[i][j - 1] = ' ';
				}
				else if ((underdesktop[i][j - 1] > 0) && (underdesktop[i][j - 1] < 10))
				{
					overdesktop[i][j - 1] = desktop[i][j - 1];
				}
				if (desktop[i + 1][j + 1] == '0')
				{
					overdesktop[i + 1][j + 1] = ' ';
				}
				else if ((underdesktop[i + 1][j + 1] > 0) && (underdesktop[i + 1][j + 1] < 10))
				{
					overdesktop[i + 1][j + 1] = desktop[i + 1][j + 1];
				}
				if (desktop[i + 1][j - 1] == '0')
				{
					overdesktop[i + 1][j - 1] = ' ';
				}
				else if ((underdesktop[i + 1][j - 1] > 0) && (underdesktop[i + 1][j - 1] < 10))
				{
					overdesktop[i + 1][j - 1] = desktop[i + 1][j - 1];
				}
				if (desktop[i - 1][j + 1] == '0')
				{
					overdesktop[i - 1][j + 1] = ' ';
				}
				else if ((underdesktop[i - 1][j + 1] > 0) && (underdesktop[i - 1][j + 1] < 10))
				{
					overdesktop[i - 1][j + 1] = desktop[i - 1][j + 1];
				}
				if (desktop[i - 1][j - 1] == '0')
				{
					overdesktop[i - 1][j - 1] = ' ';
				}
				else if ((underdesktop[i - 1][j - 1] > 0) && (underdesktop[i - 1][j - 1] < 10))
				{
					overdesktop[i - 1][j - 1] = desktop[i - 1][j - 1];
				}
			}
		}
	}
}


void saoleioverdesktop(char overdesktop[11][11])
{
	printf("  \\y | 1  2  3  4  5  6  7  8  9 |\n");
	printf("_x_\\_|___________________________|\n");
	printf("  1  | %c  %c  %c  %c  %c  %c  %c  %c  %c |\n", overdesktop[1][1], overdesktop[1][2], overdesktop[1][3], overdesktop[1][4], overdesktop[1][5], overdesktop[1][6], overdesktop[1][7], overdesktop[1][8], overdesktop[1][9]);
	printf("  2  | %c  %c  %c  %c  %c  %c  %c  %c  %c |\n", overdesktop[2][1], overdesktop[2][2], overdesktop[2][3], overdesktop[2][4], overdesktop[2][5], overdesktop[2][6], overdesktop[2][7], overdesktop[2][8], overdesktop[2][9]);
	printf("  3  | %c  %c  %c  %c  %c  %c  %c  %c  %c |\n", overdesktop[3][1], overdesktop[3][2], overdesktop[3][3], overdesktop[3][4], overdesktop[3][5], overdesktop[3][6], overdesktop[3][7], overdesktop[3][8], overdesktop[3][9]);
	printf("  4  | %c  %c  %c  %c  %c  %c  %c  %c  %c |\n", overdesktop[4][1], overdesktop[4][2], overdesktop[4][3], overdesktop[4][4], overdesktop[4][5], overdesktop[4][6], overdesktop[4][7], overdesktop[4][8], overdesktop[4][9]);
	printf("  5  | %c  %c  %c  %c  %c  %c  %c  %c  %c |\n", overdesktop[5][1], overdesktop[5][2], overdesktop[5][3], overdesktop[5][4], overdesktop[5][5], overdesktop[5][6], overdesktop[5][7], overdesktop[5][8], overdesktop[5][9]);
	printf("  6  | %c  %c  %c  %c  %c  %c  %c  %c  %c |\n", overdesktop[6][1], overdesktop[6][2], overdesktop[6][3], overdesktop[6][4], overdesktop[6][5], overdesktop[6][6], overdesktop[6][7], overdesktop[6][8], overdesktop[6][9]);
	printf("  7  | %c  %c  %c  %c  %c  %c  %c  %c  %c |\n", overdesktop[7][1], overdesktop[7][2], overdesktop[7][3], overdesktop[7][4], overdesktop[7][5], overdesktop[7][6], overdesktop[7][7], overdesktop[7][8], overdesktop[7][9]);
	printf("  8  | %c  %c  %c  %c  %c  %c  %c  %c  %c |\n", overdesktop[8][1], overdesktop[8][2], overdesktop[8][3], overdesktop[8][4], overdesktop[8][5], overdesktop[8][6], overdesktop[8][7], overdesktop[8][8], overdesktop[8][9]);
	printf("  9  | %c  %c  %c  %c  %c  %c  %c  %c  %c |\n", overdesktop[9][1], overdesktop[9][2], overdesktop[9][3], overdesktop[9][4], overdesktop[9][5], overdesktop[9][6], overdesktop[9][7], overdesktop[9][8], overdesktop[9][9]);
	printf("_____|___________________________|\n");
}


int saoleicheck(char overdesktop[11][11])
{
	int countlei = 0;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (overdesktop[i][j] == '*')
			{
				countlei++;
			}
		}
	}
	if (countlei == 10)
	{
		return 666;
	}
	return 0;
}
