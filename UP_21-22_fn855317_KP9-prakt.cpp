/**
*
* Solution to course project # 9
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Denis Azizovic
* @idnumber 855317
* @compiler GCC
*
* <file with helper functions>
*
*/


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

const int DIGIT_LENGTH = 10;
const int DIGIT_COUNT = 6;
const int LENGTH = DIGIT_LENGTH * DIGIT_COUNT;
const int WIDTH = 11;

class Canvas {
public:
	char arr[WIDTH][LENGTH];
	int time = 0;
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	int colours[DIGIT_COUNT];
	Canvas(int secs) {
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < LENGTH; j++) {
				arr[i][j] = ' ';
			}
		}
		time = secs;
		updateTime();
		cout << "hours" << hours << endl;
		cout << "mins" << minutes << endl;
		cout << "secs" << seconds << endl;
		for (int i = 0; i < DIGIT_COUNT; i++) {
			colours[i] = rand() % 15 + 1;
		}

	}
	void updateTime() {
		hours = time / 3600;
		minutes = time % 3600 / 60;
		seconds = time % 3600 % 60;
	}

	void clearDigit(int position) {
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < DIGIT_LENGTH; j++) {
				arr[i][j + position * DIGIT_LENGTH] = ' ';
			}
		}
	}
	void updateDigit(int digit, int position) {
		clearDigit(position);
		if (digit == 0) {
			for (int j = 0; j < DIGIT_LENGTH; j++) {
				arr[0][position * DIGIT_LENGTH + j] = '0';
				arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '0';
			}
			for (int i = 0; i < WIDTH; i++) {
				arr[i][(position + 1) * DIGIT_LENGTH - 1] = '0';
				arr[i][position * DIGIT_LENGTH] = '0';
			}
		}
		if (digit == 1) {
			for (int i = 0; i < WIDTH; i++) {
				arr[i][(position + 1) * DIGIT_LENGTH - 1] = '1';
			}
		}
		if (digit == 2) {
			for (int j = 0; j < DIGIT_LENGTH; j++) {
				arr[0][position * DIGIT_LENGTH + j] = '2';
				arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '2';
				arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '2';
			}
			for (int i = 0; i < WIDTH / 2; i++) {
				arr[i][(position + 1) * DIGIT_LENGTH - 1] = '2';
				arr[i + WIDTH / 2][position * DIGIT_LENGTH] = '2';
			}
		}
		if (digit == 3) {
			for (int j = 0; j < DIGIT_LENGTH; j++) {
				arr[0][position * DIGIT_LENGTH + j] = '3';
				arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '3';
				arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '3';
			}
			for (int i = 0; i < WIDTH; i++) {
				arr[i][(position + 1) * DIGIT_LENGTH - 1] = '3';
			}
		}
		if (digit == 4) {
			for (int i = 0; i < WIDTH / 2; i++) {
				arr[i][position * DIGIT_LENGTH] = '4';
			}
			for (int i = 0; i < WIDTH; i++) {
				arr[i][(position + 1) * DIGIT_LENGTH - 1] = '4';
			}
			for (int j = 0; j < DIGIT_LENGTH; j++) {
				arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '4';
			}
		}
		if (digit == 5) {
			for (int j = 0; j < DIGIT_LENGTH; j++) {
				arr[0][position * DIGIT_LENGTH + j] = '5';
				arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '5';
				arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '5';
			}
			for (int i = 0; i < WIDTH / 2; i++) {
				arr[i + WIDTH / 2][(position + 1) * DIGIT_LENGTH - 1] = '5';
				arr[i][position * DIGIT_LENGTH] = '5';
			}

		}
		if (digit == 6) {
			for (int j = 0; j < DIGIT_LENGTH; j++) {
				arr[0][position * DIGIT_LENGTH + j] = '6';
				arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '6';
				arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '6';
			}
			for (int i = 0; i < WIDTH / 2; i++) {
				arr[i + WIDTH / 2][(position + 1) * DIGIT_LENGTH - 1] = '6';
				arr[i][position * DIGIT_LENGTH] = '6';
				arr[i + WIDTH / 2][position * DIGIT_LENGTH] = '6';
			}
		}
		if (digit == 7) {
			for (int j = 0; j < DIGIT_LENGTH; j++) {
				arr[0][position * DIGIT_LENGTH + j] = '7';
			}
			for (int i = 0; i < WIDTH; i++) {
				arr[i][(position + 1) * DIGIT_LENGTH - 1] = '7';
			}
		}
		if (digit == 8) {
			for (int j = 0; j < DIGIT_LENGTH; j++) {
				arr[0][position * DIGIT_LENGTH + j] = '8';
				arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '8';
				arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '8';
			}
			for (int i = 0; i < WIDTH; i++) {
				arr[i][(position + 1) * DIGIT_LENGTH - 1] = '8';
				arr[i][position * DIGIT_LENGTH] = '8';
			}
		}
		if (digit == 9) {
			for (int j = 0; j < DIGIT_LENGTH; j++) {
				arr[0][position * DIGIT_LENGTH + j] = '9';
				arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '9';
				arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '9';
			}
			for (int i = 0; i < WIDTH / 2; i++) {
				arr[i][position * DIGIT_LENGTH] = '9';
				arr[i][(position + 1) * DIGIT_LENGTH - 1] = '9';
				arr[i + WIDTH / 2][(position + 1) * DIGIT_LENGTH - 1] = '9';
			}
		}

	}
	void showDisplay() {
		system("cls");
		for (int i = 0; i < 7; i++) {
			cout << endl;
		}
		for (int i = 0; i < WIDTH; i++) {
			for (int i = 0; i < 10; i++) {
				cout << " ";
			}
			for (int j = 0; j < LENGTH; j++) {
				if (time <= 15 * 60 && time > 1 * 60) {
					HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 6);
				}
				else if (time <= 1 * 60) {
					HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 4);
				}
				else {
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, colours[j / DIGIT_LENGTH]);
				}
				cout << arr[i][j];
				if ((j + 1) % DIGIT_LENGTH == 0) {
					cout << "  ";

				}
				if ((j + 1) % (DIGIT_LENGTH * 2) == 0 && j != LENGTH - 1) {
					if (i % (WIDTH / 3 + 1) == 3) {
						cout << "  *    ";
					}
					else {
						cout << "       ";
					}
				}
			}
			cout << endl;
		}

	}
	void timer()
	{
		while (time >= 0) {
			system("cls");
			updateDigit(hours / 10, 0);
			updateDigit(hours % 10, 1);
			updateDigit(minutes / 10, 2);
			updateDigit(minutes % 10, 3);
			updateDigit(seconds / 10, 4);
			updateDigit(seconds % 10, 5);


			if (time < 10) {
				for (int i = 0; i < 4; i++) {
					showDisplay();
					Sleep(250);
				}
			}
			else {
				showDisplay();
				Sleep(1000);
			}

			time--;
			updateTime();
		}
		Beep(500, 300);
		Beep(500, 300);
		Beep(500, 300);
	}
};


int main()
{
	srand(time(NULL));
	int second = 100;
	cout << "Enter start of timer: \n";
	cin >> second;
	Canvas h(second);
	h.timer();
}


