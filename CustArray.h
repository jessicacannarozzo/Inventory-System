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
/* Class Def: CustArray.h                          */
/* Array of customers that may buy products from   */
/* the store.                                      */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef CUSTARRAY_H
#define CUSTARRAY_H

#include "defs.h"
#include "Customer.h"

class CustArray
{
  public:
    CustArray();
    void add(Customer*); //adds new customer to the array
    Customer* get(int);  //returns customer object at a given position in array
    int getSize();       //returns the number of registered customers
  private:
    Customer* elements[MAX_ARR];
    int size;
};

#endif
