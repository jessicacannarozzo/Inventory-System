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
    void      initProducts();
    void      initCustomers();
    void      processAdmin();
    void      processCashier();

	// Verify that a given custumer id is existing and return that Customer
	Customer& verifyCustomer(int);

	// Verify that a given product id is existing and in stock
	void      verifyProduct(int);

    // Initiate customer purchase
	void 	  makePurchase(int prodId, Customer& cust);
};
#endif
