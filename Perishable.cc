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

#include "Perishable.h"

Perishable::Perishable()
           :ExpirationBehaviour()
{
  computeExpDate();
}

Perishable::~Perishable(){}

void Perishable::computeExpDate()
{
  expiryDate = manufacturedDate + lifespan;
}
