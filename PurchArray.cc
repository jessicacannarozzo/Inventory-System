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



void PurchArray::addNewPurchase(Product& p) 
{ 
	//check if product was already bought in the past
	for (int i = 0; i < purchSize; i++) {
		if (pArr[i]->getProd().getId() == p.getId()) {
		  //product was bought in the past, increment units by 1
		  pArr[i]->incrementProdQnt();
		  return; //don't need to iterate anymore, function successful
		}
  	}

  	//we didn't find the item if we get here. Customer has never bought this item before.
	Purchase* newPurch = new Purchase(p); // memory leak!
	pArr[purchSize] = newPurch; // assuming purchSize is always < MAX_ARR for this assignment
	purchSize++; 
	return;
}
