#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;


const int DIGIT_LENGTH = 10; //дължината на една цифра от таймера в char-ове (от условието)
const int DIGIT_COUNT = 6; // колко цифри има на таймера (от условието)
const int LENGTH = DIGIT_LENGTH * DIGIT_COUNT; // дължината на целия таймер в char-ове(от условието)
const int WIDTH = 11;//ширината на таймера(от условието)

class Canvas {
public:
	char arr[WIDTH][LENGTH];// двумерен масив, в него рисуваме отделните цифри от таймера
	int time = 0; // колко време остава до 00:00:00 в секунди
	int hours = 0;//таймерът ще се показва като hours:minutes:seconds
	int minutes = 0;
	int seconds = 0;
	int colours[DIGIT_COUNT];//ползваме го после заради условието цифрите да са в произволен цвят


	Canvas(int secs);
	void updateTime();
	void clearDigit(int position);
	void updateDigit(int digit, int position);
	void showDisplay();
	void timer();
};
