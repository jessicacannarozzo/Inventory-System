/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <cmath>
#include "Customer.h"

int Customer::nextCustId = 2001;

Customer::Customer(string n)
{
  id     = nextCustId++;
  name   = n;
  points = 0;
}

void Customer::buyItem(Product* p) {
  Purchase array[pArray.getPurchArraySize()];
  array = pArray.getPurchArray();

  for (int i = 0; i < pArray.getPurchArraySize(); i++) {
    if (array[i].getProd().getId() == p->getId()) {
      //product was bought in the past, increment units by 1
      pArray.getPurchArray().getProd().incrementUnits();
    }
  }
}

int    Customer::getId()     { return id;     }
string Customer::getName()   { return name;   }
int    Customer::getPoints() { return points; }
PurchArray Customer::getPurchArray() { return pArray; } //getter added
