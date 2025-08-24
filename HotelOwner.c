#include "HotelOwner.h"
#include <iostream>
#include <iomanip>

HotelOwner::HotelOwner() : adminPassword("admin123") {}

HotelOwner::HotelOwner(string owner, string hotel, string password) 
    : ownerName(owner), hotelName(hotel), adminPassword(password) {}

bool HotelOwner::authenticateAdmin(string password) {
    return password == adminPassword;
}

void HotelOwner::addRoom(vector<Room>& rooms) {
    int roomNum, categoryChoice;
    double price;
    
    cout << "\n=== Add New Room ===" << endl;
    cout << "Enter Room Number: ";
    cin >> roomNum;
    
    // Check if room already exists
    for (const Room& room : rooms) {
        if (room.getRoomNumber() == roomNum) {
            cout << "Room " << roomNum << " already exists!" << endl;
            return;
        }
    }
    
    cout << "\nSelect Room Category:" << endl;
    cout << "1. Single Person" << endl;
    cout << "2. Couple" << endl;
    cout << "3. Family" << endl;
    cout << "4. Multiple Persons" << endl;
    cout << "Enter choice: ";
    cin >> categoryChoice;
    
    cout << "Enter Room Price: $";
    cin >> price;
    
    RoomCategory category = static_cast<RoomCategory>(categoryChoice);
    Room newRoom(roomNum, category, price);
    rooms.push_back(newRoom);
    
    cout << "Room " << roomNum << " added successfully!" << endl;
}

void HotelOwner::setRoomPrices(vector<Room>& rooms) {
    int roomNum;
    double newPrice;
    
    cout << "\n=== Set Room Price ===" << endl;
    cout << "Enter Room Number: ";
    cin >> roomNum;
    
    for (Room& room : rooms) {
        if (room.getRoomNumber() == roomNum) {
            cout << "Current Price: $" << room.getPrice() << endl;
            cout << "Enter New Price: $";
            cin >> newPrice;
            room.setPrice(newPrice);
            cout << "Price updated successfully!" << endl;
            return;
        }
    }
    cout << "Room not found!" << endl;
}

void HotelOwner::addPackagePricing(vector<Room>& rooms) {
    cout << "\n=== Package Pricing Setup ===" << endl;
    cout << "Current Room Categories and Pricing:" << endl;
    
    for (const Room& room : rooms) {
        cout << "Room " << room.getRoomNumber() 
             << " - " << room.getCategoryString() 
             << " - $" << room.getPrice() << endl;
    }
    
    cout << "\nPackage pricing can be set by modifying individual room prices." << endl;
}

void HotelOwner::addMemberDetails() {
    string memberName, position, contact;
    
    cout << "\n=== Add Staff Member ===" << endl;
    cout << "Enter Member Name: ";
    cin.ignore();
    getline(cin, memberName);
    
    cout << "Enter Position: ";
    getline(cin, position);
    
    cout << "Enter Contact: ";
    getline(cin, contact);
    
    cout << "Staff member " << memberName << " added successfully!" << endl;
}

void HotelOwner::displayAllAvailability(const vector<Room>& rooms) const {
    cout << "\n=== Hotel Room Availability Report ===" << endl;
    cout << setw(10) << "Room No" << setw(15) << "Category" 
         << setw(10) << "Price" << setw(12) << "Status" 
         << setw(15) << "Customer" << endl;
    cout << string(70, '-') << endl;
    
    for (const Room& room : rooms) {
        cout << setw(10) << room.getRoomNumber()
             << setw(15) << room.getCategoryString()
             << setw(10) << "$" << room.getPrice()
             << setw(12) << room.getStatusString()
             << setw(15) << room.getCustomerName() << endl;
    }
}

void HotelOwner::generateReports(const vector<Room>& rooms) const {
    int totalRooms = rooms.size();
    int availableRooms = 0, occupiedRooms = 0, cleaningRooms = 0;
    double totalRevenue = 0.0;
    
    for (const Room& room : rooms) {
        switch (room.getStatus()) {
            case AVAILABLE: availableRooms++; break;
            case OCCUPIED: 
                occupiedRooms++; 
                totalRevenue += room.getPrice();
                break;
            case CLEANING: cleaningRooms++; break;
        }
    }
    
    cout << "\n=== Hotel Management Report ===" << endl;
    cout << "Total Rooms: " << totalRooms << endl;
    cout << "Available Rooms: " << availableRooms << endl;
    cout << "Occupied Rooms: " << occupiedRooms << endl;
    cout << "Cleaning Rooms: " << cleaningRooms << endl;
    cout << "Occupancy Rate: " << fixed << setprecision(2) 
         << (double)occupiedRooms / totalRooms * 100 << "%" << endl;
    cout << "Current Revenue: $" << totalRevenue << endl;
}

string HotelOwner::getOwnerName() const { return ownerName; }
string HotelOwner::getHotelName() const { return hotelName; }

void HotelOwner::displayOwnerMenu() {
    cout << "\n=== Hotel Owner Menu ===" << endl;
    cout << "1. Add Room" << endl;
    cout << "2. Set Room Prices" << endl;
    cout << "3. Package Pricing" << endl;
    cout << "4. Add Staff Member" << endl;
    cout << "5. View Availability Report" << endl;
    cout << "6. Generate Reports" << endl;
    cout << "7. Back to Main Menu" << endl;
    cout << "Enter choice: ";
}