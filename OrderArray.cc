/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: OrderArray.h                         */
/* Array of product purchases by customers.        */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ORDERARRAY_H
#define ORDERARRAY_H

#include "Order.h"

class OrderArray {
  public:
    OrderArray();
    ~OrderArray();
  private:
    int orderSize; //# of orders
    Order* orders[MAX_ARR];
};

#endif
