/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: CustList.h                           */
/* List of customers that may buy products from    */
/* the store.                                      */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <list>
#include <iterator>
#include <algorithm>
#include <Customer.h>

#ifndef CUSTLIST_H
#define CUSTLIST_H

class CustList {
  public:
    CustList();
    ~CustList();
    void add(Customer*); //adds new customer to the array
    Customer* get(int);  //returns customer object at a given position in array
  private:
    list<Customer> custList;
};

#endif
