#include <iostream>
#include <iomanip>


using namespace std;


// Declare and initialize variables


// Arrays


// Structures
struct Drinks {
    string name;
    float cost;
    int inventory;
};


// Function prototypes


int main() {

    
/* ------------ DRINKS DATA --------------*/

    Drinks cola = {"Cola", 0.65, 20};
    Drinks rootBeer = {"Root Beer", 0.70, 20};
    Drinks grapeSoda = {"Grape Soda", 0.75, 20};
    Drinks lemonLime = {"Lemon Lime", 0.85, 20};
    Drinks water = {"Water", 0.90, 20};
    

// DEBUG
    cout << "DEBUG : The cost of " << cola.name << " is $" << cola.cost << " and there are " << cola.inventory << " left to purchase." << endl;

    cout << "DEBUG : The cost of " << rootBeer.name << " is $" << rootBeer.cost << " and there are " << rootBeer.inventory << " left to purchase." << endl;

    cout << "DEBUG : The cost of " << grapeSoda.name << " is $" << grapeSoda.cost << " and there are " << grapeSoda.inventory << " left to purchase." << endl;

    cout << "DEBUG : The cost of " << lemonLime.name << " is $" << lemonLime.cost << " and there are " << lemonLime.inventory << " left to purchase." << endl;

    cout << "DEBUG : The cost of " << water.name << " is $" << water.cost << " and there are " << water.inventory << " left to purchase." << endl;


    return 0;
}