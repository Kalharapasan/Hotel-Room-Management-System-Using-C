#include "Customer.h"
#include <iostream>
#include <sstream>

Customer::Customer() : roomNumber(0), totalBill(0.0) {}

Customer::Customer(string n, string phone, string em, string addr) 
    : name(n), phoneNumber(phone), email(em), address(addr), roomNumber(0), totalBill(0.0) {}

string Customer::getName() const { return name; }
string Customer::getPhoneNumber() const { return phoneNumber; }
string Customer::getEmail() const { return email; }
string Customer::getAddress() const { return address; }
int Customer::getRoomNumber() const { return roomNumber; }
string Customer::getCheckInDate() const { return checkInDate; }
string Customer::getCheckOutDate() const { return checkOutDate; }
double Customer::getTotalBill() const { return totalBill; }
string Customer::getFeedback() const { return feedback; }

void Customer::setRoomNumber(int room) { roomNumber = room; }
void Customer::setCheckInDate(string date) { checkInDate = date; }
void Customer::setCheckOutDate(string date) { checkOutDate = date; }
void Customer::setTotalBill(double bill) { totalBill = bill; }
void Customer::setFeedback(string fb) { feedback = fb; }

void Customer::registerCustomer() {
    cout << "\n=== Customer Registration ===" << endl;
    cout << "Enter Name: ";
    getline(cin, name);
    
    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);
    
    cout << "Enter Email: ";
    getline(cin, email);
    
    cout << "Enter Address: ";
    getline(cin, address);
    
    cout << "Customer registered successfully!" << endl;
}

void Customer::giveFeedback(string fb) {
    feedback = fb;
    cout << "Thank you for your feedback!" << endl;
}

void Customer::displayCustomerInfo() const {
    cout << "\n=== Customer Information ===" << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phoneNumber << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
    cout << "Room Number: " << roomNumber << endl;
    cout << "Check-in Date: " << checkInDate << endl;
    cout << "Check-out Date: " << checkOutDate << endl;
    cout << "Total Bill: $" << totalBill << endl;
    if (!feedback.empty()) {
        cout << "Feedback: " << feedback << endl;
    }
}

string Customer::toFileString() const {
    return name + "," + phoneNumber + "," + email + "," + address + "," +
           to_string(roomNumber) + "," + checkInDate + "," + checkOutDate + "," +
           to_string(totalBill) + "," + feedback;
}

void Customer::fromFileString(const string& data) {
    stringstream ss(data);
    string item;
    
    getline(ss, name, ',');
    getline(ss, phoneNumber, ',');
    getline(ss, email, ',');
    getline(ss, address, ',');
    
    getline(ss, item, ',');
    roomNumber = stoi(item);
    
    getline(ss, checkInDate, ',');
    getline(ss, checkOutDate, ',');
    
    getline(ss, item, ',');
    totalBill = stod(item);
    
    getline(ss, feedback);
}