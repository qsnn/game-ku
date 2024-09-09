#include"ku.h"




void szqversion();//版本号
void szqmenu(char qizi[3][3], int data[3][3]);//菜单
void szqgame(char qizi[3][3], int data[3][3]);//游戏主体
int szqman(char qizi[3][3], int data[3][3]);//人下棋
int szqmachine(char qizi[3][3], int data[3][3]);//机器下棋
void szqdesktop(char qizi[3][3]);//棋盘局面
int szqcheck(int data[3][3]);//检查胜负平结果


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
	music(2);
	Sleep(100);
	char qizi[3][3] =
	{
		{ ' ' , ' ' , ' '} ,
		{ ' ' , ' ' , ' '} ,
		{ ' ' , ' ' , ' '}
	};
	int data[3][3] = 
	{
		{9,9,9},
		{9,9,9},
		{9,9,9}
	};
	srand(time(NULL));
	szqmenu(qizi, data);
	return 2666;
}
//三子棋主入口---------------------------****-------------------------------------



//菜单
void szqmenu(char qizi[3][3], int data[3][3])
{
	while(1)
	{
		system("cls");
		printf("版权所有：qsnn\n版本：2.0\n");
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
			system("cls");
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
void szqgame(char qizi[3][3], int data[3][3])
{
	for (int i = 0; i < 9; i++)
	{
		int decide;
		if (i % 2 == 0)
		{
			decide = szqman(qizi, data);
		}
		else
		{
			decide = szqmachine(qizi, data);
		}
		//下面是检查结果
		 
		 
		//else if不能乱用！！！！！！


		if ((decide == 200)||(decide == 201))
		{
			break;
		}
		else if (i == 8)
		{
			printf("好耶！是和平的一战！");
		}
	}

	//数组初始化

	for (int i = 0 ; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			qizi[i][j] = ' ';
			data[i][j] = 9;
		}
	}
	system("pause");
}


//人下棋
int szqman(char qizi[3][3], int data[3][3])
{
	printf("请输入你下棋的行列位置\n");
	while (1)
	{
		szqdesktop(qizi, data);
		int x, y;
		printf("请分别输入行序号x和列序号y:");
		if (scanf("%d", &x) != 1)
		{
			printf("请输入正确的序号！\n");
			while (getchar() != '\n');
			continue;
		}
		if (scanf("%d", &y) != 1)
		{
			printf("请输入正确的序号！\n");
			while (getchar() != '\n');
			continue;
		}
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			x--;
			y--;
			if (qizi[x][y] == ' ')
			{
				qizi[x][y] = '*';
				data[x][y] = 1;
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
	int temp = szqcheck(data);
	return temp;
}


//机器下棋
int szqmachine(char qizi[3][3], int data[3][3])
{
	printf("机器人思考中\n");
	for (int i = 1; i <= 6; i++)
	{
		Sleep(200);
		printf(".");
	}
	while(1)

	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (qizi[x][y] == ' ')
		{
			qizi[x][y] = 'o';
			data[x][y] = 0;
			break;
		}
	}
	szqdesktop(qizi, data);
	int temp = szqcheck(data);
	return temp;
}


//棋盘局面
void szqdesktop(char qizi[3][3])
{
	printf("\033[33m");
	printf("下面是棋盘，下棋时输入两个值，分别为行列序数\n");
	printf("  \\y |  1  |  2  |  3  |\n");
	printf("_x_\\_|_____|_____|_____|\n");
	printf("  1  |  %c  |  %c  |  %c  |\n", qizi[0][0], qizi[0][1], qizi[0][2]);
	printf("_____|_____|_____|_____|\n");
	printf("  2  |  %c  |  %c  |  %c  |\n", qizi[1][0], qizi[1][1], qizi[1][2]);
	printf("_____|_____|_____|_____|\n");
	printf("  3  |  %c  |  %c  |  %c  |\n", qizi[2][0], qizi[2][1], qizi[2][2]);
	printf("_____|_____|_____|_____|\n");
	printf("\033[0m");
}


//检查结果
int szqcheck(int data[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		if ((data[0][i] == data[1][i] && data[0][i] == data[2][i] && data[0][i] == 0) ||//行
			(data[i][0] == data[i][1] && data[i][0] == data[i][2] && data[i][0] == 0) ||//列
			(data[0][0] == 0 && data[1][1] == 0 && data[2][2] == 0) || (data[0][2] == 0 && data[1][1] == 0 && data[2][0] == 0)//斜
			)//以上为条件
		{
			printf("哦，真遗憾！您输了。\n");
			return 200;
		}

		else if ((data[0][i] == data[1][i] && data[0][i] == data[2][i] && data[0][i] == 1) ||//行
			(data[i][0] == data[i][1] && data[i][0] == data[i][2] && data[i][0] == 1) ||//列
			(data[0][0] == 1 && data[1][1] == 1 && data[2][2] == 1) || (data[0][2] == 1 && data[1][1] == 1 && data[2][0] == 1)//斜
			)//以上为条件
		{
			printf("恭喜！！！您胜利了！！！\n");
			return 201;
		}
	}
		return 20;
}