#include "HotelSystem.h"
#include <iostream>
using namespace std;

int main() {
    try {
        HotelSystem hotelSystem;
        hotelSystem.initializeSystem();
        hotelSystem.runSystem();
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}