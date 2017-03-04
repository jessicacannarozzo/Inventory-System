/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: ProdList.cc                          */
/* List of products contained in the store         */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "ProdList.h"
#include <iostream> //REMOVE THIS BEFORE SUBMITTING
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

//int ProdList::getSize() { return size; }

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


  if (prevNode == NULL) { // remove 1st element
    head = currNode->next;
    head->prev = NULL;
  } else {
    prevNode->next = currNode->next;
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


//called whenever units are added or purchased
void ProdList::reorg() {
  Node* currNode = new Node;
  currNode = head;
  Node* temp = new Node;

  while (currNode->next != NULL) {
    if (currNode->data->getUnits() > currNode->next->data->getUnits()) {
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
}

void ProdList::toString(string& outStr)
{
  stringstream ss;

  forwardToString(ss);
  ss << endl << endl;
  backwardToString(ss);

  outStr = ss.str();
}

void ProdList::forwardToString(stringstream& ss)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.
  Node* currNode = head;

  ss<<endl<<"STOCK (Increasing order of product units):"<<endl<<endl;
  ss<<" ID                                 Name             Size    Qty    Price" << endl;
  ss << " --                                 ----             ----    ---    -----" << endl;

  while (currNode != NULL) { //repetitive code, move to another function or in Product class
    productToString(ss, currNode->data);
    currNode = currNode->next;
  }

}

void ProdList::productToString(stringstream& ss, Product* p)
{
    stringstream tmp;

    ss << p->getId()   << "  " << setw(40) << p->getName() << "  " << setw(10) 
	<< p->getSize() << "  " << setw(4) << p->getUnits() << "    ";

    tmp << setw(6) << fixed << setprecision(2) << p->getPrice();
    ss << "$" << tmp.str() << endl;
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
  ss<<" ID                                 Name             Size    Qty    Price" << endl;
  ss << " --                                 ----             ----    ---    -----" << endl;

  while (currNode != NULL) {
    productToString(ss, currNode->data);

    if(currNode == head)
	  break;

    currNode = currNode->prev;

  }

}



/*
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
*/
