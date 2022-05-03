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
//	//雷的信息存储
//	//1.布置好的雷的信息
//	char mine[ROWS][COLS] = { 0 };
//	//2.排查出来的雷的信息
//	char show[ROWS][COLS] = { 0 };
//
//	//初始化棋盘
//	InitBoard(mine, ROWS, COLS, '0');
//	InitBoard(show, ROWS, COLS, '*');
//
//	//打印棋盘
//	//PrintBoard(mine, ROW, COL);
//	PrintBoard(show, ROW, COL);
//
//	//设置雷
//	SetMine(mine, ROW, COL);
//	//PrintBoard(mine, ROW, COL);
//
//	//排雷
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
//		printf("请输入您的选择：\n");
//		scanf("%d", &input);
//
//		switch (input) {
//		case 1:
//			//printf("扫雷\n");
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入有误，请重新输入\n");
//			break;
//		}
//
//	} while (input);
//
//
// return 0;
//}