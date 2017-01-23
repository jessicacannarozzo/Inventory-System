#include <string>
#include <cstdlib>
#include "Purchase.h"
using namespace std;

Purchase::Purchase() {}

Product Purchase::getProd() {
  return prod;
}

void Purchase::setProd(Product p) {
  prod = p;
}
