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

#include "NonPerishable.h"

NonPerishable::NonPerishable()
           :ExpirationBehaviour()
{
  computeExpDate();
}

NonPerishable::~NonPerishable(){}

void NonPerishable::computeExpDate()
{
  expiryDate = manufacturedDate + TWO_YRS;
}
