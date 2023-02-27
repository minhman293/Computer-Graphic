#include <winbgim.h>

int main() 
{
	initwindow(1000, 1000);					// init window graphics
	setbkcolor(15);							// set background
	cleardevice();
	den:
	for(int i=50;i<=450;i++)
	{
		setcolor(9);
		circle(2*i,500,100);	
		delay(2);
		setcolor(15);
		cleardevice();
		if(i==450)	
			goto den;	
	}
	getch();
}