#include <string>
#include <cstdlib>
#include "Purchase.h"
using namespace std;

Purchase::Purchase(Product& p) 
{
	prod = &p;
	purchQnt = 1;
}

Product& Purchase::getProd() {
  return *prod;
}

int Purchase::getPurchQnt() {
  return purchQnt;
}

void Purchase::incrementProdQnt() {
  purchQnt ++;
}
