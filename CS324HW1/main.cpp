#include <iostream>
#include "graphics.h"

int main() {
	constexpr int size = 1000;

	Canvas gc(size, size, colors::WHITE);

	for (int y = 0; y < size; y += size / 8) {
		for (int x = 0; x < size; x += size / 8) {
			Line(gc, x, y, x + 80, y + 40, colors::RED);
			Line(gc, x, y + 40, x, y, colors::BLUE);

		}
	}

	std::string fileName("testLine.pbm");
	SaveCanvasToFile(gc, fileName);

	return 1;
}