
/*
 * Write C++/Java program for line drawing using DDA or Bresenhams algorithm
 *  with patterns such as solid, dotted, dashed, dash dot and thick. 
 */

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class line_patterns {
    int x1, x2, y1, y2, steps, dx, dy, gd, gm, n, thickness;
public:
    void fget_points();
    void fline_patterns();
};

void line_patterns::fget_points() {
    cout << "\nEnter starting x and y co-ordinates of line :";
    cin >> x1 >> y1;
    cout << "\nEnter ending x and y co-ordinates of line :";
    cin >> x2 >> y2;
}

void line_patterns::fline_patterns() {
    float x, y;
    char ch;
    int k;
    float xin, yin;
    do {
        cout << "\nEnter thickness for thick line :";
        cin >> thickness;
        cout << "\nPress 1 for solid line ";
        cout << "\nPress 2 for Dotted line ";
        cout << "\nPress 3 for dashed line ";
        cout << "\nPress 4 for dashed dot line ";
        cout << "\nPress 5 for thick line ";
        cout << "\nEnter youe choice :";
        cin >> n;
        gd = DETECT;
        initgraph(&gd, &gm, NULL);
        dx = x2 - x1;
        dy = y2 - y1;
        if (abs(dx) > abs(dy))
            steps = abs(dx);
        else
            steps = abs(dy);
        x = x1;
        y = y1;
        putpixel(x, y, RED);
        xin = (float) dx / steps;
        yin = (float) dy / steps;
        switch (n) {
            case 1:
                for (k = 1; k < steps; k++) {
                    x = x + xin;
                    y = y + yin;
                    putpixel(x, y, 3);
                    delay(100);
                }
                break;
            case 2:
                for (k = 1; k < steps; k++) {
                    x = x + xin;
                    y = y + yin;
                    if (k % 2 == 0)
                        putpixel(x, y, 3);
                    delay(100);
                }
                break;
            case 3:

                for (k = 1; k < steps; k++) {
                    x = x + xin;
                    y = y + yin;
                    if (k % 10 != 6 && k % 10 != 7 && k % 10 != 8)
                        putpixel(x, y, 3);
                    delay(100);
                }
                break;
            case 4:
                for (k = 1; k < steps; k++) {
                    x = x + xin;
                    y = y + yin;
                    if (k % 10 != 6 && k % 10 != 4)
                        putpixel(x, y, RED);
                    delay(100);
                }
                break;
            case 5:
                for (k = 1; k < steps; k++) {
                    x = x + xin;
                    y = y + yin;
                    int a, b;
                    a = x;
                    b = y;
                    putpixel(x, y, RED);
                    for (int i = 0; i < thickness; i++) {
                        putpixel(a + 50, b, RED);
                        delay(10);
                    }
                }
                break;
            default:
                cout << "\nEnter valid choice ";
        }
        closegraph();
        cout << "\nDo you wish to continue (Y/N) :";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\nTHANK YOU";
}

int main() {
    line_patterns l;
    l.fget_points();
    l.fline_patterns();
    return EXIT_SUCCESS;
}