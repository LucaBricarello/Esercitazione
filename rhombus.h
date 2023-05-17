/*! \file rhombus.h
	\brief Declaration of the class Rhombus

	Details.
*/

#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <math.h>

#include "polygon.h"

using namespace std;

/// @class Rhombus
/// @brief to manage an object with the shape of a Rhombus inherit from Polygon
class Rhombus : public Polygon
{
private:

	float diagonalH;
	float diagonalV;
	float side;

	void Side();

	/// @name PURE VIRTUAL FUNCTIONS - IMPLEMENTATION
	/// @{
	float Area();
	float Perimeter();
	/// @}

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Rhombus();
	Rhombus(float dH, float dV);
	Rhombus(const Rhombus &r);
	~Rhombus();
	/// @}

	/// @name OPERATORS
	/// @{
	Rhombus& operator=(const Rhombus& r);
	bool operator==(const Rhombus& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const Rhombus& X);
	void Reset();
	/// @}

	/// @name GETTERS / SETTERS
	/// @{
	void SetHorD(float dH);
	void SetVerD(float dV);
	void SetDim(float dH, float dV);

	float GetHorD();
	float GetVerD();
	void GetDim(float& dH, float& dV);
	float GetSide();
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
