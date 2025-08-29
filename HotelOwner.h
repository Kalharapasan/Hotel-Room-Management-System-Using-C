#ifndef HOTELOWNER_H
#define HOTELOWNER_H

#include "Room.h"
#include <vector>
#include <string>
using namespace std;

class HotelOwner {
private:
    string ownerName;
    string hotelName;
    string adminPassword;
    
public:
    HotelOwner();
    HotelOwner(string owner, string hotel, string password);
    
    // Authentication
    bool authenticateAdmin(string password);
    
    // Room management
    void addRoom(vector<Room>& rooms);
    void setRoomPrices(vector<Room>& rooms);
    void addPackagePricing(vector<Room>& rooms);
    
    // Hotel management
    void addMemberDetails();
    void displayAllAvailability(const vector<Room>& rooms) const;
    void generateReports(const vector<Room>& rooms) const;
    
    // Getters
    string getOwnerName() const;
    string getHotelName() const;
    
    // Menu
    void displayOwnerMenu();
};

#endif