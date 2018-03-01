/*************************************************************************
* Title: Invoice Class
* File: Part.cpp
* Author: James Eli
* Date: 1/17/2018
*
* Invoice Class Definition.
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
#include <string>

#include "part.h"

// Default Part constructor.
Part::Part(const std::string& number, const std::string& description, int quantity,  int cost)
	: partQuantity(quantity), partCost(cost)
{
	setNumber(number);
	setDescription(description);
}

// Get/set part number.
std::string Part::getNumber() const { return std::string(partNumber); }
void Part::setNumber(const std::string& number) {
	// Copy at most 12 characters from string to partNumber.
	size_t length{ number.size() };
	length = (length < 12) ? length : 11;
	number.copy(partNumber, length);
	// Append null character.
	partNumber[length] = '\0';
}

// Get/set part description.
std::string Part::getDescription() const { return std::string(partDescription); }
void Part::setDescription(const std::string& description) {
	// Copy at most 80 characters from string to partDescription.
	size_t length{ description.size() };
	length = (length < 80) ? length : 79;
	description.copy(partDescription, length);
	// Append null character.
	partDescription[length] = '\0';
}

// Get/set quantity.
int Part::getQuantity() const { return partQuantity; }
void Part::setQuantity(int quantity) {
	// If the quantity is not positive, it should be set to 0.
	if (quantity < 0)
		partQuantity = 0;
	else
		partQuantity = quantity;
}

// Get/set cost.
int Part::getCost() const { return partCost; }
void Part::setCost(int cost) {
	// If the price per item is not positive, it should be set to 0.
	if (cost < 0)
		partCost = 0;
	else
		partCost = cost;
}

// Calculate amount.
int Part::getInvoiceAmount(void) {
	return partQuantity * partCost;
}

// Overloaded comparison operators.
bool Part::operator== (const Part& p)
{
	return (strcmp(this->partNumber, p.partNumber) == 0 &&
		strcmp(this->partDescription, p.partDescription) == 0 &&
		this->partQuantity == p.partQuantity &&
		this->partCost == p.partCost);
}

bool Part::operator!= (const Part& p)
{
	return !(*this == p);
}

