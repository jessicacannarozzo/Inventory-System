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
/* Class Def: Taxable.h                            */
/* Taxable type.  Determines the amount of tax     */
/*to be added to a product’s price when purchased  */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef TAXABLE_H
#define TAXABLE_H
#include "TaxationBehaviour.h"
#include "defs.h"
using namespace std;

class Taxable : public virtual TaxationBehaviour
{
  public:
    virtual float computeTax(float); // returns the amount of tax to be paid on the product
};

#endif
