OBJ = main.o InvControl.o Store.o Product.o UI.o CustArray.o Customer.o Purchase.o PurchArray.o ProdList.o Order.o

cushop:	$(OBJ)
	g++ -o cushop $(OBJ)

main.o:	main.cc
	g++ -c main.cc

InvControl.o:	InvControl.cc InvControl.h Store.h UI.h
	g++ -c InvControl.cc

UI.o:	UI.cc UI.h
	g++ -c UI.cc

Store.o:	Store.cc Store.h ProdList.h
	g++ -c Store.cc

Product.o:	Product.cc Product.h
	g++ -c Product.cc

CustArray.o:	CustArray.cc CustArray.h Customer.h defs.h
	g++ -c CustArray.cc

Customer.o:	Customer.cc Customer.h PurchArray.h
	g++ -c Customer.cc

Purchase.o: Purchase.cc Purchase.h Product.h defs.h
	g++ -c Purchase.cc

PurchArray.o: PurchArray.cc PurchArray.h Purchase.h defs.h
	g++ -c PurchArray.cc

ProdList.o: ProdList.cc ProdList.h Product.h defs.h
	g++ -c ProdList.cc

Order.o: Order.cc Order.h Customer.h PurchArray.h defs.h
	g++ -c Order.cc

clean:
	rm -f $(OBJ) cushop
