/// \file RightTriangle.cpp
///	\brief class RightTriangle: implementation of the functions
///
///	Details.
///

#include <iostream>

#include "RightTriangle.h"

//===============================================================================================================
//CONSTRUCTORS - DESTRUCTOR

/// @brief default constructor 
RightTriangle::RightTriangle() 
{

	cout << "RightTriangle - Default Constructor" << endl;

	Init();

}

/// @brief init constructor 
/// @param _base base of the triangle
/// @param _altitude altitude of the triangle
RightTriangle::RightTriangle(float _base, float _altitude) 
{

	Init();

	cout << "RightTriangle - Init Constructor" << endl;

	if (_base <= 0.)
		WarningMessage("Constructor: base should be > 0");
	else
		base = _base;

	if (_altitude <= 0.)
		WarningMessage("Constructor: altitude should be > 0");
	else
		altitude = _altitude;

	/// updating area, perimeter and hypotenuse values each time the dimensions get changed
	Hypotenuse();
	Area();
	Perimeter();
}

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
RightTriangle::RightTriangle(const RightTriangle& r) 
{

	cout << "RightTriangle - Copy Constructor" << endl;

	Init(r);

}

/// @brief destructor 
RightTriangle::~RightTriangle() 
{

	cout << "RightTriangle - Destructor" << endl;
	Reset();

}

//===============================================================================================================
//OPERATOR OVERLOAD

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
RightTriangle& RightTriangle::operator=(const RightTriangle& r) 
{

	cout << "RightTriangle - operator =" << endl;

	Reset();
	Init(r);

	return *this;

}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same diagonals  
bool RightTriangle::operator==(const RightTriangle& r) 
{

	if (r.base == base && r.altitude == altitude)
		return true;

	return false;

}

//===============================================================================================================
//INITIALIZERS

/// @brief default initialization of the object, updating area, perimeter and hypotenuse values
void RightTriangle::Init() 
{

	Reset();

	base = 0.;
	altitude = 0.;

	/// updating area, perimeter and hypotenuse values each time the dimensions get changed
	Hypotenuse();
	Area();
	Perimeter();

}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void RightTriangle::Init(const RightTriangle& r) 
{

	Reset();
	base = r.base;
	altitude = r.altitude;

	/// updating area, perimeter and hypotenuse values each time the dimensions get changed
	Hypotenuse();
	Area();
	Perimeter();

}

/// @brief total reset of the object    
void RightTriangle::Reset() 
{

	base = 0.;
	altitude = 0.;

	/// updating area, perimeter and hypotenuse values each time the dimensions get changed
	Hypotenuse();
	Area();
	Perimeter();

}

//===============================================================================================================
//COMPUTATIONAL

/// @brief compute the hypotenuse of the triangle and stores it in the variable hypotenuse of the class RightTriangle
void RightTriangle::Hypotenuse()
{

	hypotenuse = sqrt(pow(base, 2) + pow(altitude, 2));

}

/// @brief compute the area of the triangle and stores it in the variable area of the class Polygon
/// @return area of the triangle
float RightTriangle::Area() 
{

	area = ( ( base * altitude ) / 2. );
	return area;

}

/// @brief compute the perimeter of the triangle and stores it in the variable perimeter of the class Polygon
/// @return perimeter of the triangle
float RightTriangle::Perimeter() 
{

	perimeter = base + altitude + hypotenuse;
	return perimeter;

}

//===============================================================================================================
//SETTERS

/// @brief set the base of the triangle, updating area, perimeter and hypotenuse values
/// @param _base base value
void RightTriangle::SetBase(float _base) 
{

	if (_base < 0.) 
	{
		WarningMessage("SetBase: base should be > 0");
		return;
	}

	base = _base;

	/// updating area, perimeter and hypotenuse values each time the dimensions get changed
	Hypotenuse();
	Area();
	Perimeter();

}

/// @brief set the altitude of the triangle, updating area, perimeter and hypotenuse values
/// @param _altitude altitude value
void RightTriangle::SetAltitude(float _altitude) 
{

	if (_altitude < 0.) 
	{
		WarningMessage("SetAltitude: altitude should be > 0");
		return;
	}

	altitude = _altitude;

	/// updating area, perimeter and hypotenuse values each time the dimensions get changed
	Hypotenuse();
	Area();
	Perimeter();

}

/// @brief set base and altitude of the triangle, updating area, perimeter and hypotenuse values
/// @param _base base value
/// @param _altitude altitude value
void RightTriangle::SetDim(float _base, float _altitude) 
{

	SetBase(_base);
	SetAltitude(_altitude);

}

//===============================================================================================================
//GETTERS

/// @brief get the base value of the triangle
/// @return base value
float RightTriangle::GetBase() 
{

	return base;

}

/// @brief get altitude value of the triangle
/// @return altitude value
float RightTriangle::GetAltitude() 
{

	return altitude;
}

/// @brief get base and altitude values of the triangle
/// @param _base parameter to return the base value
/// @param _altitude parameter to return the altitude value
void RightTriangle::GetDim(float& _base, float& _altitude) 
{

	_base = base;
	_altitude = altitude;

}

/// @brief get the hypotenuse value of the triangle
/// @return hypotenuse value
float RightTriangle::GetHypotenuse() 
{

	return hypotenuse;

}

//===============================================================================================================
//DIAGNOSTIC

/// @brief write an error message 
/// @param string message to be printed
void RightTriangle::ErrorMessage(const char* string) 
{

	cout << endl << "ERROR -- RightTriangle --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void RightTriangle::WarningMessage(const char* string) 
{

	cout << endl << "WARNING -- RightTriangle --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void RightTriangle::Dump() 
{
	cout << endl;

	cout << "---RightTriangle---" << endl;
	cout << endl;

	cout << "Base = " << base << endl;
	cout << "Altitude = " << altitude << endl;
	cout << "Hypotenuse = " << hypotenuse << endl;

	Polygon::Dump();

	cout << endl << flush;

}

//===============================================================================================================
//DRAW

/// @brief to draw the Triangle, just printing on the screen "Triangle printed"
void RightTriangle::Draw()
{

	cout << "Triangle printed" << endl;
	cout << "Area = " << area << endl;
	cout << "Perimeter = " << perimeter << endl;

}