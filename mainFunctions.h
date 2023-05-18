/*! \file mainFunctions.h
	\brief Declaration of the general functions used in the user interfaces

	Details.
*/


#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include "polygon.h"

#define MAX_NUMBER_OF_OBJECTS 100

void ListReset(Polygon* _list[]);
void DisplayMenu();
void AskChoice(int& choice);
void ChoiceManager(const int choice, Polygon* _list[], int& _listCnt);
bool CreateRectangle(Polygon* _list[], int& _listCnt);
bool CreateRhombus(Polygon* _list[], int& _listCnt);
bool CreateRightTriangle(Polygon* _list[], int& _listCnt);
bool Draw(Polygon* _list[], const int _listCnt);
bool ListDelete(Polygon* _list[], int& _listCnt);

#endif
