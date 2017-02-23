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
  : head(0) {}

ProdList::~ProdList() {
  Node* currNode = head;
  Node* nextNode;

 while (currNode != NULL) {
   nextNode = currNode->next;
   delete currNode;
   currNode = nextNode;
 }
}

// int ProdList::getSize() { return size; }

//maintain order of units
int ProdList::add(Product* p) { //add to back
  Node* newProd = new Node;
  Node* currNode;
  newProd->data = p;
  newProd->next = NULL;
  newProd->prev = NULL;
  currNode = head;

  if (currNode == NULL) { //list is empty
    head = newProd;
    return C_OK;
  }

  while (currNode->next != NULL) {
    currNode = currNode->next;
  }
  currNode->next = newProd;
  newProd->prev = currNode;
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

//find's data according to prod ID
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

//sorts the product list in ascending order of number of units, called whenever units are added
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
