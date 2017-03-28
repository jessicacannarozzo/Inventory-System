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

#include "Taxable.h"

Taxable::Taxable(string n, string s, int u, float p,int m,int d,int y)
           :Product(n,s,u,p,m,d,y){}
           
Taxable::~Taxable(){}

float Taxable::computeTax()
{
  float taxRate = ON_TAX/100;
  return price * taxRate;
}
