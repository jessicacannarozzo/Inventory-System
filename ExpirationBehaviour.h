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
/* Class Def: ExpirationBehaviour.h                */
/* ExpirationBehaviour type. Contain expiration    */
/* date behaviour of a product                     */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef EXPIRATIONBEHAVIOUR_H
#define EXPIRATIONBEHAVIOUR_H
#include "Date.h"
#include "defs.h"
using namespace std;

class ExpirationBehaviour
{
  public:
    virtual Date computeExpDate(Date, int) = 0; // computes and sets the product’s expiry date
 
};

#endif
