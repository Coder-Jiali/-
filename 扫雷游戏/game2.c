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

	//�к�
	for (i = 0; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++) {
		//�к�
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
		//��ȡҪ������õ�������
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;//...

		//�жϸ�λ���Ƿ�Ϊ��
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
	int flag = 1; //�״����ױ���
	while (win < row * col - EASY_COUNT) {
		//�����������
		printf("��������Ҫ���׵����꣺\n");
		scanf("%d%d", &x, &y);

		//�������Ϸ���
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col)) {
			//����
			if (mine[x][y] == '1') {
				if (flag == 1) {
					printf("��λ�������ף��㻹��һ�λ��ᡣ\n");
					flag = 0; 
					show[x][y] = 'M'; 
					PrintBoard(show, row, col);
				}
				else {
					printf("�ܱ�Ǹ��������ˡ�\n");
					printf("��Ϸ������\n");
					PrintBoard(mine, row, col);
					break;
				}
			}
			else {
				//��Χ�׵ĸ���
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				PrintBoard(show, row, col);
				win++;
			}
		}
		else {
			printf("��������Ƿ������������롣\n");
		}
	}
	if (win == row * col - EASY_COUNT) {
		printf("��ϲ�㣬ɨ�׳ɹ�!\n");
		PrintBoard(mine, row, col);
	}
	
}