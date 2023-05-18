/// \file rectangle.cpp
///	\brief class Rectangle: implementation of the functions
///
///	Details.
///

#include <iostream>

#include "Rectangle.h"

//===============================================================================================================
//CONSTRUCTORS - DESTRUCTOR

/// @brief default constructor
Rectangle::Rectangle() 
{

	cout << "Rectangle - Default Constructor" << endl;

	Init();

}

/// @brief init constructor
/// @param w width
/// @param h length
Rectangle::Rectangle(float w, float l) 
{

	Init();

	cout << "Rectangle - Init Constructor" << endl;

	if (w <= 0.)
		WarningMessage("Constructor: width should be > 0");
	else
		width = w;

	if (l <= 0.) 
		WarningMessage("Constructor: length should be > 0");
	else
		length = l;

	/// updating area and perimeter values each time the dimensions get changed
	Area();
	Perimeter();
}

/// @brief copy constructor
/// @param rectangle to copy passed by reference
Rectangle::Rectangle(const Rectangle &r)
{

	cout << "Rectangle - Copy Constructor" << endl;
	
	Init(r);

}

/// @brief destructor 
Rectangle::~Rectangle() 
{

	cout << "Rectangle - Destructor" << endl;
	Reset();

}

//===============================================================================================================
//OPERATOR OVERLOAD

/// @brief overload operator =, changes values of area and perimeter inherited from Polygon
/// @param Rectagle to be copied passed by reference (as a constant to block an eventual change to the object to be copied)
/// @return this object
Rectangle& Rectangle::operator=(const Rectangle& r)
{

	cout << "Rectangle - operator =" << endl;

	Reset();
	Init(r);

	return *this;

}

/// @brief overload operator == (useful for if(obj1=obj2) construct, when are to obj equal? we have to decide it, obj1 is the caller, obj2 is called as a parameter)
/// @param Rectagle to check if it is equal to the rectangle that called == operator (as a constant to block an eventual change)
/// @return true if lentgh and width of the two rectangles are equal, false otherwise (we decided the meaning of the operator ==)
bool Rectangle::operator==(const Rectangle& r)
{
	if (width == r.width && length == r.length)
	{
		return true;
	}
	return false;
}

//===============================================================================================================
//INITIALIZERS

/// @brief function to initialize a default Rectangle
void Rectangle::Init()
{

	Reset();

	width = 0;
	length = 0;

	/// updating area and perimeter values each time the dimensions get changed
	Area();
	Perimeter();

}

/// @brief function to copy the values of a given Rectangle in the Rectangle that calls the function
/// @param Reference to rectangle to copy
void Rectangle::Init(const Rectangle& r)
{
	
	Reset();
	
	width = r.width;
	length = r.length;

	/// updating area and perimeter values each time the dimensions get changed
	Area();
	Perimeter();

}

/// @brief function to reset the parameters of a Rectangle
void Rectangle::Reset()
{

	width = 0.;
	length = 0.;

	/// updating area and perimeter values each time the dimensions get changed
	Area();
	Perimeter();

}


//===============================================================================================================
//COMPUTATIONAL

/// @brief function to calculate the area of a rectangle, changes value of area inherited from Polygon, vitualized = 0
/// @return perimeter of the rectangle
float Rectangle::Area()
{

	area = ( width * length );
	return area;

}

/// @brief function to calculate the perimeter of a rectangle, changes value of perimeter inherited from Polygon, vitualized = 0
/// @return perimeter of the rectangle
float Rectangle::Perimeter()
{

	perimeter = 2 * (length + width);
	return perimeter;

}

//===============================================================================================================
//SETTERS

/// @brief set width of the object, updating area and perimeter values
/// @param w width value
void Rectangle::SetWidth(float w) 
{

	if (w < 0) {
		WarningMessage("SetWidth: width should be > 0");
		return;
	}

	width = w;

	/// updating area and perimeter values each time the dimensions get changed
	Area();
	Perimeter();
}

/// @brief set length of the object, updating area and perimeter values
/// @param l length value
void Rectangle::SetLength(float l) 
{

	if (l < 0) {
		WarningMessage("SetLength: length should be > 0");
		return;
	}

	length = l;

	/// updating area and perimeter values each time the dimensions get changed
	Area();
	Perimeter();
}

/// @brief set width and length of the object, updating area and perimeter values
/// @param w width value
/// @param l length value
void Rectangle::SetDim(float w, float l) 
{

	SetWidth(w);
	SetLength(l);

}

//===============================================================================================================
//GETTERS

/// @brief get width of the object
/// @return width of the object
float Rectangle::GetWidth() 
{

	return width;

}

/// @brief get length of the object
/// @return length of the object
float Rectangle::GetLength() 
{

	return length;

}

/// @brief get width and length of the object returning them in the given variables
/// @param w variable to return the width value
/// @param l variable to return the length value
void Rectangle::GetDim(float& w, float& l)
{

	w = width;
	l = length;

	return;
}

//===============================================================================================================
//DIAGNOSTIC

/// @brief write an error message 
/// @param string message to be printed
void Rectangle::ErrorMessage(const char* string)
{

	cout << endl << "ERROR -- Rectangle --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Rectangle::WarningMessage(const char* string)
{

	cout << endl << "WARNING -- Rectangle --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Rectangle::Dump()
{
	cout << endl;

	cout << "---Rectangle---" << endl;
	cout << endl;

	cout << "Length = " << length << endl;
	cout << "Width = " << width << endl;

	Polygon::Dump();

	cout << endl << flush;

}

//===============================================================================================================
//DRAW

/// @brief to draw the Rectangle, just printing on the screen "Rectangle printed"
void Rectangle::Draw()
{

	cout << "Rectangle printed" << endl;
	cout << "Area = " << area << endl;
	cout << "Perimeter = " << perimeter << endl;

}