/*! \file mainFunctions.cpp
	\brief Implementation of the general functions of mainFunctions.h

	Details.
*/

#include "mainFunctions.h"
#include "polygon.h"
#include "rectangle.h"
#include "rhombus.h"
#include "RightTriangle.h"

/// @brief initializing the array to 0
void ListReset(Polygon* _list[])
{
	for (int i = 0; i < MAX_NUMBER_OF_OBJECTS; i++)
	{
		_list[i] = 0;
	}
}

/// @brief show the menu
void DisplayMenu()
{

	cout << endl;
	cout << "Choose what to do:" << endl;
	cout << endl;
	cout << "1 - Create a Rectangle" << endl;
	cout << "2 - Create a Rhombus" << endl;
	cout << "3 - Create a Right Triangle" << endl;
	cout << "4 - Draw all the items in the list" << endl;
	cout << "5 - Exit" << endl;
	cout << endl;

}

/// @brief asking the user to choose what to do, saving the choice in _choice
/// @param _choice variable to save user choice
void AskChoice(int& _choice) 
{
	// choice reset
	_choice = 0;
	cout << "Insert number: ";
	scanf_s("%d", &_choice);
	// if charachter is inserted and i don't catch with a getchar the stdin flux gets blocked, a charachter does not change the value of _choice, so the reset automaticly chooses an unexisting option
	getchar();
	cout << endl;

}

/// @brief function to manage the possible choices
/// @param _choice choice done by the user (const)
/// @param _list list of all to objects
/// @param _listCnt reference to the list counter
void ChoiceManager(const int _choice, Polygon* _list[], int& _listCnt)
{
	switch (_choice)
	{
	case 1:

		if (CreateRectangle(_list, _listCnt))
			cout << endl << "Rectangle created" << endl;
		else
			cout << endl << "Rectangle NOT created" << endl;
		break;

	case 2:

		if(CreateRhombus(_list, _listCnt))
			cout << endl << "Rhombus created" << endl;
		else
			cout << endl << "Rhombus NOT created" << endl;
		break;

	case 3:

		if (CreateRightTriangle(_list, _listCnt))
			cout << endl << "Triangle created" << endl;
		else
			cout << endl << "Triangle NOT created" << endl;
		break;

	case 4:

		Draw(_list, _listCnt);
		break;

	case 5:

		ListDelete(_list, _listCnt);
		cout << "Exiting from the program..." << endl;
		exit(0);

	default:

		cout << "Choosen number is not an option" << endl;
		cout << "Insert a new one" << endl;
		break;
	}
}

/// @brief create a Rectangle and add it into the list
/// @param _list list of all to objects
/// @param _listCnt reference to the list counter
/// @return true if everything went right, false if something went wrong
bool CreateRectangle(Polygon* _list[], int& _listCnt)
{

	float _length;
	float _width;

	/// check if the list is full
	if (_listCnt >= MAX_NUMBER_OF_OBJECTS)
	{

		cout << "List is full" << endl;

		/// list is full - Error
		return false;

	}

	/// asking object dimensions
	cout << "Insert Rectangle length value:" << endl;
	scanf_s("%f", &_length);
	cout << "Insert Rectangle width value:" << endl;
	scanf_s("%f", &_width);
	cout << endl;

	/// creating object and adding it to the list
	_list[_listCnt] = new Rectangle(_width, _length);
	
	/// object added, updating listCnt
	_listCnt++;

	return true;

}

/// @brief create a Rhombus and add it into the list
/// @param _list list of all to objects
/// @param _listCnt reference to the list counter
/// @return true if everything went right, false if something went wrong
bool CreateRhombus(Polygon* _list[], int& _listCnt)
{

	float _diagH;
	float _diagV;

	/// check if the list is full
	if (_listCnt >= MAX_NUMBER_OF_OBJECTS)
	{

		cout << "List is full" << endl;

		/// list is full - Error
		return false;

	}

	/// asking object dimensions
	cout << "Insert Rhombus horizontal diagonal value:" << endl;
	scanf_s("%f", &_diagH);
	cout << "Insert Rhombus vertical diagonal value:" << endl;
	scanf_s("%f", &_diagV);
	cout << endl;

	/// creating object and adding it to the list
	_list[_listCnt] = new Rhombus(_diagH, _diagV);

	/// object added, updating listCnt
	_listCnt++;

	return true;

}

/// @brief create a Right Triangle and add it into the list
/// @param _list list of all to objects
/// @param _listCnt reference to the list counter
/// @return true if everything went right, false if something went wrong
bool CreateRightTriangle(Polygon* _list[], int& _listCnt)
{

	float _base;
	float _altitude;

	/// check if the list is full
	if (_listCnt >= MAX_NUMBER_OF_OBJECTS)
	{

		cout << "List is full" << endl;

		/// list is full - Error
		return false;

	}

	/// asking object dimensions
	cout << "Insert Right Triangle base value:" << endl;
	scanf_s("%f", &_base);
	cout << "Insert Right Triangle altitude value:" << endl;
	scanf_s("%f", &_altitude);
	cout << endl;

	/// creating object and adding it to the list
	_list[_listCnt] = new RightTriangle(_base, _altitude);

	/// object added, updating listCnt
	_listCnt++;

	return true;

}

/// @brief Draw all the objects in the list, (just printing perimeter and area for each object)
/// @param _list list of all to objects
/// @param _listCnt value reached by listCnt, it is the number of objects in the list
void Draw(Polygon* _list[], const int _listCnt)
{

	/// cycling the array to draw every object in it
	for (int i = 0; i < _listCnt; i++)
	{

		cout << i << " - ";
		_list[i]->Draw();
		cout << endl;

	}

}

/// @brief Deleting all the objects in the list
/// @param _list list of all to objects
/// @param _listCnt value reached by listCnt, it is the number of objects in the list
void ListDelete(Polygon* _list[], int& _listCnt)
{

	for (int i = 0; i < _listCnt; i++)
	{
		delete _list[i];
		_list[i] = 0;
	}

	_listCnt = 0;

}