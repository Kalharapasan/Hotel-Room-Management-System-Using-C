#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;

enum RoomCategory {
    SINGLE = 1,
    COUPLE = 2,
    FAMILY = 3,
    MULTIPLE = 4
};

enum RoomStatus {
    AVAILABLE = 1,
    OCCUPIED = 2,
    CLEANING = 3
};

class Room {
private:
    int roomNumber;
    RoomCategory category;
    double price;
    RoomStatus status;
    string customerName;
    
public:
    Room();
    Room(int number, RoomCategory cat, double pr);
    
    // Getters
    int getRoomNumber() const;
    RoomCategory getCategory() const;
    double getPrice() const;
    RoomStatus getStatus() const;
    string getCustomerName() const;
    string getCategoryString() const;
    string getStatusString() const;
    
    // Setters
    void setStatus(RoomStatus st);
    void setCustomerName(string name);
    void setPrice(double pr);
    
    // Room operations
    bool bookRoom(string customerName);
    void checkoutRoom();
    void cleanRoom();
    
    // File operations
    string toFileString() const;
    void fromFileString(const string& data);
};

#endif