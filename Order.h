/**
 * @file Order.h
 * @brief Defines the Order class used in the Restaurant Ordering System. It encapsulates details about an order, including its ID, type, meals, and status.
 *        The class provides functionality to manage and retrieve order details.
 * @author Edward Villano
 */

#ifndef RESTAURANTREAL_ORDER_H
#define RESTAURANTREAL_ORDER_H

#include <string>
#include "Food.h"
#include <vector>

using namespace std;

// Enumerations for OrderType and Status
enum OrderType {
    DRIVE_THROUGH,
    ONSITE,
    PHONE,
    DOORDASH
};

const string OrderTypeList[4]{
        "DRIVE_THROUGH",
        "ONSITE",
        "PHONE",
        "DOORDASH"
};

enum Status {
    PLACED,
    COOKING,
    COMPLETE,
    READY_FOR_PICKUP,
};

const string StatusList[5]{
        "Placed",
        "Cooking",
        "Complete",
        "Ready for pickup",
};

/**
 * @class Order
 * @brief Represents an individual order in the restaurant system.
 *
 * Contains information about the order ID, type, the meals included, customer name, order status, and skip count.
 */
class Order {
    private:
        int orderID; // Unique identifier for the order
        OrderType type; // Type of the order (DRIVE_THROUGH, ONSITE, etc.)
        vector<Food> meal; // List of food items in the order
        int skipCount; // Skip count for the order, relevant for certain order types
        string name; // Customer name associated with the order
        Status status; // Current status of the order (PLACED, COOKING, etc.)

    public:
        /**
         * Default constructor for the Order class.
         * Initializes an Order object with default values.
         */
        Order();

        /**
        * Constructor for the Order class with parameters.
        * Initializes an Order object with specified order ID, name, and type.
        *
        * @param orderIDP The unique identifier for the order.
        * @param nameP The name associated with the order.
        * @param typeP The type of the order (e.g., DRIVE_THROUGH, ONSITE).
        */
        Order(int orderIDP, string nameP, OrderType typeP);

        /**
         * Constructor for Order class with additional parameters
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
        Order(int orderIDP, string nameP, OrderType typeP,
          vector <Food> mealP, int skipCountP, Status statusP);

        /**
        * Adds meals to the order based on user input.
        * Allows the user to continually add items to the order and returns true if any meal was added.
        *
        * @return True if at least one meal is added to the order, false if the user exits the menu without adding.
        */
        bool addMeal();

        /**
        * Calculates and returns the total amount of the order.
        * Adds up the prices of each food item in the order.
        *
        * @return The total price of the order as a double.
        */
        double getAmount();

        /**
        * Retrieves the current skip count of the order.
        *
        * @return The skip count as an integer.
        */
        int getSkipCount();

        /**
        * Increases the skip count of the order by one, up to a maximum of three.
        */
        void increaseSkipCount();

        /**
        * Retrieves the type of the order.
        *
        * @return The type of the order as an OrderType enum.
        */
        OrderType getOrderType();

        /**
         * Retrieves the unique identifier of the order.
         *
         * @return The order ID as an integer.
         */
        int getOrderID();

        /**
         * Retrieves the name associated with the order.
         *
         * @return The name as a string.
         */
        string getName();

        /**
         * Prints the details of the order, including all food items, their prices, and the total amount.
         * If the order is a Doordash order, a service fee is included in the total amount.
         *
         * @param input A boolean flag to indicate if additional user interaction is required after printing.
         */
        void print(bool input);

        /**
         * Retrieves the current status of the order.
         *
         * @return The current status as a Status enum.
         */
        Status getOrderStatus();

        /**
         * Retrieve the size of vector meal
         * followed by each food enum
         *
         * @return meal size and each food enum
         */
        string mealToString();

        /**
         * Sets the status of the order to a new value and prints the update.
         *
         * @param statusP The new status to set, represented as an integer.
         * @return The updated status as a Status enum.
         */
        Status setOrderStatus(int statusP);
};

#endif //RESTAURANTREAL_ORDER_H