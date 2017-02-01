/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: Product.h                            */
/* Products that may be purchased from the store.  */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "defs.h"
#include "Product.h"

class Purchase {
  public:
    Purchase();
    Purchase(Product& p);

    Product& getProd();
	int getPurchQnt();

    // increments quantity of the same product bought by a customer
    void incrementProdQnt();

  private:
	Product* prod;
	int purchQnt; // num of units of that product bought by a customer
};
