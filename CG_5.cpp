
/* Write C++/Java program to draw inscribed and Circumscribed circles in the
 *  triangle as shown as an example below. (Use any Circle drawing and Line
 *  drawing algorithms) 
 */

#include <cstdlib>
#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>
using namespace std;

int main() {
    int gd = DETECT;
    int gm;
    int ans = int((sqrt(double(3)) / 2) * 150);
    initgraph(&gd, &gm, "");
    delay(500);
    circle(300, 200, 150);
    delay(500);
    line(300, 275, 300 - ans, 275);
    delay(500);
    line(300, 275, 300 + ans, 275);
    delay(500);
    line(300 + ans, 275, 300, 50);
    delay(500);
    line(300 - ans, 275, 300, 50);
    delay(500);
    circle(300, 200, 75);
    delay(5000);
    closegraph();
    return EXIT_SUCCESS;
}