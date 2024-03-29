/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: Order.cc                             */
/* List of customer orders.                        */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Order.h"

int Order::nextOrderId = 1000;

Order::Order(Customer* c) { //init Order
  orderID = nextOrderId++;
  //orderID = id;
  cust = c;
  totalAmount = 0;
}


Order::Order(Order& o) { //copy constructor

  orderID = o.getOrderID();
  totalAmount = o.getTotalAmount();
  cust = o.getCustomer();
  
  for(int i = 0; i < o.getOrderPurches().getPurchArraySize(); i++)
  {
    Purchase* p = new Purchase( *(o.getOrderPurches().getPurchase(i)) );
    purchases.addNewPurchase(p);
  }
  
}


//getters
int Order::getOrderID() { return orderID; }

int Order::getNextOrderID() { return nextOrderId; }

Customer* Order::getCustomer() { return cust; }

PurchArray& Order::getOrderPurches() { return purchases; }

float Order::getTotalAmount() { return totalAmount; }

void Order::addPurchase(Product* p)
{
  //check if product is already part of the same order
	for (int i = 0; i < purchases.getPurchArraySize(); i++) {
		if (purchases.getProd(i)->getId() == p->getId()) {
		  	//product is already in the order, increment units by 1
		  	purchases.getPurchase(i)->incrementProdQnt();
		  	totalAmount += p->getPrice();
		  	return; //don't need to iterate anymore, function successful
		}
	}

  	//we didn't find the item if we get here. Add brand new purchase.
	Purchase* newPurch = new Purchase(p);
	purchases.addNewPurchase(newPurch);
	totalAmount += p->getPrice();
}

