#include "defs.h"
#include "Product.h"

class Purchase {
  public:
    Purchase();
    Product getProd();
    void setProd(Product p);

  private:
    Product prod; //id of purchased product and num of units
};
