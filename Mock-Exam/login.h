#pragma once
#include <iostream>
#include <conio.h>

char loginarray[9]{ '1','2','3','4','5','6','7','8','9' };
char password[5]{ '1','4','5','2','3' };
int Aposition = 0;

void fixAposition() {//this function changes Aposition if it is outside the range of login array
	if (Aposition > 8) {
		Aposition = Aposition - sizeof(loginarray) / sizeof(loginarray[0]);
	}
	else if (Aposition < 0) {
		Aposition = Aposition + sizeof(loginarray) / sizeof(loginarray[0]);
	}
}

void Printtable(){
	loginarray[Aposition] = '*';
	for (int i = 0; i < sizeof(loginarray) / sizeof(loginarray[0]); i++) {
		std::cout << "|" <<loginarray[i]<< "|";
		if ((i+1) % 3 == 0) {
			std::cout << "\n";
		}
	}
	std::cout << "Enter the 4 digit password by moving the * asterisk with  w,a,s,d or arrow keys";
}

bool Enterpassword() {
	char input[5]{ 'n','n','n','n','n' };
	char keypressed = 'n';
	int nextpos = 0;

	for (int i = 0; i < 5; i++) {
		input[i] = loginarray[Aposition];
		Printtable();
		keypressed = _getch();
		switch (keypressed) {
		case 'w':
		case'W':
		case'ÓH':
			Aposition -= 3;
			fixAposition();
			break;
		case's':
		case'S':
		case'ÓP':
			Aposition += 3;
			fixAposition();
			break;
		case 'a':
		case 'A':
		case'ÓK':
			Aposition--;
			fixAposition();
			break;
		case'd':
		case'D':
		case'ÓM':
			Aposition++;
			fixAposition();
			break;
		default:
			std::cout << "You can only use w,a,s,d or the arrow keys!";
		}
	}
	return true;

}
