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
    void mainMenu(int&);                //not implemented...
    void adminMenu(int&);               //displays admin menu options
    void cashierMenu(int&);             //displays cashier menu options
    void promptForInt(string, int&);    //prompts integer from user
    void promptForStr(string, string&); //prompts string from user
    void promptForFloat(string, float&);//prompts float  from user
    void printError(string);            //displays given error message
    void printUsageError();             //displays usage error for running program
    void printStock(ProdArray&);        //displays store product stock info
    void printCustomers(CustArray&);    //displays registered customers info
    void pause();

	//print a summary to the screen of the total purchase amount and number of points earned
	void printPurchaseSummary(float, int);

  private:
    int    readInt();
};

#endif
