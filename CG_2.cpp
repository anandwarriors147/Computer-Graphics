
/*
 *  Write C++/Java program to draw circle using Bresenham‘s algorithm. Inherit
 *  pixel class. 
 */

#include<graphics.h>
#include<iostream>
#include<cstdlib>
using namespace std;

class dcircle {
private:
    int x0, y0;
public:

    dcircle() {
        x0 = 0;
        y0 = 0;
    }

    void setoff(int xx, int yy) {
        x0 = xx;
        y0 = yy;
    }

    void drawbc(int x1, int y1, int r) //Bresenham's Circle
    {
        int i, x, y;
        float d;
        x = 0, y = r;
        d = 3 - 2 * r; //decision variable
        do {
            putpixel(x1 + x0 + x, y0 - y1 + y, 15);
            putpixel(x1 + x0 + y, y0 - y1 + x, 15);
            putpixel(x1 + x0 + y, y0 - y1 - x, 15);
            putpixel(x1 + x0 + x, y0 - y1 - y, 15);
            putpixel(x1 + x0 - x, y0 - y1 - y, 15);
            putpixel(x1 + x0 - y, y0 - y1 - x, 15);
            putpixel(x1 + x0 - y, y0 - y1 + x, 15);
            putpixel(x1 + x0 - x, y0 - y1 + y, 15);
            if (d <= 0) {
                d = d + (4 * x) + 6;
            } else {
                y = y - 1;
                d = d + (4 * x - 4 * y) + 10;
            }
            x++;
        } while (x <= y);
    }
};

int main() {
    int gd = DETECT, gm;
    int i, x, y, r, ch, xmax, ymax, xmid, ymid;
    float a, b;
    char ans;
    initgraph(&gd, &gm, NULL);
    dcircle c1;
    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax / 2;
    ymid = ymax / 2;

    line(xmid, 0, xmid, ymax); //Y co-ordinate
    line(0, ymid, xmax, ymid); //X co-ordinate
    do {
        cout << "\nEnter Cricle Drwaing algorithm";
        cout << "\n1.BRESENHAM'S..";
        cout << "\n2.EXIT..";
        cout << "\nEnter your choice: ";
        cin>>ch;
        switch (ch) {
            case 1:
            {
                cout << "\n Enter x: ";
                cin>>x;
                cout << "\n Enter y: ";
                cin>>y;
                cout << "\n Enter radius: ";
                cin>>r;
                c1.setoff(xmid, ymid);
                setcolor(15);
                c1.drawbc(x, y, r);
                break;
            }
            case 2:
                exit(0);
                break;
        }
        cout << "\nDO U Want To Continue y OR n: ";
        cin>>ans;
        cout << endl;
    } while (ans != 'n');
    delay(1500);
    getch();
    closegraph();
    return EXIT_SUCCESS;
}