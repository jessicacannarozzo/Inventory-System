/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: OrderArray.h                         */
/* Array of customer Orders.                       */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ORDERARRAY_H
#define ORDERARRAY_H

#include "Order.h"

class OrderArray {
  public:
    OrderArray();
    OrderArray(OrderArray&); 
    ~OrderArray();
    //getters
    //Order* getOrders();
    int getOrderSize();
    Order* getOrder(int);  // gets particular order at index
    void addOrder(Order*); // adds new order to array 
    void cleanup(); // cleans up array
  private:
    int orderSize; //# of orders
    Order* orders[MAX_ARR];
};

#endif
