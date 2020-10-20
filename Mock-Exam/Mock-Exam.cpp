#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include "login.h"
#include "Menu.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "task4.h"

int main()
{
	std::srand(std::time(nullptr));
	do {
		if (fails >= chances) {
			endlogin = true;
			std::cout << "\nYou have entered the wrong password 3 or more times, terminating program";
			return 0;
		}
		else {
			if (Enterpassword()) {
				endlogin = true;
				std::cout << "\nYou have entered the correct pasword, menu will appear soon";
				Sleep(5000);
			}
			else if(fails < chances) {
				std::cout << "\nYou have entered the wrong password, try again, you have " << chances-fails <<" more tries\npress enter to try again";
				std::cin.ignore(256, '\n');
				std::cin.sync();
			}
		}
	} while (!endlogin);
	system("cls");

	taskchoice = Choosetask();
	system("cls");
	if (taskchoice == 1) {
		Dicetask();
	}
	else if (taskchoice == 2) {
		Task2();
	}
	else if (taskchoice == 3) {
		task3();
	}
	else if (taskchoice == 4) {
		task4();
	}
	

}