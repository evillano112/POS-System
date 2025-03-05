/**
 * @author Edward Villano
 *
 */

#include "Order.h"
#include "RestaurantSystem.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>

/**
 * Adds a skip count to all phone and Doordash orders.
 * This function iterates through the orders and increases the skip count for each.
 *
 * @param index The number of orders to process.
 */
void RestaurantSystem::addSkipCountToAll(int index) {
    for (int i = 0; i < index; i++){
        Orders[i].increaseSkipCount();
    }
}

/**
 * Checks for lower priority orders based on specific criteria.
 * It iterates through orders to find the first order that matches the criteria:
 * Order status is PLACED, skip count is 3, and order type is either PHONE or DOORDASH.
 *
 * @param index The number of orders to check.
 * @return The index of the first order that matches the criteria or the passed index if no match is found.
 */
int RestaurantSystem::checkLowerPriority(int index) {
    for (int i = 0; i < index; i++) {
        if ((Orders[i].getOrderStatus() == PLACED) && (Orders[i].getSkipCount() == 3)
            && (Orders[i].getOrderType() == PHONE)) {
            return i;
        }
    }
    for (int i = 0; i < index; i++) {
        if ((Orders[i].getOrderStatus() == PLACED) && (Orders[i].getSkipCount() == 3)
            && (Orders[i].getOrderType() == DOORDASH)) {
            return i;
        }
    }
    return index;
}

/**
 * Checks the queue for a specific type of order.
 * This function looks for the next order of a given type that is placed, and updates its status to cooking.
 * It also handles the logic for adding skip counts and printing the order.
 *
 * @param type The type of order to look for.
 * @return True if a matching order is found and processed, false otherwise.
 */
bool RestaurantSystem::checkQueueForType(OrderType type){
    int tempIndex = 0;
    for (int i = 0; i < Orders.size(); i++){
        if (Orders[i].getOrderStatus() == PLACED && Orders[i].getOrderType() == type
            && ( (Orders.size() == 1) || (i != currentOrderIndex) ) ) {
            if (type == DRIVE_THROUGH || type == ONSITE ) {
                tempIndex = checkLowerPriority(i);
                //Add skip count to skipped orders
                addSkipCountToAll(i);
            } else {
                tempIndex = i;
            }
            Orders[tempIndex].print(false);
            // set status to cooking

            Orders[tempIndex].setOrderStatus(0);
            currentOrderIndex = tempIndex;

            return true;
        }
    }
    return false;
};

// Constructor and destructor
RestaurantSystem::RestaurantSystem() = default;
RestaurantSystem::~RestaurantSystem(){};

/**
 * Prints orders based on their status and type.
 * This function iterates through all orders and prints those matching the specified status and type.
 *
 * @param statusP The status of orders to print.
 * @param typePs A vector of order types to include in the printout.
 */
void RestaurantSystem::printOrders(int statusP, const vector<int>& typePs) {
    cout << "\n----NAME-----|--ID--|---TYPE---|-STATUS-" << endl;
    for(int i = 0; i < Orders.size(); i++){
        bool typeMatch = false;
        for (int typeP : typePs) {
            if(Orders[i].getOrderType() == typeP) {
                typeMatch = true;
                break;
            }
        }

        if(Orders[i].getOrderStatus() == statusP && typeMatch) {
            cout << setw(12) << left << Orders[i].getName()
                 << " | " << setw(4) << Orders[i].getOrderID()
                 << " | " << setw(6) << OrderTypeList[Orders[i].getOrderType()]
                 << " | " << setw(8) << StatusList[Orders[i].getOrderStatus()] << endl;
        }
    }
}

/**
 * Prompts the user to place an order and adds it to the system.
 * The function collects order details from the user, including order type and name, and adds a new order to the system.
 */
void RestaurantSystem::placeOrder() {
    nextID += 1;
    int type = -1;
    string name;

    while (type > 4 || type < 1){
        cout << "\nOrder Type: \n"
                " 1. Drive Through\n"
                " 2. Onsite\n"
                " 3. Phone\n"
                " 4. Doordash" << endl;
        cin >> type;

        if(type > 4 || type < 1){
            cout << endl << "Invalid input. Please try again: ";
        }
    }

    bool isValid = false;

    while (!isValid) {
        cout << "First name: ";
        cin >> name;

        // Check if input contains spaces
        if (name.find(' ') == string::npos && !name.empty()) {
            isValid = true;
        } else {
            cout << "Invalid input. Please enter a single word without spaces.\n";
            // Clear the input buffer in case of an invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    Order newOrder = Order(nextID, name, static_cast<OrderType>(type -1));

    if (newOrder.addMeal()){
        Orders.push_back(newOrder);
        newOrder.print(true);
    } else {
        cout << "Nothing was added to the order"
                "\nCanceling and returning to menu\n" << endl;
    }
}

/**
 * Processes the next order in the queue based on a set priority.
 * The function checks the queue in a predefined order (DRIVE_THROUGH, ONSITE, PHONE, DOORDASH) and processes the next available order.
 */
void RestaurantSystem::getNextOrderToCook() {

    if (checkQueueForType(DRIVE_THROUGH)){
        return;
    } else if (checkQueueForType(ONSITE)){
        return;
    } else if (checkQueueForType(PHONE)){
        return;
    } else if (checkQueueForType(DOORDASH)) {
        return;
    } else {
        cout << "No orders found!" << endl;
        return;
    }
}

/**
 * Prints the details of the current order.
 * The function displays information about the order that is currently being processed.
 */
void RestaurantSystem::getOrderDetails() {
    Orders[currentOrderIndex].print(false);
}

/**
 * Marks the current order as complete.
 * The function updates the status of the current order to indicate it is completed.
 */
void RestaurantSystem::markOrderComplete() {
    Orders[currentOrderIndex].setOrderStatus(1);
}

/**
 * Lists all orders that are waiting to be picked up.
 * The function displays orders with a specific status (waiting for pickup).
 */
void RestaurantSystem::listAllOrders() {
    string trash;

    RestaurantSystem::printOrders(3, {2,3});

    cout << "\nPress enter to continue...";
    cin.ignore();
    cin.clear();
    getline(cin,trash);
}

/**
 * Marks an order as ready for pickup based on the order ID provided by the user.
 * The function prompts the user for an order ID, then changes the status of the specified order to indicate it is ready for pickup.
 */
void RestaurantSystem::markOrderForPickup() {
    RestaurantSystem::printOrders(2, {2,3});

    int markOrderID = -1;

    while(markOrderID < 0) {
        cout << endl << "Input order ID number that you would like to change status: ";
        cin >> markOrderID;

        if(markOrderID < 0) {
            cout << "Please enter a valid order id" << endl;
        }
    }

    bool isFound = false;

    for (auto& order : Orders) {
        if (order.getOrderID() == markOrderID) {
            order.setOrderStatus( 2); // Mark the order as complete
            isFound = true;
            break; // Break out of the loop once the order is found and updated
        }
    }

    if (!isFound) {
        cout << "ID # not found" << endl;
    }
}

/**
 * Prompts the user for an order ID and cancels the corresponding order.
 * The function lists all cancellable orders, then allows the user to select one for cancellation based on its ID.
 */
void RestaurantSystem::cancelOrder() {
    int cancelOrderId = -1;
    string trash;

    if (Orders.empty()) {
        cout << "There are no orders available to cancel." << endl;

        cout << "\nPress enter to continue...";
        cin.ignore();
        cin.clear();
        getline(cin,trash);

        return;
    }

    else{
        RestaurantSystem::printOrders(0, {1,2,3,4});

    while(cancelOrderId < 0) {
        cout << endl << "Input order ID number that you would like to cancel: ";
        cin >> cancelOrderId;

        if(cancelOrderId < 0) {
            cout << "Please enter a valid order id" << endl;
        }
    }
        vector<Order>::iterator it;

        bool isFound = false;

        for (it = Orders.begin(); it != Orders.end() ; it++) {
            if (it->getOrderID() == cancelOrderId){
                if(it->getOrderStatus() == PLACED) {
                    it = Orders.erase(it);
                    --it;
                    isFound = true;
                }
            }
        }
        if(!isFound || it->getOrderStatus() != 0) {
            cout << "ID # not found" << endl;
        }
    }
}


/**
 * Reads a file for orders
 */
void RestaurantSystem::fileRead(ifstream& inputStreamPP){
    int currentOrderIndexFile;
    int nextIDFile;
    int orderIDFile;
    string nameFile;
    int typeFile;
    OrderType typeFileCast;
    int mealSize;
    int mealFile;
    vector <Food> mealFileCast;
    int skipCountFile;
    int statusFile;
    Status statusFileCast;


    if (!inputStreamPP.eof()){
        inputStreamPP >> currentOrderIndexFile;
        currentOrderIndex = currentOrderIndexFile;
    }
    if (!inputStreamPP.eof()){
        inputStreamPP >> nextIDFile;
        nextID = nextIDFile;
    }

    while(inputStreamPP >> orderIDFile >> nameFile >> typeFile >> mealSize){

        typeFileCast = static_cast<OrderType>(typeFile);

        for (int k = 0; k < (mealSize - 1); k++) {
            if (inputStreamPP >> mealFile) {
                mealFileCast.push_back(static_cast<FOOD>(mealFile));
            } else {
                std::cerr << "Error reading meal" << endl;
                break;
            }
        }

        if (!(inputStreamPP >> skipCountFile >> statusFile)) {
            cerr << "Error reading skip count and status" << endl;
            break;
        }
        statusFileCast = static_cast<Status>(statusFile);


        Orders.push_back(Order(orderIDFile, nameFile, typeFileCast,
                          mealFileCast, skipCountFile, statusFileCast));

    }


};

/**
 * Writes orders to a file
 */
void RestaurantSystem::fileWrite(ofstream& outputStreamPP){
    if (Orders.size() > 0) {
        outputStreamPP << currentOrderIndex << " " << nextID << endl;
    }
    for (int i = 0; i < Orders.size(); i++) {
        if (i > 0){
            outputStreamPP << "\n";
        }

        outputStreamPP << Orders[i].getOrderID() << " " << Orders[i].getName() << " " <<
                      Orders[i].getOrderType() << " " << Orders[i].getSkipCount() << " "
                      << Orders[i].getOrderStatus();

        outputStreamPP << "\n" << Orders[i].mealToString();

    }
};