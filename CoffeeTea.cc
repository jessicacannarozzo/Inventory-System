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

#include "CoffeeTea.h"

CoffeeTea::CoffeeTea(string n, string s, int u, float p, int m, int d, int y, int l)
          :Product(n,s,u,p,m,d,y,l))
{
  expB = new NonPerishable;
  taxB = new Taxable;
  computeExpDate();
}
          
CoffeeTea::~CoffeeTea(){}
