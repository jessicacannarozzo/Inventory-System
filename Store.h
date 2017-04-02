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
// #include "ProdArray.h"
#include "ProdList.h"
//#include "Product.h"
#include "CustArray.h"
#include "Customer.h"
#include "Dairy.h"
#include "CoffeeTea.h"
#include "Bakery.h"
#include "Meat.h"
#include "MiscGoods.h"

class Store
{

  public:
    void       addProd(Product*); //add Product in store stock
    void       addCust(Customer*);// add new customer
    ProdList& getStock();        //get collection of products in stock
    CustArray& getCustomers();    //get collection of registered customers

    // Verify that a given custumer id is existing. Return prt to customer found, or null otherwise
	Customer* verifyCustomer(int);

	// Verify that a given product id is existing. Return prt to product, or null otherwise
	Product* verifyProdId(int);
	int verifyProdInStock(Product* p); // Verify that a given product is in stock

	void productPurchase(Product*, Customer*, float*, int*, float*); // Init customer purchase

	//compute loyalty points earned by a customer with a purchase. Update customer points. Return number of points.
	int computeLoyaltyPoints(float, Customer*);
    int addInventory(int, int); //update product in stock with new units arrived
    int removeProd(Product*); //removed product from stock

  private:
    ProdList  stock;
    CustArray  customers;

};

#endif
