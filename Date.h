/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: Date.h                               */
/* MONTH/DAY/YEAR                                  */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef DATE_H
#define DATE_H
#include <ostream>
using namespace std;

class Date {
  friend ostream& operator<<(ostream&, Date&);
  public:
    Date(int, int, int);
    Date& operator+=(int);
    Date operator+(int);
    bool operator>(Date&);
    bool operator<(Date&);


  private:
    int convertToDays() const;
    void setDate(int);
    int month;
    int day;
    int year;
};

#endif
