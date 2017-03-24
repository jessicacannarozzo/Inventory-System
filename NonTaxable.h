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
#include <string>
#include "Product.h"
#include "defs.h"
using namespace std;

class NonTaxable : public Product
{
  public:
    NonTaxable(string="Unknown", string="Unknown", int=0, float=0.0f);
    virtual float computeTax(); // returns the amount of tax to be paid on the product
};

#endif
