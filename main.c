#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;


  c.red = 0;
  c.green =0;
  c.blue = 0;

  clear_screen(s);
int i,k,l,m;
 i = 0;
 k = 0;
 l = 0;
 m = 0;
 for(i;i<500;i++){
    if (i > 250)
      c.red = i - 250;
     c.blue = i;
     draw_line(250, 250, 500, 500 - i,s,c);
 }
 for(l;l<500;l++){
     c.green = l;
     if (l > 250)
      c.red= 250 - (l - 250);

     draw_line(250 ,250 , 500 - l, 0 ,s,c);
 }
 for(k;k<500;k++){
   if (k < 250)
     c.blue = 250 - k;
   if (k > 250)
    c.green = 250 - (k - 250);
     //if (k > 250)
       //c.green = 250 - (k - 250);
     draw_line(0 , k, 250,250 ,s,c);
 }
 for(m;m<500;m++){
   if (m < 250){
     c.red = m;
     c.green =m;
     c.blue = m;
   }
   else{
     c.red = 250- (m- 250);
     c.green =250 - (m - 250);
     c.blue = 250 - (m- 250);
   }
     draw_line(m ,500 ,250,250 ,s,c);
 }




  display(s);
  save_extension(s, "lines.png");
}
