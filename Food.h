/**
 * @file Food.h
 * @brief Defines the Food class and related enumerations for the restaurant system.
 * @authors Edward Villano
 */

#ifndef RESTAURANTREAL_FOOD_H
#define RESTAURANTREAL_FOOD_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Enumeration representing different types of food and drinks available.
 * This includes a variety of beverages and meal options.
 */
enum FOOD {
    WATER,
    SODA,
    TEA,
    COFFEE,
    BEER,
    MIXED_DRINK,
    WINGS,
    QUESADILLAS,
    FRIED_MOZZ,
    HAMBURGER,
    CHEESEBURGER,
    CHICKEN_TENDERS,
    GRILLED_SALMON,
    VEG_RICE_BOWL,
    APPLE_PIE,
    LAVA_CAKE,
    ICE_CREAM
};

/**
 * Array of strings representing the names of the food items in the FOOD enumeration.
 */
const string foodString[17]{
        "Water","Soda","Tea","Coffee",
        "Beer","Mixed Drink",
        "Wings", "Quesadillas", "Fried Mozzarella",
        "Hamburger","Cheeseburger","Four Chicken Tenders",
        "Grilled Salmon","Vegetable Rice Bowl",
        "Apple Pie","Lava Cake","Ice Cream"

};

/**
 * Array of floats representing the prices of the food items in the FOOD enumeration.
 */
const float priceList[17] = {
    0.00, 1.990, 2.990, 2.990,
    5.990, 6.990,
    8.990, 7.990, 7.990,
    10.990, 11.990, 6.990,
    12.990, 9.990,
    8.99, 9.99, 6.99
};

/**
 * @class Food
 * @brief It encapsulates details about a food item such as its type and provides methods
 * for retrieving its price and displaying its information.
 */
class Food {
    private:
        FOOD food; // Type of food

    public:
        /**
         * Constructor to create a food item with a specified type.
         * @param foodP Type of food as defined in the FOOD enumeration.
         */
        Food(FOOD foodP);

        /**
         * Default constructor for the Food class.
         * Initializes a food item to a default value.
         */
        Food();

        /**
         * Retrieves the price of the food item.
         * @return The price of the food item.
         */
        float getPrice();

        /**
         * Get enum number and convert to string
         * @return converted enum in string
         */

        string getEnumToString();

        /**
         * Prints details of the food item, including its name and price.
         */
        void print();
};

#endif //RESTAURANTREAL_FOOD_H