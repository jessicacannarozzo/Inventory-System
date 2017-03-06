/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: ProdList.h                           */
/* List of products contained in the store         */
/* * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PRODlIST_H
#define PRODlIST_H

#include "defs.h"
#include "Product.h"

class ProdList {
  class Node
  {
    friend class ProdList;
    private:
      Product* data;
      Node*    next;
      Node*    prev;
  };
  public:
    ProdList();
    ~ProdList();
    int add(Product*); //adds the product in its correct place in the list (by order of units)
    int removeProd(Product*); // removes product from the list
    void reorg(); //sorts the product list in ascending order of number of units
    Product* find(int); //finds product according to given ID
    void toString(string&); //returns string with inventory info in both forward and backward directions

  private:
    Node* head;
	  void forwardToString(stringstream&); //returns string with inventory info in forward direction
    void backwardToString(stringstream&); //returns string with inventory info in backward direction
    void productToString(stringstream&, Product*); //returns string with product info


};

#endif
