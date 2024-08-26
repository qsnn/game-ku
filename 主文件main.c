#include"ku.h"


//几个游戏
int mainversion();
int mainguessnum();
int mainszq();
int mainsaolei();
//游戏接口说明：按照次序return [n]666
//比如说：猜数字1666，三子棋2666 ......
//新增游戏只需添加接口即可


//主文件函数
int mainmenu();
int end(int mainres);


//主入口---------------------------****-------------------------------------
int main()
{
	int endreturn;
	do
	{
		int mainres = mainmenu();//mainmenu会返回一个数值，处理游戏结果
		if (mainres == 0)
		{
			break;
		}
		endreturn = end(mainres);//根据游戏结果运行结束程序
	} while (endreturn = 666);
	return 0;
}

//主入口---------------------------****-------------------------------------



//1、主菜单函数
int mainmenu()
{
	while(1)
	{
		PlaySound(NULL, NULL, SND_PURGE);
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
		printf("***************************************************\n");
		printf("*************  QS游戏库-made by qsnn  *************\n");
		printf("*************  版本：v1.2             *************\n");
		printf("***************************************************\n");
		printf("请选择你想玩的游戏\n");
		printf("1 *> 猜数字\n");
		printf("2 *> 三子棋\n");
		printf("3 *> 扫雷\n");
		printf("v *> 版本日志\n");
		printf("exit *> 退出\n");
		printf(" *>");
		char mainchoose[10];
		scanf("%s", &mainchoose);//选择进行的游戏
		if (strcmp(mainchoose, "1") == 0)
		{
			return mainguessnum();//返回1666
		}
		else if (strcmp(mainchoose, "2") == 0)
		{
			return mainszq();//返回2666
		}
		else if (strcmp(mainchoose, "3") == 0)
		{
			return mainsaolei();//返回3666
		}
		else if (strcmp(mainchoose, "v") == 0)
		{
			mainversion();
			return 666;
		}
		else if (strcmp(mainchoose, "exit") == 0)
		{
			return 0;
		}
		else
		{
			printf("请1秒后输入正确的指令！");
			Sleep(1000);
		}
	}
}



//2、结束函数
int end(int mainres)
{

	//下面处理游戏返回的结果

	system("cls");
	if (mainres == 1666)
	{
		printf("恭喜你！猜数字游戏已结束！\n");
	}
	else if (mainres == 2666)
	{
		printf("恭喜你！三子棋游戏已结束！\n");
	}
	else if (mainres == 3666)
	{
		printf("恭喜你！扫雷游戏已结束！\n");
	}
	else if (mainres == 404)
	{
		printf("产品维护中---------------\n");
		system("pause");
		return 666;
	}
	else if (mainres == 666)
	{
		return 666;
	}
	else if (mainres == 0)
	{
		return 0;
	}

	else
	{
		printf("程序出错了，请重启游戏！");
	}
	return 666;
}