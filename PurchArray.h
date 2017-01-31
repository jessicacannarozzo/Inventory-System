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
