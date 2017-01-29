#include "defs.h"
#include "Product.h"

class Purchase {
  public:
    Purchase(Product& p);  //K: according to forum, there should be at least one prod when calling Purchase(). Prod is also set here

    Product getProd();
	int getPurchQnt();

    // increments quantity of the same product bought by a customer
    void incrementProdQnt(); 

  private:
	Product* prod; //K: keeping reference instead of a prod copy
	int purchQnt; // num of units of that product bought by a customer
};
