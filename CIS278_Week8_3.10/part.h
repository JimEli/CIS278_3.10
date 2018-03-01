/*************************************************************************
* Title: Invoice Class
* File: Part.h
* Author: James Eli
* Date: 1/17/2018
*
* Invoice Class Declaration.
*
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
* set to 0.
*
* Notes:
*  (1) I added overloaded comparison and stream operators.
*  (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/17/2018: Initial release. JME
*************************************************************************/
#ifndef _PART_H
#define _PART_H

#include <iostream>
#include <string>
#include <cstring>

class Part {
public:
	// Default part inventory constructor.
	Part(const std::string& = "", const std::string& = "", int = 0, int = 0);

	// Accessor functions for part number.
	void setNumber(const std::string&);
	std::string getNumber() const;

	// Accessor functions for part description.
	void setDescription(const std::string&);
	std::string getDescription() const;

	// Accessor functions for quantity.
	void setQuantity(int);
	int getQuantity() const;

	// Accessor functions for cost.
	void setCost(int);
	int getCost() const;

	// Return amount (quantity*cost).
	int getInvoiceAmount(void);

	// Overloaded comparison operators.
	bool operator== (const Part&);
	bool operator!= (const Part&);

	// Print formatted tool record. 
	friend std::ostream& operator<< (std::ostream& os, const Part& part)
	{
		return os << "Part #" << part.getNumber()
			<< "\nPart Description: " << part.getDescription()
			<< "\nPart Quantity: " << part.getQuantity()
			<< "\nPart cost: " << part.getCost()
			<< std::endl;
	}

private:
	// Private member data.
	char partNumber[12];
	char partDescription[80];
	int partQuantity;
	int partCost;
};

#endif
