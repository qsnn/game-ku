#include"ku.h"


//������Ϸ
int mainversion();
int mainguessnum();
int mainszq();
int mainsaolei();
//��Ϸ�ӿ�˵�������մ���return [n]666
//����˵��������1666��������2666 ......
//������Ϸֻ����ӽӿڼ���


//���ļ�����
int mainmenu();
int end(int mainres);


//�����---------------------------****-------------------------------------
int main()
{
	int endreturn;
	do
	{
		int mainres = mainmenu();//mainmenu�᷵��һ����ֵ��������Ϸ���
		endreturn = end(mainres);//������Ϸ������н�������
	} while (endreturn = 666);
	return "Exit";
}

//�����---------------------------****-------------------------------------



//1�����˵�����
int mainmenu()
{
	while(1)
	{
		PlaySound(NULL, NULL, SND_PURGE);
		system("cls");
		printf("***************************************************\n");
		printf("*************  QS��Ϸ��-made by qsnn  *************\n");
		printf("************  �汾��v1.1               ************\n");
		printf("***************************************************\n");
		printf("��ѡ�����������Ϸ\n");
		printf("1 *> ������\n");
		printf("2 *> ������\n");
		printf("3 *> ɨ��\n");
		printf("v *> �汾��־\n");
		printf("exit *> �˳�\n");
		printf(" *>");
		char mainchoose[10];
		scanf("%s", &mainchoose);//ѡ����е���Ϸ
		if (strcmp(mainchoose, "1") == 0)
		{
			return mainguessnum();//����1666
		}
		else if (strcmp(mainchoose, "2") == 0)
		{
			return mainszq();//����2666
		}
		else if (strcmp(mainchoose, "3") == 0)
		{
			return mainsaolei();//����3666
		}
		else if (strcmp(mainchoose, "v") == 0)
		{
			return mainversion();
		}
		else if (strcmp(mainchoose, "exit") == 0)
		{
			break;
		}
		else
		{
			printf("��1���������ȷ��ָ�");
			Sleep(1000);
		}
	}
}



//2����������
int end(int mainres)
{

	//���洦����Ϸ���صĽ��

	system("cls");
	if (mainres == 1666)
	{
		printf("��ϲ�㣡��������Ϸ�ѽ�����");
	}
	else if (mainres == 2666)
	{
		printf("��ϲ�㣡��������Ϸ�ѽ�����");
	}
	else if (mainres == 3666)
	{
		printf("��ϲ�㣡ɨ����Ϸ�ѽ�����");
	}
	else if (mainres == 000)
	{
		printf("��Ʒά����---------------");
	}
	else
	{
		printf("��������ˣ���������Ϸ��");
	}


	//�����Ƿ���������÷���ֵ������һ������

	char mainchoosere[100];
	while (((strcmp(mainchoosere, "1")) != 0) && ((strcmp(mainchoosere, "1")) != 0))//���ѭ���Ǵ����û�����Ƿ��ַ������
	{
		printf("\n");
		printf("������������ȷ���Ƿ�ص����˵�:\n");
		printf("����1 *> �������˵�\n");
		printf("����2 *> ����\n");
		printf(" *>");
		scanf("%s", &mainchoosere);//����ѡ��
		if (strcmp(mainchoosere, "1") == 0)
		{
			return 666;
		}
		else if (strcmp(mainchoosere, "2") == 0)
		{
			return 0;
		}
		else
		{
			printf("��������ȷ������");
			printf("\n");
			return 1;
		}
	}
}