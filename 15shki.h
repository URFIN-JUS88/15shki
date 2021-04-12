#pragma once
#include<iostream>
#include<math.h>
#include<cstdlib>
#include <conio.h>
#include <time.h>
using namespace std;
void create_pole(int pole[], int size);
void show_pole(int pole[], int size);
void mix_pole(int pole[], int size);
void move(int pole[], int size);
int winTest(int pole[], int size);
void menu1(int* size);
int menu2(int (*ptr_15shki)());
void counter(int* count_move);
void start_timer(clock_t* start);
void stop_timer(clock_t* stop);
void show_timer(clock_t* start, clock_t* stop);