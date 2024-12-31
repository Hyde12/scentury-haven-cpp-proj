#include <iostream>
#include <string>
#include <cstdlib> // For system("cls") on Windows

using namespace std;

int main() {
    string name;
    int age;

    // Welcome message
    cout << "===============================\n";
    cout << "  Welcome to Scentury Haven!   \n";
    cout << "===============================\n\n";

    cout << "We are thrilled to have you here!\n";
    cout << "Before proceeding to the catalog, please enter your details below:\n\n";

    cout << "---------------------------------\n\n";
    cout << "Name: ";
    getline(cin, name);

    cout << "Age: ";
    cin >> age;
    cout << "\n---------------------------------\n";

    if (age <= 0 || age >= 100) {
        cout << "\nOops! Invalid Age. Please try again.\n";
        return 0;
    }

    cout << "\nThank you, " << name << "! You are now ready to explore the catalog.\n";
    cout << "Enjoy your time at Scentury Haven!\n\n";

    double priceToPay = 0;
    double discount = (age >= 60) ? 0.9 : 1.0;
    int page = 0;
    int choice;

    while (true) {
        cout << "**************************************************************************************************************\n\n";
        cout << "Here are our menu items! Type the corresponding number to pick an option.\n\n";
        cout << "---------------------------------\n";
        switch (page) {
            case 0: 
                cout << "Menu:\n";
                cout << "1. Fragrances\n";
                cout << "2. Gift Sets\n";
                cout << "3. Seasonal Offers\n";
                cout << "4. Exit\n";
                cout << "0. Reset Cart\n";
                break;
            case 1:
                cout << "Fragrances Menu:\n";
                cout << "1. Chloé - Eau de Parfum (Rose Elegance) - PHP 2,520\n";
                cout << "2. Tom Ford - Neroli Portofino (Lemon Zest) - PHP 2,240\n";
                cout << "3. Le Labo - Santal 33 (Sandalwood Spirit) - PHP 3,080\n";
                cout << "4. Return to Main menu\n";
                break;
            case 2: 
                cout << "Gift Sets Menu:\n";
                cout << "1. Jo Malone London - Red Roses & Wood Sage & Sea Salt (Eternal Bond Set) - PHP 5,040\n";
                cout << "2. Diptyque - Discovery Set (Family Harmony) - PHP 6,720\n";
                cout << "3. Creed - Aventus (Personalized Fragrance Box) - PHP 5,600\n";
                cout << "4. Return to Main menu\n";
                break;
            case 3:
                cout << "Seasonal Offers Menu:\n";
                cout << "1. Guerlain - Shalimar Souffle de Parfum (Winter Wonderland) - PHP 2,800\n";
                cout << "2. Hermès - Terre d'Hermès Eau Très Fraîche (Summer Bloom) - PHP 2,520\n";
                cout << "3. Tom Ford - Tobacco Vanille (Autumn Aura) - PHP 2,800\n";
                cout << "4. Return to Main menu\n";
                break;
        }
        cout << "---------------------------------\n\n";   

        cout << "Enter your choice: ";
        cin >> choice;

        if (page == 0) {
            if (choice == 4) {
                system("cls"); 
                if (priceToPay > 0) {
                    cout << "\nThank you for visiting Scentury Haven, " << name << "!\n";
                    cout << "Your total price is: PHP " << priceToPay << "\n";
                    cout << "We hope to see you again soon.\n";
                } else {
                    cout << "\nThank you for visiting Scentury Haven, " << name << "!\n";
                    cout << "No items were added to your cart. We hope to see you again soon.\n";
                }
                break;  // Exit the program
            }

            if (choice == 0) { 
                cout << "Your cart has been reset!\n\n"; 
                priceToPay = 0;
                continue;
            }

            if (choice > 0 && choice < 4) { 
                page = choice; 
                cout << "\n";
            } else { cout << "Invalid choice. Try again.\n\n"; }
        } else {
            switch (page) {
                case 1:
                    switch (choice) {
                        case 1:
                            priceToPay += 2520 * discount;
                            break;
                        case 2:
                            priceToPay += 2240 * discount;
                            break;
                        case 3:
                            priceToPay += 3080 * discount;
                            break;
                        case 4:
                            page = 0;
                            break;
                    }
                    break;
                case 2:
                    switch (choice) {
                        case 1:
                            priceToPay += 5040 * discount;
                            break;
                        case 2:
                            priceToPay += 6720 * discount;
                            break;
                        case 3:
                            priceToPay += 5600 * discount;
                            break;
                        case 4:
                            page = 0;
                            break;
                    }
                    break;
                case 3:
                    switch (choice) {
                        case 1:
                            priceToPay += 2800 * discount;
                            break;
                        case 2:
                            priceToPay += 2520 * discount;
                            break;
                        case 3:
                            priceToPay += 2800 * discount;
                            break;
                        case 4:
                            page = 0;
                            break;
                    }
                    break;
            }
            cout << "Added to cart! Your cart now adds up to: PHP  " << priceToPay << "!\n\n";
            if (discount != 1) { cout << "--- Applied discount of 10% ---\n\n"; }
        }
    }
    return 0;
}
