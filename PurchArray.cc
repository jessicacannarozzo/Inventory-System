#include <string>
#include <cstdlib>
#include "PurchArray.h"
using namespace std;

//init
PurchArray::PurchArray() {
  purchSize = 0;
}

int PurchArray::getPurchArraySize() { return purchSize; } //get the size


Purchase& PurchArray::getPurchase(int index){
	return pArr[index];
}

Product& PurchArray::getProd (int index)
{
	return pArr[index].getProd();

}


void PurchArray::addNewPurchase(Purchase& p) 
{ 
	pArr[purchSize] = p; // assuming purchSize is always < MAX_ARR for this assignment
	purchSize++; 
	return;
}
