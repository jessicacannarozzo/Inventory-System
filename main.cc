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
/* Class Def: Main.cc                              */
/* Launches the program.                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "InvControl.h"
#include "Date.h"
#include <iostream>

int main(int argc, char* argv[])
{

  /*Date *d = new Date(5, 1, 0);

  cout << *d << endl;
  d += 1;
  cout << *d << endl;
  */

   InvControl control;

   control.launch(argc, argv);


  return 0;
}
