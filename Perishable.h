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
#include <string>
using namespace std;

class Perishable : public Product
{
  public:
    Perishable(string="Unknown", string="Unknown", int=0, float=0.0f);
    virtual void computeExpDate(); // computes and sets the product’s expiry date
  
  protected:
    int lifespan; // the number of days between the manufactured date and the expiry date
};

#endif
