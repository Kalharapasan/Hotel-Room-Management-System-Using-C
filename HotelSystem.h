#ifndef HOTELSYSTEM_H
#define HOTELSYSTEM_H

#include "HotelOwner.h"
#include "HotelManager.h"
#include "Customer.h"
#include "Room.h"
#include "FileManager.h"
#include <vector>
using namespace std;

class HotelSystem {
private:
    HotelOwner owner;
    HotelManager manager;
    vector<Room> rooms;
    vector<Customer> customers;
    
public:
    HotelSystem();
    ~HotelSystem();
    
    // System initialization
    void initializeSystem();
    void loadData();
    void saveData();
    
    // Main menu and navigation
    void displayMainMenu();
    void runSystem();
    
    // User role menus
    void handleOwnerOperations();
    void handleManagerOperations();
    void handleCustomerOperations();
    
    // Authentication
    bool authenticateUser(int userType);
    
    // Utility functions
    void displayWelcomeMessage();
    void displayGoodbyeMessage();
};

#endif