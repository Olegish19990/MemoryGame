#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <thread>
#include <windows.h>


using namespace std;



const string red = "\033[31m";
const string yellow = "\033[33m";
const string nul = "\033[0m";
const string green = "\033[32m";
#pragma region Вывод_доски
void view(char mas[4][4], bool is_switched[4][4]) {
	cout << "Сейчас поле выглядит вот так:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (is_switched[i][j] == false) {
				cout << red << "X " << nul;
			}
			else {
				cout << mas[i][j] << " ";
			}
		}
		cout << endl;
	}
}
#pragma endregion



#pragma region Заполнение_доски
void pole(char mas[4][4]) {
	char symb[] = "##**++--==//$$^^";
	random_shuffle(symb, symb + 16);
	int h = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mas[i][j] = symb[h];
			//cout << mas[i][j] << " ";
			h++;
		}
		cout << endl;
	}
	cout << endl;
}
#pragma endregion



#pragma region Ход
void hod(char mas[4][4], bool is_switched[4][4]) {
	int str1, str2, sto1, sto2;
	cin.ignore();
	cout << "Введите строку 1 символа:" << endl;
	
	cin >> str1;
	cout << "Введите столбец 1 символа:" << endl;
	cin >> sto1;
	cout << "Введите строку 2 символа:" << endl;
	cin >> str2;
	cout << "Введите столбец 2 символа:" << endl;
	cin >> sto2;
	if (mas[str1 - 1][sto1 - 1] == mas[str2 - 1][sto2 - 1]) {
		cout << "Вы  угадали " << endl;
		is_switched[str1 - 1][sto1 - 1] = true;
		is_switched[str2 - 1][sto2 - 1] = true;
	}
	else {
		cout << "Вы НЕ угадали " << endl;
	}



}



void turn(int number, char mas[4][4], bool is_switched[4][4]) {
	view(mas, is_switched);
	hod(mas, is_switched);
	number++;
}
#pragma endregion



#pragma region Проверка_открытых_ячеек
bool is_false(bool is_switched[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (is_switched[i][j] == false) {
				return true;
			}
		}
	}
	return false;
}
#pragma endregion



int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int str, sto;
	int start;
	int a;
	int help = 10;
	int number = 1;
	bool is_switched[4][4] = { false };
	char mas[4][4];
	cout << green << "\t\t Память\n Суть игры: найти пару одинаковых символов, за как можно короткое время.\n Имеется 3 подсказки, использовать которые можно нажав <1>\n" << nul;
	cin >> start;
	if (start == 2) return 0;
	else {
		pole(mas);
	}
	while (is_false) {
		cout << "1)Подсказка\n2)Сделать ход" << endl;
		cin >> a;
		if (a == 1) {
			if (help > 0) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						cout << mas[i][j];
					}
					cout<<endl;
				}
				Sleep(1000);
				system("cls");
			}
			else {
				cout << "Подсказки закончились" << endl;
			}
		}
		else {
			if (a == 2) {
				turn(number, mas, is_switched);
			}
			else {
				cout << "Error" << endl;
			}
		}


	}
	cout << "Вы прошли игру за " << number << "ходов" << endl;
	return 0;
}