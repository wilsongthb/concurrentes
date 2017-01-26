
#include <cstdio>
#include <cmath>
#include <graphics.h>
//#include "metodos.h"

#include <thread>
//#include <iostream>

using namespace std;

#include "g_metodos.h"

void mostrar(int *arr_1, int *arr_2, int *arr_3, int *arr_4){
    initwindow(MAX_X, MAX_Y, "ORDENACION CONCURRENTE");
    while(true){

        //limpia la pantalla para dibujar denuevo
        cleardevice();

        //lineas separadores
        line(0, MAX_Y/2, MAX_X, MAX_Y/2);
        line(MAX_X/2, 0, MAX_X/2, MAX_Y);

        outtext("Burbuja");
        graficar_array(arr_1, 5, (MAX_Y/2)-5);
        moveto(MAX_X/2,0);//se mueve para escribir
        outtext("Insercion");
        graficar_array(arr_2, (MAX_X/2)+5, (MAX_Y/2)-5);
        moveto(0, MAX_Y/2);//se mueve para escribir
        outtext("Merge");
        graficar_array(arr_3, 5, MAX_Y-5);
        moveto(MAX_X/2, MAX_Y/2);//se mueve para escribir
        outtext("Quicksort");
        graficar_array(arr_4, (MAX_X/2)+5, MAX_Y-5);

        //getch();
        Sleep(200);
    }
}
void copy_array(int *arr_1, int *arr_2){
    for(int i = 0; i < N ; i++){
        arr_2[i] = arr_1[i];
    }
}

int main(){
    int arr_1[N], arr_2[N], arr_3[N], arr_4[N];
    //srand(1);
    llenar_array(arr_1);
    //llenar_array(arr_2);
    //llenar_array(arr_3);
    //llenar_array(arr_4);
    copy_array(arr_1,arr_2);
    copy_array(arr_1,arr_3);
    copy_array(arr_1,arr_4);


    thread t1(mostrar, arr_1, arr_2, arr_3, arr_4);
    thread t2(G_Burbuja, arr_1, N);
    thread t3(G_QuickSort, arr_4, N);
    thread t4(G_IDirecta, arr_2, N);
    thread t5(Merge, arr_3, N);

    t1.join();

	getch();
	closegraph();
    return 0;
}
