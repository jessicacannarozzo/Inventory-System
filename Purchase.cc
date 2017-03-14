#include <string>
#include <cstdlib>
#include "Purchase.h"
using namespace std;

Purchase::Purchase() 
{
	prod = 0;
	purchQnt = 0;
}

Purchase::Purchase(Product* p) 
{
	prod = p;
	purchQnt = 1;
}


//copy constructor
Purchase::Purchase(Purchase& p) 
{
  purchQnt = p.getPurchQnt();
  prod = p.getProd();
}


Product* Purchase::getProd() {
  return prod;
}

int Purchase::getPurchQnt() {
  return purchQnt;
}

void Purchase::incrementProdQnt() {
  purchQnt ++;
}
