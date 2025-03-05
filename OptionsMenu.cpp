/**
 * @file OptionsMenu.cpp
 * @brief This file contains the OptionsMenu class which handles the main menu display and processing of user choices
 *        for the Restaurant Ordering System.
 * @author Edward Villano
 */
#include "OptionsMenu.h"
#include <iostream>
#include <limits>

/**
 * Displays the main menu of the restaurant ordering system.
 * This function prints the options available to the user, including placing orders,
 * getting order details, marking orders as complete, and exiting the program.
 */
void OptionsMenu::DisplayMainMenu() {
    cout << "\n---------------------------------\n";
    cout << "   Restaurant Ordering System   \n";
    cout << "---------------------------------\n";
    cout << "1. Place an order\n";
    cout << "2. Get the next order to cook\n";
    cout << "3. Get current order details\n";
    cout << "4. Mark current order as complete\n";
    cout << "5. List all orders waiting to be picked up\n";
    cout << "6. Mark order as ready for pick up\n";
    cout << "7. Cancel an order\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

/**
 * Processes the user's choice from the main menu.
 * This function reads the user's choice and executes the corresponding action
 * in the Restaurant Ordering System. It handles options like placing orders,
 * getting next orders to cook, marking orders as complete, and canceling orders.
 * It continues to display the menu and process choices until the user decides to exit (choice 0).
 */
void OptionsMenu::ProcessChoice(ifstream& inputStreamP, ofstream& outputStreamP) {

    POS.fileRead(inputStreamP);
    int choice = -1;

    while (choice != 0) {
        DisplayMainMenu();
        choice = menuInput();
        switch (choice) {

            case 0:
                POS.fileWrite(outputStreamP);
                break;
            case 1:
                POS.placeOrder();
                break;
            case 2:
                POS.getNextOrderToCook();
                break;
            case 3:
                POS.getOrderDetails();
                break;
            case 4:
                POS.markOrderComplete();
                break;
            case 5:
                POS.listAllOrders();
                break;
            case 6:
                POS.markOrderForPickup();
                break;
            case 7:
                POS.cancelOrder();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    cout << "Bye!" << endl;
}

/**
 * Captures and validates user input for menu selection.
 * This function ensures that the input is a valid integer within the expected range.
 * It repeatedly prompts the user for input until a valid number is entered.
 *
 * @return The validated choice entered by the user.
 */
int OptionsMenu::menuInput(){
    int choice = -1;
    while (choice > 7 || choice < 0) {
        cin >> choice;
        // Check for input failure
        if (cin.fail()) {
            cin.clear(); // Clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip to the next line
            cout << "Invalid input. Please enter a number.\n";
        }
    }
    return choice;
}