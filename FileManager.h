#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Room.h"
#include "Customer.h"
#include <vector>
#include <string>
using namespace std;

class FileManager {
public:
    // Room file operations
    static void saveRoomsToFile(const vector<Room>& rooms, const string& filename = "rooms.txt");
    static void loadRoomsFromFile(vector<Room>& rooms, const string& filename = "rooms.txt");
    
    // Customer file operations
    static void saveCustomersToFile(const vector<Customer>& customers, const string& filename = "customers.txt");
    static void loadCustomersFromFile(vector<Customer>& customers, const string& filename = "customers.txt");
    
    // Utility functions
    static bool fileExists(const string& filename);
    static void createBackup(const string& filename);
};

#endif