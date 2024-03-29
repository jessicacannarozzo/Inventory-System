/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: ProdList.cc                          */
/* List of products contained in the store         */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "ProdList.h"
#include <iomanip>
#include <string>
#include <sstream>

ProdList::ProdList()
  : head(0) {}

ProdList::~ProdList() {
  Node* currNode = head;
  Node* nextNode;

 while (currNode != NULL) {
   nextNode = currNode->next;
   delete currNode->data;
   delete currNode;
   currNode = nextNode;
 }
}

//maintain order of units
int ProdList::add(Product* p) {
  Node* newProd = new Node;
  Node* currNode;
  Node*  prevNode;

  newProd->data = p;
  newProd->next = NULL;
  newProd->prev = NULL;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
	if (newProd->data->getExpDate() < currNode->data->getExpDate())
		break; // found the insertion point, quit loop
	prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {	// add to beginning
    head = newProd;
  }
  else {
    prevNode->next = newProd;
	newProd->prev = prevNode;
  }

  newProd->next = currNode;
  if(currNode != NULL)
  	currNode->prev = newProd;

  return C_OK;
}

int ProdList::removeProd(Product* p) {
  Node* currNode = head;
  Node* prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data == p)
      break;
	prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == NULL) { //we can't find the node, does not exist
    return C_NOK;
  }

  if (prevNode == NULL) { // remove 1st element
    head = currNode->next;
    head->prev = NULL;
  }
  else {
    prevNode->next = currNode->next;

    if (currNode->next != NULL)
      currNode->next->prev = prevNode;
  }

  //otherwise... delete successful
  delete currNode->data;
  delete currNode;
  return C_OK;
}


Product* ProdList::find(int id) {
  Node* currNode = head;

  while (currNode != NULL) {
    if (currNode->data->getId() == id) {
      return currNode->data;
    } else {
      currNode = currNode->next;
    }
  }

  return NULL; // not found
}


//called whenever units are added or purchased
void ProdList::reorg() {
  Node* currNode = head;
  Node* temp = new Node;

  while (currNode->next != NULL) {
    if (currNode->data->getExpDate() < currNode->next->data->getExpDate()) {
      //swap
      temp->data = currNode->data;
      currNode->data = currNode->next->data;
      currNode->next->data = temp->data;

      // reset
      currNode = head;
    } else {
      //traverse
      currNode = currNode->next;
    }
  }
  delete temp;
}

//calls forwardToString and backwardToString functions, sets input value to the new output string
void ProdList::toString(string& outStr)
{
  stringstream ss;

  forwardToString(ss);
  ss << endl << endl;
  //backwardToString(ss);

  outStr = ss.str();
}

void ProdList::forwardToString(stringstream& ss)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.
  Node* currNode = head;

  ss<<endl<<"STOCK (Increasing order of product expiry date):"<<endl<<endl;
  ss<<" ID                                 Name             Size    Qty    Price    Exp.Date" << endl;
  ss << " --                                 ----             ----    ---    -----    --------" << endl;

  while (currNode != NULL) {
    productToString(ss, currNode->data);
    currNode = currNode->next;
  }

}

//formats product information
void ProdList::productToString(stringstream& ss, Product* p)
{
    stringstream tmp;

    ss << p->getId()   << "  " << setw(40) << p->getName() << "  " << setw(10)
	<< p->getSize() << "  " << setw(4) << p->getUnits() << "    ";

    tmp << setw(6) << fixed << setprecision(2) << p->getPrice();
    ss << "$" << tmp.str();
    Date d = p->getExpDate();
    ss << "  "<< d << endl;
}

void ProdList::backwardToString(stringstream& ss)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.
  Node* currNode = head;
  if(currNode != NULL) // find last element in list
  {
    while (currNode->next != NULL)
      currNode = currNode->next;
  }


  ss<<endl<<"STOCK (Decreasing order of product units):"<<endl<<endl;
  ss<<" ID                                 Name             Size    Qty    Price    Exp.Date" << endl;
  ss << " --                                 ----             ----    ---    -----    --------" << endl;

  while (currNode != NULL) {
    productToString(ss, currNode->data);

    if(currNode == head)
	  break;

    currNode = currNode->prev;

  }

}
