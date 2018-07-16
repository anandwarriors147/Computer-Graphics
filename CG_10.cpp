
/* Write C++/Java program to draw any object such as flower, waves using any
 *  curve generation techniques .
 *   
 *                      @@  BEZIER CURVES  @@
 */

//#include <cstdlib>
//#include <iostream>
//#include <cmath>
//#include <graphics.h>
//using namespace std;
//
//int main(void) {
//    float x1 = 0;
//    float y1 = 0;
//    int j;
//    int gd = DETECT;
//    int gm;
//    float u = 0;
//    int x[4];
//    int y[4];
//
//    for (int i = 0; i < 4; ++i) {
//        cin >> x[i] >> y[i];
//    }
//
//    initgraph(&gd, &gm, NULL);
//
//    for (u = 0; u <= 1;) {
//        x1 = (x[0] * pow(1 - u, 3)) + (3 * x[1] * pow(1 - u, 2) * u) + (3 * x[2] * pow(u, 2) * (1 - u)) + (x[3] * pow(u, 3));
//        y1 = (y[0] * pow(1 - u, 3)) + (3 * y[1] * pow(1 - u, 2) * u) + (3 * y[2] * pow(u, 2) * (1 - u)) + (y[3] * pow(u, 3));
//        putpixel(x1, y1, WHITE);
//        u = u + 0.0005;
//        delay(5);
//    }
//    closegraph();
//    return EXIT_SUCCESS;
//}

#include <stdio.h> 
#include <stdlib.h> 
#include <graphics.h> 
#include <math.h>   

void bezier(int x[4][4], int y[4][4]) {
    int gd = DETECT, gm;
    int i, j;
    double t;
    initgraph(&gd, &gm, "");
    for (i = 0; i < 4; i++) {
        for (t = 0.0; t < 1.0; t += 0.0005) {
            double xt = pow(1 - t, 3) * x[i][0] + 3 * t * pow(1 - t, 2) * x[i][1] + 3 * pow(t, 2) * (1 - t) * x[i][2] + pow(t, 3) * x[i][3];
            double yt = pow(1 - t, 3) * y[i][0] + 3 * t * pow(1 - t, 2) * y[i][1] + 3 * pow(t, 2) * (1 - t) * y[i][2] + pow(t, 3) * y[i][3];
            putpixel(xt, yt, WHITE);
        }
    }
    setcolor(RED);
    getch();
    closegraph();
    return;
}

int main() {
    int x[4][4], y[4][4];
    int i, j;
    printf("Enter the x- and y-coordinates of the four control points.\n"); /* Co-ordinates for four petals total 16. If you want to increase petals increase the size of x & y array. Each petal will add four more points.*/
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d%d", &x[i][j], &y[i][j]);
        }
    }
    bezier(x, y);
}

//(200, 200) (160, 160) (240, 160) (200, 200) //for first petal
//(200, 200) (240, 160) (240, 240) (200, 200) //for second petal
//(200, 200) (240, 240) (160, 240) (200, 200) //for third petal
//(200, 200) (160, 240) (160, 160) (200, 200) //for fourth petal