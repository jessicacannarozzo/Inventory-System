OBJ = main.o InvControl.o Store.o Product.o UI.o CustArray.o Customer.o Purchase.o PurchArray.o ProdList.o Order.o OrderArray.o OrderServer.o Date.o Perishable.o 
NonPerishable.o Taxable.o NonTaxable.o

cushop:	$(OBJ)
	g++ -o cushop $(OBJ)

main.o:	main.cc
	g++ -c main.cc

InvControl.o:	InvControl.cc InvControl.h Store.h UI.h OrderServer.h
	g++ -c InvControl.cc

UI.o:	UI.cc UI.h CustArray.h ProdList.h OrderArray.h
	g++ -c UI.cc

Store.o:	Store.cc Store.h ProdList.h
	g++ -c Store.cc

Product.o:	Product.cc Product.h Date.h
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

OrderArray.o: OrderArray.cc OrderArray.h Order.h
	g++ -c OrderArray.cc

OrderServer.o: OrderServer.cc OrderServer.h OrderArray.h
	g++ -c OrderServer.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Perishable.o: Perishable.cc Perishable.h Product.h
	g++ -c Perishable.cc
	
NonPerishable.o: NonPerishable.cc NonPerishable.h Product.h defs.h
	g++ -c NonPerishable.cc	

Taxable.o: Taxable.cc Taxable.h Product.h defs.h
	g++ -c Taxable.cc
	
NonTaxable.o: NonTaxable.cc NonTaxable.h Product.h
	g++ -c NonTaxable.cc	
clean:
	rm -f $(OBJ) cushop
