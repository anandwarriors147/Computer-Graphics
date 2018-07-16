
#include <graphics.h>
#include <cmath>
#include <iostream>

int main() {
    int i, j = 0, gd = DETECT, gm;
    initgraph(&gd, &gm, " ");
    for (i = 0; i <= 420; i = i + 10, j++) {
        rectangle(50 + i, 275, 150 + i, 400);
        rectangle(150 + i, 350, 200 + i, 400);
        circle(75 + i, 410, 10);
        circle(175 + i, 410, 10);
        delay(10);
        if (j == 15)
            j = 2;
        cleardevice();
    }
    closegraph();
    return 0;
}