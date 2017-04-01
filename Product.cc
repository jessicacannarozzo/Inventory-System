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

#include "Product.h"

int Product::nextProdId = 5001;

Product::Product(string n, string s, int u, float p, int m, int d, int y, int l)
        :manufacturedDate(m,d,y)
{
  id    = nextProdId++;
  name  = n;
  size  = s;
  units = (u >= 0) ? u : 0;
  price = (p >= 0) ? p : 0;
  lifespan = l;
  taxB = NULL;
  expB = NULL;
  expiryDate = NULL;
}

Product::~Product() {}

void Product::incrementUnits() {
  units++;
}

void Product::decrementUnits() {
  units--;
}

void Product::incrementUnitsByX(int x) {
  units += x;
}

int    Product::getId()    { return id;    }
string Product::getName()  { return name;  }
string Product::getSize()  { return size;  }
int    Product::getUnits() { return units; }
float  Product::getPrice() { return price; }
Date   Product::getExpDate(){return expiryDate;}

void   Product::computeExpDate()
{
  expiryDate = expD->computeExpDate(manufacturedDate, lifespan);
}
void   Product::computeTax()
{
  taxB->computeTax();
}
