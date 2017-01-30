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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#include "Product.h"
#include "PurchArray.h"

class Customer
{
  public:
    Customer(string="Unknown");
    int    getId();
    string getName();
    int    getPoints();
    PurchArray getPurchArray();
    void buyItem(Product&);
	void addPoints(int); //add loyalty points

  protected:
    static int nextCustId;
    int        id;
    string     name;
    int        points;
    PurchArray pArray; //collection of purchases
};

#endif
