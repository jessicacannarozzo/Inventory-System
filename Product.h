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
/* Class Def: Product.h                            */
/* Product type. Includes all information for each */
/* item at the store.                              */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PRODUCT_H
#define PRODUCT_H
#include "Date.h"
#include "TaxationBehaviour.h"
#include "ExpirationBehaviour.h"
#include <string>
using namespace std;

class Product
{
  public:
    Product(string="Unknown", string="Unknown", int=0, float=0.0f,int=0,int=0,int=0,int=0);
    virtual ~Product();
    int    getId();        //returns product id
    string getName();      //returns product name
    string getSize();      //returns product size
    int    getUnits();     //returns product units available
    float  getPrice();     //returns product price
    void incrementUnits(); //increments units by 1.
	void decrementUnits(); //decrements units by 1.
    void incrementUnitsByX(int); //increments units by X amount
    virtual float computeTax(); //returns the amount of tax to be paid on the product
    virtual void  computeExpDate(); // computes and sets the product’s expiry date
    Date& getExpDate();

  protected:
    static int nextProdId;
    int        id;
    string     name;
    string     size;
    int        units;
    float      price;
    Date       manufacturedDate;
    Date       expiryDate;
    int        lifespan; //the number of days between the manufactured date and the expiry date
    TaxationBehaviour*   taxB;
    ExpirationBehaviour* expB;
};

#endif
