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

//getters
int OrderArray::getOrderSize() { return orderSize; }

Order* OrderArray::getOrders() { return *orders; } //Do we need this getter? Only the print function would use it, we could implement a toString() here

Order* OrderArray::getOrder(int i) { return orders[i]; }
