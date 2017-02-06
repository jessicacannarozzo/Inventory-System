/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: Store.h                              */
/* Keeps track of customer and product information */
/* in a store.                                     */
/* * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef STORE_H
#define STORE_H

#include <math.h>
#include "ProdArray.h"
#include "Product.h"
#include "CustArray.h"
#include "Customer.h"
#include <cstdlib> // used to terminate program case customer or product is not found

class Store
{
  public:
    void       addProd(Product&); //add Product in store stock
    void       addCust(Customer&);// add new customer
    ProdArray& getStock();        //get collection of products in stock
    CustArray& getCustomers();    //get collection of registered customers
    Customer&  getCustomer(int);  //get customer at a given position

	// Verify that a given custumer id is existing, and return a reference to that Customer
	Customer& verifyCustomer(int);

	// Verify that a given product id is existing and in stock. Return a ref to that Product
	Product& verifyProduct(int);

    // Initiate customer purchase
	void productPurchase(Product&, Customer&, float*, int*);

	//compute loyalty points earned by a customer with a purchase. Update customer points. Return number of points.
	int computeLoyaltyPoints(float, Customer&);


  private:
    ProdArray  stock;
    CustArray  customers;




  // Initiate customer purchase
  //void productPurchase(Product&, Customer&, float*, int*);

  //compute loyalty points earned by a customer with a purchase. Update customer points. Return number of points.
  //int computeLoyaltyPoints(float, Customer&);
};

#endif
