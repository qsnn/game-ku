#include"ku.h"


void gnversion();//版本
void gnmenu();//菜单
void gngame();//游戏主体
void gnpunish();//彩蛋
void gnqsnnnb();//彩蛋



//猜数字主入口---------------------------****-------------------------------------
int mainguessnum()
{
	system("cls");
	printf("正在初始化猜数字游戏");
	for (int i = 1; i <= 6; i++)
	{
		Sleep(200);
		printf(".");
	}
	Sleep(1300);
	printf("\nMusic已就绪！");
	Sleep(800);
	music(1);
	Sleep(1000);
	gnmenu();
	return 1666;
}
//猜数字主入口---------------------------****-------------------------------------



//菜单
void gnmenu()
{
	while(1)
	{
		system("cls");
		printf("版权所有：qsnn\n版本：4.2\n");
		printf(" ________________________ \n");
		printf("||----------------------||\n");
		printf("||      猜数字游戏      ||\n");
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
			gngame();
		}
		else if (strcmp(choose1, "2") == 0)
		{
			printf("\n真遗憾,后面有彩蛋呢\n");
			system("pause");
			break;
		}
		else if (strcmp(choose1, "3") == 0)
		{
			gnversion();
			system("pause");
		}
		else
		{
			printf("别给我乱输\n1秒后重来！");
			Sleep(1000);
		}
	}
}



//游戏主体
void gngame()
{
	srand(time(NULL));
	int num = rand() % 100 + 1;
	int score = 0;
	printf("游戏开始\n游戏规则介绍:  你有八次输入机会来猜0~100的幸运数字。\n请开始你的表演：");
	for (int i = 1; i <= 8; i++)
	{
		int num1;
		if (scanf("%d", &num1) != 1)
		{
			printf("请输入整数！\n");
			while (getchar() != '\n');
			i--;
			continue;
		}
		else if (num == num1)
		{
			printf("恭喜你答对了！\n");
			score++;
			break;
		}
		else if (num1 > num)
		{
			printf("高了！\n你还有%d次机会\n", 8 - i);
		}
		else if (num1 < num)
		{
			printf("低了！\n你还有%d次机会\n", 8 - i);
		}
	}
	if (score == 1)
	{
		printf("恭喜你通关！\n");
		system("pause");
	}
	else if (score == 0)
	{
		gnpunish();
	}
}



//彩蛋
void gnpunish()
{
	system("cls");
	printf("非常遗憾，您没能猜对数字\n");
	printf("接下来您有两个选择:\n");
	printf("重新进行游戏：>* 1\n");
	printf("结束游戏：>* 2\n");
	char choose2[100];
	scanf("%s", &choose2);
	if (strcmp(choose2, "1") == 0)
	{
		system("cls");
		printf("鉴于你上把错了\n给你个小小的惩罚！！！\n过关后即可进行下一把\n");
		system("shutdown -s -t 60");
		printf("电脑将在60秒后关机！\n输入你的真心话即可解除惩罚（提示：qsnnnb）\n请输入:______\n");
		gnqsnnnb();
		gnmenu();
	}
	else if (strcmp(choose2, "2") == 0)
	{
		printf("非常遗憾告诉您,由于您没有坚持进行游戏，您的电脑将在一分钟后关机\n但是，还有补救办法\n输入你的真心话即可解除惩罚（提示：qsnnnb）\n请输入:_______\n");
		system("shutdown -s -t 60");
		gnqsnnnb();
	}
	else
	{
		printf("别给我乱搞！\n重来！");
		Sleep(1000);
		gnpunish();
	}
}
void gnqsnnnb()
{
	char qsnnnb[] = "qsnnnb";
	char nb[100];
	scanf("%99s", &nb);
	int result;
	result = strcmp(nb, qsnnnb);
	if (result == 0)
	{
		printf("我猜你已经被吓出一身汗了吧！\n惩罚解除！\n");
		system("shutdown -a");
	}
	else
	{
		printf("一点都不诚实！\n惩罚提前！\n");
		system("shutdown -a");
		system("shutdown -s -t 5");
		system("pause");
	}
}