/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: OrderArray.cc                        */
/* Array of product purchases by customers.        */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "OrderServer.h"

//OrderServer::OrderServer() {}

//OrderServer::~OrderServer() {}

void OrderServer::update(Order* order)
{
    orders.addOrder(order);
}


void OrderServer::retrieve(OrderArray& arr)
{
  arr.cleanup();
  
  // Fill arr with orders
  for(int i = 0; i < orders.getOrderSize(); i++)
  {
    arr.addOrder(orders.getOrder(i));
  }
}
