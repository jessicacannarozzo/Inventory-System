OBJ = main.o InvControl.o Store.o Product.o UI.o CustList.o Customer.o Purchase.o PurchArray.o ProdList.o Order.o OrderArray.o OrderServer.o Date.o Perishable.o NonPerishable.o Taxable.o NonTaxable.o Dairy.o CoffeeTea.o Bakery.o Meat.o MiscGoods.o

cushop:	$(OBJ)
	g++ -o cushop $(OBJ)

main.o:	main.cc
	g++ -c main.cc

InvControl.o:	InvControl.cc InvControl.h Store.h UI.h OrderServer.h
	g++ -c InvControl.cc

UI.o:	UI.cc UI.h CustList.h ProdList.h OrderArray.h
	g++ -c UI.cc

Store.o:	Store.cc Store.h ProdList.h
	g++ -c Store.cc

Product.o:	Product.cc Product.h Date.h ExpirationBehaviour.h TaxationBehaviour.h
	g++ -c Product.cc

CustList.o:	CustList.cc CustList.h Customer.h defs.h
	g++ -c CustList.cc

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

Perishable.o: Perishable.cc Perishable.h ExpirationBehaviour.h defs.h
	g++ -c Perishable.cc

NonPerishable.o: NonPerishable.cc NonPerishable.h ExpirationBehaviour.h defs.h
	g++ -c NonPerishable.cc

Taxable.o: Taxable.cc Taxable.h TaxationBehaviour.h defs.h
	g++ -c Taxable.cc

NonTaxable.o: NonTaxable.cc NonTaxable.h TaxationBehaviour.h
	g++ -c NonTaxable.cc

Dairy.o: Dairy.cc Product.h Perishable.h NonTaxable.h
	g++ -c Dairy.cc

CoffeeTea.o: CoffeeTea.cc Product.h NonPerishable.h Taxable.h
	g++ -c CoffeeTea.cc

Bakery.o: Bakery.cc Product.h Perishable.h Taxable.h
	g++ -c Bakery.cc

Meat.o: Meat.cc Product.h Perishable.h NonTaxable.h
	g++ -c Meat.cc

MiscGoods.o: MiscGoods.cc Product.h NonPerishable.h NonTaxable.h
	g++ -c MiscGoods.cc

clean:
	rm -f $(OBJ) cushop
