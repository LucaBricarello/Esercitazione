/*! \file mainFunctions.h
	\brief Declaration of the general functions used in the user interfaces

	Details.
*/


#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include "polygon.h"

#define MAX_NUMBER_OF_OBJECTS 100

/// @name User options
/// @{
bool CreateRectangle(Polygon* _list[], int& _listCnt);
bool CreateRhombus(Polygon* _list[], int& _listCnt);
bool CreateRightTriangle(Polygon* _list[], int& _listCnt);
void Draw(Polygon* _list[], const int _listCnt);
/// @}

/// @name User interface
/// @{
void DisplayMenu();
void AskChoice(int& choice);
/// @}

/// @name Choice manager
/// @{
void ChoiceManager(const int choice, Polygon* _list[], int& _listCnt);
/// @}

/// @name Functions to manage the list
/// @{
void ListReset(Polygon* _list[]);
void ListDelete(Polygon* _list[], int& _listCnt);
/// @}

#endif
