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

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product
{
  public:
    Product(string="Unknown", string="Unknown", int=0, float=0.0f);
    int    getId();
    string getName();
    string getSize();
    int    getUnits();
    float  getPrice();
    void incrementUnits(); //increments units by 1.
	void decrementUnits(); //increments units by 1.

  protected:
    static int nextProdId;
    int        id;
    string     name;
    string     size;
    int        units;
    float      price;
};

#endif
