/// \file main.cpp
///	\brief user interface
///
///	Details.
///

#include <iostream>

#include "polygon.h"
#include "rectangle.h"
#include "rhombus.h"
#include "RightTriangle.h"
#include "mainFunctions.h"

int main() 
{
	Polygon* list[MAX_NUMBER_OF_OBJECTS];
	int choice;
	int listCnt = 0;

	///initializing array
	ListReset(list);

	while (true)
	{

		/// printing menu
		DisplayMenu();

		/// option selection
		AskChoice(choice);

		/// managing the choice
		ChoiceManager(choice, list, listCnt);

	}

	return 0;
}