#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;


const int DIGIT_LENGTH = 10; //��������� �� ���� ����� �� ������� � char-��� (�� ���������)
const int DIGIT_COUNT = 6; // ����� ����� ��� �� ������� (�� ���������)
const int LENGTH = DIGIT_LENGTH * DIGIT_COUNT; // ��������� �� ����� ������ � char-���(�� ���������)
const int WIDTH = 11;//�������� �� �������(�� ���������)

class Canvas {
public:
	char arr[WIDTH][LENGTH];// �������� �����, � ���� �������� ��������� ����� �� �������
	int time = 0; // ����� ����� ������ �� 00:00:00 � �������
	int hours = 0;//�������� �� �� ������� ���� hours:minutes:seconds
	int minutes = 0;
	int seconds = 0;
	int colours[DIGIT_COUNT];//�������� �� ����� ������ ��������� ������� �� �� � ���������� ����


	Canvas(int secs);
	void updateTime();
	void clearDigit(int position);
	void updateDigit(int digit, int position);
	void showDisplay();
	void timer();
};
