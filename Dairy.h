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
/* Class Def: Dairy.h                              */
/* Dairy type. Dairy product category              */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef DAIRY_H
#define DAIRY_H
#include <string>
#include "Perishable.h"
#include "NonTaxable.h"
using namespace std;

class Dairy : public Perishable, public NonTaxable
{
  public:
    Dairy(string="Unknown", string="Unknown", int=0, float=0.0f, int);
};

#endif
