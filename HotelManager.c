#include "HotelManager.h"
#include <iostream>
#include <iomanip>

HotelManager::HotelManager() {}

HotelManager::HotelManager(string name, string id) : managerName(name), managerId(id) {}

void HotelManager::checkAvailableRooms(const vector<Room>& rooms) const {
    cout << "\n=== Available Rooms ===" << endl;
    cout << setw(10) << "Room No" << setw(15) << "Category" 
         << setw(10) << "Price" << setw(12) << "Status" << endl;
    cout << string(50, '-') << endl;
    
    bool foundAvailable = false;
    for (const Room& room : rooms) {
        if (room.getStatus() == AVAILABLE) {
            cout << setw(10) << room.getRoomNumber()
                 << setw(15) << room.getCategoryString()
                 << setw(10) << "$" << room.getPrice()
                 << setw(12) << room.getStatusString() << endl;
            foundAvailable = true;
        }
    }
    
    if (!foundAvailable) {
        cout << "No rooms available at the moment." << endl;
    }
}

bool HotelManager::bookRoomForCustomer(vector<Room>& rooms, vector<Customer>& customers) {
    int roomNum;
    string customerName;
    
    cout << "\n=== Book Room for Customer ===" << endl;
    checkAvailableRooms(rooms);
    
    cout << "\nEnter Room Number to book: ";
    cin >> roomNum;
    
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);
    
    for (Room& room : rooms) {
        if (room.getRoomNumber() == roomNum && room.getStatus() == AVAILABLE) {
            if (room.bookRoom(customerName)) {
                // Update customer record
                for (Customer& customer : customers) {
                    if (customer.getName() == customerName) {
                        customer.setRoomNumber(roomNum);
                        customer.setCheckInDate("Today"); // In real app, use actual date
                        customer.setTotalBill(room.getPrice());
                        break;
                    }
                }
                
                cout << "Room " << roomNum << " booked successfully for " << customerName << endl;
                return true;
            }
        }
    }
    
    cout << "Room booking failed. Room may not be available." << endl;
    return false;
}

void HotelManager::checkoutCustomer(vector<Room>& rooms, vector<Customer>& customers) {
    int roomNum;
    
    cout << "\n=== Customer Checkout ===" << endl;
    displayOccupiedRooms(rooms);
    
    cout << "\nEnter Room Number for checkout: ";
    cin >> roomNum;
    
    for (Room& room : rooms) {
        if (room.getRoomNumber() == roomNum && room.getStatus() == OCCUPIED) {
            string customerName = room.getCustomerName();
            room.checkoutRoom();
            
            // Update customer record
            for (Customer& customer : customers) {
                if (customer.getName() == customerName && customer.getRoomNumber() == roomNum) {
                    customer.setCheckOutDate("Today"); // In real app, use actual date
                    break;
                }
            }
            
            cout << "Customer " << customerName << " checked out from room " << roomNum << endl;
            cout << "Room marked for cleaning." << endl;
            return;
        }
    }
    
    cout << "Room not found or not occupied." << endl;
}

void HotelManager::markRoomForCleaning(vector<Room>& rooms) {
    int roomNum;
    
    cout << "\n=== Mark Room for Cleaning ===" << endl;
    cout << "Enter Room Number: ";
    cin >> roomNum;
    
    for (Room& room : rooms) {
        if (room.getRoomNumber() == roomNum) {
            room.setStatus(CLEANING);
            cout << "Room " << roomNum << " marked for cleaning." << endl;
            return;
        }
    }
    
    cout << "Room not found." << endl;
}

void HotelManager::markRoomCleaned(vector<Room>& rooms) {
    int roomNum;
    
    cout << "\n=== Mark Room as Cleaned ===" << endl;
    cout << "Rooms in cleaning status:" << endl;
    
    bool foundCleaning = false;
    for (const Room& room : rooms) {
        if (room.getStatus() == CLEANING) {
            cout << "Room " << room.getRoomNumber() << " - " << room.getCategoryString() << endl;
            foundCleaning = true;
        }
    }
    
    if (!foundCleaning) {
        cout << "No rooms are currently being cleaned." << endl;
        return;
    }
    
    cout << "\nEnter Room Number that has been cleaned: ";
    cin >> roomNum;
    
    for (Room& room : rooms) {
        if (room.getRoomNumber() == roomNum && room.getStatus() == CLEANING) {
            room.cleanRoom();
            cout << "Room " << roomNum << " is now available for booking." << endl;
            return;
        }
    }
    
    cout << "Room not found or not in cleaning status." << endl;
}

void HotelManager::registerNewCustomer(vector<Customer>& customers) {
    Customer newCustomer;
    newCustomer.registerCustomer();
    customers.push_back(newCustomer);
}

void HotelManager::displayCustomerDetails(const vector<Customer>& customers) const {
    if (customers.empty()) {
        cout << "\nNo customers registered." << endl;
        return;
    }
    
    cout << "\n=== All Customers ===" << endl;
    for (const Customer& customer : customers) {
        customer.displayCustomerInfo();
        cout << string(50, '-') << endl;
    }
}

void HotelManager::updateCustomerDetails(vector<Customer>& customers) {
    string customerName;
    
    cout << "\n=== Update Customer Details ===" << endl;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);
    
    for (Customer& customer : customers) {
        if (customer.getName() == customerName) {
            cout << "Customer found. Current details:" << endl;
            customer.displayCustomerInfo();
            
            // In a complete implementation, allow updating specific fields
            cout << "Customer details display completed." << endl;
            return;
        }
    }
    
    cout << "Customer not found." << endl;
}

void HotelManager::displayRoomsByCategory(const vector<Room>& rooms, RoomCategory category) const {
    cout << "\n=== Rooms by Category ===" << endl;
    bool found = false;
    
    for (const Room& room : rooms) {
        if (room.getCategory() == category) {
            cout << "Room " << room.getRoomNumber() 
                 << " - $" << room.getPrice() 
                 << " - " << room.getStatusString() << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "No rooms found in this category." << endl;
    }
}

void HotelManager::displayOccupiedRooms(const vector<Room>& rooms) const {
    cout << "\n=== Occupied Rooms ===" << endl;
    cout << setw(10) << "Room No" << setw(15) << "Category" 
         << setw(15) << "Customer" << setw(10) << "Price" << endl;
    cout << string(60, '-') << endl;
    
    bool foundOccupied = false;
    for (const Room& room : rooms) {
        if (room.getStatus() == OCCUPIED) {
            cout << setw(10) << room.getRoomNumber()
                 << setw(15) << room.getCategoryString()
                 << setw(15) << room.getCustomerName()
                 << setw(10) << "$" << room.getPrice() << endl;
            foundOccupied = true;
        }
    }
    
    if (!foundOccupied) {
        cout << "No rooms are currently occupied." << endl;
    }
}

string HotelManager::getManagerName() const { return managerName; }
string HotelManager::getManagerId() const { return managerId; }

void HotelManager::displayManagerMenu() {
    cout << "\n=== Hotel Manager Menu ===" << endl;
    cout << "1. Check Available Rooms" << endl;
    cout << "2. Book Room for Customer" << endl;
    cout << "3. Customer Checkout" << endl;
    cout << "4. Mark Room for Cleaning" << endl;
    cout << "5. Mark Room as Cleaned" << endl;
    cout << "6. Register New Customer" << endl;
    cout << "7. Display Customer Details" << endl;
    cout << "8. Display Occupied Rooms" << endl;
    cout << "9. Back to Main Menu" << endl;
    cout << "Enter choice: ";
}