/**
 * @file OptionsMenu.h
 * @brief The OptionsMenu class is responsible for displaying the main menu of the restaurant
 *        ordering system, processing user choices, and handling menu input validation.
 *        It acts as a user interface for interacting with the RestaurantSystem.
 * @authors Edward Villano
 */
#ifndef OPTIONS_MENU_H
#define OPTIONS_MENU_H

#include "RestaurantSystem.h"

using namespace std;

/**
 * @class OptionsMenu
 * @brief this class is used to display the menu options, then process and validate the user input
 */
class OptionsMenu {
public:
    /**
    * Displays the main menu of the restaurant ordering system.
    * This method prints the options available to the user, including placing orders,
    * getting order details, marking orders as complete, and exiting the program.
    */
    void DisplayMainMenu();

    /**
     * Reads and stores orders from input file
     * Processes the user's choice from the main menu.
     * This method reads the user's choice and executes the corresponding action
     * in the Restaurant Ordering System. It handles options like placing orders,
     * getting next orders to cook, marking orders as complete, and canceling orders.
     * It continues to display the menu and process choices until the user decides to exit.
     * Writes orders to output file upon exiting
     */
    void ProcessChoice(ifstream& inputStreamP, ofstream& outputStreamP);

    /**
     * Captures and validates user input for menu selection.
     * This method ensures that the input is a valid integer within the expected range.
     * It repeatedly prompts the user for input until a valid number is entered.
     *
     * @return The validated choice entered by the user.
     */
    int menuInput();

private:
    // Instance of RestaurantSystem to manage restaurant operations.
    RestaurantSystem POS = RestaurantSystem();
};

#endif // OPTIONS_MENU_H