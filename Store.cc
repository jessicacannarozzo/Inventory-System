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


#include "Store.h"
#include <iostream>

ProdArray& Store::getStock()     { return stock; }

CustArray& Store::getCustomers() { return customers; }

void Store::addProd(Product& prod)
{
  stock.add(prod);
}

void Store::addCust(Customer& cust)
{
  customers.add(cust);
}

int Store::addInventory(int orderID, int UnitsArrived) {
  Product* p = stock.getProductByID(orderID);
  if (UnitsArrived <= 0) {
    return C_NOK;
  } else {
    p->incrementUnitsByX(UnitsArrived);
  }
  return C_OK;
}
