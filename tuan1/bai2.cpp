#include <winbgim.h>

int main() 
{
	initwindow(1000, 1000);					// init window graphics
	setbkcolor(15);							// set background
	cleardevice();
	den:
	for(int i=50;i<=450;i++)
	{
		setcolor(7);
		circle(2*i,500,100);	
		delay(0);
		setcolor(15);
		cleardevice();
		if(i==450)	
			goto den1;
	}
	den1:
	for(int i=450;i>=50;i--)
	{
		setcolor(7);
		circle(2*i,500,100);			
		delay(0) ;
		setcolor(15);
		cleardevice();
		if(i==50)
			goto den;
	}
	getch();
}