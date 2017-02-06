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

void Store::addProd(Product* prod)
{
  stock.add(prod);
}

void Store::addCust(Customer* cust)
{
  customers.add(cust);
}

int Store::addInventory(int orderID, int UnitsArrived) {
  Product* p = stock.getProductByID(orderID);
  if (p != NULL) {
    if (UnitsArrived <= 0) {
      cout << "Invalid amount. Please enter an amount greater than 0." << endl;
      return C_NOK;
    } else {
      (*p).incrementUnitsByX(UnitsArrived);
      return C_OK;
    }
  } else {
    cout << "Item not found." << endl;
    return C_NOK;
  }
}

Store::~Store()
{
	//deallocate products from stock
	for(int i = 0; i < stock.getSize(); i++)
	{
		delete &(stock.get(i));
	}


	//deallocate customers
	for(int i = 0; i < customers.getSize(); i++)
	{
		delete &(customers.get(i));
	}
}
