#pragma once
#include "libraries.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef
struct text_info2 {
   unsigned char winleft;        /* left window coordinate */
   unsigned char wintop;         /* top window coordinate */
   unsigned char winright;       /* right window coordinate */
   unsigned char winbottom;      /* bottom window coordinate */
   unsigned char attribute;      /* text attribute */
   unsigned char normattr;       /* normal attribute */
   unsigned char currmode;       /* BW40, BW80, C40, C80, or C4350 */
   unsigned char screenheight;   /* text screen's height */
   unsigned char screenwidth;    /* text screen's width */
   unsigned char curx;           /* x-coordinate in current window */
   unsigned char cury;           /* y-coordinate in current window */
} text_info2;

text_info2 vActual2 = {0, 0, 79, 24, 15, 15, 14, 25, 80, 1, 1};

void gotoxy(int x, int y) {
   COORD c;

   if(x < 1 || x > vActual2.screenwidth ||
      y < 1 || y > vActual2.screenheight) return;
   vActual2.curx = x;
   vActual2.cury = y;
   c.X = vActual2.winleft + x - 1;
   c.Y = vActual2.wintop + y - 1;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void textbackground(int newcolor) {
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
      (csbi.wAttributes & 0x0f) | (newcolor << 4));
   vActual2.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}

void textcolor(int newcolor) {
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
      (csbi.wAttributes & 0xf0) | newcolor);
   vActual2.attribute = (csbi.wAttributes & 0xf0) | newcolor;
}

#ifdef __cplusplus
}
#endif
