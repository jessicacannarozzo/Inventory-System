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

// Initiate customer purchase
void Store::productPurchase(Product& prod, Customer& cust, float* totalAmount, int* totalPoints) {


  	cust.buyItem(prod);

  	//reduce the number of units of that product available in the store
  	prod.decrementUnits();

  	//compute the number of loyalty points earned by the customer with purchasing that product
  	*totalPoints += computeLoyaltyPoints(prod.getPrice(), cust);
  	*totalAmount += prod.getPrice();

}

int Store::computeLoyaltyPoints(float price, Customer& cust)
{
	int points = round(price);
	// add the loyalty points to the customer’s points
	cust.addPoints(points);
	return points;
}
