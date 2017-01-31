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
