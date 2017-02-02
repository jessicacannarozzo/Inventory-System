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

void Customer::buyItem(Product& p)
{
	//check if product was already bought in the past
	for (int i = 0; i < pArray.getPurchArraySize(); i++) {
		if (pArray.getProd(i).getId() == p.getId()) {
		  	//product was bought in the past, increment units by 1
		  	pArray.getPurchase(i).incrementProdQnt();
		  	return; //don't need to iterate anymore, function successful
		}
	}

  	//we didn't find the item if we get here. Customer has never bought this item before.
	Purchase newPurch(p);
	pArray.addNewPurchase(newPurch);
}

void Customer::addPoints(int p)    { points += p; }

int    Customer::getId()     { return id;     }
string Customer::getName()   { return name;   }
int    Customer::getPoints() { return points; }
PurchArray& Customer::getPurchArray() { return pArray; } //getter added
