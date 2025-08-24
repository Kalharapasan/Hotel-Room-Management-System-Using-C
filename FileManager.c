#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::saveRoomsToFile(const vector<Room>& rooms, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << " for writing." << endl;
        return;
    }
    
    for (const Room& room : rooms) {
        file << room.toFileString() << endl;
    }
    
    file.close();
    cout << "Room data saved to " << filename << endl;
}

void FileManager::loadRoomsFromFile(vector<Room>& rooms, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Note: " << filename << " not found. Starting with empty room list." << endl;
        return;
    }
    
    rooms.clear();
    string line;
    
    while (getline(file, line)) {
        if (!line.empty()) {
            Room room;
            room.fromFileString(line);
            rooms.push_back(room);
        }
    }
    
    file.close();
    cout << "Loaded " << rooms.size() << " rooms from " << filename << endl;
}

void FileManager::saveCustomersToFile(const vector<Customer>& customers, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << " for writing." << endl;
        return;
    }
    
    for (const Customer& customer : customers) {
        file << customer.toFileString() << endl;
    }
    
    file.close();
    cout << "Customer data saved to " << filename << endl;
}

void FileManager::loadCustomersFromFile(vector<Customer>& customers, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Note: " << filename << " not found. Starting with empty customer list." << endl;
        return;
    }
    
    customers.clear();
    string line;
    
    while (getline(file, line)) {
        if (!line.empty()) {
            Customer customer;
            customer.fromFileString(line);
            customers.push_back(customer);
        }
    }
    
    file.close();
    cout << "Loaded " << customers.size() << " customers from " << filename << endl;
}

bool FileManager::fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

void FileManager::createBackup(const string& filename) {
    if (!fileExists(filename)) return;
    
    string backupName = filename + ".backup";
    ifstream src(filename);
    ofstream dst(backupName);
    
    dst << src.rdbuf();
    
    src.close();
    dst.close();
    cout << "Backup created: " << backupName << endl;
}