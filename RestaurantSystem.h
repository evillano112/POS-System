/**
 * @author Edward Villano
 *
 */

#ifndef RESTAURANTREAL_RESTAURANTSYSTEM_H
#define RESTAURANTREAL_RESTAURANTSYSTEM_H

#include <queue>
#include <string>
#include <unordered_map>
#include <fstream>
#include "Order.h"

using namespace std;

/**
 * Manages the queueing system of orders in a restaurant.
 */
class RestaurantSystem {
private:
    int nextID = 0;
    vector <Order> Orders;
    int currentOrderIndex = 0;

public:

    /**
     * Constructor for the RestaurantSystem class.
     */
    RestaurantSystem();

    void printOrders(int statusP, const vector<int>& typePs);

    /**
     * Adds 1 to skip count of all
     * phone and doordash orders
     * placed before index
     */
    void addSkipCountToAll(int index);

    /**
     * Check to see if order before
     * index has priority due to
     * skip count of 3
     * @param index
     * @return Phone or door dash
     * order with priority or original
     * index if there isnt
     */
    int checkLowerPriority(int index);

    /**
     * Checks queue for specified type
     * @param type
     * @return whether the type is present
     */
    bool checkQueueForType(OrderType type);
    /**
     * Places an order into the system with a specific order ID and type.
     * @param orderID Unique identifier for the order.
     * @param type Type of the order.
     */
    void placeOrder();

    /**
     * Processes and gets the next order to be cooked.
     */
    void getNextOrderToCook();

    /**
     * Prompts user for ID
     * Retrieves and displays details of a specific order based on its ID.
     */
    void getOrderDetails();

    /**
     * Prompts user for ID
     * Marks an order as complete and removes it from the system.
     */
    void markOrderComplete();

    /**
     * Lists all orders currently in the system.
     */
    void listAllOrders();

    /**
     * Prompts user for ID
     * Marks an order as ready for pickup.
     */
    void markOrderForPickup();

    /**
     * Prompts user for ID
     * Cancels an order based on its ID.
     */
    void cancelOrder();

    /**
     * Destructor for the RestaurantSystem class.
     * Responsible for freeing dynamically allocated memory.
     */
    ~RestaurantSystem();

    /**
     * Reads a file for orders
     */
    void fileRead(ifstream& inputStreamP);

    /**
     * Writes orders to a file
     */
    void fileWrite(ofstream& outputStreamP);
};

#endif // RESTAURANTREAL_RESTAURANTSYSTEM_H