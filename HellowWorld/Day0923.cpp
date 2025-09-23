#include "Day0923.h"
#include <cstdio>

void Day0923::TestTemplateClass()
{
	Coordinate<int> PositionInt(1,3);
	Coordinate<float> PositionFloat(0.05f,5.7f);

	printf("PositionInt : %d, %d\n", PositionInt.x, PositionInt.y);
	printf("PositionFloat : %f, %f\n", PositionFloat.x, PositionFloat.y);

	PositionInt.Print();
	PositionFloat.Print();

	Coordinate<std::string> PositionString("A", "B");
	PositionString.Print();

}
