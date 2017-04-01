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
/* Class Def: NonTaxable.h                         */
/* NonTaxable type.  Determines the amount of tax  */
/*to be added to a product’s price when purchased  */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef NONTAXABLE_H
#define NONTAXABLE_H
#include "TaxationBehaviour.h"
#include "defs.h"
using namespace std;

class NonTaxable : public virtual TaxationBehaviour
{
  public:
    NonTaxable();
    virtual ~NonTaxable();
    virtual float computeTax(); // returns the amount of tax to be paid on the product
};

#endif
