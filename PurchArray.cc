#include <string>
#include <cstdlib>
#include "PurchArray.h"
using namespace std;

//init
PurchArray::PurchArray() {
  purchSize = 0;
}

int PurchArray::getPurchArraySize(){ return purchSize; } 


Purchase* PurchArray::getPurchase(int index){ return pArr[index]; }

Product* PurchArray::getProd (int index){ return pArr[index]->getProd(); }


void PurchArray::addNewPurchase(Purchase* p) 
{ 
	if (purchSize >= MAX_ARR) return;
	pArr[purchSize] = p;
	purchSize++; 
	return;
}

PurchArray::~PurchArray()
{
	for (int i = 0; i < purchSize; i++)
	{
		delete pArr[i];	
	}
}
