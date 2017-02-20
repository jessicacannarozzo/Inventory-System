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
#include <math.h> // using round() in computeLoyaltyPoints()

ProdList& Store::getStock()     { return stock; }

CustArray& Store::getCustomers() { return customers; }

void Store::addProd(Product* prod)
{
  stock.add(prod);
}

void Store::addCust(Customer* cust)
{
  customers.add(cust);
}

Store::~Store()
{
	//deallocate products from stock
	// for(int i = 0; i < stock.getSize(); i++)
	// {
	// 	delete stock.get(i);
	// }


	//deallocate customers
	for(int i = 0; i < customers.getSize(); i++)
	{
		delete customers.get(i);
	}
}





Customer* Store::verifyCustomer(int id)
{
	// search for existing customer
	for (int i=0; i < customers.getSize(); i++) {
		if(customers.get(i)->getId() == id)
		{
			return customers.get(i);
		}
	}
	return NULL;
}



Product* Store::verifyProduct(int prodId)
{
  //   if(prodId <= 0) return NULL;
  //
  //   // search for existing product
	// for (int i = 0; i< stock.getSize(); i++) {
	// 	Product* prod = stock.get(i);
	// 	if(prod->getId() == prodId && prod->getUnits() > 0)
	// 	{
	// 		return prod;
	// 	}
	// }
	// return NULL;

  return stock.find(prodId);
}



void Store::productPurchase(Product* prod, Customer* cust, float* totalAmount, int* totalPoints)
{

	cust->buyItem(prod);

	//reduce the number of units of that product available in the store
	prod->decrementUnits();

	//compute the number of loyalty points earned by the customer with purchasing that product
	*totalPoints += computeLoyaltyPoints(prod->getPrice(), cust);
	*totalAmount += prod->getPrice();

}

int Store::computeLoyaltyPoints(float price, Customer* cust)
{
	int points = round(price);
	// add the loyalty points to the customer’s points
	cust->addPoints(points);
	return points;
}



int Store::addInventory(int orderID, int unitsArrived) {
  //Product* p = stock.getProductByID(orderID);
  if (unitsArrived <= 0) return C_NOK;

  Product* p = verifyProduct(orderID);
  if(p == NULL) return C_NOK;

  p->incrementUnitsByX(unitsArrived);
  return C_OK;
}
