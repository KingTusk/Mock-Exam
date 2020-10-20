#pragma once
#include <iostream>

int getRandomNumber(int min, int max);
int Throwdice();
void Countdice(int amount);
void Dicetask();

int diceThrows[6]{ 0,0,0,0,0,0 };

void Dicetask(){
    Countdice(2000);
    std::cout << "Dice thrown:" << std::endl;
    for (int i = 0; i < (sizeof(diceThrows) / sizeof(diceThrows[0]));i++) {
        std::cout << "die " << (i + 1) << " " << diceThrows[i] << std::endl;
    }
}

void Countdice(int amount) {
    int dice = 0;
    for (int i = 0; i <= amount; i++) {
        dice = Throwdice();
        diceThrows[dice - 1]++;
    }
}

int Throwdice() {
    return getRandomNumber(1, 6);
}

int getRandomNumber(int min, int max) //code is from learncpp.com, it produces a random number between min and max
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}