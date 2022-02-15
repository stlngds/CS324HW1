#include <iostream>
#include "graphics.h"
#include <math.h>

int main() {

	//////////////////////////////////////
	//Init
	//////////////////////////////////////

	InitGraphics(); 
	constexpr int size = 1000; //Our canvas is made up of 1000 by 1000 pixels (represented by a vector of RGB values from 0 to 255)
	Canvas gc(size, size, colors::WHITE); //Background color is white.
	//Temporary stuff.
	Point p;
	double x, y;


	//////////////////////////////////////
	//Plots
	//////////////////////////////////////

	//Plot the function y = 3.0*e^(-0.33x)*sin(3x) for x = 0 to x = 3*pi, with a continuous line.
	SetWindow(0, -10, (3.0 * 3.141592653589), 10); //What is drawn on our canvas will be all the space wrt the function from x = 0 to 3pi, and y = -10 to 10.
	p = WindowToViewport(0, 0); //Initial point is at 0, 0.
	p = ViewportToCanvas(p.x, p.y, size, size); //
	MoveTo2D(p.x, p.y);

	for (x = 0; x <= (3.0 * 3.141592653589); x += 0.01) {
		y = 3.0 * exp((-0.33 * x)) * sin(3.0 * x);
		p = WindowToViewport(x, y);
		p = ViewportToCanvas(p.x, p.y, size, size);
		DrawTo2D(p.x, p.y, gc);
	}
	std::string fileName("sinusoidalcontinuous.ppm");
	SaveCanvasToFile(gc, fileName);

	return 1;
}