#include "15shki.h"

int main() {
	setlocale(LC_ALL, "rus");
	system("cls");
	system("color 07");
	int (*ptr_15shki)();
	ptr_15shki = main;
	int count_move = 0;
	clock_t start, stop;
	int size;
	menu1(&size);
	int* pole;
	pole = new int[size];
	create_pole(pole, size);
	mix_pole(pole, size);
	show_pole(pole, size);
	start_timer(&start);
	do {
		move(pole, size);
		show_pole(pole, size);
		counter(&count_move);
	} while (winTest(pole,size)==0);
	stop_timer(&stop);
	show_timer(&start, &stop);
	menu2(ptr_15shki);
}
