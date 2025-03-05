/**
 * @file Order.cpp
 * @brief This file contains the Order class, responsible for handling individual orders in the restaurant system,
 *        including their creation, modification, and information retrieval.
 * @author Edward Villano
 */

#include "Order.h"
#include "Food.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

/**
 * Default constructor for the Order class.
 * Initializes an Order object with default values.
 */
Order::Order() = default;

/**
 * Constructor for the Order class with parameters.
 * Initializes an Order object with specified order ID, name, and type.
 *
 * @param orderIDP The unique identifier for the order.
 * @param nameP The name associated with the order.
 * @param typeP The type of the order (e.g., DRIVE_THROUGH, ONSITE).
 */
Order::Order(int orderIDP, string nameP, OrderType typeP){
    orderID = orderIDP;
    name = nameP;
    type = typeP;
    status = PLACED;
    if (type == DRIVE_THROUGH || type == ONSITE){
        skipCount = -1;
    } else {
        skipCount = 0;
    }
}

/**
 * Constructor for the Order class with additional parameters
 * for existing private values.
 * Specifically for file reading.
 *
 * @param orderIDP
 * @param nameP
 * @param typeP
 * @param mealP
 * @param skipCountP
 * @param statusP
 */
Order::Order(int orderIDP, string nameP, OrderType typeP,
             vector <Food> mealP, int skipCountP, Status statusP   ){
    orderID = orderIDP;
    name = nameP;
    type = typeP;
    meal = mealP;
    skipCount = 0;
    status = statusP;
}
/**
 * Adds meals to the order based on user input.
 * Allows the user to continually add items to the order and returns true if any meal was added.
 *
 * @return True if at least one meal is added to the order, false if the user exits the menu without adding.
 */
bool Order::addMeal(){
    int choice1, choice2;

    choice1 = choice2 = -1;

    cout << "\nSelect Item Type To Add:\n"
            " 1. Drink\n"
            " 2. Appetizer\n"
            " 3. Entree\n"
            " 4. Desert\n"
            " 0. Stop adding" << endl;
    cin >> choice1;

    if (choice1 == 0){
        return false;
    }

    while (choice1 != 0) {

        choice2 = -1;

        cin.ignore();
        cin.clear();


        switch (choice1) {
            case 1:
                while (choice2 < 1 || choice2 > 6) {
                    cout << "\nDrinks:\n"
                            " 1. Water\n"
                            " 2. Soda\n"
                            " 3. Tea\n"
                            " 4. Coffee\n"
                            " 5. Beer\n"
                            " 6. Mixed Drink\n"
                            " 0. Back to item type selection"
                         << endl;

                    cin >> choice2;

                    if (choice2 < 0 || choice2 > 6) {
                        cout << "Invalid input, please try again." << endl;
                    }

                    if (choice2 == 0){
                        break;
                    } else {
                        meal.push_back(Food(static_cast<FOOD>(choice2-1)));
                    }
                }
                break;

            case 2:
                while (choice2 < 1 || choice2 > 3) {
                    cout << "\nAppetizers:\n"
                            " 1. Wings\n"
                            " 2. Quesadillas\n"
                            " 3. Fried Mozzarella\n"
                            " 0. Back to item type selection" << endl;

                    cin >> choice2;

                    if (choice2 < 0 || choice2 > 3) {
                        cout << "Invalid input, please try again." << endl;
                    }

                    if (choice2 == 0) {
                        break;
                    } else {
                        meal.push_back(Food(static_cast<FOOD>(choice2 + 5)));
                    }
                }
                break;

            case 3:
                while (choice2 < 1 || choice2 > 5) {
                    cout << "\nEntrees:\n"
                            " 1. Hamburger\n"
                            " 2. Cheeseburger\n"
                            " 3. Four Chicken Tenders\n"
                            " 4. Grilled Salmon\n"
                            " 5. Vegetable Rice Bowl\n"
                            " 0. Back to item type selection" << endl;
                    cin >> choice2;

                    if (choice2 < 0 || choice2 > 5) {
                        cout << "Invalid input, please try again." << endl;
                    }

                    if (choice2 == 0) {
                        break;
                    } else {
                        meal.push_back(Food(static_cast<FOOD>(choice2 + 8)));
                    }
                }
                break;

            case 4:
                while (choice2 < 1 || choice2 > 3) {
                    cout << "\nDeserts:\n"
                            " 1. Apple Pie\n"
                            " 2. Lava Cake\n"
                            " 3. Ice Cream\n"
                            " 0. Back to item type selection" << endl;
                    cin >> choice2;

                    if (choice2 < 0 || choice2 > 3) {
                        cout << "Invalid input, please try again." << endl;
                    }

                    if (choice2 == 0) {
                        break;
                    } else {
                        meal.push_back(Food(static_cast<FOOD>(choice2 + 13)));
                    }
                }
                break;

            default:
                cout << "Invalid input, please try again." << endl;
                break;
        };

        cout << "\nSelect Item Type To Add:\n"
                " 1. Drink\n"
                " 2. Appetizer\n"
                " 3. Entree\n"
                " 4. Desert\n"
                " 0. Stop adding" << endl;
        cin >> choice1;
    }
    return true;
};

/**
 * Calculates and returns the total amount of the order.
 * Adds up the prices of each food item in the order.
 *
 * @return The total price of the order as a double.
 */
double Order::getAmount(){
    double amount = 0.00;
    for(Food& e: meal ){
        amount += e.getPrice();
    };
    return amount;
};

/**
 * Retrieves the current skip count of the order.
 *
 * @return The skip count as an integer.
 */
int Order::getSkipCount(){
    return skipCount;
};

/**
 * Increases the skip count of the order by one, up to a maximum of three.
 */
void Order::increaseSkipCount(){
    if (skipCount < 3) {
        skipCount += 1;
    }
};

/**
 * Retrieves the type of the order.
 *
 * @return The type of the order as an OrderType enum.
 */
OrderType Order::getOrderType(){
    return type;
}

/**
 * Retrieves the unique identifier of the order.
 *
 * @return The order ID as an integer.
 */
int Order::getOrderID(){
    return orderID;
};

/**
 * Retrieves the name associated with the order.
 *
 * @return The name as a string.
 */
string Order::getName(){
    return name;
}

/**
 * Retrieve the size of vector meal
 * followed by each food enum value
 *
 * @return meal size and each food enum
 */
string Order::mealToString(){
    string s;
    s = to_string(meal.size());

    for (int i = 0; i < meal.size(); i++){
        s +=( " " + meal[i].getEnumToString());
    }

    return s;
}

/**
 * Prints the details of the order, including all food items, their prices, and the total amount.
 * If the order is a Doordash order, a service fee is included in the total amount.
 *
 * @param input A boolean flag to indicate if additional user interaction is required after printing.
 */
void Order::print(bool input){
    string trash;
    transform(name.begin(), name.end(), name.begin(), ::toupper);

    double total = 0.00;

if(input){
    cout << endl << "---------------------------------" << endl;
    cout << "    THANK YOU " << setw(10) << name << "!" << endl;
    cout << "---------------------------------" << endl << endl;
}
else{
    cout << endl << setw(10) << name << "   " << orderID << endl;
}
    for(int i = 0; i < meal.size(); i++){
        meal[i].print();
        total += meal[i].getPrice();
    }
    if(getOrderType() == 3) {
        cout << endl << setw(15) << "Doordash Service Fee = 5%" << endl;
        cout << setw(15) <<  "Total Price: $" << (total*1.05) << endl;
    }
    else{
        cout << endl << setw(15) << "Total Price: $" << total << endl;
    }

    if(input) {
        cout << endl << "---------------------------------" << endl;
        cout << "\nPress enter to continue...";

        cin.ignore();
        cin.clear();
        getline(cin, trash);
    }
}

/**
 * Retrieves the current status of the order.
 *
 * @return The current status as a Status enum.
 */
Status Order::getOrderStatus(){
    return status;
}

/**
 * Sets the status of the order to a new value and prints the update.
 *
 * @param statusP The new status to set, represented as an integer.
 * @return The updated status as a Status enum.
 */
Status Order::setOrderStatus(int statusP){
    status = static_cast<Status>(statusP + 1);

    cout << "Order #" << orderID << " marked as " << StatusList[status] << endl;

    return status;
}