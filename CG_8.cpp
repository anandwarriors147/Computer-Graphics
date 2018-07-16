
/* Write C++/Java program to implement translation, sheer, rotation and
 *  scaling transformations on equilateral triangle and rhombus.
 * 
 *  Note : Implementation provided only for triangle.
 *         Rhombus can be done similarly.         
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <graphics.h>
#include <winbgim.h>
using namespace std;

class Translation {
private:
    int value;
public:

    void setValue(int temp) {
        value = temp;
    }

    int getValue() {
        return value;
    }

    Translation operator+(Translation obj) {
        Translation t;
        t.value = value + obj.value;
        return t;
    }
};

class Scaling {
private:
    int value;
public:

    void setValue(int temp) {
        value = temp;
    }

    int getValue() {
        return value;
    }

    Scaling operator*(Scaling obj) {
        Scaling s;
        s.value = value * obj.value;
        return s;
    }
};

class Sheer {
private:
    int value;
public:

    void setValue(int temp) {
        value = temp;
    }

    int getValue() {
        return value;
    }

    Sheer operator+(Sheer obj) {
        Sheer t;
        t.value = value + obj.value;
        return t;
    }

    Sheer operator*(Sheer obj) {
        Sheer s;
        s.value = value * obj.value;
        return s;
    }
};

class Rotation {
private:
    int value;
public:

    void setValue(int temp) {
        value = temp;
    }

    int getValue() {
        return value;
    }

    Rotation operator+(Rotation obj) {
        Rotation r;
        r.value = value + obj.value;
    }

    Rotation operator-(Rotation obj) {
        Rotation r;
        r.value = value - obj.value;
    }
};

int main() {
    int gd = DETECT, gm;
    int choice;
    int x1, y1, x2, y2, x3, y3;
    int a, b, c, d, e, f, g, h;
    Translation t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14;
    Scaling s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14;
    Rotation r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16;
    Sheer sh1, sh2, sh3, sh4, sh5, sh6, sheerFactorY, sh7, sh8, sh9, sh10, sh11, sh12;
    do {
        cout << "\n\t\t M E N U";
        cout << "\n\t 1.Translation "
                << "\n\t 2.Scaling"
                << "\n\t 3.Rotation"
                << "\n\t 4.Sheering"
                << "\n\t 5.Exit"
                << "\n\t Please Enter Your Choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                int tx, ty;
                cout << "\n\tEnter the co-ordinates for triangle";
                cout << "\n\tEnter x1,y1 : ";
                cin >> x1 >> y1;
                cout << "\n\tEnter x2,y2 : ";
                cin >> x2 >> y2;
                cout << "\n\tEnter x3,y3 : ";
                cin >> x3 >> y3;
                cout << "\n\tEnter the Translation Parameters";
                cout << "\n\tEnter tx : ";
                cin >> tx;
                cout << "\n\tEnter ty : ";
                cin >> ty;
                t1.setValue(x1);
                t2.setValue(y1);
                t3.setValue(x2);
                t4.setValue(y2);
                t5.setValue(x3);
                t6.setValue(y3);
                t7.setValue(tx);
                t8.setValue(ty);
                initgraph(&gd, &gm, "");
                line(x1, y1, x2, y2);
                delay(500);
                line(x2, y2, x3, y3);
                delay(500);
                line(x3, y3, x1, y1);
                delay(500);
                t9 = t1 + t7;
                t10 = t2 + t8;
                t11 = t3 + t7;
                t12 = t4 + t8;
                t13 = t5 + t7;
                t14 = t6 + t8;
                a = t9.getValue();
                b = t10.getValue();
                c = t11.getValue();
                d = t12.getValue();
                e = t13.getValue();
                f = t14.getValue();
                line(a, b, c, d);
                delay(500);
                line(c, d, e, f);
                delay(500);
                line(e, f, a, b);
                delay(5000);
                closegraph();
                break;

            case 2:
                int sx, sy;
                cout << "\n\tEnter the co-ordinates for triangle";
                cout << "\n\tEnter x1,y1 : ";
                cin >> x1 >> y1;
                cout << "\n\tEnter x2,y2 : ";
                cin >> x2 >> y2;
                cout << "\n\tEnter x3,y3 : ";
                cin >> x3 >> y3;
                cout << "\n\tEnter the Scaling Parameters";
                cout << "\n\tEnter sx : ";
                cin >> sx;
                cout << "\n\tEnter sy : ";
                cin >> sy;
                s1.setValue(x1);
                s2.setValue(y1);
                s3.setValue(x2);
                s4.setValue(y2);
                s5.setValue(x3);
                s6.setValue(y3);
                s7.setValue(sx);
                s8.setValue(sy);
                initgraph(&gd, &gm, NULL);
                line(x1, y1, x2, y2);
                delay(500);
                line(x2, y2, x3, y3);
                delay(500);
                line(x1, y1, x3, y3);
                delay(500);
                s9 = s1 * s7;
                s10 = s2 * s8;
                s11 = s3 * s7;
                s12 = s4 * s8;
                s13 = s5 * s7;
                s14 = s6 * s8;
                a = s9.getValue();
                b = s10.getValue();
                c = s11.getValue();
                d = s12.getValue();
                e = s13.getValue();
                f = s14.getValue();
                line(a, b, c, d);
                delay(500);
                line(c, d, e, f);
                delay(500);
                line(e, f, a, b);
                delay(5000);
                closegraph();
                break;
            case 3:
                int degreeOfRotation;
                cout << "\n\tEnter the co-ordinates for triangle";
                cout << "\n\tEnter x1,y1 : ";
                cin >> x1 >> y1;
                cout << "\n\tEnter x2,y2 : ";
                cin >> x2 >> y2;
                cout << "\n\tEnter x3,y3 : ";
                cin >> x3 >> y3;
                cout << "\n\tEnter the Degree of Rotation : ";
                cin >> degreeOfRotation;
                degreeOfRotation = int(degreeOfRotation * M_PI) / 180;
                r1.setValue(x1);
                r2.setValue(y1);
                r3.setValue(x2);
                r4.setValue(y2);
                r5.setValue(x3);
                r6.setValue(y3);
                initgraph(&gd, &gm, "");
                line(x1, y1, x2, y2);
                delay(500);
                line(x2, y2, x3, y3);
                delay(500);
                line(x3, y3, x1, y1);
                delay(500);
                a = r3.getValue();
                a = a * cos((float) degreeOfRotation);
                r7.setValue(a);
                b = r4.getValue();
                b = b * sin((float) degreeOfRotation);
                r8.setValue(b);
                a = r3.getValue();
                a = a * sin((float) degreeOfRotation);
                r9.setValue(a);
                b = r4.getValue();
                b = b * cos((float) degreeOfRotation);
                r10.setValue(b);
                r11 = r7 - r8;
                r12 = r9 + r10;
                e = r11.getValue();
                f = r12.getValue();
                line(0, 0, e, f);
                g = e;
                h = f;
                a = r5.getValue();
                a = a * cos((float) degreeOfRotation);
                r13.setValue(a);
                b = r6.getValue();
                b = b * sin((float) degreeOfRotation);
                r14.setValue(b);
                c = r5.getValue();
                c = c * sin((float) degreeOfRotation);
                r15.setValue(c);
                d = r6.getValue();
                d = d * cos((float) degreeOfRotation);
                r16.setValue(d);
                e = r15.getValue();
                f = r16.getValue();
                line(0, 0, e, f);
                 delay(500);
                line(g, h, e, f);
                 delay(5000);
                break;
            case 4:
                int sheer;
                cout << "\n\tEnter the co-ordinates for triangle";
                cout << "\n\tEnter x1,y1 : ";
                cin >> x1 >> y1;
                cout << "\n\tEnter x2,y2 : ";
                cin >> x2 >> y2;
                cout << "\n\tEnter x3,y3 : ";
                cin >> x3 >> y3;
                cout << "\n\tEnter the Sheer factor in Y-direction : ";
                cin >> sheer;
                sheerFactorY.setValue(sheer);
                sh1.setValue(x1);
                sh2.setValue(y1);
                sh3.setValue(x2);
                sh4.setValue(y2);
                sh5.setValue(x3);
                sh6.setValue(y3);
                initgraph(&gd, &gm, "");
                line(x1, y1, x2, y2);
                delay(500);
                line(x2, y2, x3, y3);
                delay(500);
                line(x3, y3, x1, y1);
                delay(500);
                a = sh1.getValue() * sheerFactorY.getValue();
                sh7.setValue(a);
                d = sh7.getValue() + sh2.getValue();
                sh8.setValue(d);
                b = sh3.getValue() * sheerFactorY.getValue();
                sh9.setValue(b);
                e = sh9.getValue() + sh4.getValue();
                sh10.setValue(e);
                c = sh5.getValue() * sheerFactorY.getValue();
                sh11.setValue(c);
                f = sh11.getValue() + sh6.getValue();
                sh12.setValue(f);
                line(x1, d, x2, e);
                delay(500);
                line(x2, e, x3, f);
                delay(500);
                line(x3, f, x1, d);
                delay(5000);
                closegraph();
                break;
            case 5:
                exit(EXIT_SUCCESS);
                break;
        }
    } while (choice != 5);
    return EXIT_SUCCESS;
}