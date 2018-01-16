#include "Employee.h"
#include <cstring>
#include <cstdint>
#include <iostream>

Employee::Employee()
{
  imie_nazwisko = "";
  Position = "";
  Age = 0;
}

Employee::Employee(std::string i_m, std::string s, uint8_t w)
{
  imie_nazwisko = i_m;
  Position = s;
  Age = w;
}

Employee::~Employee()
{

}

std::ostream & operator << (std::ostream &s, const Employee &E)
{
  s << "Pracownik: \nImie i Nazwisko: \t\tPosition: \t\tAge: \n" << E.imie_nazwisko << "\t\t\t" << E.Position << "\t\t" << unsigned(E.Age) << "\n";
  return s;
}

Employee& Employee::operator=(const Employee& E)
{
  imie_nazwisko = E.imie_nazwisko;
  Position = E.Position;
  Age = E.Age;
  return *this;
}
