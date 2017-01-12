// sc_ejemplo1.cpp: define el punto de entrada de la aplicacion de consola.
#include "funciones.h"


#include <iostream>
#include <thread>
#include <time.h>
#include <chrono>
#include <ctime>

#define N 500

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
