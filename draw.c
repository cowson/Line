#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x, y, A, B, d;
	if (x0 - x1 != 0){
		float m = ((y0 - y1)/(x0 - x1));
  	if (m  < 0){ //reverse line if it is going wrong way
    	x = x0;
    	y = y0;
    	x0 = x1;
    	y0 = y1;
    	x1 = x;
    	y1 = y;
  	}
}
  x = x0;
  y = y0;
  A = y1 - y0;
  B = -1 * (x1 - x0);
  if ((B * -1) >= A && A >= 0){//octant 1
    d = 2 * A + B;
    while (x < x1){
      plot(s, c, x, y);
      if (d > 0){
	y++;
	d += 2 * B;
      }
      x++;
      d += 2 * A;
    }
  }
  else if (A > (B * -1) && A >= 0){//octant 2
    d = A + 2 * B;
    while (y < y1){
      plot(s, c, x, y);
	if (d < 0){
	  x++;
	  d += 2 * A;
	}
      y++;
      d += 2 * B;
    }
  }
  else if (A < B){//octant 3
    d = A - 2 * B;
    while (y > y1){
      plot(s, c, x, y);
      if (d > 0){
	x++;
	d += 2 * A;
      }
      y--;
      d -= 2 * B;
    }
  }
  else {//octant 4
    d = 2 * A - B;
    while (x < x1){
      plot(s, c, x, y);
      if (d < 0){
	y--;
	d -= 2 * B;
      }
      x++;
      d += 2 * A;
    }
  }
}
