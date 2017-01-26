#include "defs.h"
#include "Purchase.h"

class PurchArray {

  public:
    PurchArray();
    Purchase* getPurchArray();
    int getPurchArraySize();

  private:
    Purchase* pArr[MAX_ARR];
    int purchSize;
};
