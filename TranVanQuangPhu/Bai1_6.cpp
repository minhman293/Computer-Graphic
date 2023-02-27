#include <graphics.h>
#include <math.h>

int main()
{
   initwindow(600, 600);
   	setbkcolor(15);							// set background
	cleardevice();

   setcolor(BLUE);
   for(int i=0;i<=300;i++)
   {
   		line(300,i,600,i);
	} 
	getch();
}

