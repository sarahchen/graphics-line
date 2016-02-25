#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int A = y1 - y0;
  int B = x0 - x1;
  float m = -((float)A/ (float)B);
  int d = (2*A) + B;

  int x = x0;
  int y = y0;
  // 0 < m < 1 (Octant 1)
  if(0 <= m && m <= 1) {
    while(x < x1) {
      plot(s, c, x, y);
      if(d > 0) {
        y = y + 1;
        d = d + (2*B);
      }
      x = x+1;
      d = d + (2*A);
    }
  }
  // m > 1 (Octant 2)
  else if(m > 1) {
    while(y < y0) {
      plot(s, c, x, y);
      if(d < 0) {
        x = x + 1;
        d = d + (2*A);
      }
      y = y+1;
      d = d + (2*B);
    }
  }
  // -1 < m < 0 (Octant 8)
  else if(-1<=m && m<=0) {
    while(x < x1) {
      plot(s, c, x, y);
      if(d < 0) {
        y = y-1;
        d = d - (2*B);
      }
      x = x+1;
      d = d + (2*A);
    }
  }
  // m < -1 (Octant 7)
  else if(m<(-1)) {
    while(y < y1) {
      plot(s, c, x, y);
      if(d > 0) {
        x = x+1;
        d = d + (2*A);
      }
      y = y-1;
      d = d-(2*B);
    }
  }
  
}
