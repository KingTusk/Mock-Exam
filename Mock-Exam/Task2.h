#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "Task1.h" //included for the getRandomnumber function

struct player {
	int health = 0;
	std::string name = "No name given";
};

std::vector<player> players;

void Setplayers();
void Sortvector();
void Printvector();
void Task2();

void Task2() {
	Setplayers();
	Printvector();
	std::cout << std::endl << "Sorted table below" << std::endl;
	Sortvector();
	Printvector();
}

void Printvector() {
	std::cout << "Number\t" << "Name\t\t" << "health\t" << "Health bar" << std::endl;
	for (int i = 0; i < players.size(); i++) {
		std::cout << i << "\t" << players.at(i).name << "\t\t" <<players.at(i).health << "\t";
		for (int j = 1; j <= players.at(i).health;j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void Sortvector() {
	int savedvalue = 0;
	std::string savedname = " ";
	for (int i = 0; i < players.size(); i++) {
		for (int j = 0; j < players.size(); j++) {
			if (players.at(i).health > players.at(j).health && j > i) {

				savedvalue = players.at(i).health;
				savedname = players.at(i).name;

				players.at(i).health = players.at(j).health;
				players.at(i).name = players.at(j).name;

				players.at(j).health = savedvalue;
				players.at(j).name = savedname;

			}
		}
	}
}

void Setplayers(){ // sets players names and health
	players.resize(10);
	players.at(0).name = "John";
	players.at(1).name = "Jonas";
	players.at(2).name = "Emily";
	players.at(3).name = "Frankie";
	players.at(4).name = "Dobber";
	players.at(5).name = "Martin";
	players.at(6).name = "Sara";
	players.at(7).name = "Joseph";
	players.at(8).name = "Quentin";
	players.at(9).name = "Alex";
	for (int i = 0; i < players.size(); i++) {
		players.at(i).health = getRandomNumber(1, 20);
	}
}