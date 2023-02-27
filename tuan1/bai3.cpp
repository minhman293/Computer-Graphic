#include <graphics.h>

int main()
{
    initwindow(1000, 600, " ");

for (int i = 0; i < 200; i++) {
   int x = rand() % getmaxx(); //// lay ngau nhien toa do cua diem x tu 0 den diem lon nhat cua X
   int y = rand() % getmaxy(); // lay ngau nhien toa do cua diem y tu 0 den diem lon nhat cua Y
   putpixel(x, y, WHITE); //to diem co toa do (x,y) trên màn hình theo màu White.
}

int x = 400, y = 300;  //Set tao do ban dau cua qua bong
int r = 30;  //Set ban kinh cua cua bong
int dx = 5, dy = 3;  //Set toc do cua qua bong

while (true) {
    setfillstyle(SOLID_FILL, LIGHTBLUE); // dat mau va to màu cho cac hinh dac va mien dong 
    fillellipse(x, y, r, r); // ve bong

    delay(50); // thoi gian delay giua các khung hình
    setcolor(BLACK); // xóa qua bóng o vi trí cu
    setfillstyle(SOLID_FILL, BLACK); // do màu den cho vi trí cu
    fillellipse(x, y, r, r); // xóa qua bóng o vi trí cu

    x += dx; // di chuyen qua bóng theo chieu ngang
    y += dy; // di chuyen qua bóng theo chieu doc

    // neu qua bóng cham biên thì doi chieu di chuyen
    if (x + r > getmaxx() || x - r < 0) {
        dx = -dx;
    }
    if (y + r > getmaxy() || y - r < 0) {
        dy = -dy;
    }

    // tao hieu ung di chuyen qua bóng bong XOR_PUT
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    fillellipse(x, y, r, r);
    fillellipse(x + dx, y + dy, r, r);
    
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x + dx, y + dy, r, r);
    fillellipse(x, y, r, r);
}


getch();
closegraph();
return 0;
}