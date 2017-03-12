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

Order::Order(Customer* c, PurchArray p) { //init Order
  orderID = nextOrderId++; //ok to do this, same as in product class?
  //orderID = id;
  cust = c;
  purchases = p;
}

//getters
int Order::getOrderID() { return orderID; }

Customer* Order::getCustomer() { return cust; }

PurchArray& Order::getOrderPurches() { return purchases; }

float Order::getTotalAmount() { return totalAmount; }
