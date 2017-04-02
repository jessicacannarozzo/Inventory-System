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
/* Class Def: InvControl.h                         */
/* Controls the inventory of the store. Processes  */
/* cashier and administration functions, which     */
/* allows the store to process transactions.       */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef INVCONTROL_H
#define INVCONTROL_H

#include "Store.h"
#include "UI.h"
#include "OrderServer.h"

class InvControl
{
  public:
    InvControl();
    void launch(int, char*[]);
  private:
    Store              store;
    UI                 view;
    static OrderServer orderServer;
    void   initProducts();  //initiate original product stock
    void   initCustomers(); //initiate collection of registered customers
    void   initNewProd(int, string, string, int, float, int, int, int, int);   //new prods may be added to the store
    void   processAdmin();  //process admin menu options
    void   processCashier();//process cashier menu options

};
#endif
