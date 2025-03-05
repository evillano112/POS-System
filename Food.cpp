/**
 * @file Food.cpp
 * @brief This file contains the Food class, which represents a food item in the restaurant ordering system,
 *        including its type and price.
 * @author Edward Villano
 */

#include "Food.h"

using namespace std;

/**
 * Constructor for the Food class.
 * Initializes a Food object with a specific type of food.
 *
 * @param foodP The type of food as an enum value.
 */
Food::Food(FOOD foodP) {
    food = foodP;
};

/**
 * Default constructor for the Food class.
 * Initializes a Food object with default values.
 */
Food::Food() = default;

/**
 * Prints the food item and its price.
 * This function displays the food item as a string and its corresponding price to the console.
 */
void Food::print(){
    cout << setw(15) << foodString[food] << setw(5) << "$" << getPrice() << endl;
}

/**
 * Get enum number and conver to string
 * @return converted enum in string
 */
string Food::getEnumToString(){
    return to_string(static_cast<int>(food));
}

/**
 * Retrieves the price of the food item.
 * This function returns the price associated with the food item's enum type.
 *
 * @return The price of the food item as a float.
 */
float Food::getPrice() {
    return priceList[food];
}
