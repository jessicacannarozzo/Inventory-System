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
/* Class Def: InvControl.h                         */
/* Controls the inventory of the store. Processes  */
/* cashier and administration functions, which     */
/* allows the store to process transactions.       */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef INVCONTROL_H
#define INVCONTROL_H

#include "Store.h"
#include "UI.h"

class InvControl
{
  public:
    InvControl();
    void launch(int, char*[]);
  private:
    Store     store;
    UI        view;
    void      initProducts();  //initiate product stock
    void      initCustomers(); //initiate collection of registered customers
    void      processAdmin();  //process admin menu options
    void      processCashier();//process cashier menu options

	// Verify that a given custumer id is existing, and return a ref to that Customer
	Customer* verifyCustomer(int);

	// Verify that a given product id is existing and in stock. Return a ref to that Product
	Product* verifyProduct(int);

    // Initiate customer purchase
	void productPurchase(Product*, Customer*, float*, int*);

	//compute loyalty points earned by a customer with a purchase. Update customer points. Return number of points.
	int computeLoyaltyPoints(float, Customer*);

};
#endif
