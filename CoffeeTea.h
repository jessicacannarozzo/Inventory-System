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
/* Class Def: CoffeeTea.h                          */
/* CoffeeTea type. CoffeeTea product category      */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef COFFEETEA_H
#define COFFEETEA_H
#include "Product.h"
using namespace std;

class CoffeeTea : public Product
{
  public:
    CoffeeTea(string="Unknown", string="Unknown", int=0, float=0.0f,int=0,int=0,int=0,int=0);
    virtual ~CoffeeTea();
};

#endif
