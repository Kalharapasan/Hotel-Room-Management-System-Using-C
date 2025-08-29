#include "Room.h"
#include <sstream>

Room::Room() : roomNumber(0), category(SINGLE), price(0.0), status(AVAILABLE), customerName("") {}

Room::Room(int number, RoomCategory cat, double pr) 
    : roomNumber(number), category(cat), price(pr), status(AVAILABLE), customerName("") {}

int Room::getRoomNumber() const { return roomNumber; }
RoomCategory Room::getCategory() const { return category; }
double Room::getPrice() const { return price; }
RoomStatus Room::getStatus() const { return status; }
string Room::getCustomerName() const { return customerName; }

string Room::getCategoryString() const {
    switch(category) {
        case SINGLE: return "Single Person";
        case COUPLE: return "Couple";
        case FAMILY: return "Family";
        case MULTIPLE: return "Multiple Persons";
        default: return "Unknown";
    }
}

string Room::getStatusString() const {
    switch(status) {
        case AVAILABLE: return "Available";
        case OCCUPIED: return "Occupied";
        case CLEANING: return "Cleaning";
        default: return "Unknown";
    }
}

void Room::setStatus(RoomStatus st) { status = st; }
void Room::setCustomerName(string name) { customerName = name; }
void Room::setPrice(double pr) { price = pr; }

bool Room::bookRoom(string custName) {
    if (status == AVAILABLE) {
        status = OCCUPIED;
        customerName = custName;
        return true;
    }
    return false;
}

void Room::checkoutRoom() {
    if (status == OCCUPIED) {
        status = CLEANING;
        customerName = "";
    }
}

void Room::cleanRoom() {
    if (status == CLEANING) {
        status = AVAILABLE;
        customerName = "";
    }
}

string Room::toFileString() const {
    return to_string(roomNumber) + "," + 
           to_string(static_cast<int>(category)) + "," + 
           to_string(price) + "," + 
           to_string(static_cast<int>(status)) + "," + 
           customerName;
}

void Room::fromFileString(const string& data) {
    stringstream ss(data);
    string item;
    
    getline(ss, item, ',');
    roomNumber = stoi(item);
    
    getline(ss, item, ',');
    category = static_cast<RoomCategory>(stoi(item));
    
    getline(ss, item, ',');
    price = stod(item);
    
    getline(ss, item, ',');
    status = static_cast<RoomStatus>(stoi(item));
    
    getline(ss, customerName);
}