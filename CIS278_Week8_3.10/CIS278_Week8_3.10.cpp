/*************************************************************************
* Title: Invoice Class
* File: CIS278_Week8_3.10.cpp
* Author: James Eli
* Date: 1/17/2018
*
* Exercise 3.10 on page 100, Invoice Class
* Create a class called Invoice that a hardware store might use to represent 
* an invoice for an item sold at the store. An Invoice should include four 
* data members—a part number (type string), a part description (type string), 
* a quantity of the item being purchased (type int) and a price per item 
* (type int). Your class should have a constructor that initializes the four 
* data members. Provide a set and a get function for each data member. In 
* addition, provide a member function named getInvoiceAmount that calculates 
* the invoice amount (i.e., multiplies the quantity by the price per item), 
* then returns the amount as an int value. If the quantity is not positive, 
* it should be set to 0. If the price per item is not positive, it should be 
* set to 0. Write a test program that demonstrates class Invoice’s 
* capabilities.
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/17/2018: Initial release. JME
*************************************************************************/
#include <iostream> // cin/cout/endl
#include <cassert>  // assertions

#include "part.h"

using namespace std;

int main()
{
	// Instantiate and init some Part classes.
	Part p1{ "1234", "This is a part description", 1, 99 };
	Part p2;

	p2.setNumber("4321");
	p2.setDescription("Another part description");
	p2.setQuantity(2);
	p2.setCost(100);
	
	Part p3 = p2;
	Part p4(p3);

	// Display part information.
	cout << p1;
	cout << "Invoice amount = " << p1.getInvoiceAmount() << endl;
	cout << "\nPart #" << p2.getNumber() << endl;
	cout << "Part Description: " << p2.getDescription() << endl;
	cout << "Part Quantity: " << p2.getQuantity() << endl;
	cout << "Part Cost: " << p2.getCost() << endl;
	cout << "Invoice amount = " << p2.getInvoiceAmount() << endl;

	// Test equality operators.
	assert(p3 == p4);
	assert(p2 != Part());

	return 0;
}

