#pragma once
#include <iostream>
#include <conio.h>

int points = 0;
char bettergrid[15][15]{ // same grid as in task 3, updated for task 4
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#','.','.','.','.','.',' ','.','.','.','.','.','.','.','#'},
	{'#',' ','#','#','#','#',' ','.','#','#','#','.','#','#','#'},
	{'#',' ',' ','.',' ','#',' ','.','.','.','.','.','.','.','#'},
	{'#','.','.',' ','.','#',' ','.','#','.','#','#','#',' ','#'},
	{'#','.','#','#','#','#',' ','.','#','.','.','.','#',' ','#'},
	{'#','.','#',' ',' ','#',' ','#','#','#','.','#','#',' ','#'},
	{'#','.','#',' ',' ',' ',' ','.','.',' ','.',' ',' ',' ','#'},
	{'#','.','#',' ',' ',' ',' ','#','.',' ',' ',' ',' ',' ','#'},
	{'#','.','#',' ',' ',' ',' ','#','.','.','.','.','.',' ','#'},
	{'#','.','.','.','.','.','.','#','.','#','#','#','.',' ','#'},
	{'#','#','#','#','#','#','.','#','#','#','#','#',' ','#','#'},
	{'#',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};

void Printbettergrid();
void t4introduction();
void t4Playermovement();
void t4gameplay();
void task4();

void task4() {
	t4introduction();
	t4gameplay();
}

void t4gameplay() {
	bool run = true;
	do {
		system("cls");
		Printbettergrid();
		t4Playermovement();
	} while (run);
}

void t4introduction(){
	std::cout << "Welcome to this pac-man like game!" << std::endl << "Use w,a,s,d or arrow keys to move around,You are the E" << std::endl << "# are walls you can't pass through, . are food to eat worth 5 points each, press enter when ready and have fun!";
	getchar(); // to make sure the user read the introduction
}

void t4Playermovement() { //determines which move the player makes and whether or not it is allowed
	char keypressed = 'n';
	keypressed = _getch();
	if (keypressed == -32 || keypressed == 224) {
		keypressed = _getch();
	}

	switch (keypressed) {
	case 'w':
	case'W':
	case 72:
		if (bettergrid[player1.row - 1][player1.column] != '#') {
			if (bettergrid[player1.row - 1][player1.column] == '.') {
				points += 5;
				bettergrid[player1.row - 1][player1.column] = ' ';
			}
			player1.row--;
		}
		break;
	case's':
	case'S':
	case 80:
		if (bettergrid[player1.row + 1][player1.column] != '#') {
			if (bettergrid[player1.row + 1][player1.column] == '.') {
				points += 5;
				bettergrid[player1.row + 1][player1.column] = ' ';
			}
			player1.row++;
		}
		break;
	case 'a':
	case 'A':
	case 75:
		if (bettergrid[player1.row][player1.column - 1] != '#') {
			if (bettergrid[player1.row][player1.column - 1] == '.') {
				points += 5;
				bettergrid[player1.row][player1.column - 1] = ' ';
			}
			player1.column--;
		}
		break;
	case'd':
	case'D':
	case 77:
		if (bettergrid[player1.row][player1.column + 1] != '#') {
			if (bettergrid[player1.row][player1.column + 1] == '.') {
				points += 5;
				bettergrid[player1.row][player1.column + 1] = ' ';
			}
			player1.column++;
		}
		break;
	default:
		break;
	}
}

void Printbettergrid() {
	for (int i = 0; i < sizeof(bettergrid) / sizeof(bettergrid[0]); i++) {
		for (int j = 0; j < sizeof(bettergrid[0]) / sizeof(bettergrid[0][0]); j++) {
			if (player1.row == i && player1.column == j) {
				std::cout << 'E';
			}
			else {
				std::cout << bettergrid[i][j];
			}
			if (j == sizeof(bettergrid[0]) / sizeof(bettergrid[0][0]) - 1) {
				std::cout << std::endl;
			}
		}
	}
	std::cout << "Points: " << points;
}