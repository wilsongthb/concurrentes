// sc_ejemplo1.cpp: define el punto de entrada de la aplicacion de consola.

#include <iostream>
#include <thread>
#include <time.h>
#include <chrono>
#include <ctime>

#include "funciones.h"

#define N 1000

using namespace std;

double primos[N];

int main()
{
	thread t1(new_chrono, 1, (N * 3) / 4);//calcula los primeros 3/4 de operaciones
	thread t2(new_chrono, (N * 3) / 4, N);// calcula la ultima parte

	t2.join();
	t1.join();
	
    return 0;
}
