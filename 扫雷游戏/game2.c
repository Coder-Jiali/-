#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col) {
	int i, j;

	//列号
	for (i = 0; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++) {
		//行号
		printf("%d ",i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}


void SetMine(char board[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count) {
		//获取要随机设置的雷坐标
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;//...

		//判断该位置是否为空
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y) {
	return 
		mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x, y;
	int win = 0;
	int flag = 1; //首次排雷保护
	while (win < row * col - EASY_COUNT) {
		//玩家输入坐标
		printf("请输入你要排雷的坐标：\n");
		scanf("%d%d", &x, &y);

		//检查坐标合法性
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col)) {
			//踩雷
			if (mine[x][y] == '1') {
				if (flag == 1) {
					printf("该位置上有雷！你还有一次机会。\n");
					flag = 0; 
					show[x][y] = 'M'; 
					PrintBoard(show, row, col);
				}
				else {
					printf("很抱歉，你踩雷了。\n");
					printf("游戏结束。\n");
					PrintBoard(mine, row, col);
					break;
				}
			}
			else {
				//周围雷的个数
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				PrintBoard(show, row, col);
				win++;
			}
		}
		else {
			printf("输入坐标非法，请重新输入。\n");
		}
	}
	if (win == row * col - EASY_COUNT) {
		printf("恭喜你，扫雷成功!\n");
		PrintBoard(mine, row, col);
	}
	
}