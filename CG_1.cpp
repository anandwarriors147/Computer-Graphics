
/* 
 *  Write C++/Java program to draw line using DDA and Bresenham‘s algorithm.
 *  Inherit pixel class and Use function overloading. 
 */


#include<graphics.h>
#include<iostream>
using namespace std;

class Pixel {
protected:
    int x1, y1, color;
public:

    Pixel() {
        x1 = 0;
        y1 = 0;
        color = 15;
    }

    void setCordinates(int x, int y) {
        x1 = x;
        y1 = y;
    }

    void setColor(int c) {
        color = c;
    }

    void draw() {
        putpixel(x1, y1, color);
    }
};

class Line : public Pixel {
private:
    int x2, y2;
public:

    Line() : Pixel() {
        x2 = 0, y2 = 0;
    }

    void setLineCordinates(int x, int y, int x1, int y1) {
        Pixel::setCordinates(x, y);
        x2 = x1;
        y2 = y1;
    }

    void drawBresenhamsLine() {
        float x, y, dx, dy, decisionParameter, temp;
        int i, s1, s2, ex;
        dx = abs(x2 - x1);
        dy = abs(y2 - y1);
        x = x1;
        y = y1;
        Pixel::setCordinates(x, y);
        Pixel::draw();
        if (x2 > x1) {
            s1 = 1;
        }
        if (x2 < x1) {
            s1 = -1;
        }
        if (x2 == x1) {
            s1 = 0;
        }
        if (y2 > y1) {
            s2 = 1;
        }
        if (y2 < y1) {
            s2 = -1;
        }
        if (y2 == y1) {
            s2 = 0;
        }
        if (dy > dx) {
            temp = dx;
            dx = dy;
            dy = temp;
            ex = 1;
        } else {
            ex = 0;
        }
        decisionParameter = 2 * dy - dx;
        i = 1;
        do {
            while (decisionParameter >= 0) {
                if (ex == 1) {
                    x = x + s1;
                } else {
                    y = y + s2;
                }
                decisionParameter = decisionParameter + 2 * dy - 2 * dx;
            }
            if (ex == 1) {
                y = y + s2;
            } else {
                x = x + s1;
            }
            decisionParameter = decisionParameter + 2 * dy;
            Pixel::setCordinates(x, y);
            Pixel::draw();
            i++;
        } while (i <= dx);
    }

    void drawDdaLine(int colour) {
        float x, y, dx, dy, steps;
        int i;
        Pixel::setColor(colour);
        dx = abs(x2 - x1);
        dy = abs(y2 - y1);
        if (dx >= dy) {
            steps = dx;
        } else {
            steps = dy;
        }
        dx = dx / steps;
        dy = dy / steps;
        x = x1 + 0.5;
        y = y1 + 0.5;
        i = 1;
        while (i <= steps) {
            Pixel::setCordinates(x, y);
            Pixel::draw();
            x = x + dx;
            y = y + dy;
            i++;
        }
        Pixel::setCordinates(x, y);
        Pixel::draw();
    }
};

int main() {
    int gd = DETECT, gm;
    int choice, x1, y1, x2, y2, xmax, ymax, xmid, ymid;
    char a;
    initgraph(&gd, &gm, NULL);
    Pixel aPixel;
    Line aLine;
    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax / 2;
    ymid = ymax / 2;
    line(xmid, 0, xmid, ymax);
    line(0, ymid, xmax, ymid);
    do {
        cout << "\n1.DDA LINE";
        cout << "\n2.BRESENHAM'S LINE";
        cout << "\n3.EXIT";
        cout << "\nEnter your choice :";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\n Enter x1 :";
                cin>>x1;
                cout << "\n Enter y1 :";
                cin>>y1;
                cout << "\n Enter x2 :";
                cin>>x2;
                cout << "\n Enter y2 :";
                cin>>y2;
                aLine.setLineCordinates(x1 + xmid, ymid - y1, x2 + xmid, ymid - y2);
                aLine.drawDdaLine(6);
                break;
            case 2:
                cout << "\n Enter x1: ";
                cin>>x1;
                cout << "\n Enter y1: ";
                cin>>y1;
                cout << "\n Enter x2: ";
                cin>>x2;
                cout << "\n Enter y2: ";
                cin>>y2;
                aLine.setLineCordinates(x1 + xmid, ymid - y1, x2 + xmid, ymid - y2);
                aLine.drawBresenhamsLine();
                break;
            case 3:
                exit(0);
                break;
        }
        cout << "\nDO U Want To Continue Y Or N: ";
        cin >> a;
    } while (a != 'n' || a != 'N');
    delay(1000);
    getch();
    closegraph();
    return EXIT_SUCCESS;
}