/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: Date.cc                              */
/* MONTH/DAY/YEAR                                  */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>

Date::Date(int m, int d, int y) {
  this->month = m;
  this->day = d;
  this->year = y;
}

//overloaded operators
Date& Date::operator+=(int numDays) {
 this->setDate(convertToDays() + numDays);

 return *this;
}

Date Date::operator+(int numDays) {
  Date tempDate = *this;
  tempDate += numDays;

  return tempDate;
}


//Returns a boolean indicating whether this date is greater than the other
bool Date::operator>(Date& other) {
  if (this->convertToDays() > other.convertToDays()) {
    return true;
  } else return false;
}

//Returns a boolean indicating whether this date is less than the other
bool Date::operator<(Date& other) {
  if (this->convertToDays() < other.convertToDays()) {
    return true;
  } else return false;
}

void Date::setDate(int days) { //from days
  this->year = days / 365;
  this->month = (days % 365) / 30;
  this->day = (days % 365) % 30;
}

int Date::convertToDays() const {
  return (this->day + this->month*30 + this->year*365);
}

//print: source: Dr. Christine Laurendeau
ostream& operator<<(ostream& output, Date& d) {
  output<<setfill('0')<<setw(2)<<d.month<<"/"
      <<setfill('0')<<setw(2)<<d.day<<"/"
      <<setfill('0')<<setw(2)<<d.year;

  return output;
}
