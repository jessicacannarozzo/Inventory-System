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
/* Class Def: MiscGoods.h                          */
/* MiscGoods type. MiscGoods product category      */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MISCGOODS_H
#define MISCGOODS_H
#include "Product.h"
#include "NonPerishable.h"
#include "NonTaxable.h"
using namespace std;

class MiscGoods : public Product
{
  public:
    MiscGoods(string="Unknown", string="Unknown", int=0, float=0.0f, int=0,int=0,int=0,int=0);
    virtual ~MiscGoods();
};

#endif
