#ifndef HOTELMANAGER_H
#define HOTELMANAGER_H

#include "Room.h"
#include "Customer.h"
#include <vector>
#include <string>
using namespace std;

class HotelManager {
private:
    string managerName;
    string managerId;
    
public:
    HotelManager();
    HotelManager(string name, string id);
    
    // Room management
    void checkAvailableRooms(const vector<Room>& rooms) const;
    bool bookRoomForCustomer(vector<Room>& rooms, vector<Customer>& customers);
    void checkoutCustomer(vector<Room>& rooms, vector<Customer>& customers);
    void markRoomForCleaning(vector<Room>& rooms);
    void markRoomCleaned(vector<Room>& rooms);
    
    // Customer management
    void registerNewCustomer(vector<Customer>& customers);
    void displayCustomerDetails(const vector<Customer>& customers) const;
    void updateCustomerDetails(vector<Customer>& customers);
    
    // Utility functions
    void displayRoomsByCategory(const vector<Room>& rooms, RoomCategory category) const;
    void displayOccupiedRooms(const vector<Room>& rooms) const;
    
    // Getters
    string getManagerName() const;
    string getManagerId() const;
    
    // Menu
    void displayManagerMenu();
};

#endif