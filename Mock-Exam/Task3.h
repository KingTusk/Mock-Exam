#pragma once
#include <iostream>

struct pacman { //used to determine player position
	int row = 13;
	int column = 7;
} player1 ;
char grid[15][15]{
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ','#','#','#','#',' ',' ','#','#','#',' ','#','#','#'},
	{'#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ','#',' ',' ','#',' ','#','#','#',' ','#'},
	{'#',' ','#','#','#','#',' ',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#',' ','#'},
	{'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ','#',' ','#','#','#',' ',' ','#'},
	{'#','#','#','#','#','#',' ','#','#','#','#','#',' ','#','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};

void Printgrid();
void Playermovement();
void gameplay();
void introduction();
void task3();

void task3() {
	introduction();
	gameplay();
}

void introduction() {
	std::cout << "Welcome to this pac-man like game!" << std::endl << "Use w,a,s,d or arrow keys to move around,you are the E, # are walls you can't pass through" << std::endl <<  "press enter when ready and have fun!";
	getchar(); // to make sure the user read the introduction
}

void gameplay() {
	bool run = true;
	do {
		system("cls");
		Printgrid();
		Playermovement();
	} while (run);

}

void Playermovement() { //determines which move the player makes and whether or not it is allowed
	char keypressed = 'n';

	keypressed = _getch();
	if (keypressed == -32 || keypressed == 224) {
		keypressed = _getch();
	}
	switch (keypressed) {
	case 'w':
	case'W':
	case 72:
		if (grid[player1.row - 1][player1.column] != '#') {
			player1.row--;
		}
		break;
	case's':
	case'S':
	case 80:
		if (grid[player1.row + 1][player1.column] != '#') {
			player1.row++;
		}
		break;
	case 'a':
	case 'A':
	case 75:
		if (grid[player1.row][player1.column-1] != '#') {
			player1.column--;
		}
		break;
	case'd':
	case'D':
	case 77:
		if (grid[player1.row][player1.column+1] != '#') {
			player1.column++;
		}
		break;
	default:
		break;
	}
}

void Printgrid() {
	for (int i = 0; i < sizeof(grid) / sizeof(grid[0]); i++) {
		for (int j = 0; j < sizeof(grid[0]) / sizeof(grid[0][0]);j++) {
			if (player1.row == i && player1.column == j) {
				std::cout << 'E';
			}
			else {
				std::cout << grid[i][j];
			}
			if (j == sizeof(grid[0]) / sizeof(grid[0][0])-1) {
				std::cout << std::endl;
			}
		}
	}
}


