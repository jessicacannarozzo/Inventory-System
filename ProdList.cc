/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: ProdList.cc                          */
/* List of products contained in the store         */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "ProdList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

ProdList::ProdList()
  : head(0), size(0) {}

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

int ProdList::getSize() { return size; }

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
	if (newProd->data->getUnits() <= currNode->data->getUnits())
		break; // found the insertion point, quit loop
	prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {	// add to beginning
    head = newProd;
	newProd->prev = head;
	newProd->next = currNode;
	size++;
	return C_OK;
  } 
  else {
    prevNode->next = newProd;
	newProd->prev = prevNode;
  }
  newProd->next = currNode;
  if(currNode != NULL)
  	currNode->prev = newProd;

  size++;
  return C_OK;
}

int ProdList::removeProd(Product* p) {
  Node* currNode = head;

  while (currNode != NULL) {
    if (currNode->data == p)
      break;
    currNode = currNode->next;
  }

  if (currNode->prev == NULL) { //removing head
    head = currNode->next;
    head->prev = NULL;
  } else {
    currNode->prev->next = currNode->next;
    // prevNode->next = currNode->next;
  }

    if (currNode->data != p) { //we can't find the node, does not exist
    return C_NOK;
  }

  //otherwise... delete successful
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

void ProdList::print() {
  Node* currNode = head;

  stringstream ss;

  cout << endl << "STOCK: " << endl << endl;
  cout << " ID                                 Name             Size    Qty    Price" << endl;
  cout << " --                                 ----             ----    ---    -----" << endl;

  while (currNode != NULL) {

    // Product* prod = arr.get(i);

    cout << currNode->data->getId()   << "  " << setw(40) << currNode->data->getName() << "  "
         << setw(10) << currNode->data->getSize() << "  " << setw(4)  << currNode->data->getUnits() << "    ";

    ss << setw(6) << fixed << setprecision(2) << currNode->data->getPrice();

    cout << "$" << ss.str() << endl;
    ss.str("");
    currNode = currNode->next;
  }
}

//called whenever units are added or purchased
void ProdList::reorg() {
  Node* currNode = new Node;
  currNode = head;
  Node* temp = new Node;

  while (currNode->next != NULL) {
    if (currNode->data->getUnits() > currNode->next->data->getUnits()) {
      //swap
      // temp = currNode->next;
      // currNode->next = currNode;
      // currNode = temp;
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
}
