/*! \file rhombus.cpp
	\brief class Rhombus: implementation of the functions

	Details.
*/

#include<iostream>

#include "rhombus.h"

//===============================================================================================================
//CONSTRUCTORS - DESTRUCTOR

/// @brief default constructor
Rhombus::Rhombus() 
{

	cout << "Rhombus - Default Constructor" << endl;

	Init();

}

/// @brief init constructor
/// @param dH horizontal diagonal dimension
/// @param dL horizontal diagonal dimension
Rhombus::Rhombus(float dH, float dV)
{

	Init();

	cout << "Rhombus - Init Constructor" << endl;

	if (dH <= 0.)
		WarningMessage("Constructor: diagonalH should be > 0");
	else
		diagonalH = dH;

	if (dV <= 0.)
		WarningMessage("Constructor: diagonalV should be > 0");
	else
		diagonalV = dV;

	/// updating area, perimeter and side values each time the dimensions get changed
	Side();
	Area();
	Perimeter();

}


/// @brief copy constructor
/// @param Rhombus to copy passed by reference
Rhombus::Rhombus(const Rhombus& r)
{

	cout << "Rhombus - Copy Constructor" << endl;

	Init(r);

}

/// @brief destructor 
Rhombus::~Rhombus() 
{

	cout << "Rhombus - Destructor" << endl;
	Reset();

}

//===============================================================================================================
//OPERATOR OVERLOAD

/// @brief overload operator =, changes values of area and perimeter inherited from Polygon
/// @param Rhombus to be copied passed by reference (as a constant to block an eventual change to the object to be copied)
/// @return this object
Rhombus& Rhombus::operator=(const Rhombus& r)
{

	cout << "Rhombus - operator =" << endl;

	Reset();
	Init(r);


	return *this;

}

/// @brief overload operator == (useful for if(obj1=obj2) construct, when are to obj equal? we have to decide it, obj1 is the caller, obj2 is called as a parameter)
/// @param Rhombus to check if it is equal to the Rhombus that called == operator (as a constant to block an eventual change)
/// @return true if diagonalH and diagonalV of the two Rhombus are equal, false otherwise (we decided the meaning of the operator ==)
bool Rhombus::operator==(const Rhombus& r)
{

	if (diagonalH == r.diagonalH && diagonalV == r.diagonalV)
	{
		return true;
	}
	return false;

}

//===============================================================================================================
//INITIALIZERS

/// @brief function to initialize a default Rhombus, updating area, perimeter and side values
void Rhombus::Init()
{

	Reset();

	diagonalH = 0;
	diagonalV = 0;

	/// updating area, perimeter and side values each time the dimensions get changed
	Side();
	Area();
	Perimeter();

}

/// @brief function to copy the values of a given Rhombus in the Rhombus that calls the function
/// @param r reference to Rhombus to copy
void Rhombus::Init(const Rhombus& r)
{

	Reset();

	diagonalH = r.diagonalH;
	diagonalV = r.diagonalV;

	/// updating area, perimeter and side values each time the dimensions get changed
	Side();
	Area();
	Perimeter();

}

/// @brief function to reset the parameters of a Rhombus
void Rhombus::Reset()
{

	diagonalH = 0;
	diagonalV = 0;

	/// updating area, perimeter and side values each time the dimensions get changed
	Side();
	Area();
	Perimeter();

}

//===============================================================================================================
//COMPUTATIONAL

/// @brief compute the side of the Rhombus and stores it in the variable side of the class Rhombus
void Rhombus::Side()
{

	side = sqrt(pow(diagonalH/2, 2) + pow(diagonalV / 2, 2));

}

/// @brief compute the area of a Rhombus, changes value of area inherited from Polygon, vitualized = 0
/// @return area of the Rhombus
float Rhombus::Area()
{

	area = ( (diagonalH * diagonalV) / 2. );
	return area;

}

/// @brief compute the perimeter of a Rhombus, changes value of perimeter inherited from Polygon, vitualized = 0
/// @return perimeter of the Rhombus
float Rhombus::Perimeter()
{

	perimeter = (side * 4);
	return perimeter;

}

//===============================================================================================================
//SETTERS

/// @brief set diagonalH of the object, updating area, perimeter and side values
/// @param dH diagonalH value
void Rhombus::SetHorD(float dH)
{

	if (dH < 0.) {
		WarningMessage("SetHorD: horizontal diagonal should be > 0");
		return;
	}

	diagonalH = dH;

	/// updating area, perimeter and side values each time the dimensions get changed
	Side();
	Area();
	Perimeter();

}

/// @brief set diagonalV of the object, updating area, perimeter and side values
/// @param dV diagonalV value
void Rhombus::SetVerD(float dV)
{

	if (dV < 0.) {
		WarningMessage("SetVerD: vertical diagonal should be > 0");
		return;
	}

	diagonalV = dV;

	/// updating area, perimeter and side values each time the dimensions get changed
	Side();
	Area();
	Perimeter();

}

/// @brief set dimensions of the object, updating area, perimeter and side values
/// @param dH diagonalH value
/// @param dV diagonalV value
void Rhombus::SetDim(float dH, float dV)
{

	SetHorD(dH);
	SetVerD(dV);

}

//===============================================================================================================
//GETTERS

/// @brief get diagonalH of the object
/// @return diagonalH value
float Rhombus::GetHorD()
{

	return diagonalH;

}

/// @brief get diagonalV of the object
/// @return diagonalV value
float Rhombus::GetVerD()
{

	return diagonalV;

}

/// @brief get diagonalH and diagonalV of the object returning them in the given variables
/// @param given variable to return diagonalH
/// @param given variable to return diagonalV
void Rhombus::GetDim(float& dH, float& dV)
{

	dH = diagonalH;
	dV = diagonalV;

}

/// @brief get side of the object
/// @return side value
float Rhombus::GetSide()
{
	return side;
}

//===============================================================================================================
//DIAGNOSTIC

/// @brief write an error message 
/// @param string message to be printed
void Rhombus::ErrorMessage(const char* string)
{

	cout << endl << "ERROR -- Rhombus --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Rhombus::WarningMessage(const char* string)
{

	cout << endl << "WARNING -- Rhombus --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Rhombus::Dump()
{
	cout << endl;

	cout << "---Rhombus---" << endl;
	cout << endl;

	cout << "Horizontal Diagonal = " << diagonalH << endl;
	cout << "Vertical Diagonal = " << diagonalV << endl;
	cout << "Side = " << side << endl;

	Polygon::Dump();

	cout << endl << flush;

}

//===============================================================================================================
//DRAW

/// @brief to draw the Rhombus, just printing on the screen "Rhombus printed"
void Rhombus::Draw()
{

	cout << "Rhombus printed" << endl;

}