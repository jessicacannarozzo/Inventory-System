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
/* Class Def: Bakery.h                          */
/* Bakery type. Bakery product category      */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef BAKERY_H
#define BAKERY_H
#include <string>
#include "Perishable.h"
#include "Taxable.h"
using namespace std;

class Bakery : public Perishable, public Taxable
{
  public:
    Bakery(string="Unknown", string="Unknown", int=0, float=0.0f, int=0,int=0,int=0, int=1);
    virtual ~Bakery();
};

#endif
