#pragma once
#include<iostream>
#include<math.h>
#include<cstdlib>
#include <conio.h>
using namespace std;
void create_pole(int pole[], int size);
void show_pole(int pole[], int size);
void mix_pole(int pole[], int size);
void move(int pole[], int size);
int winTest(int pole[], int size);
int menu1();
void counter(int* count_move);