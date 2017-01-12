#include <iostream>
#include <cmath>
#include <cstdlib>
#include <graphics.h>
using namespace std;
#define PI 3.1415
#define RAD PI/180.0

int main(){
    int n;
    cout<<"ingrese cantidad: ";
    cin>>n;

    int X[n];
    int Y[n];
    int R[n];

    for(int i = 0; i<n; i++){
        R[i] = 20 + rand()%30;
        X[i] = R[i] + rand()%(600-2*R[i]);
        Y[i] = R[i] + rand()%(600-2*R[i]);
    }

    initwindow(600,600);

    for(int i = 0; i<n; i++){
        circle(X[i], Y[i], R[i]);
    }

    getch();
    return 0;
}
