/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: Order.h                              */
/* Product purchases by customers.                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ORDER_H
#define ORDER_H

#include "defs.h"
#include "Customer.h"
#include "PurchArray.h"

class Order {
  public:
    Order(Customer*, PurchArray);
    //getters
    int getOrderID();
    Customer* getCustomer();
    PurchArray& getOrderPurches();
    float getTotalAmount();
  private:
    int orderID;
    Customer* cust;
    PurchArray purchases;
    float totalAmount;
    static int nextOrderId;
    
};

#endif
