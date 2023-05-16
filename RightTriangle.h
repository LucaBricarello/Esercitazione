/*! \file RightTriangle.h
	\brief Declaration of the class RightTriangle

	Details.
*/


#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include <iostream>
#include <math.h>

#include "polygon.h"

using namespace std;

/// @class RightTriangle
/// @brief a class for RightTriangle
class RightTriangle : public Polygon
{
private:
	float base;
	float altitude;
	float hypotenuse;

	void Hypotenuse();

	/// @name PURE VIRTUAL FUNCTIONS - IMPLEMENTATION
	/// @{
	float Area();
	float Perimeter();
	/// @}

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	RightTriangle();
	RightTriangle(float _base, float _altitude);
	RightTriangle(const RightTriangle& r);
	~RightTriangle();
	/// @}

	/// @name OPERATORS
	/// @{
	RightTriangle& operator=(const RightTriangle& r);
	bool operator==(const RightTriangle& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const RightTriangle& r);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @{
	void SetBase(float _base);
	void SetAltitude(float _altitude);
	void SetDim(float _base, float _altitude);

	float GetBase();
	float GetAltitude();
	void GetDim(float& _base, float& _altitude);
	float GetHypotenuse();

	/// @}

	/// @name DRAWING
	/// @{
	void Draw();
	/// @}

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	void Dump();
	/// @}

};

#endif
