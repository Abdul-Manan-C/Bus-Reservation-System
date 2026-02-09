#include<iostream>
#include<fstream>
#include<string>
using namespace std;  

void addBus();
void reserveSeat();
void viewReservations();
void viewBuses();   

int main() {
    int choice = -1;

    while (choice != 99) {
        cout << "\n[ 0: Show Menu | 99: Exit ] -> Enter Choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\n===== BUS RESERVATION SYSTEM =====";
            cout << "\n1. Add Bus Information";
            cout << "\n2. Reserve Seat(s)";
            cout << "\n3. Show Reservation Report";
            cout << "\n4. Show Available Buses";
            cout << "\n99. Exit Program";
            cout << "\n====================================";
            cout << "\nEnter Option: ";
            cin >> choice;
        }

        switch(choice) {
            case 1: addBus(); break;
            case 2: reserveSeat(); break;
            case 3: viewReservations(); break;
            case 4: viewBuses(); break;
            case 99: cout << "Exiting...\n"; break;
            default: if(choice != 0) cout << "Invalid Input!\n";
        }
    }
    return 0;
}

void addBus() {
    ofstream busFile("bus_data.txt", ios::app);
    string plate, type, chasis;
    int seats;

    cout << "\n-----ADD BUS-----\n";
    cin.ignore(); 
    cout << "Enter Bus Plate Number: ";
    getline(cin, plate);

    cout << "Enter Bus Chasis Number: ";
    getline(cin, chasis);

    do {
        cout << "Enter Bus Type (mini/big): ";
        cin >> type;
    } while(type != "mini" && type != "big"); 

    seats = (type == "mini") ? 30 : 50;

    // Format: Plate | Chasis | Type | Seats
    busFile << plate << "|" << chasis << "|" << type << "|" << seats << endl;
    busFile.close();

    cout << "Bus added successfully.\n";
}

void reserveSeat() {
    viewBuses();

    string plate, passenger, bPlate, bChassis, bType, goBack;
    int seatNum, requestedSeats, totalSeats = 0, reservedCount = 0;
    bool busFound = false;

    cout << "\n--- Starting Reservation ---" << endl;
    cin.ignore();
    cout << "Refer to the list above and enter Bus Plate Number: ";
    getline(cin, plate);

    ifstream busFile("bus_data.txt");
    string line;
    while (getline(busFile, bPlate, '|')) {
        getline(busFile, bChassis, '|');
        getline(busFile, bType, '|');
        busFile >> totalSeats;
        busFile.ignore(); 
        
        if (bPlate == plate) {
            busFound = true;
            break;
        }
    }
    busFile.close();

    if (!busFound) {
        cout << "Error: Bus not found! Please check the plate number." << endl;
        return;
    }

    ifstream checkSeats("seat.txt");
    string sPlate, sName;
    int sNum;
    while (checkSeats >> sPlate >> sNum) {
        getline(checkSeats, sName);
        if (sPlate == plate) reservedCount++;
    }
    checkSeats.close();

    int seatsLeft = totalSeats - reservedCount;
    cout << "Seats Left in this bus: " << seatsLeft << endl;

    cout << "Do you want to see which specific seats are left? (Y/N): ";
    char showSeats;
    cin >> showSeats;

    if (showSeats == 'Y' || showSeats == 'y') {
        cout << "Available Seat Numbers: ";
        bool first = true;
        for (int i = 1; i <= totalSeats; i++) {
            bool taken = false;
            ifstream verify("seat.txt");
            while (verify >> sPlate >> sNum) {
                getline(verify, sName);
                if (sPlate == plate && sNum == i) {
                    taken = true;
                    break;
                }
            }
            verify.close();
            if (!taken) {
                if (!first) cout << ", ";
                cout << i;
                first = false;
            }
        }
        cout << endl;
    }

    cout << "\nHow many seats do you want to reserve? ";
    cin >> requestedSeats;

    if (requestedSeats > seatsLeft) {
        cout << "Error: Only " << seatsLeft << " seats available!" << endl;
        return;
    }

    for (int i = 0; i < requestedSeats; i++) {
        retrySeat:
        cout << "Enter Seat Number for Passenger " << i + 1 << ": ";
        cin >> seatNum;

        bool alreadyTaken = false;
        ifstream verify("seat.txt");
        while (verify >> sPlate >> sNum) {
            getline(verify, sName);
            if (sPlate == plate && sNum == seatNum) {
                alreadyTaken = true;
                break;
            }
        }
        verify.close();

        if (alreadyTaken || seatNum > totalSeats || seatNum < 1) {
            cout << "Invalid or already reserved seat! Enter again." << endl;
            goto retrySeat;
        }

        cout << "Enter Passenger Name: ";
        cin.ignore();
        getline(cin, passenger);

        ofstream seatFile("seat.txt", ios::app);
        seatFile << plate << " " << seatNum << " " << passenger << endl;
        seatFile.close();
    }

    cout << "\n------------------------------------" << endl;
    cout << "RESERVATION SUCCESSFUL!" << endl;
    cout << "Bus Plate: " << plate << " | Chassis: " << bChassis << endl;
    cout << "------------------------------------" << endl;

    cout << "\nReserve for another bus? (Y/N): ";
    cin >> goBack;
    if (goBack == "Y" || goBack == "y") reserveSeat();
}

void viewReservations() {
    ifstream seatFile("seat.txt");
    string plate, passenger, bPlate, bType, bChassis;
    int seatNum, totalSeats;
    bool empty = true;

    cout << "\n--- All Reserved Seats ---" << endl;
    while (seatFile >> plate >> seatNum) {
        seatFile.ignore();
        getline(seatFile, passenger);

        string foundChassis = "Unknown";
        ifstream busFile("bus_data.txt");
        while (getline(busFile, bPlate, '|')) {
            getline(busFile, bChassis, '|');
            getline(busFile, bType, '|');
            busFile >> totalSeats;
            busFile.ignore();
            if (bPlate == plate) {
                foundChassis = bChassis;
                break;
            }
        }
        busFile.close();

        cout << "Bus: " << plate << " (Chassis: " << foundChassis << ")"
             << " | Seat: " << seatNum << " | Passenger: " << passenger << endl;
        empty = false;
    }
    seatFile.close();
    if (empty) cout << "No reservations found." << endl;
}

void viewBuses() {
    ifstream busFile("bus_data.txt");
    string plate, type, chasis;
    int seats;
    bool empty = true;

    cout << "\n--- Available Buses ---\n";
    while (getline(busFile, plate, '|')) {
        getline(busFile, chasis, '|');
        getline(busFile, type, '|');
        busFile >> seats;
        busFile.ignore();
        cout << "Plate: " << plate << " | Chassis: " << chasis << " | Type: " << type << " | Seats: " << seats << endl;
        empty = false;
    }
    busFile.close();
    if (empty) cout << "No buses found.\n";
}