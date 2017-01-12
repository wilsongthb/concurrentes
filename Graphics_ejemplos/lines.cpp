#include <cstdio>
#include <cmath>
#include <graphics.h>
using namespace std;

int main(){
    initwindow(500, 500);
    for(int i = 0; i<50; i++){
        int y = 20 + rand()%200;
        line(100 + i*5, 400, 100 + i*5, 400 - y);
    }
    getch();
    return 0;
}
