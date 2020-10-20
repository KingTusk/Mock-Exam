#pragma once
#include <conio.h>
#include <iostream>

bool menudone = false;
int taskchoice = 0;

int Choosetask();
bool wronginput();

int Choosetask(){
	bool done = false;
	int returnval = 0;
	do {
		char choice = 0;
		std::cout << "Choose what to do: " << std::endl << "1. task 1" << std::endl << "2. task 2" << std::endl << "3. task 3" << std::endl << "4. task 4" << std::endl << "5. Quit program" << std::endl;
		choice = _getch();
		switch (choice) {
		case '1':
			returnval = 1;
			done = true;
			break;
		case '2':
			returnval = 2;
			done = true;
			break;
		case '3':
			returnval = 3;
			done = true;
			break;
		case '4':
			returnval = 4;
			done = true;
			break;
		case '5':
			returnval = 5;
			done = true;
			break;
		default:
			done = wronginput();
		}
	} while (!done);
	return returnval;
}

bool wronginput() {
	char choice = 'o';
	std::cin.clear(256, '\n');
	std::cin.sync();
	std::cout << "Wrong input … Do you want to try again: (y/n) ";
	std::cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		return false;
	}
	else {
		return true;
		exit(0);
	}
}