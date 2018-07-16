/* Write C++/Java program to draw the following pattern using any Line drawing
 *  algorithms. 
 */  

#include <cstdlib>
#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <stdio.h>
using namespace std;

int calcMidPoint(int a, int b) {
    return (a + b) / 2;
}

int main() {
    int gd = DETECT;
    int gm;
    int midx1;
    int midy1;
    int midx2;
    int midy2;
    int innerMidx1;
    int innerMidy1;
    int innerMidx2;
    int innerMidy2;
    int storeX1;
    int storeY1;
    initgraph(&gd, &gm, "");
    line(100, 50, 300, 50);
    delay(500);
    line(300, 50, 300, 200);
    delay(500);
    line(300, 200, 100, 200);
    delay(500);
    line(100, 200, 100, 50);
    delay(500);
    midx1 = calcMidPoint(100, 300);
    midy1 = calcMidPoint(50, 50);
    midx2 = calcMidPoint(300, 300);
    midy2 = calcMidPoint(50, 200);
    line(midx1, midy1, midx2, midy2);
    delay(500);
    innerMidx1 = calcMidPoint(midx1, midx2);
    innerMidy1 = calcMidPoint(midy1, midy2);
    delay(500);
    midx1 = calcMidPoint(300, 100);
    midy1 = calcMidPoint(200, 200);
    line(midx2, midy2, midx1, midy1);
    delay(500);
    innerMidx2 = calcMidPoint(midx2, midx1);
    innerMidy2 = calcMidPoint(midy2, midy1);
    line(innerMidx1, innerMidy1, innerMidx2, innerMidy2);
    delay(500);
    storeX1 = innerMidx1;
    storeY1 = innerMidy1;
    delay(500);
    midx2 = calcMidPoint(100, 100);
    midy2 = calcMidPoint(200, 50);
    line(midx1, midy1, midx2, midy2);
    delay(500);
    innerMidx1 = calcMidPoint(midx1, midx2);
    innerMidy1 = calcMidPoint(midy1, midy2);
    line(innerMidx2, innerMidy2, innerMidx1, innerMidy1);
    delay(500);
    midx1 = calcMidPoint(100, 300);
    midy1 = calcMidPoint(50, 50);
    line(midx2, midy2, midx1, midy1);
    delay(500);
    innerMidx2 = calcMidPoint(midx2, midx1);
    innerMidy2 = calcMidPoint(midy1, midy2);
    line(innerMidx1, innerMidy1, innerMidx2, innerMidy2);
    delay(500);
    line(innerMidx2, innerMidy2, storeX1, storeY1);
    delay(5000);
    closegraph();
    return EXIT_SUCCESS;
}