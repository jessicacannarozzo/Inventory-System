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
    Order(Customer*);
    //getters
    int getOrderID();
    Customer* getCustomer();
    PurchArray& getOrderPurches();
    float getTotalAmount();

    void addPurchase(Product*); // adds a new purchase to the order
  private:
    int orderID;
    Customer* cust;
    PurchArray purchases;
    float totalAmount;
    static int nextOrderId;
    
};

#endif
