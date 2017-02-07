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
/* Class Def: ProdArray.h                          */
/* Array of products contained in the store        */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PRODARRAY_H
#define PRODARRAY_H

#include "defs.h"
#include "Product.h"

class ProdArray
{
  public:
    ProdArray();
    void add(Product*);//adds a product in array
    Product* get(int); //returns a product at a given position in array
    int getSize();     //returns number of products in array
    Product* getProductByID(int);
  private:
    Product* elements[MAX_ARR];
    int size;
};

#endif
