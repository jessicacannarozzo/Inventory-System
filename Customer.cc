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

int Customer::buyItem(Product* p) {
  for (int i = 0; i < pArray.getPurchArraySize(); i++) {
    if (pArray.getPurchArray()[i].getProd().getId() == p->getId()) {
      //product was bought in the past, increment units by 1
      pArray.getPurchArray()[i].getProd().incrementUnits();
      return 1; //don't need to iterate anymore, function successful
    }
  }
  //we didn't find the item if we get here. Customer has never bought this item before.

  //K: I think some kind of addProduct(p) function should be implemented on PurchArray class in order to keep encapsulation principles, then we could just call pArray.add(p) here and move code below to PurchArray class
  Purchase array[pArray.getPurchArraySize()+1];

  for (int i = 0; i < pArray.getPurchArraySize(); i++) {
    array[i] = pArray.getPurchArray()[i];
  }

  array[pArray.getPurchArraySize()].setProd(*p);
  pArray.incrementPurchArraySize();

  //put elements back into pArray
  for (int i = 0; i < pArray.getPurchArraySize(); i++) {
    pArray.getPurchArray()[i] = array[i];
  }

  return 1; //now function is successful
}

int    Customer::getId()     { return id;     }
string Customer::getName()   { return name;   }
int    Customer::getPoints() { return points; }
PurchArray Customer::getPurchArray() { return pArray; } //getter added
