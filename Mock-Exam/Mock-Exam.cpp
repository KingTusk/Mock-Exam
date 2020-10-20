#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "login.h"

int main()
{
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
				std::cout << "\nYou have entered the wrong password, try again, you have " << chances-fails <<" more tries";
				Sleep(5000);
			}
		}
	} while (!endlogin);
	std::cout << "Made it to line 26";
}