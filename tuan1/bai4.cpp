#include <graphics.h>
#include <conio.h>

//Ham Ve Xe Hinh Chu Nhat
void vehcn(int x, int y, int color) {
    setfillstyle(SOLID_FILL, color); // dat mau tô và màu tô cho các hình dac và mien dóng 
    bar(x, y, x+40, y+20);
    //duoc su dung de ve mot hình chu nhat dac có toa do góc trái trên là (x, y) và góc phai duoi là (x+40, y+20)
    //Kich thuoc cua HCN la 40 x 20
}

//Ham Chay
void run() {
    int speed = 1, x = 0, y = 200;

    while (1) {
        vehcn(x, y, LIGHTBLUE);

        if (kbhit()) {
            char c = getch();

            if (c == 27) break; //Esc
            if (c == 77) speed = 1;  // trai
            if (c == 75) speed = 4;  // phai
            if (c == 72) {
            	vehcn(x,y,0);
			    y -= 15;   // len
			}  
            if (c == 80){ 
                vehcn(x,y,0);
			    y += 15;   // xuong
			}
        }

        delay(speed * 35);
        vehcn(x, y, 0);

        x += 5;
        if (x > getmaxx()) x = 0;
        if (y > getmaxy()) y = 5;
        if (y < 0) y = getmaxy();
    }

    closegraph();//ket thuc do hoa
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");//bat dau do hoa

    run();

    getch();
    closegraph();//ket thuc do hoa
    return 0;
}