/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: OrderArray.cc                        */
/* Array of product purchases by customers.        */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "OrderArray.h"

OrderArray::OrderArray() {
  orderSize = 0;
}

//copy constructor
OrderArray::OrderArray(OrderArray& arr) {

  orderSize = arr.getOrderSize();
  for(int i = 0; i < orderSize; i++)
  {
    orders[i] = new Order (*(arr.getOrder(i)));
  }
  
}

OrderArray::~OrderArray() {
  for (int i = 0; i < orderSize; i++) {
    delete orders[i];
  }
}

//add
void OrderArray::addOrder(Order* o) {
  if (orderSize >= MAX_ARR) return; //too many orders
  
  orders[orderSize] = o;
  orderSize++;
}

void OrderArray::cleanup()
{
  for(int i = 0; i < orderSize; i++)
    delete orders[i];
}

//getters
int OrderArray::getOrderSize() { return orderSize; }

Order* OrderArray::getOrder(int i) { return orders[i]; }

//Order* OrderArray::getOrders() { return *orders; } 
