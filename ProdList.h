/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: ProdList.h                           */
/* List of products contained in the store         */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

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
    int add(Product*);
    int removeProd(Product*);
    void reorg();
    Product* find(int);
    void print();
    // int getSize();
  private:
    Node* head;
    // int size;
};
