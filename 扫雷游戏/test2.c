//#define _CRT_SECURE_NO_WARNINGS 1
//#include "game2.h"
//
//
//void menu() {
//	printf("************************************\n");
//	printf("*************  1.PLAY  *************\n");
//	printf("*************  0.EXIT  *************\n");
//	printf("************************************\n");
//
//}
//void game() {
//	//�׵���Ϣ�洢
//	//1.���úõ��׵���Ϣ
//	char mine[ROWS][COLS] = { 0 };
//	//2.�Ų�������׵���Ϣ
//	char show[ROWS][COLS] = { 0 };
//
//	//��ʼ������
//	InitBoard(mine, ROWS, COLS, '0');
//	InitBoard(show, ROWS, COLS, '*');
//
//	//��ӡ����
//	//PrintBoard(mine, ROW, COL);
//	PrintBoard(show, ROW, COL);
//
//	//������
//	SetMine(mine, ROW, COL);
//	//PrintBoard(mine, ROW, COL);
//
//	//����
//	FindMine(mine, show, ROW, COL);
//}
//
//
//int main(){
//
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do {
//		menu();
//		printf("����������ѡ��\n");
//		scanf("%d", &input);
//
//		switch (input) {
//		case 1:
//			//printf("ɨ��\n");
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("������������������\n");
//			break;
//		}
//
//	} while (input);
//
//
// return 0;
//}