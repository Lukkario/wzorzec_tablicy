#include <iostream>
#include "Employee.h" //Defines class Employee
#include "Map.h" //Defines template Map<Key,Value>

using namespace std;

int main(void)
{
	typedef unsigned int ID; //Identification number of Employee
	Map<ID,Employee> database; //Database of employees

	database.Add(761028073,Employee("Jan Kowalski","salesman",28)); //Add first
	database.Add(510212881,Employee("Adam Nowak","storekeeper",54)); //Add second
	database.Add(730505129,Employee("Anna Zaradna","secretary",32)); //Add third
	cout << database << endl; //Print database

	Map<ID,Employee> newDatabase = database; //Make a copy of database
	Employee* pE;
	pE = newDatabase.Find(510212881); //Find employee using its ID
	pE->Position = "salesman"; //Modify the position of employee
	pE = newDatabase.Find(761028073); //Find employee using its ID
	pE->Age = 29; //Modify the age of employee
	database = newDatabase; //Update original database

	cout << database << endl; //Print original database*/
	return 0;
}
