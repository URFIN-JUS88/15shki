#include "15shki.h"
void create_pole(int pole[], int size) {
	for (int i = 0; i < size; i++) {
		pole[i] = i;
	}
}
void show_pole(int pole[], int size) {
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
void mix_pole(int pole[], int size) {
	int temp;
	srand(time(0));
	for (int i = 0; i < size; i++) {
		int random = rand() % size;
		temp = pole[i];
		pole[i] = pole[random];
		pole[random] = temp;
	}
}
void move(int pole[], int size) {
	int index = 0, temp = 0;
	int key;
	for (int i = 0; i < size; i++) {
		if (pole[i] == 0) {
			index = i;
		}
	}
	key = _getch();
	if (key == 224) {
		key = _getch();
	}
	switch (key)// up=72;left=75;right=77;down=80;
	{
	case 80:
		if (index - (int)sqrt(size) >= 0) {
			temp = pole[index];
			pole[index] = pole[index - (int)sqrt(size)];
			pole[index - (int)sqrt(size)] = temp;
		}
		else {
			cout << "�������� ���!! ���������� ��� ���" << endl;
			move(pole, size);
		}
		break;
	case 77:
		if (index - 1 < 0 || index - 1 == (int)sqrt(size) - 1 || index - 1 == 2 * (int)sqrt(size) - 1 || index - 1 == 3 * (int)sqrt(size) - 1) {
			cout << "�������� ���!! ���������� ��� ���" << endl;
			move(pole, size);
		}
		else {
			temp = pole[index];
			pole[index] = pole[index - 1];
			pole[index - 1] = temp;
		}
		break;
	case 75:
		if (index + 1 > size - 1 || index + 1 == (int)sqrt(size) || index + 1 == 2 * (int)sqrt(size) || index + 1 == 3 * (int)sqrt(size)) {
			cout << "�������� ���!! ���������� ��� ���" << endl;
			move(pole, size);
		}
		else {
			temp = pole[index];
			pole[index] = pole[index + 1];
			pole[index + 1] = temp;
		}
		break;
	case 72:
		if (index + (int)sqrt(size) <= size - 1) {
			temp = pole[index];
			pole[index] = pole[index + (int)sqrt(size)];
			pole[index + (int)sqrt(size)] = temp;
		}
		else {
			cout << "�������� ���!! ���������� ��� ���" << endl;
			move(pole, size);
		}
		break;
	case 141: //��� �������! �������� ����������
		for (int i = 0; i < size - 1; i++) {
			pole[i] = i + 1;
		}
		break;
	default:
		cout << "���������� ��������� UP, LEFT, RIGHT, DOWN" << endl;
		move(pole, size);
		break;
	}
}
int winTest(int pole[], int size) {
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		if (pole[i] == i + 1) {
			count++;
		}
	}
	if (count == size - 1) {
		system("color 2f");
		cout << endl; cout << endl; cout << endl; cout << endl;
		cout << "***      ***                      ***               ***  *             ***** ***** *****"<< endl;
		cout << "  *** ***                          ***             ***                 ***** ***** *****"  << endl;
		cout << "    ***      *** ***   ***   ***    ***     *     ***   *** ********    ***   ***   ***" << endl;
		cout << "    ***    ***     *** ***   ***     ***   ***   ***    *** ***    **   ***   ***   ***" << endl;
		cout << "    ***    ***     *** ***   ***      ***  ***  ***     *** ***    ***   *     *     *" << endl;
		cout << "    ***      *** ***     *****         ***     ***      *** ***    ***   *     *     *" << endl;
		return 1;
	}
	else {
		return 0;
	}
}
int menu1() {
	int action;
	cout << "1. ������ ���� 4x4" << endl;
	cout << "2. ������ ���� 3x3" << endl;
	cin >> action;
	switch (action)
	{
	case 1:
		return 16;
		break;
	case 2:
		return 9;
		break;
	default:
		cout << "�������� ����� ����" << endl;
		menu1();
	}
}
void counter(int* count_move) {
	count_move++;
	//cout << *ptr_count_move << endl;
}