#include "mygraphics.h"

int main(){

	// Initialising
	int w = 0, h = 0;
	getWindowDimensions(w,h);

	cls();
	showConsoleCursor(false);

	drawLine(0,5,w,5,255);
	drawEllipse(w-10,0,w,10,0,255,0,0,255,0);

	// main event loop
	int i=0,j=0;
	while (true){
		drawRectangle(10*i+0,j+0,10*i+25,j+25,0,0,0,255,0,0);
		delay(10);
		drawRectangle(10*i+0,j+0,10*i+25,j+25,0,0,0,0,0,0);

		i++;
		if (10*i > w) i = 0;

		char c = getKey();

		if (c == 'q') break;

		if (c == 's') i = 0;

		if (c == 'k') j += 10;

		if (c == 'i') j -= 10;

	}

	// cleaning
	drawLine(0,5,w,5,0);
	drawEllipse(w-10,0,w,10,0,0,0,0,0,0);

	cls();
	showConsoleCursor(true);

	gotoxy(0,0);

	return 0;
}

