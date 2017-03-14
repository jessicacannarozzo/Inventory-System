/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: OrderServer.h                        */
/* Stores a collection of customer Orders.         */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ORDERSERVER_H
#define ORDERSERVER_H

#include "OrderArray.h"

class OrderServer {
  public:
    //OrderServer();
    //~OrderServer(); // Do we need a destructor?
    //getters
    void update(Order* order);
    void retrieve(OrderArray& arr);
    
  private:
    OrderArray orders;
};

#endif
