/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: CustList.cc                          */
/* List of customers that may buy products from    */
/* the store.                                      */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "CustList.h"

CustList::CustList() {} //empty custList

CustList::~CustList() 
{

  for(itr = custList.begin(); itr != custList.end(); ++itr)
  {
    delete *itr;
  } 
  custList.clear();
  
}

void CustList::add(Customer* c) { //adds new customer to the end of the array
  custList.push_back(c);
}

Customer& CustList::get(int index) { //returns customer object at a given position in array
  Customer cust;
  for (itr = custList.begin(); itr != custList.end(); itr++) {
    if (index == 0) return **itr;
    else index--;
  }
  return cust; //customer does not exist
}
