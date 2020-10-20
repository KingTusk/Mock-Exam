#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

//This header file includes all or most of the code used in the login page task

char loginarray[9]{ '1','2','3','4','5','6','7','8','9' };
char password[4]{ '4','5','2','3' };
int Aposition = 0;
int fails = 0;
bool endlogin = false;
char input[4]{ 'n','n','n','n' };
int chances = 3;

void fixAposition();
void Printtable();
bool Enterpassword();

void fixAposition() {//this function changes Aposition if it is outside the range of login array
	if (Aposition > 8) {
		Aposition = Aposition - sizeof(loginarray) / sizeof(loginarray[0]);
	}
	else if (Aposition < 0) {
		Aposition = Aposition + sizeof(loginarray) / sizeof(loginarray[0]);
	}
}

void Printtable(){
	for (int i = 0; i < sizeof(loginarray) / sizeof(loginarray[0]); i++) {
		if (i == Aposition) {
			std::cout << "|" << "*" << "|";
		}
		else
		{
					std::cout << "|" <<loginarray[i]<< "|";
		}
		if ((i+1) % 3 == 0) {
			std::cout << "\n";
		}
	}
	std::cout << "Enter the 4 digit password by moving the * asterisk with  w,a,s,d or arrow keys";
}

bool Enterpassword() {
	char keypressed = 'n';
	bool correctpassword = true;

	for (int i = 0; i < 4; i++) {
		input[i] = loginarray[Aposition];
		if (i == 0) {
			system("cls");
			Printtable();
		}
		keypressed = _getch();
		if (keypressed == -32 || keypressed == 224) {
			keypressed = _getch();
		}
		switch (keypressed) {
		case 'w':
		case'W':
		case 72:
			Aposition -= 3;
			fixAposition();
			input[i] = loginarray[Aposition];
			break;
		case's':
		case'S':
		case 80:
			Aposition += 3;
			fixAposition();
			input[i] = loginarray[Aposition];
			break;
		case 'a':
		case 'A':
		case 75:
			Aposition--;
			fixAposition();
			input[i] = loginarray[Aposition];
			break;
		case'd':
		case'D':
		case 77:
			Aposition++;
			fixAposition();
			input[i] = loginarray[Aposition];
			break;
		default:
			std::cout << "\nYou can only use w,a,s,d or the arrow keys!";
			i--;
			Sleep(3000);
		}
		system("cls");
		Printtable();
	}
	Aposition = 0;
	for (int i = 0; i < sizeof(password) / sizeof(password[0]); i++) {
		if (password[i] != input[i]) {
			fails++;
			correctpassword = false;
			break;
		}
	}
	return correctpassword;
}
