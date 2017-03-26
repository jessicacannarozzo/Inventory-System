/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <cstdlib>
#include "InvControl.h"

OrderServer InvControl::orderServer;

InvControl::InvControl()
{
  initProducts();
  initCustomers();
}

void InvControl::launch(int argc, char* argv[])
{
  if (argc != 2) {
    view.printUsageError();
    exit(1);
  }

  string option(argv[1]);

  if (option == "-a") {		// Admin menu
    processAdmin();
  }
  else if (option == "-c") {	// Cashier menu
    processCashier();
  }
  else {
    view.printUsageError();
    exit(1);
  }
}

void InvControl::processAdmin()
{
  int    choice;
  string prodName, prodSize;
  int    prodUnits, prodId, amount;
  float  prodPrice;

  int code;

  while (1) {
    choice = -1;
    view.adminMenu(choice);
    if (choice == 1) {		// add new product - FIX THIS LATER
      view.printError("Sorry. Option currently not available."); //REMOVE THIS LINE
      /*
      view.promptForStr("Product name", prodName);
      view.promptForStr("Product size", prodSize);
      view.promptForInt("# units", prodUnits);
      view.promptForFloat("Price", prodPrice);
      Product* prod = new Product(prodName, prodSize, prodUnits, prodPrice);
      store.addProd(prod);
      view.pause();
      */
    }
    else if (choice == 2) {	// add inventory
	  code = C_NOK;
	  while (code == C_NOK){
		  view.promptForInt("Product ID", prodId);
		  view.promptForInt("Quantity", amount);
		  code = store.addInventory(prodId, amount);
		  if (code == C_NOK) view.printError("Product not found.");
	  }
	  view.pause();
    }
    else if (choice == 3) {	// print inventory
      view.printStock(store.getStock());
      view.pause();
    }
    else if (choice == 4) {	// print customers
      view.printCustomers(store.getCustomers());
      view.pause();
    }
    else if (choice == 5) {	// remove product
	  code = C_NOK;
	  while (code == C_NOK){
		  view.promptForInt("Product ID", prodId);

		  Product* prod = store.verifyProdId(prodId);
		  if (prod == NULL)
			view.printError("Product not found.");
 		  else
			code = store.removeProd(prod);
	  }
      view.pause();
    }
    else if (choice == 6){ // print orders
      OrderArray orders;
      orderServer.retrieve(orders);
      view.printOrders(orders);
    }
    else {
      break;
    }
  }
}

void InvControl::processCashier()
{
  int choice;
  int prodId, custId;
  // int code;

  while (1) {
    choice = -1;
    view.cashierMenu(choice);
    if (choice == 1) {			// purchases

	  Customer* cust = NULL;

	  while (cust == NULL){
      	view.promptForInt("Enter customer id", custId);
	    cust = store.verifyCustomer(custId);
		if (cust == NULL) view.printError("Customer not found.");
	  }

	  //Init cust purchase
	  float totalAmount = 0;
	  int   totalPoints = 0;
	  view.promptForInt("Enter a sequence of product ids to be purchased (Terminate with 0)", prodId);

 	  Product* prod = NULL;
      Order* newOrder = new Order (cust);

	  while (prodId != 0 || prod == NULL)
	  {
		if (prodId == 0)
      		break;

	  	prod = store.verifyProdId(prodId);
		int c;
		if(prod != NULL) c = store.verifyProdInStock(prod);
        if(prod == NULL || c == C_NOK)
		  view.printError("Product not found or out of stock");

		else
		{
		  // update client purchases
		  store.productPurchase(prod, cust, &totalAmount, &totalPoints);
		  // update order server purchases
		  newOrder->addPurchase(prod);
        }
		view.promptForInt("Next product id", prodId);
	  }

	  view.printPurchaseSummary(totalAmount, totalPoints);
      // send new order to the order server for storage
      orderServer.update(newOrder);
    }
    else if (choice == 2) {		// return purchases
      view.printError("Feature not implemented");
    }
    else if (choice == MAGIC_NUM) {	// print inventory and customers
      view.printStock(store.getStock());
      view.printCustomers(store.getCustomers());

      OrderArray orders;
      orderServer.retrieve(orders);
      if(orders.getOrderSize() == 0)
        view.printError("COPY DID NOT WORK");
      view.printOrders(orders);

      view.pause();
    }
    else {
      break;
    }
  }
}



void InvControl::initProducts()
{
  //Dynamically allocated memory

  MiscGoods* prod01 = new MiscGoods("Sudzzy Dish Soap", "1 L", 10, 3.99f);
  store.addProd(prod01);

  MiscGoods* prod02 = new MiscGoods("Peachy Laundry Soap", "2 L", 3, 8.99f);
  store.addProd(prod02);

  MiscGoods* prod03 = new MiscGoods("Daisy's Spicy Chili", "150 g", 5, 1.29f);
  store.addProd(prod03);

  MiscGoods* prod04 = new MiscGoods("Daisy's Maple Baked Beans", "220 g", 2, 2.49f);
  store.addProd(prod04);

  Meat* prod05 = new Meat("Marmaduke Hot Dogs", "12-pack", 4, 4.99f, 30);
  store.addProd(prod05);

  Meat* prod06 = new Meat("Garfield Hamburger Patties", "900 g", 2, 11.99f, 30);
  store.addProd(prod06);

  Dairy* prod07 = new Dairy("Chunky Munkey Ice Cream", "2 L", 1, 2.97f, 45);
  store.addProd(prod07);

  Bakery* prod08 = new Bakery("It's Your Bday Chocolate Cake", "500 g", 0, 12.99f, 5);
  store.addProd(prod08);

  Bakery* prod09 = new Bakery("Happy Baker's Hot dog buns", "12-pack", 5, 3.49f, 14);
  store.addProd(prod09);

  Bakery* prod10 = new Bakery("Happy Baker's Hamburger buns", "8-pack", 8, 3.99f, 15);
  store.addProd(prod10);

  Dairy* prod11 = new Dairy("Moo-cow 2% milk", "1 L", 7, 2.99f, 7);
  store.addProd(prod11);

  CoffeeTea* prod12 = new CoffeeTea("Moo-cow instant coffee", "200 g", 3, 4.99f);
  store.addProd(prod12);

  Dairy* prod13 = new Dairy("Moo-cow 5% coffee cream", "250 ml", 4, 1.49f, 20);
  store.addProd(prod13);

  MiscGoods* prod14 = new MiscGoods("Good Morning Granola Cereal", "400 g", 2, 5.49f);
  store.addProd(prod14);

  CoffeeTea* prod15 = new CoffeeTea("Lightening Bolt Instant Coffee", "150 g", 8, 4.99f);
  store.addProd(prod15);

  CoffeeTea* prod16 = new CoffeeTea("Lightening Bolt Decaf Coffee", "100 g", 2, 4.99f);
  store.addProd(prod16);

  MiscGoods* prod17 = new MiscGoods("Munchies BBQ Chips", "250 g", 7, 2.99f);
  store.addProd(prod17);

  MiscGoods* prod18 = new MiscGoods("Munchies Ketchup Chips", "250 g", 3, 2.99f);
  store.addProd(prod18);

  MiscGoods* prod19 = new MiscGoods("Dogbert Salted Chips", "210 g", 4, 1.99f);
  store.addProd(prod19);

  MiscGoods* prod20 = new MiscGoods("Dogbert Sweet and Spicy Popcorn", "180 g", 5, 2.29f);
  store.addProd(prod20);

  //our product!!!
  MiscGoods* prod21 = new MiscGoods("Off-brand Kit-Kat", "1000 g", 100, 9.99f);
  store.addProd(prod21);

}

void InvControl::initCustomers()
{
  //Dynamically allocated memory
  Customer* cust01 = new Customer("Starbuck");
  Customer* cust02 = new Customer("Apollo");
  Customer* cust03 = new Customer("Boomer");
  Customer* cust04 = new Customer("Athena");
  Customer* cust05 = new Customer("Helo");
  Customer* cust06 = new Customer("Crashdown");
  Customer* cust07 = new Customer("Hotdog");
  Customer* cust08 = new Customer("Kat");
  Customer* cust09 = new Customer("Chuckles");
  Customer* cust10 = new Customer("Racetrack");

  store.addCust(cust01);
  store.addCust(cust02);
  store.addCust(cust03);
  store.addCust(cust04);
  store.addCust(cust05);
  store.addCust(cust06);
  store.addCust(cust07);
  store.addCust(cust08);
  store.addCust(cust09);
  store.addCust(cust10);
}
