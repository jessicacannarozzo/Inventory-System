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

/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/* Authors: Jess Cannarozzo (101007447)            */
/*          Karla Martins Spuldaro (101021516)     */
/*                                                 */
/* Class Def: UI.h                                 */
/* Provides the user interface for this            */
/* application.                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

#include "ProdArray.h"
#include "CustArray.h"

class UI
{
  public:
    void mainMenu(int&);                //displays main menu & propmts user for a choice
    void adminMenu(int&);               //displays admin menu & propmts user for a choice
    void cashierMenu(int&);             //displays cashier menu & propmts user for a choice
    void promptForInt(string, int&);    //stores client's entry choice in an int
    void promptForStr(string, string&); //stores client's entry choice in a string
    void promptForFloat(string, float&);//stores client's entry choice in a float
    void printError(string);            //displays given error msg 
    void printUsageError();             //displays main menu error msg for wrong input
    void printStock(ProdArray&);        //displays complete product information from stock
	void pause();                       //prompts client to press enter

	//prints out all the purchase information for each customer, in addition to all the customer’s information
    void printCustomers(CustArray&);

	//print a summary to the screen of the total purchase amount and number of points earned
	void printPurchaseSummary(float, int);

  private:
    int    readInt(); //converts given string to an int
};

#endif
