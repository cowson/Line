#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x, y, d;
  int A = y1 - y0;
  int B = -(x1-x0);
  x = x0;
  y = y0;
  d = 2*A + B;
  while(x <= x1) {
    plot(s, c, x, y);
    if (d > 0) {
      y++;
      d+=(2*B);
    }
    x++;
    d+= 2*A;
  }
}
