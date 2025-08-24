# Hotel Room Management System

A comprehensive hotel management system built in C++ with object-oriented design principles. The system manages hotel operations including room management, customer registration, and staff operations.

## Features

### 🏨 Hotel Owner Features
- **Admin Authentication**: Secure login system for hotel owners
- **Room Management**: Add new rooms with different categories and pricing
- **Price Management**: Set and update room prices dynamically
- **Package Pricing**: Configure pricing for different customer types (Single, Couple, Family, Multiple)
- **Staff Management**: Add and manage staff member details
- **Reports & Analytics**: Generate occupancy reports and revenue analytics
- **Full System Access**: Complete visibility of all hotel operations

### 👔 Hotel Manager Features
- **Room Operations**: Check available rooms and manage bookings
- **Customer Booking**: Book rooms for customers and handle check-ins
- **Checkout Process**: Process customer checkouts and prepare rooms for cleaning
- **Room Maintenance**: Mark rooms for cleaning and update status when cleaned
- **Customer Management**: Register new customers and maintain customer records
- **Real-time Status**: View occupied rooms and customer details

### 🏠 Hotel Customer Features
- **Registration**: Complete customer registration with personal details
- **Feedback System**: Provide feedback and reviews about hotel services
- **Profile Management**: View and manage personal information
- **Booking History**: Access to booking and stay history

## System Architecture

### Core Classes

1. **Room Class** (`Room.h/cpp`)
   - Manages individual room properties and status
   - Handles room categories: Single, Couple, Family, Multiple
   - Tracks room status: Available, Occupied, Cleaning
   - Manages pricing and customer assignment

2. **Customer Class** (`Customer.h/cpp`)
   - Stores customer personal information
   - Manages booking details and stay history
   - Handles customer feedback and reviews

3. **HotelOwner Class** (`HotelOwner.h/cpp`)
   - Administrative functions and system configuration
   - Room and pricing management
   - Staff management and reporting
   - System analytics and reports

4. **HotelManager Class** (`HotelManager.h/cpp`)
   - Day-to-day operations management
   - Customer service and booking operations
   - Room maintenance and housekeeping coordination

5. **FileManager Class** (`FileManager.h/cpp`)
   - Handles data persistence to text files
   - Manages backup and recovery operations
   - File I/O operations for rooms and customers

6. **HotelSystem Class** (`HotelSystem.h/cpp`)
   - Main system controller and user interface
   - Authentication and menu management
   - Coordinates all system operations

## Data Storage

The system uses text files for data persistence:
- `rooms.txt`: Stores all room information and current status
- `customers.txt`: Stores customer details and booking history
- Automatic backup creation for data safety

## Room Categories & Pricing

- **Single Person**: Individual accommodation
- **Couple**: Double occupancy rooms
- **Family**: Family-sized accommodations
- **Multiple Persons**: Group accommodation options

## Building and Running

### Prerequisites
- C++ compiler (g++ recommended)
- C++17 support
- Make utility (optional)

### Build Instructions

#### Using Make:
```bash
# Build the system
make

# Run the system
make run

# Clean build files
make clean

# Debug build
make debug
```

#### Manual Compilation:
```bash
g++ -std=c++17 -Wall -Wextra -O2 -o hotel_system main.cpp Room.cpp Customer.cpp HotelOwner.cpp HotelManager.cpp FileManager.cpp HotelSystem.cpp
```

#### Run the Program:
```bash
./hotel_system
```

## Usage Guide

### Getting Started
1. Run the program
2. Choose your user type from the main menu
3. Authenticate (Owner password: "admin123")
4. Navigate through the respective menus

### Default Login Credentials
- **Hotel Owner Password**: `admin123`
- **Manager ID**: Any ID (simplified authentication)

### Sample Workflow
1. **Owner**: Add rooms with categories and set prices
2. **Manager**: Register customers and book available rooms
3. **Manager**: Process checkouts and manage room cleaning
4. **Customer**: Register and provide feedback
5. **Owner**: Generate reports and analyze performance

## File Structure

```
hotel-management-system/
├── main.cpp                 # Main entry point
├── Room.h/.cpp             # Room management
├── Customer.h/.cpp         # Customer operations
├── HotelOwner.h/.cpp       # Owner functionality
├── HotelManager.h/.cpp     # Manager operations
├── FileManager.h/.cpp      # File I/O operations
├── HotelSystem.h/.cpp      # Main system controller
├── Makefile                # Build configuration
├── README.md               # This file
├── rooms.txt              # Room data (created at runtime)
└── customers.txt          # Customer data (created at runtime)
```

## Features Highlights

### 🔐 Security
- Password-protected owner access
- Role-based authentication system
- Data backup and recovery

### 📊 Analytics
- Occupancy rate calculation
- Revenue tracking
- Room status monitoring
- Customer feedback analysis

### 💾 Data Management
- Automatic data saving
- Text file storage system
- Backup creation
- Data validation and error handling

### 🎯 User Experience
- Clear menu-driven interface
- Comprehensive error handling
- Real-time status updates
- Detailed information display

## System Requirements

- **Operating System**: Cross-platform (Windows, Linux, macOS)
- **Compiler**: C++17 compatible compiler
- **Memory**: Minimal requirements
- **Storage**: Small footprint for data files

## Future Enhancements

- Database integration (SQLite/MySQL)
- Web-based interface
- Payment processing integration
- Advanced reporting and analytics
- Email notification system
- Multi-language support

## Contributing

Feel free to contribute to this project by:
1. Reporting bugs
2. Suggesting new features
3. Improving documentation
4. Submitting pull requests

## License

This project is created for educational purposes. Feel free to use and modify as needed.

## Support

For questions or support, please refer to the code comments and documentation within the source files.