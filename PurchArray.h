/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: PurchArray.h                         */
/* Array of items that may be purchased from the   */
/* store.                                          */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "defs.h"
#include "Purchase.h"

class PurchArray {

  public:
    PurchArray();
    Purchase& getPurchase(int);
    int getPurchArraySize();
    void addNewPurchase(Purchase&);
	Product& getProd (int);

  private:
    Purchase pArr[MAX_ARR];
    int purchSize;
};
