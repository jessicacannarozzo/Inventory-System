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
/* Class Def: Perishable.h                         */
/* Perishable type. Contain perishable behaviour to*/
/* compute a product’s expiry date                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PERISHABLE_H
#define PERISHABLE_H
#include "ExpirationBehaviour.h"
#include "defs.h"
using namespace std;

class Perishable : public virtual ExpirationBehaviour
{
  public:
    virtual Date computeExpDate(Date, int); // computes and sets the product’s expiry date
};

#endif
