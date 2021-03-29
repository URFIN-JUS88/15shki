#include<iostream>
#include<math.h>
#include<cstdlib>
#include <conio.h>
using namespace std;
void create_pole(int pole[], const int size);
void show_pole(int pole[], const int size);
void mix_pole(int pole[], const int size);
void move(int pole[], const int size);
void winTest(int pole[], const int size);
void menu(int action);
void count_hods(int count_hod);
int main() {
	int count_hod = 0;
	setlocale(LC_ALL, "rus");
	const int size = 16;
	int pole[size] = {};
	create_pole(pole, size);
	//show_pole(pole, size);
	mix_pole(pole, size);
	show_pole(pole, size);
	do {
		//count++;
		move(pole, size);
		show_pole(pole, size);
		count_hods(count_hod);
		winTest(pole, size);
	} while (true);
	
}
void create_pole(int pole[], const int size) {
	for (int i = 0; i < size; i++) {
		pole[i] = i;
	}
}
void show_pole(int pole[], const int size) {
	system("cls");
	for (int i = 0; i < sqrt(size); i++) {
		for (int j = 0; j < sqrt(size); j++) {
			if (pole[(int)sqrt(size) * i + j] < 10 && pole[(int)sqrt(size) * i + j] != 0)
			{
				cout << "  " << pole[(int)sqrt(size) * i + j];
			}
			else if (pole[(int)sqrt(size) * i + j] >= 10 && pole[(int)sqrt(size) * i + j] < size) {
				cout << " " << pole[(int)sqrt(size) * i + j];
			}
			else if (pole[(int)sqrt(size) * i + j] == 0) {
				cout << "   ";
			}
		}
		cout << endl;
	}
}
void mix_pole(int pole[], const int size) {
	int temp;
	srand(time(0));
	for (int i = 0; i < size; i++) {
		int random = rand() % size;
		temp = pole[i];
		pole[i] = pole[random];
		pole[random] = temp;
	}
}
void move(int pole[], const int size) {
	int index=0, temp=0;
	int key;
	for (int i = 0; i < size; i++) {
		if (pole[i] == 0) {
			index = i;
		}
	}
	key=_getch();
	if (key == 224) {
		key = _getch();
	}
	switch (key)// up=72;left=75;right=77;down=80;
	{
	case 80:
		if (index - 4 >= 0) {
			temp = pole[index];
			pole[index] = pole[index - 4];
			pole[index - 4] = temp;
		}
		else {
			cout << "�������� ���!! ���������� ��� ���";
			move(pole, size);
		}
		break;
	case 77:
		if (index - 1 < 0 || index - 1 == 3 || index - 1 == 7 || index - 1 == 11) {
			cout << "�������� ���!! ���������� ��� ���";
			move(pole, size);
		}
		else {
			temp = pole[index];
			pole[index] = pole[index - 1];
			pole[index - 1] = temp;
		}
		break;
	case 75:
		if (index + 1 > size-1 || index + 1 == 4 || index + 1 == 8 || index + 1 == 12) {
			cout << "�������� ���!! ���������� ��� ���";
			move(pole, size);
		}
		else {
			temp = pole[index];
			pole[index] = pole[index + 1];
			pole[index + 1] = temp;
		}
		break;
	case 72:
		if (index + 4 <= size-1) {
			temp = pole[index];
			pole[index] = pole[index + 4];
			pole[index + 4] = temp;
		}
		else {
			cout << "�������� ���!! ���������� ��� ���";
			move(pole, size);
		}
		break;
	default:
		cout << "���������� ��������� UP, LEFT, RIGHT, DOWN";
		move(pole, size);
		break;
	}
}
void winTest(int pole[], const int size) {
	int count = 0;
	for (int i = 0; i < size-1; i++) {
		if (pole[i] == i) {
			count++;
		}
	}
	if (count == size - 1) {
		cout << "You Win!!!";
	}
}
void menu(int action) {
	cout << "1. ������ ���� 4x4" << endl;
	cout << "2. ������ ���� 3x3" << endl;
}
void count_hods(int count_hod) {
	count_hod++;
	cout<< count_hod;
}