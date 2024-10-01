#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_PASSENGERS = 100;

struct Passenger {
    string name;
    int seatNumber;
    string flightDetail;
};

void bookFlight(Passenger passengers[], int& numPassengers) {
    if (numPassengers >= MAX_PASSENGERS) {
        cout << "No seats available." << endl;
        return;
    }

    Passenger newPassenger;
    cout << "Enter passenger details: " << endl;
    cout << "Name: ";
    cin >> newPassenger.name;
    cout << "Seat Number: ";
    cin >> newPassenger.seatNumber;
    cout << "Flight Detail: ";
    cin >> newPassenger.flightDetail;

    passengers[numPassengers] = newPassenger;
    numPassengers++;

    cout << "Flight booked successfully." << endl;
}

void displayBookedFlights(const Passenger passengers[], int numPassengers) {
    cout << "Booked Flights:" << endl;
    for (int i = 0; i < numPassengers; i++) {
        cout << "Passenger " << i + 1 << ":" << endl;
        cout << "Name: " << passengers[i].name << endl;
        cout << "Seat Number: " << passengers[i].seatNumber << endl;
        cout << "Flight Detail: " << passengers[i].flightDetail << endl;
        cout << endl;
    }
}

void cancelFlight(Passenger passengers[], int& numPassengers) {
    int seatNumber;
    cout << "Enter the seat number of the flight to cancel: ";
    cin >> seatNumber;

    for (int i = 0; i < numPassengers; i++) {
        if (passengers[i].seatNumber == seatNumber) {
            passengers[i] = passengers[numPassengers - 1];
            numPassengers--;
            cout << "Flight canceled successfully." << endl;
            return;
        }
    }

    cout << "Flight with seat number " << seatNumber << " not found." << endl;
}

void saveBookedFlightsToFile(const Passenger passengers[], int numPassengers) {
    ofstream outputFile("booked_flights.txt");
    if (!outputFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    for (int i = 0; i < numPassengers; i++) {
        outputFile << "Passenger " << i + 1 << ":" << endl;
        outputFile << "Name: " << passengers[i].name << endl;
        outputFile << "Seat Number: " << passengers[i].seatNumber << endl;
        outputFile << "Flight Detail: " << passengers[i].flightDetail << endl;
        outputFile << endl;
    }

    outputFile.close();
    cout << "Booked flights saved to file." << endl;
}

int main() {
    Passenger passengers[MAX_PASSENGERS];
    int numPassengers = 0;

    int choice;
    cout << "Flight Booking System" << endl;
    cout << "1. Book a Flight" << endl;
    cout << "2. Display Booked Flights" << endl;
    cout << "3. Cancel a Flight" << endl;
    cout << "4. Save Booked Flights to File" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bookFlight(passengers, numPassengers);
            break;
        case 2:
            displayBookedFlights(passengers, numPassengers);
            break;
        case 3:
            cancelFlight(passengers, numPassengers);
            break;
        case 4:
            saveBookedFlightsToFile(passengers, numPassengers);
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}