#include <string>
#include <cstdlib>
#include "PurchArray.h"
using namespace std;

//init
PurchArray::PurchArray() {
  purchSize = 0;
}

int PurchArray::getPurchArraySize() { return purchSize; } //get the size

Purchase* PurchArray::getPurchArray() { return *pArr; }

void PurchArray::incrementPurchArraySize() { purchSize++; }
