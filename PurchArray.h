/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: PurchArray.h                         */
/* Array of items that may be purchased from the   */
/* store.                                          */
/* * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PURCHARRAY_H
#define PURCHARRAY_H
#include "defs.h"
#include "Purchase.h"

class PurchArray {

  public:
    PurchArray();
	  ~PurchArray();               //destructor: deallocates dynamically allocated purchases
    Purchase* getPurchase(int);    //get the purchase
    int getPurchArraySize();       //get the size
    void addNewPurchase(Purchase*);//add new Purchase in collection
	Product* getProd (int);        //get product from a given position in purchase coolection

  private:
    Purchase* pArr[MAX_ARR];
    int purchSize;
};

#endif
