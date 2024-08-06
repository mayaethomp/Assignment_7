// Maya Thompson
// CS 1, Section #0107
// Assignment #7
// Summary: This program simulates a vending machine experience, allowing a user to select a drink and how much money they would like to spend. The program then displays the user's change, the final quantity of drinks, and total revenue earned. 

#include <iostream>
#include <iomanip>

using namespace std;


/*
------ ALGORITHM PSEUDOCODE ------
Declare structures, initialize global variables, and define function prototypes
Use a function to display a menu for the user to input a drink choice (1-5), validate that choice, and return the user's choice
If user selects 6, end program
Use a do/while loop to ensure the menu keeps displaying until the user inputs 6 to quit
Use a boolean to determine if user's drink selection is in stock
If user's drink selection is not in stock, display "Out of Stock" to the user and re-prompt the menu
If user's drink selection is in stock, subtract 1 from the drink's inventory and ask the user how much they want to spend
Use a function to prompt the user how much money they want to enter, validate that input and return their selection
Use a switch statement to determine if user has sufficient funds for drink selection
If user has sufficient funds for chosen drink selection, add cost of drink to total revenue and display their change, else display "Insufficient funds"
When the user selects 6, display the total revenue the machine has earned and the inventory quantity of each drink remaining, and end program
*/


// Declare structures
struct Drinks {
    const string name;
    const float cost;
};

// Practing struct, array would be easier for a single type
struct Inventory {
    int Qty;
};

// Declare and initialize global variables
/* ------------ DRINKS DATA --------------*/

    const Drinks cola = {"Cola", 0.65};
    const Drinks rootBeer = {"Root Beer", 0.70};
    const Drinks grapeSoda = {"Grape Soda", 0.75};
    const Drinks lemonLime = {"Lemon Lime", 0.85};
    const Drinks water = {"Water", 0.90};

    Inventory colaQty = {20};
    Inventory rootBeerQty = {20};
    Inventory grapeSodaQty = {20};
    Inventory lemonLimeQty = {20};
    Inventory waterQty = {20};

// Function prototypes
int menuSelection();     // Function to display a menu for the user to input a choice, validate that choice, and return the user's choice and set return value to menu
float userFunds();       // Function to prompt the user how much money they want to input, validate that input and return their selection


int main() {

    int menu;
    float totalRevenue = 0; // total revenue earned by machine

    do {
        // user's menu selection is set to menu variable
        menu = menuSelection();

        // If user selects 6, break loop and end program
        if (menu == 6) {
            break;
        }

        // Default drink to be in stock
        bool drinkInStock = true;

        // If user's drink selection is not in stock, display "Out of stock", else remove 1 from drink item's inventory count
        switch (menu) {
            case 1:
                if (colaQty.Qty <= 0) {
                    cout << "SOLD OUT" << endl << endl;
                    drinkInStock = false;
                } else {
                    colaQty.Qty -= 1;
                }
                break;                
            case 2:
                if (rootBeerQty.Qty <= 0) {
                    cout << "SOLD OUT" << endl << endl;
                    drinkInStock = false;
                } else {
                    rootBeerQty.Qty -= 1;
                }
                break;     
            case 3:
                if (grapeSodaQty.Qty <= 0) {
                    cout << "SOLD OUT" << endl << endl;
                    drinkInStock = false;
                } else {
                    grapeSodaQty.Qty -= 1;
                }
                break; 
            case 4: 
                if (lemonLimeQty.Qty <= 0) {
                    cout << "SOLD OUT" << endl << endl;
                    drinkInStock = false;
                } else {
                    lemonLimeQty.Qty -= 1;
                }
                break; 
            case 5:
                if (waterQty.Qty <= 0) {
                    cout << "SOLD OUT" << endl << endl;
                    drinkInStock = false;
                } else {
                    waterQty.Qty -= 1;
                }
                break;           
        }

        // If user's drink selection is in stock
        if (drinkInStock) {
            // user's fund choice is set to money variable
            float money = userFunds();
            float change;
            
            // Switch statement to determine if user has sufficient funds for drink selection and displays their change
            switch(menu) {
                case 1:
                    if (money >= cola.cost) { 
                            change = money - cola.cost; // calculate user's change
                            cout << setprecision(2) << "Change: $" << change << endl; // display user's change
                            totalRevenue += cola.cost;  // add cost to total revenue
                        } else {
                        cout << "Insufficient funds." << endl;
                        break;
                    }
                    break;
                case 2:
                    if (money >= rootBeer.cost) { 
                            change = money - rootBeer.cost;
                            cout << setprecision(2) << "Change: $" << change << endl;
                            totalRevenue += rootBeer.cost;
                        } else {
                        cout << "Insufficient funds." << endl;
                        break;
                    }
                    break;
                case 3:
                    if (money >= grapeSoda.cost) { 
                            change = money - grapeSoda.cost;
                            cout << setprecision(2) << "Change: $" << change << endl;
                            totalRevenue += grapeSoda.cost;
                        } else {
                        cout << "Insufficient funds." << endl;
                        break;
                    }
                    break;
                case 4:
                    if (money >= lemonLime.cost) { 
                            change = money - lemonLime.cost;
                            cout << setprecision(2) << "Change: $" << change << endl;
                            totalRevenue += lemonLime.cost;
                        } else {
                        cout << "Insufficient funds." << endl;
                        break;
                    }
                    break;
                case 5:
                    if (money >= water.cost) { 
                            change = money - water.cost;
                            cout << setprecision(2) << "Change: $" << change << endl;
                            totalRevenue += water.cost;
                        } else {
                        cout << "Insufficient funds." << endl;
                        break;
                    }
                    break;
                default:
                    cout << "Invalid selection." << endl;
                    break;       
            }
        } 
        
    } while (menu != 6);

    // Display total revenue and the inventory of each drink item
    cout << "Total Revenue:  $" << totalRevenue << endl << endl
         << "Drink " << setw(15) << "Number Left" << endl << endl
         << "Cola" << setw(15) << colaQty.Qty << endl
         << "Root Beer" << setw(10) << rootBeerQty.Qty << endl
         << "Grape Soda" << setw(9) << grapeSodaQty.Qty << endl
         << "Lemon Lime" << setw(9) << lemonLimeQty.Qty << endl
         << "Water" << setw(14) << waterQty.Qty << endl << endl;

    return 0;
}


// Function Definitions

// ----- MENU DISPLAY ----- //

int menuSelection()
{
    int menu;
    while (true) {
        cout << endl << "1) Cola " << setw(10) << "$" << setprecision(2) << fixed << cola.cost << setw(15) << "Qty: " << colaQty.Qty << endl
                     <<  "2) Root Beer " << setw(5) << "$" << setprecision(2) << fixed << rootBeer.cost << setw(15) << "Qty: " << rootBeerQty.Qty << endl
                     << "3) Grape Soda " << setw(4) << "$" << setprecision(2) << fixed << grapeSoda.cost << setw(15) << "Qty: " << grapeSodaQty.Qty << endl
                     << "4) Lemon-Lime " << setw(4) << "$" << setprecision(2) << fixed << lemonLime.cost << setw(15) << "Qty: " << lemonLimeQty.Qty << endl
                     << "5) Water " << setw(9) << "$" << setprecision(2) << fixed << water.cost << setw(15) << "Qty: " << waterQty.Qty << endl << endl

             << "Select a drink (1-5) or enter 6 to quit: ";

        cin >> menu;
        // To prevent infinite loop, if cin fails, clear input, ignore entire line until null
        if (cin.fail()) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // Validate user response 
        if (menu >= 1 && menu <= 6) {
            return menu;
        } else {
            cout << "Invalid response entered. Please try again." << endl << endl;
        }
    }
}


// ----- USER FUNDS ----- // 

float userFunds() 
{
    float funds;
    while(true) {
        cout << "Enter the amount of money you want to insert: ";
        cin >> funds;

        // To prevent infinite loop, if cin fails, clear input, ignore entire line until null
        if (cin.fail()) { 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        
        // Validate user response by limiting inputs to > 0 and < 1
        if (funds < 0 || funds > 1.00) {
            cout << "This machine cannot accept values less than 0 or greater than $1.00." << endl;
        } else {
            return funds;
        }
    }
}