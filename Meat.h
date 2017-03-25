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
/* Class Def: Meat.h                               */
/* Meat type. Meat product category                */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MEAT_H
#define MEAT_H
#include <string>
#include "Perishable.h"
#include "NonTaxable.h"
using namespace std;

class Meat : public Perishable, public NonTaxable
{
  public:
    Meat(string="Unknown", string="Unknown", int=0, float=0.0f, int=1);
};

#endif
