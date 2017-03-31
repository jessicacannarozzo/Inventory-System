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
/* Class Def: TaxationBehaviour.h                  */
/* TaxationBehaviour type. Contain taxation        */
/* behaviour of a product                          */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef TAXATIONBEHAVIOUR_H
#define TAXATIONBEHAVIOUR_H
#include "Product.h"
using namespace std;

class TaxationBehaviour
{
  public:
    TaxationBehaviour();
    virtual ~TaxationBehaviour();
    virtual float computeTax() = 0; // returns the amount of tax to be paid on the product
 
};

#endif
