#include "defs.h"
#include "Purchase.h"

class PurchArray {

  public:
    PurchArray();
    Purchase* getPurchArray();
    int getPurchArraySize();
    void incrementPurchArraySize();

  private:
    Purchase* pArr[MAX_ARR];
    int purchSize;
};
