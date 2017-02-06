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


Customer& Store::getCustomer(int position)
{
	return customers.get(position);

}


Customer& Store::verifyCustomer(int id)
{
	// search for existing customer
	for (int i = 0; i < customers.getSize(); i++) {
    	Customer& cust = customers.get(i);
		if(cust.getId() == id) return cust;
	}

	//if customer was not found, the program is terminated
	exit(1);
}



Product& Store::verifyProduct(int prodId)
{
	for (int i=0; i< stock.getSize(); i++) {
    	Product& prod = stock.get(i);
		if(prod.getId() == prodId && prod.getUnits() > 0) return prod;
	}

	//if product was not found, the program is terminated
	exit(1);
}


void Store::productPurchase(Product& prod, Customer& cust, float* totalAmount, int* totalPoints)
{

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

