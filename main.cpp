#include <iostream>

#include "polygon.h"
#include "RightTriangle.h"

int main() 
{

	//test variables
	float base1;
	float altitude1;
	float hypotenuse1;
	float Per1;
	float Ar1;

	float base2;
	float altitude2;
	float hypotenuse2;
	float Per2;
	float Ar2;

	RightTriangle objA;
	RightTriangle objB(-2, -9);

	objB.Dump();

	RightTriangle objC(objB);

	objC.Dump();

	objA.SetDim(5, 10);
	objA.SetBase(6);
	objA.SetAltitude(18);

	base1 = objA.GetBase();
	altitude1 = objA.GetAltitude();
	hypotenuse1 = objA.GetHypotenuse();
	Ar1 = objA.GetArea();
	Per1 = objA.GetPerimeter();
	objA.GetDim(base2, altitude2);

	objA.Draw();

	objA.Dump();

	if (objC == objA)
	{
		cout << "TEST - Differenti" << endl;
	}

	objC = objA;

	if (objC == objA)
	{
		cout << "TEST - Uguali" << endl;
	}

	return 0;
}