 #include<stdio.h>
 #include<stdlib.h>
 #include<graphics.h>

 void ellips(int xc,int yc,int rx,int ry)
 {
   int gm=DETECT,gd;
   int x, y, p;
 initgraph(&gm,&gd," ");
   x=0;
   y=ry;
   
   p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
   while((2*x*ry*ry)<(2*y*rx*rx))
   {
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
delay(10);
        if(p<0)
        {
     x=x+1;
     p=p+(2*ry*ry*x)+(ry*ry);
        }
        else
        {
     x=x+1;
     y=y-1;
     p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
        }
   }
   p=((float)x+0.5)*((float)x+0.5)*ry*ry+(y-1)*(y-1)*rx*rx-rx*rx*ry*ry;

         while(y>=0)
   {
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc-y,WHITE);

        if(p>0)
        {
     y=y-1;
     p=p-(2*rx*rx*y)+(rx*rx);

        }
        else
        {
     y=y-1;
     x=x+1;
     p=p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
       }
   }
   getch();
   closegraph();
 }

 void main()
 {
   int xc,yc,rx,ry;
   printf("Enter type centre of ellipse Xc,yc:\t");
   scanf("%d %d",&xc,&yc);
   
   printf("Enter length alog to x axis\n");
   scanf("%d",&rx);
   printf("Enter length along y axis\n");
   scanf("%d",&ry);
   ellips(xc,yc,rx,ry);
   getch();
 }


