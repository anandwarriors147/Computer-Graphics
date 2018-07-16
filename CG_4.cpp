
/* Write C++/Java program to draw a convex polygon and fill it with desired
 * color using Seed fill algorithm. Use mouse interfacing to draw polygon
 */

#include<iostream>
#include<graphics.h>
using namespace std;

void boundary_fill(int x, int y, int boundary_c, int fill_c) {
    if (getpixel(x, y) != boundary_c && getpixel(x, y) != fill_c) {
        putpixel(x, y, fill_c);
        boundary_fill(x, y + 1, boundary_c, fill_c);
        boundary_fill(x, y - 1, boundary_c, fill_c);
        boundary_fill(x - 1, y, boundary_c, fill_c);
        boundary_fill(x + 1, y, boundary_c, fill_c);
    }
}

void flood_fill(int x, int y, int fill_c) {
    if (getpixel(x, y) != fill_c) {
        putpixel(x, y, fill_c);
        flood_fill(x, y + 1, fill_c);
        flood_fill(x, y - 1, fill_c);
        flood_fill(x - 1, y, fill_c);
        flood_fill(x + 1, y, fill_c);
        return;
    }
}

void bresenham_line(int x1, int y1, int x2, int y2, int color) {
    int dx, dy, steps, dp, x, y, i;
    dx = x2 - x1;
    dy = y2 - y1;
    if (dy < dx) {
        x = x1;
        y = y1;
        if (dy == -90)
            steps = 90;
        else
            steps = dx;
    } else {

        steps = dy;
    }
    dp = 2 * dy - dx;
    for (i = 0; i < steps; i++) {
        if (dp < 0) {
            if (dy == -90)
                y = y - 1;
            else
                x = x + 1;
            putpixel(x, y, color);
            dp = dp + 2 * dy;
        } else {
            y = y + 1;
            putpixel(x, y, color);
            dp = dp + 2 * dy - 2 * dx;
        }
        delay(10);
    }
}

int main() {
    char ch;
    int gd = DETECT, gm;
    int x, y, color, n;
    int rect[10] = {150, 60, 280, 60, 280, 150, 150, 150, 150, 60};
    do {
        cout << "\n******SEED FILLING ALGORITHMS******";
        cout << "\nPress 1 for implementing boundary fill algorithm ";
        cout << "\nPress 2 for implementing flood fill algorithm";
        cout << "\nEnter your choice :";
        cin >> n;
        switch (n) {
            case 1:
                cout << "\nEnter the co-ordinates of seed :";
                cin >> x >> y;
                cout << "\nEnter the color which you want to fill in polygon :";
                cin >> color;
                initgraph(&gd, &gm, NULL);
                drawpoly(5, rect);
                outtextxy(180, 160, "Rectangle");
                boundary_fill(x, y, WHITE, color);
                delay(100);
                closegraph();
                break;
            case 2:
                initgraph(&gd, &gm, NULL);
                bresenham_line(150, 150, 150, 60, 4);
                bresenham_line(150, 60, 280, 60, 1);
                bresenham_line(280, 60, 280, 150, 3);
                bresenham_line(150, 150, 280, 150, 2);
                cout << "\nEnter the co-ordinates of seed :";
                cin >> x >> y;
                cout << "\nEnter the color which you want to fill in polygon :";
                cin >> color;
                outtextxy(180, 160, "Rectangle");
                flood_fill(x, y, color);
                delay(10);
                closegraph();
                break;
            default:
                cout << "\nEnter valid choice ";
        }
        cout << "\nDo you wish to continue (Y/N) :";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    cout << "\nTHANK YOU";
    return EXIT_SUCCESS;
}

/*
 #include<stdio.h>
#include<graphics.h>
void right_fill(int x, int y);
void left_fill(int x, int y);
int main()
{
 int gd=DETECT, gm,op,i,x,y,n,a[10][3];
   printf("\nEnter no. of vertices : ");
 scanf("%d", &n);
 for(i=0;i<n;i++)
    {
     printf("\nEnter the co-ordinates : ");
     scanf("%d%d", &a[i][0], &a[i][1]);
    }
    printf("\nEnter seeding point : ");
    scanf("%d%d", &x, &y);
    initgraph(&gd, &gm, NULL);
    for(i=0;i<n;i++)
    {
     line(a[i][0], a[i][1], a[(i+1)%n][0], a[(i+1)%n][1]);
    }
    right_fill(x,y);
    left_fill(x-1,y);
    getch();
}
 void right_fill(int x, int y)
 {
  while((getpixel(x,y)!=WHITE) && (getpixel(x,y)!=RED))
  {
   delay(1);
   putpixel(x,y,RED);
   right_fill(++x,y);
   x=x-1;
   right_fill(x,y-1);
   right_fill(x,y+1);
  }
 }
 void left_fill(int x, int y)
 {
  while((getpixel(x,y)!=WHITE) && (getpixel(x,y)!=RED))
  {
   delay(1);
   putpixel(x,y,RED);
   left_fill(--x,y);
   x=x+1;
   left_fill(x,y-1);
   left_fill(x,y+1);
  }
 }
 */