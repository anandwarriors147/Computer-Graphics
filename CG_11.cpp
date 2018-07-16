
/* 
 * Write C++/Java program to generate fractal patterns by using Koch curves. 
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <graphics.h>
using namespace std;

void koch(int x1, int y1, int x2, int y2, int flag) {
    float angle = (60 * M_PI) / 180;
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;
    int x4 = (2 * x2 + x1) / 3;
    int y4 = (2 * y2 + y1) / 3;
    int x = x3 + ((x4 - x3) * cos(angle)) + ((y4 - y3) * sin(angle));
    int y = y3 - ((x4 - x3) * sin(angle)) + ((y4 - y3) * sin(angle));
    if (flag > 0) {
        koch(x1, y1, x3, y3, flag - 1);
        koch(x3, y3, x, y, flag - 1);
        koch(x, y, x4, y4, flag - 1);
        koch(x4, y4, x2, y2, flag - 1);
    } else {
        line(x1, y1, x3, y3);
        delay(5);
        line(x3, y3, x, y);
        delay(5);
        line(x, y, x4, y4);
        delay(5);
        line(x4, y4, x2, y2);
        delay(5);
    }
}

int main(void) {
    int flag = 5;
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, NULL);
    koch(200, 100, 400, 100, flag);
    closegraph();
    return EXIT_SUCCESS;
}

