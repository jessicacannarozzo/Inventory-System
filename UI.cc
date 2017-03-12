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

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "UI.h"

using namespace std;


void UI::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add new product \n\n";
  cout<< "          2. Add more inventory \n\n";
  cout<< "          3. Print inventory \n\n";
  cout<< "          4. Print customers \n\n";
  cout<< "          5. Remove product \n\n";
  cout<< "          6. Print orders \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 6) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void UI::cashierMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM CASHIER MENU\n\n";
  cout<< "          1. Product purchases\n\n";
  cout<< "          2. Product returns\n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 2) {
    cout << "Enter your selection:  ";
	choice = readInt();
    if (choice == MAGIC_NUM) return;
  }
}



void UI::printStock(ProdList& arr)
{ 
  string s;
  arr.toString(s);
  cout << s;
}



void UI::printCustomers(CustArray& arr)
{
  cout << endl << "CUSTOMERS: " << endl << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  for (int i=0; i < arr.getSize(); i++) {
    Customer* cust = arr.get(i);
    cout << cust->getId() << "  " << setw(10) << cust->getName()
         << "  " << setw(4) << cust->getPoints() << endl;

	// iterate through customer purchase array
	PurchArray& purchases = cust->getPurchArray();
    printPurchases(purchases);
  }
}


void UI::printPurchaseSummary(float totalAmount, int points)
{
	cout << "\n\n PURCHASE SUMMARY : \n\n";
    cout<< " Total purchase amount: $" << totalAmount <<"\n";
    cout<< " Total points earned  :  " << points <<"\n"<<endl;
}


void UI::printError(string err)
{
  cout << endl << err << " -- press enter to continue...";
  cin.get();
}

void UI::printUsageError()
{
  cout << endl << "Usage:  cushop OPTION" << endl << endl;
  cout <<         "        where OPTION is either: " << endl;
  cout <<         "              -a  Admin menu"        << endl;
  cout <<         "              -c  Cashier menu"      << endl << endl;
}

void UI::promptForInt(string prompt, int& num)
{
  cout << prompt << ": ";
  num = readInt();
}

void UI::promptForStr(string prompt, string& str)
{
  cout << prompt << ": ";
  getline(cin, str);
}

void UI::promptForFloat(string prompt, float& num)
{
  string str;

  cout << prompt << ": ";
  getline(cin, str);

  stringstream ss(str);
  ss >> num;
}

int UI::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void UI::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}


void UI::printPurchases(PurchArray& arr)
{
  cout << endl << "Purchased items: " << endl << endl;
  cout << "PROD ID                              Name             Size    Qty   Subtotal" << endl;
  cout << " --                                 ----             ----    ---    -------" << endl;
  for(int i = 0; i < arr.getPurchArraySize(); i++)
  {
    stringstream ss;
    Purchase* p = arr.getPurchase(i);

    cout << p->getProd()->getId()   << "  " << setw(40) << p->getProd()->getName() << "  "
         << setw(10) << p->getProd()->getSize() << "  " << setw(4)  << p->getPurchQnt() 
         << "    ";

    ss << setw(6) << fixed << setprecision(2) << p->getProd()->getPrice()*p->getPurchQnt();
    cout << "$" << ss.str() << endl;
    ss.str("");
  }
  cout << "---------------------------------------------------------------------------" << endl << endl;

}


void UI::printOrders(OrderArray& orders)
{
  cout << endl << endl << "ORDERS: " << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  for (int i=0; i < orders.getOrderSize(); i++) {
    Order* order = orders.getOrder(i);
    cout << "Order ID: " << order->getOrderID() << "  " << setw(10)
         << "Customer: " << order->getCustomer()->getName() << setw(15) 
         << "  " << setw(20) << "TOTAL: $" << order->getTotalAmount()  << endl;
    PurchArray& purchases = order->getOrderPurches();
    printPurchases(purchases);
  }
}
