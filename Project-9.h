
Canvas::Canvas(int secs) {//конструктор, даваме като параметър от колко секунди да започва таймера
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			arr[i][j] = ' '; // в началото таймера е празен, няма цифри върху него
		}
	}
	time = secs;
	updateTime();//ъпдейтваме hours,minutes и seconds
	for (int i = 0; i < DIGIT_COUNT; i++) {
		colours[i] = rand() % 15 + 1;
	}//в colours записваме 6 произволни числа между 1 и 15, по-надолу става по-ясно;

}
void Canvas::updateTime() {//записваме колко часове, минути и секунди остават, например ако time=100sec, тогава hours=0, minutes=1, seconds=40
	hours = time / 3600;// ако time=200, тогава hours=0, minutes=3; seconds=20  и т.н.
	minutes = time % 3600 / 60;
	seconds = time % 3600 % 60;
}

void Canvas::clearDigit(int position) {//изчиства определена цифра от таймера, позициите са от 0 до 5, 0 и 1 - за часовете, 2 и 3 - за минути, 4 и 5 - за секундите
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < DIGIT_LENGTH; j++) {
			arr[i][j + position * DIGIT_LENGTH] = ' ';
		}
	}
}
void Canvas::updateDigit(int digit, int position) {// променя дадена цифра на определена позиция, когато таймерът трябва да се промени
	clearDigit(position);// първо трябва изтрием предишната цифра, например ако таймерът е на 00:00:25 и мине една секунда първо изтриваме 5 и после добавяме 4, и става 00:00:24
	if (digit == 0) {
		for (int j = 0; j < DIGIT_LENGTH; j++) {//принтираме хоризонталните линии на 0
			arr[0][position * DIGIT_LENGTH + j] = '0';
			arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '0';
		}
		for (int i = 0; i < WIDTH; i++) {//принтираме вертикалните линии на 0
			arr[i][(position + 1) * DIGIT_LENGTH - 1] = '0';
			arr[i][position * DIGIT_LENGTH] = '0';
		}
	}
	if (digit == 1) {
		for (int i = 0; i < WIDTH; i++) {// 1 е лесно, само една вертикална черта
			arr[i][(position + 1) * DIGIT_LENGTH - 1] = '1';
		}
	}
	if (digit == 2) {
		for (int j = 0; j < DIGIT_LENGTH; j++) {//принтираме трите хоризонтални линии на 2
			arr[0][position * DIGIT_LENGTH + j] = '2';
			arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '2';
			arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '2';
		}
		for (int i = 0; i < WIDTH / 2; i++) {// и двете вертикални
			arr[i][(position + 1) * DIGIT_LENGTH - 1] = '2';
			arr[i + WIDTH / 2][position * DIGIT_LENGTH] = '2';
		}
	}
	if (digit == 3) {
		for (int j = 0; j < DIGIT_LENGTH; j++) {//3 хоризонтални линии
			arr[0][position * DIGIT_LENGTH + j] = '3';
			arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '3';
			arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '3';
		}
		for (int i = 0; i < WIDTH; i++) {// една вертикална
			arr[i][(position + 1) * DIGIT_LENGTH - 1] = '3';
		}
	}
	if (digit == 4) {
		for (int i = 0; i < WIDTH / 2; i++) {// късата вертикална линия, която е отляво
			arr[i][position * DIGIT_LENGTH] = '4';
		}
		for (int i = 0; i < WIDTH; i++) {//късата вертикална линия, която е отдясно
			arr[i][(position + 1) * DIGIT_LENGTH - 1] = '4';
		}
		for (int j = 0; j < DIGIT_LENGTH; j++) {//хоризонталната линия по средата
			arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '4';
		}
	}
	if (digit == 5) {
		for (int j = 0; j < DIGIT_LENGTH; j++) {//почти същото като при 2, но наобратно
			arr[0][position * DIGIT_LENGTH + j] = '5';
			arr[WIDTH / 2][position * DIGIT_LENGTH + j] = '5';
			arr[WIDTH - 1][position * DIGIT_LENGTH + j] = '5';
		}
		for (int i = 0; i < WIDTH / 2; i++) {
			arr[i + WIDTH / 2][(position + 1) * DIGIT_LENGTH - 1] = '5';
			arr[i][position * DIGIT_LENGTH] = '5';
		}

	}
	if (digit == 6) {//почти същоот като 5, но едната вертикална  линия е по-дълга
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
	if (digit == 7) { //една хоризонтална горе и една вертикална линия
		for (int j = 0; j < DIGIT_LENGTH; j++) {
			arr[0][position * DIGIT_LENGTH + j] = '7';
		}
		for (int i = 0; i < WIDTH; i++) {
			arr[i][(position + 1) * DIGIT_LENGTH - 1] = '7';
		}
	}
	if (digit == 8) {// 3 хоризонтални линии и 2 вертикални
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
	if (digit == 9) {// като 8 но лявата вертикална линия е само до средата
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
void Canvas::showDisplay() {//принтира arr, показва таймера на конзолата
	system("cls");//първо изчистваме конзолата, каквото е било принтирано на нея, вече го няма
	for (int i = 0; i < 7; i++) {
		cout << endl;
	}//в условието пише че таймера трябва да е центриран в конзола с размер 80х25, таймерът е с размер 60х11, т.е принтим 7 ((25-11)/2) нови реда в началото за да е по средата по Оу->
	for (int i = 0; i < WIDTH; i++) {//обхождаме масива arr
		for (int i = 0; i < 10; i++) {
			cout << " ";//принтираме 10 ((80-60)/2) спейса за да е посредата и по Ох->
		}
		for (int j = 0; j < LENGTH; j++) {
			if (time <= 15 * 60 && time > 1 * 60) {// ако остават по-малко от 15 минути таймерът трябва да е жълт по условие
				//тези не знам как точно работят, но оцветяват output-a  на конзолата в различни цветове, 6 е за жълто
				HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 6);
			}
			else if (time <= 1 * 60) {// ако остава по-малко от 1 минута таймерът трябва да е червен по условие
				HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 4);// 6 е за жълто, 4 е за червено
			}
			else {// ако таймерът е на над 15 минути ,трябва всяка цифра да е в различен цвят
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, colours[j / DIGIT_LENGTH]);
				//в colours записахме 6 произволни числа от 1 до 15(31 ред) тук го използваме за оцветяването, взависимост до коя цифра от таймера сме стигнали оцветяваме в различен цвят
				//всяка позиция заема 10 (DIGIT_LENGTH) символа, тоест за j от 0 до 9 искаме да е един цвят, от 10 до 19 - друг цвят,.. от 50 до 59-друг цвят
				//цветовете вземаме според числото в colours[j/digit_length];
				//ако е 4 е жълто, ако е 6 е червено, и така за всички числва от 1 до 15, искаме да е на рандом
			}
			cout << arr[i][j];//принтираме символът до, който сме стигнали
			if ((j + 1) % DIGIT_LENGTH == 0) {//оставяме малко разстояние между отделните цифри, иначе не е много четливо
				cout << "  ";
			}
			if ((j + 1) % (DIGIT_LENGTH * 2) == 0 && j != LENGTH - 1) {
				if (i % (WIDTH / 3 + 1) == 3) {//принтираме двоеточието между цифрите за часовете, минутите и секундите, ако не сме написали това излизат така: 002522, с това са 00:25:22
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
void Canvas::timer()
{
	while (time >= 0) {// докато не свърши времето(таймера не стигне 0)
		updateDigit(hours / 10, 0);//ъпдейтваме цифрите от таймера всяка секунда
		updateDigit(hours % 10, 1);
		updateDigit(minutes / 10, 2);
		updateDigit(minutes % 10, 3);
		updateDigit(seconds / 10, 4);
		updateDigit(seconds % 10, 5);


		if (time < 10) {// ако остават по-малко от 10 секунди таймера трябва да примигва
			for (int i = 0; i < 4; i++) {
				showDisplay();//принтираме таймера
				Sleep(250);//казваме на програмата да заспи за 1/4 секунда(250 милисекунди), цикълът ще се завърти 4 пъти общо става 1 секунда
			}//тоест ако остават по-малко от 10 секунди, принтираме таймера 4 пъти във всяка секунда и така постигаме мигането

		}
		else {
			showDisplay();//принтираме таймера
			Sleep(1000);//казваме на програмата да заспи за 1 секунда (1000 милисекунди) , иначе цифрите ще се сменят много бързо
		}

		time--;//намаляме времето с една секунда
		updateTime();//ъпдейтваме стойностите за hours, minutes, seconds след като time  е намалено с 1
		//например ако преди time  е било 60 и след това стане 59, minutes преди е било 1,след като мине 1 секунда updateTime го променя на 0,
		// seconds преди е било 0, updateTime го променя на 59
	}
	//След като приключи цикъла, тоест таймерът е свършил(time=0), по условие трябва да се възпроизведе звуков сигнал, това става чрез beep
	Beep(500, 300);
	Beep(500, 300);
	Beep(500, 300);
}



int main()
{
	srand(time(NULL));//трябва да seed-нем rand(фунцкията за рандъм стойност), иначе не работи както трябва
	int second = 100;//от колко секунди ще започва таймера
	Canvas h(second);//създаваме обект от класа Canvas  и викаме констуктора, като му подаваме от колко секунди ще започва таймера
	h.timer();//викаме метода timer
}


