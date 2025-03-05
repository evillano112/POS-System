/**
 * @file main.cpp
 * @brief Main entry point for the Restaurant Ordering System.
 *        This file handles file input/output operations and initiates the user interaction through the OptionsMenu.
 * @author Edward Villano
 */
#include <iostream>
#include <fstream>
#include "OptionsMenu.h"

using namespace std;

/**
 * Function main begins with program execution
 * @param argc The number of command line arguments
 * @param argv The array of command line arguments
 * @return The result of program execution
 */
int main(int argc, char** argv) {
    string inputFilePath, outputFilePath, s;
    for (int i = 0; i < argc ; i++){
        s = argv[i];
        if (s == "-o"){
            outputFilePath = argv[i+1];
        } else if (s == "-i"){
            inputFilePath = argv[i+1];
        }
    }

    ifstream inputFile(inputFilePath);
    ofstream outputFile(outputFilePath);

    if(!inputFile){
        cerr << "Input file not found" << endl;
    }
    cout << "\nInputting from: " << inputFilePath << endl;
    cout << "Outputting to: " << outputFilePath << "\n\n\n" <<endl;

    OptionsMenu menu;
    menu.ProcessChoice(inputFile, outputFile);



    if (inputFile.is_open()) {
        inputFile.close();
    }
    if (outputFile.is_open()) {
        outputFile.close();
    }

    return 0;
}