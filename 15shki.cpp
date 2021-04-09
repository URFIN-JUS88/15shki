#include "15shki.h"

int main() {
	setlocale(LC_ALL, "rus");
	int count_move = 0;
	int* ptr_count_move = &count_move;
	int size;
	size = menu1();
	int* pole;
	pole = new int[size];
	create_pole(pole, size);
	mix_pole(pole, size);
	show_pole(pole, size);
	do {
		move(pole, size);
		show_pole(pole, size);
		//counter(&count_move);
		cout << count_move++ << endl;
	} while (winTest(pole,size)==0);
}
