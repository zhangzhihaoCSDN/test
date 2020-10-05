#define _CRT_SECURE_NO_WARNINGS l
#include <stdio.h>
#include "game.h"

void menu()
{
	printf("**********************");
	printf("******* 1.play *******");
	printf("******* 0.exit *******");
	printf("**********************");
}
void game()
{
	char ret = 0;
	//���һ����������Ϸ
	//�洢����
	char board[ROW][COL] = {0};//����Ӧ�ó�ʼ��Ϊ�ո�
	InitBoard(board,ROW,COL);//��ʼ������ - �ո�
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//����һ�·��֣�
	//������Ϸ�Ĺ���֮��
	//1.���win - '*'
	//2.����win - '#'
	//3.ƽ�� - 'Q'
	//4.���� - 'C'
	while (1)
	{
		PlayerMove(board,ROW,COL);
		//�ж���Ӯ
		ret = CheckWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		//�ж���Ӯ
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
	DisplayBoard(board, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��������Ϸ
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}