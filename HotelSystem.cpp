#include "HotelSystem.h"
#include <iostream>
#include <limits>
using namespace std;

HotelSystem::HotelSystem() : owner("Default Owner", "Grand Hotel", "admin123"), 
                             manager("Default Manager", "MGR001") {}

HotelSystem::~HotelSystem() {
    saveData();
}

void HotelSystem::initializeSystem() {
    displayWelcomeMessage();
    loadData();
}

void HotelSystem::loadData() {
    cout << "\nLoading hotel data..." << endl;
    FileManager::loadRoomsFromFile(rooms);
    FileManager::loadCustomersFromFile(customers);
    cout << "Data loading completed." << endl;
}

void HotelSystem::saveData() {
    cout << "\nSaving hotel data..." << endl;
    FileManager::saveRoomsToFile(rooms);
    FileManager::saveCustomersToFile(customers);
    cout << "Data saving completed." << endl;
}

void HotelSystem::displayMainMenu() {
    cout << "\n" << string(50, '=') << endl;
    cout << "       HOTEL MANAGEMENT SYSTEM" << endl;
    cout << string(50, '=') << endl;
    cout << "1. Hotel Owner Login" << endl;
    cout << "2. Hotel Manager Login" << endl;
    cout << "3. Customer Registration/Operations" << endl;
    cout << "4. Save Data" << endl;
    cout << "5. Exit System" << endl;
    cout << string(50, '=') << endl;
    cout << "Enter your choice: ";
}

void HotelSystem::runSystem() {
    int choice;
    
    while (true) {
        displayMainMenu();
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                if (authenticateUser(1)) {
                    handleOwnerOperations();
                }
                break;
            case 2:
                if (authenticateUser(2)) {
                    handleManagerOperations();
                }
                break;
            case 3:
                handleCustomerOperations();
                break;
            case 4:
                saveData();
                break;
            case 5:
                displayGoodbyeMessage();
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void HotelSystem::handleOwnerOperations() {
    int choice;
    
    while (true) {
        owner.displayOwnerMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                owner.addRoom(rooms);
                break;
            case 2:
                owner.setRoomPrices(rooms);
                break;
            case 3:
                owner.addPackagePricing(rooms);
                break;
            case 4:
                owner.addMemberDetails();
                break;
            case 5:
                owner.displayAllAvailability(rooms);
                break;
            case 6:
                owner.generateReports(rooms);
                break;
            case 7:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void HotelSystem::handleManagerOperations() {
    int choice;
    
    while (true) {
        manager.displayManagerMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                manager.checkAvailableRooms(rooms);
                break;
            case 2:
                manager.bookRoomForCustomer(rooms, customers);
                break;
            case 3:
                manager.checkoutCustomer(rooms, customers);
                break;
            case 4:
                manager.markRoomForCleaning(rooms);
                break;
            case 5:
                manager.markRoomCleaned(rooms);
                break;
            case 6:
                manager.registerNewCustomer(customers);
                break;
            case 7:
                manager.displayCustomerDetails(customers);
                break;
            case 8:
                manager.displayOccupiedRooms(rooms);
                break;
            case 9:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void HotelSystem::handleCustomerOperations() {
    int choice;
    string customerName, feedback;
    
    cout << "\n=== Customer Operations ===" << endl;
    cout << "1. Register as New Customer" << endl;
    cout << "2. Give Feedback" << endl;
    cout << "3. View My Details" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1: {
            Customer newCustomer;
            newCustomer.registerCustomer();
            customers.push_back(newCustomer);
            break;
        }
        case 2:
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, customerName);
            
            for (Customer& customer : customers) {
                if (customer.getName() == customerName) {
                    cout << "Enter your feedback: ";
                    getline(cin, feedback);
                    customer.giveFeedback(feedback);
                    return;
                }
            }
            cout << "Customer not found." << endl;
            break;
        case 3:
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, customerName);
            
            for (const Customer& customer : customers) {
                if (customer.getName() == customerName) {
                    customer.displayCustomerInfo();
                    return;
                }
            }
            cout << "Customer not found." << endl;
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice." << endl;
    }
}

bool HotelSystem::authenticateUser(int userType) {
    string password;
    
    if (userType == 1) {  // Owner
        cout << "\nEnter Owner Password: ";
        cin >> password;
        if (owner.authenticateAdmin(password)) {
            cout << "Owner authentication successful!" << endl;
            return true;
        } else {
            cout << "Authentication failed!" << endl;
            return false;
        }
    } else if (userType == 2) {  // Manager
        string managerId;
        cout << "\nEnter Manager ID: ";
        cin >> managerId;
        cout << "Manager authentication successful!" << endl;  // Simplified authentication
        return true;
    }
    
    return false;
}

void HotelSystem::displayWelcomeMessage() {
    cout << "\n" << string(60, '*') << endl;
    cout << "*" << string(58, ' ') << "*" << endl;
    cout << "*" << string(15, ' ') << "WELCOME TO GRAND HOTEL" << string(21, ' ') << "*" << endl;
    cout << "*" << string(10, ' ') << "Hotel Room Management System" << string(20, ' ') << "*" << endl;
    cout << "*" << string(58, ' ') << "*" << endl;
    cout << string(60, '*') << endl;
}

void HotelSystem::displayGoodbyeMessage() {
    saveData();
    cout << "\n" << string(50, '=') << endl;
    cout << "Thank you for using Hotel Management System!" << endl;
    cout << "Data has been saved successfully." << endl;
    cout << "Have a great day!" << endl;
    cout << string(50, '=') << endl;
}