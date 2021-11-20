#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void showBoard(char positions2[3][3]) {
	system("cls");
	printf("\t %c | %c | %c \n", positions2[0][0], positions2[0][1], positions2[0][2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", positions2[1][0], positions2[1][1], positions2[1][2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", positions2[2][0], positions2[2][1], positions2[2][2]);
}

int main() {
	char positions[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
	
	char answer;
	int plays, l, c, player = 0;
	
	do {
		plays = 1;
		
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				positions[i][j] = ' ';
			}
		}
		
		do {
			showBoard(positions);
			
			if (player % 2 == 0) {
				printf("\nUser X\n");
			} else {
				printf("\nUser O\n");
			}
			
			printf("write a line from 1 to 3:");
			scanf("%i", &l);
			
			printf("write a column from 1 to 3:");
			scanf("%i", &c);
			
			if (l < 1 || c < 1 || l > 3 || c > 3) {
				l = 0;
				c = 0;
			} else if (positions[l-1][c-1] != ' ') {
				l = 0;
				c = 0;
			} else {
				if (player % 2 == 0) {
					positions[l-1][c-1] = 'X';
				} else {
					positions[l-1][c-1] = 'O';
				}
				
				player++;
				plays++;
			}
			
			if (positions[0][0] == 'X' && positions[0][1] == 'X' && positions[0][2] == 'X') { plays = 11; }
			if (positions[1][0] == 'X' && positions[1][1] == 'X' && positions[1][2] == 'X') { plays = 11; }
			if (positions[2][0] == 'X' && positions[2][1] == 'X' && positions[2][2] == 'X') { plays = 11; }
			if (positions[0][0] == 'X' && positions[1][0] == 'X' && positions[2][0] == 'X') { plays = 11; }
			if (positions[0][1] == 'X' && positions[1][1] == 'X' && positions[2][1] == 'X') { plays = 11; }
			if (positions[0][2] == 'X' && positions[1][2] == 'X' && positions[2][2] == 'X') { plays = 11; }
			if (positions[0][0] == 'X' && positions[1][1] == 'X' && positions[2][2] == 'X') { plays = 11; }
			if (positions[0][2] == 'X' && positions[1][1] == 'X' && positions[2][0] == 'X') { plays = 11; }
			
			if (positions[0][0] == 'O' && positions[0][1] == 'O' && positions[0][2] == 'O') { plays = 12; }
			if (positions[1][0] == 'O' && positions[1][1] == 'O' && positions[1][2] == 'O') { plays = 12; }
			if (positions[2][0] == 'O' && positions[2][1] == 'O' && positions[2][2] == 'O') { plays = 12; }
			if (positions[0][0] == 'O' && positions[1][0] == 'O' && positions[2][0] == 'O') { plays = 12; }
			if (positions[0][1] == 'O' && positions[1][1] == 'O' && positions[2][1] == 'O') { plays = 12; }
			if (positions[0][2] == 'O' && positions[1][2] == 'O' && positions[2][2] == 'O') { plays = 12; }
			if (positions[0][0] == 'O' && positions[1][1] == 'O' && positions[2][2] == 'O') { plays = 12; }
			if (positions[0][2] == 'O' && positions[1][1] == 'O' && positions[2][0] == 'O') { plays = 12; }
		} while(plays <= 9);
		
		showBoard(positions);
		
		if (plays == 10) {
			printf("tied game!\n");
		} else if (plays == 11) {
			printf("player X won!\n");
		} else if (plays == 12) {
			printf("player O won!\n");
		}
		
		printf("Do you want to play again?");
		scanf("%s", &answer);
	} while (answer == 's');
	
}
