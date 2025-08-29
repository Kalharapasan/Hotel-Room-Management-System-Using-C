#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    string name;
    string phoneNumber;
    string email;
    string address;
    int roomNumber;
    string checkInDate;
    string checkOutDate;
    double totalBill;
    string feedback;
    
public:
    Customer();
    Customer(string n, string phone, string em, string addr);
    
    // Getters
    string getName() const;
    string getPhoneNumber() const;
    string getEmail() const;
    string getAddress() const;
    int getRoomNumber() const;
    string getCheckInDate() const;
    string getCheckOutDate() const;
    double getTotalBill() const;
    string getFeedback() const;
    
    // Setters
    void setRoomNumber(int room);
    void setCheckInDate(string date);
    void setCheckOutDate(string date);
    void setTotalBill(double bill);
    void setFeedback(string fb);
    
    // Customer operations
    void registerCustomer();
    void giveFeedback(string feedback);
    void displayCustomerInfo() const;
    
    // File operations
    string toFileString() const;
    void fromFileString(const string& data);
};

#endif