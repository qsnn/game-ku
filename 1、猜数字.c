#include"ku.h"


void gnversion();//�汾
void gnmenu();//�˵�
void gngame();//��Ϸ����
void gnpunish();//�ʵ�
void gnqsnnnb();//�ʵ�



//�����������---------------------------****-------------------------------------
int mainguessnum()
{
	system("cls");
	printf("���ڳ�ʼ����������Ϸ");
	for (int i = 1; i <= 6; i++)
	{
		Sleep(200);
		printf(".");
	}
	Sleep(1300);
	printf("\nMusic�Ѿ�����");
	Sleep(800);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC);
	Sleep(1000);
	gnmenu();
	return 1666;
}
//�����������---------------------------****-------------------------------------



//�汾
void gnversion()
{
	printf("1.1���Ż�ѭ���ṹ��\n");
	printf("2.0��ȫ�°汾��ȫ�½��棬ȫ�¹��ܣ����Ӳʵ���\n");
	printf("2.1���޸���һЩBUG��\n");
	printf("3.0�������Ż�����С�ڴ�ռ�ã������Ż�\n");
	printf("3.1���޸����������ַ��������»��������ϵ����⡣\n");
	printf("4.0������sao�����ı������֣��Ż��˴���ṹ��\n");
	printf("4.1���Ľ���ʾ��޸�������С�������³�����������\n");
}


//�˵�
void gnmenu()
{
	while(1)
	{
		system("cls");
		printf("��Ȩ���У�qsnn\n�汾��4.1\n");
		printf(" ________________________ \n");
		printf("||----------------------||\n");
		printf("||      ��������Ϸ      ||\n");
		printf("||______________________||\n");
		printf(" ------------------------ \n");
		printf("\n������������ȷ����Ϸ�Ƿ�Ҫ��ʼ:\n");
		printf("����1 *> ��ʼ\n");
		printf("����2 *> ����\n");
		printf("����3 *> �鿴������־\n");
		printf(" *>");
		char choose1[100];
		scanf("%s", &choose1);
		if (strcmp(choose1, "1") == 0)
		{
			gngame();
		}
		else if (strcmp(choose1, "2") == 0)
		{
			printf("\n���ź�,�����вʵ���\n");
			system("pause");
			break;
		}
		else if (strcmp(choose1, "3") == 0)
		{
			system("cls");
			gnversion();
			system("pause");
		}
		else
		{
			printf("���������\n1���������");
			Sleep(1000);
		}
	}
}



//��Ϸ����
void gngame()
{
	srand(time(NULL));
	int num = rand() % 100 + 1;
	int score = 0;
	printf("��Ϸ��ʼ\n��Ϸ�������:  ���а˴������������0~100���������֡�\n�뿪ʼ��ı��ݣ�");
	for (int i = 1; i <= 8; i++)
	{
		int num1;
		if (scanf("%d", &num1) != 1)
		{
			printf("������������\n");
			while (getchar() != '\n');
			i--;
			continue;
		}
		else if (num == num1)
		{
			printf("��ϲ�����ˣ�\n");
			score++;
			break;
		}
		else if (num1 > num)
		{
			printf("���ˣ�\n�㻹��%d�λ���\n", 8 - i);
		}
		else if (num1 < num)
		{
			printf("���ˣ�\n�㻹��%d�λ���\n", 8 - i);
		}
	}
	if (score == 1)
	{
		printf("��ϲ��ͨ�أ�\n");
		system("pause");
	}
	else if (score == 0)
	{
		gnpunish();
	}
}



//�ʵ�
void gnpunish()
{
	system("cls");
	printf("�ǳ��ź�����û�ܲ¶�����\n");
	printf("��������������ѡ��:\n");
	printf("���½�����Ϸ��>* 1\n");
	printf("������Ϸ��>* 2\n");
	char choose2[100];
	scanf("%s", &choose2);
	if (strcmp(choose2, "1") == 0)
	{
		system("cls");
		printf("�������ϰѴ���\n�����СС�ĳͷ�������\n���غ󼴿ɽ�����һ��\n");
		system("shutdown -s -t 60");
		printf("���Խ���60���ػ���\n����������Ļ����ɽ���ͷ�����ʾ��qsnnnb��\n������:______\n");
		gnqsnnnb();
		gnmenu();
	}
	else if (strcmp(choose2, "2") == 0)
	{
		printf("�ǳ��ź�������,������û�м�ֽ�����Ϸ�����ĵ��Խ���һ���Ӻ�ػ�\n���ǣ����в��Ȱ취\n����������Ļ����ɽ���ͷ�����ʾ��qsnnnb��\n������:_______\n");
		system("shutdown -s -t 60");
		gnqsnnnb();
	}
	else
	{
		printf("������Ҹ㣡\n������");
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
		printf("�Ҳ����Ѿ����ų�һ���˰ɣ�\n�ͷ������\n");
		system("shutdown -a");
	}
	else
	{
		printf("һ�㶼����ʵ��\n�ͷ���ǰ��\n");
		system("shutdown -a");
		system("shutdown -s -t 5");
		system("pause");
	}
}