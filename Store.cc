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

CustList& Store::getCustomers() { return customers; }

void Store::addProd(Product* prod)
{
  stock.add(prod);
}

void Store::addCust(Customer* cust)
{
  customers.add(cust);
}


Customer* Store::verifyCustomer(int id)
{
  Customer* cust = new Customer("");
	// search for existing customer
	for (int i=0; &customers.get(i) != NULL; i++) {
    *cust = customers.get(i);
  
		if (cust->getId() == id) {
		    delete cust;
			return &customers.get(i);
		}
	}
    delete cust;
	return NULL; //customer not found
}



Product* Store::verifyProdId(int prodId)
{
  return stock.find(prodId);
}


int Store::verifyProdInStock(Product* p)
{
  if (p->getUnits() == 0)
    return C_NOK;
  return C_OK;
}


void Store::productPurchase(Product* prod, Customer* cust, float* totalAmount, int* totalPoints, float* tax)
{

	cust->buyItem(prod);

	//reduce the number of units of that product available in the store
	prod->decrementUnits();
  	stock.reorg(); //reorganize stock

	//compute the number of loyalty points earned by the customer with purchasing that product
	*totalPoints += computeLoyaltyPoints(prod->getPrice(), cust);
	*tax = prod->computeTax();
	*totalAmount += (prod->getPrice() + *tax);
}

int Store::computeLoyaltyPoints(float price, Customer* cust)
{
	int points = round(price);
	// add the loyalty points to the customer’s points
	cust->addPoints(points);
	return points;
}



int Store::addInventory(int orderID, int unitsArrived) {

  if (unitsArrived <= 0) return C_NOK;

  Product* p = verifyProdId(orderID);
  if(p == NULL) return C_NOK;

  p->incrementUnitsByX(unitsArrived);
  stock.reorg(); //reorganize stock
  return C_OK;
}


int Store::removeProd(Product* prod)
{
  return stock.removeProd(prod);
}
