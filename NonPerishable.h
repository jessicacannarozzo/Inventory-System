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
/* Class Def: NonPerishable.h                      */
/* NonPerishable type. Contain non-perishable      */
/* behaviour to compute a product’s expiry date    */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef NONPERISHABLE_H
#define NONPERISHABLE_H
#include <string>
#include "defs.h"

using namespace std;

class NonPerishable : public Product
{
  public:
    NonPerishable(string="Unknown", string="Unknown", int=0, float=0.0f);
    virtual void computeExpDate(); // computes and sets the product’s expiry date
};

#endif
