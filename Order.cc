/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: Order.cc                             */
/* List of customer orders.                        */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Order.h"

Order::Order(int id, Customer* c, PurchArray p) { //init Order
  orderID = id;
  cust = c;
  purchases = p;
}

//getters
int Order::getOrderID() { return orderID; }

Customer* Order::getCustomer() { return cust; }

PurchArray& Order::getOrderPurches() { return purchases; }
