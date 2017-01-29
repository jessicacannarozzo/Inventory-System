#include "defs.h"
#include "Purchase.h"

class PurchArray {

  public:
    PurchArray();
    Purchase* getPurchArray(); //K: not necessary, no other class should have access to this
    int getPurchArraySize();
    void addNewPurchase(Product&);

  private:
    Purchase* pArr[MAX_ARR];
    int purchSize;
};
