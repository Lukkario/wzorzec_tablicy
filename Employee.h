#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <cstdint>
#include <iostream>

class Employee{
public:
      std::string imie_nazwisko;
      std::string Position;
      uint8_t Age;
      Employee();
      Employee(std::string, std::string, uint8_t);
      ~Employee();
      Employee& operator=(const Employee&);
      friend std::ostream& operator << (std::ostream &, const Employee &);
};


#endif
