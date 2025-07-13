/*
Author: Musa Elqaq
Date: 2025/07/12
Filename: collatz.cpp
Purpose: Lets you see some basic information related to the Collatz conjecture.
A good video resource to learn more about this can be found here:
https://www.youtube.com/watch?v=094y1Z2wpJg by Veritasium


*/

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>


using namespace std;

void welcome() {
    printf("\nWelcome to a simple Collatz Conjecture value finder.");
    printf("\nThe basis of the conjecture is as follows: \n");
    printf("\nIf a number is odd, mulitply it by 3 and add 1.");
    printf("\nIf a number is even, divide it by 2.");
    printf("\nThe conjecture asserts that all numbers will end ");
    printf("\nin a 4 - 2 - 1 loop.");
}


/*
    Basic recursive operation:
        If odd , multiply by 3 and add 1
        If even, divide by 2
    
    @param num The initial seed value
    @param hailstones The vector of all found hailstone/step values
    @param maxVal The maximum value found among the hailstone values
    @returns The vector of all hailstone values
*/
void collatzer(long long num, vector<long long>& hailstones, long long& maxVal) {

    // long long dividerVal = 2; // Maybe on larger numbers, an int 2 would start breaking?

    if (num < 0) {
        printf("\n\nNegative numbers are not currently supported by this program.  Please try a different seed.\n\n");
        return;
    }

    // Handles the given input into 1 of 3 cases: 0, 1, or any other number
    switch (num) {
        case (0):
            // Shouldn't be possible unless the user enters in 0 specifically, but just in case.
            
            // If the hailstones vector is empty, add the 0 to it.  Else, do nothing/do not include it
            if (hailstones.empty()) {
                hailstones.push_back(num);
            }

            break;
        case (1):
            hailstones.push_back(num);
            printf("\nThe #%d hailstone number is now:%lld", hailstones.size(), num);
            printf("\n\nEnd of hailstone generation reached.\n");
            break;
        default:

            // Add the new value to the hailstones list
            hailstones.push_back(num);
            printf("\nThe #%d hailstone number is now:%lld", hailstones.size(), num);

            // Update the max value if needed
            if (num > maxVal) {
                maxVal = num;
            }

            // For even numbers: divide by 2
            if ((num % 2) == 0) {
                collatzer(num / 2, hailstones, maxVal);
            } 
            // For odd numbers : multiply by 3 and add 1
            else {
                collatzer(((num * 3) + 1), hailstones, maxVal);
            }
            break;
    }

}


/*
    Output the hailstone values
*/
void outputHailstones(const vector<long long>& hailstones) {
    for (long long val : hailstones) {
        printf(" %lld -", val);
    }
}


/*
    Allows the user to view statistics on the seed they entered

    @param hailstones A vector of calculated hailstone, or step, values generated from a given seed number
    @param maxVal The maximum value found when calculating the hailstone values of the given seed

    @returns Outputs the desired statistics, and will return `5` or `6` if the user wants to change the seed or exit.
*/
int viewStatistics(const vector<long long>& hailstones, long long maxVal) {
    
    if (hailstones.empty()) {
        printf("\n\nSomehow, there are no values in the hailstone list. Cannot give statistics in this situation.\n\n");
        return -1;
    }
    else { // Assuming the hailstone list is not empty, if the maxVal never changed somehow, set it to the first value in the list.
        if (maxVal == LONG_LONG_MIN) {
            maxVal = hailstones.at(0);
        }
    }

    int viewStats = 0;
    bool loop = true; // continue asking the user for operations on this specific seed value
    
    printf("\nWould you like to view the statistics of your entered value?");
    printf("\n\t1. View Largest Number Reached");
    printf("\n\t2. View Total Number of Hailstone Values (Steps)");
    printf("\n\t3. View All Hailstone Values");
    printf("\n\t4. View All Statistics");
    printf("\n\t5. Try a different number");
    printf("\n\t6. Quit");

    // Handles user input; always runs at least once
    do {
        printf("\n\nYour choice (1-6): ");

        // Handle viewing of statistics
        cin >> viewStats;
        switch (viewStats) {
            
            // Show the largest number
            case (1):
                printf("\nThe largest number reached was: %lld", maxVal);
                break;
            
            // Show the Total Number of Hailstone Values (Steps)
            case (2):
                printf("\nThe Total Number of Hailstone Values (Steps) was: %d", hailstones.size());
                break;

            // Show all hailstone values
            case (3):
                printf("\nThe hailstone/step values generated are: ");
                outputHailstones(hailstones);
                break;

            // Show all Statistics
            case (4):
                printf("\nThe largest number reached was: %lld", maxVal);
                printf("\nThe Total Number of Hailstone Values (Steps) was: %d\n", hailstones.size());
                printf("\nThe hailstone/step values generated are: ");
                outputHailstones(hailstones);
                break;
            
            // Exits to try a different number (in main function)
            case (5): // Break out of the loop
                loop = false;
                break;
        
            // Exits program (in main function)
            case (6): // Break out of the loop
                loop = false;
                break;
            
            // Handles any unsupport values
            default:
                printf("\nInvalid option entered. Please try again...\n");
                viewStatistics(hailstones, maxVal);
                break;
        }

    } while (loop);

    return viewStats; // Returns the values used, should really only be 5 or 6
}

// Main function
int main() {

    welcome();

    vector<long long> hailstones;
    long long maxVal = LONG_LONG_MIN;

    long long seed = 0;
    bool loop = true;

    int viewStats = 0;

    do {

        // Reset the values used
        hailstones.clear(); 
        seed = 0;
        maxVal = LONG_LONG_MIN;

        // Prompts the user for a seed
        printf("\nEnter in a seed value: ");
        cin >> seed;
        // printf("\nSeed is now: %lld", seed);

        // Runs the conjecture on the given seed number and stores the hailstone vals
        collatzer(seed, hailstones, maxVal);

        // Prompts the user on what they want to see/do next
        viewStats = viewStatistics(hailstones, maxVal);

        // The user wants to try a different number
        if (viewStats == 5) {
            loop = true;
        }
        // The user wants to exit
        else if (viewStats == 6) {
            loop = false;

            // Reset the values used
            hailstones.clear(); 
            seed = 0;
            maxVal = LONG_LONG_MIN;
        }
        // Other (non-error) values for viewStats are covered in viewStatistics()
        else if (viewStats == -1) {
            printf("\nAn Error Occurred: Please try a different seed.\n");
            continue;
        }

    } while (loop);

    printf("\n\nThank you for using this program!  Good bye!\n\n");

    return 0;
}