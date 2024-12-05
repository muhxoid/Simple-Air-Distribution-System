#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

string username() { return "username"; }
string password() { return "password"; }

class login {
private:
    string userName = username ();
    string userPassword = password ();
public:
    void inputUserAndPass () { cout << "Username: "; cin >> userName;
    cout << "Password: "; cin >> userPassword; }

    int verifyLogin () {
    int attemptCount = 0;
    const int maxAttempts = 3;
    while (attemptCount < maxAttempts) {
    inputUserAndPass();
    if (userName == username() && userPassword == password()) { return 1; }
    else { attemptCount++; cout << (maxAttempts - attemptCount) << endl; }
    } return 0; } };

class FlightBooking {
private:
    string storedDate;
    string returnDate;
    string storedFrom;
    string storedTo;
    int travelType = 0;
    string passengerName1;
    string passengerName2;
    string passportno;
    string email;

    string AMM() { return "AMM"; }
    string BGW() { return "BGW"; }
    string DXB() { return "DXB"; }
    string JED() { return "JED"; }
    string ISL() { return "ISL"; }
    string MHD() { return "MHD"; }
    string BSR() { return "BSR"; }
    string EBL() { return "EBL"; }
    string NJF() { return "NJF"; }

public:

    void inputDate() {
    string date;
    cin >> date;
    if (date.length() == 10 && date[4] == '/' && date[7] == '/') { storedDate = date; } }

    void type() {
    cin >> travelType;
    if (travelType == 2) {
    cout << "->";
    cin >> returnDate; } }

    string departure() {
        string airport;
        cin >> airport;
        if (airport == "BGW") { storedFrom = airport; return BGW(); }
        else if (airport == "BSR") { storedFrom = airport; return BSR(); }
        else if (airport == "EBL") { storedFrom = airport; return EBL(); }
        else if (airport == "NJF") { storedFrom = airport; return NJF(); }
        else return "NULL"; }

    string arrival() {
        string airport;
        cin >> airport;
        if (airport == "AMM") { storedTo = airport; return AMM(); }
        else if (airport == "DXB") { storedTo = airport; return DXB(); }
        else if (airport == "JED") { storedTo = airport; return JED(); }
        else if (airport == "ISL") { storedTo = airport; return ISL(); }
        else if (airport == "MHD") { storedTo = airport; return MHD(); }
        else if (airport == "BGW") { storedTo = airport; return BGW(); }
        else if (airport == "BSR") { storedTo = airport; return BSR(); }
        else if (airport == "EBL") { storedTo = airport; return EBL(); }
        else if (airport == "NJF") { storedTo = airport; return NJF(); }
        else return "NULL"; }

    double calPrice(string from, string to) {

        double price = 0;

        if ((from == "BGW" && to == "BSR") || (from == "BSR" && to == "BGW")) price = 130.0;
        else if ((from == "BGW" && to == "EBL") || (from == "EBL" && to == "BGW")) price = 140.0;
        else if ((from == "BGW" && to == "NJF") || (from == "NJF" && to == "BGW")) price = 180.0;
        else if ((from == "BSR" && to == "EBL") || (from == "EBL" && to == "BSR")) price = 150.0;
        else if ((from == "BSR" && to == "NJF") || (from == "NJF" && to == "BSR")) price = 160.0;
        else if ((from == "EBL" && to == "NJF") || (from == "NJF" && to == "EBL")) price = 170.0;
        else if ((from == "BGW" && to == "AMM") || (from == "AMM" && to == "BGW")) price = 100.0;
        else if ((from == "BGW" && to == "DXB") || (from == "DXB" && to == "BGW")) price = 200.0;
        else if ((from == "BGW" && to == "JED") || (from == "JED" && to == "BGW")) price = 110.0;
        else if ((from == "BGW" && to == "ISL") || (from == "ISL" && to == "BGW")) price = 160.0;
        else if ((from == "BGW" && to == "MHD") || (from == "MHD" && to == "BGW")) price = 150.0;
        else if ((from == "BSR" && to == "AMM") || (from == "AMM" && to == "BSR")) price = 105.0;
        else if ((from == "BSR" && to == "DXB") || (from == "DXB" && to == "BSR")) price = 210.0;
        else if ((from == "BSR" && to == "JED") || (from == "JED" && to == "BSR")) price = 115.0;
        else if ((from == "BSR" && to == "ISL") || (from == "ISL" && to == "BSR")) price = 165.0;
        else if ((from == "BSR" && to == "MHD") || (from == "MHD" && to == "BSR")) price = 155.0;
        else if ((from == "EBL" && to == "AMM") || (from == "AMM" && to == "EBL")) price = 120.0;
        else if ((from == "EBL" && to == "DXB") || (from == "DXB" && to == "EBL")) price = 220.0;
        else if ((from == "EBL" && to == "JED") || (from == "JED" && to == "EBL")) price = 125.0;
        else if ((from == "EBL" && to == "ISL") || (from == "ISL" && to == "EBL")) price = 170.0;
        else if ((from == "EBL" && to == "MHD") || (from == "MHD" && to == "EBL")) price = 160.0;
        else if ((from == "NJF" && to == "AMM") || (from == "AMM" && to == "NJF")) price = 130.0;
        else if ((from == "NJF" && to == "DXB") || (from == "DXB" && to == "NJF")) price = 230.0;
        else if ((from == "NJF" && to == "JED") || (from == "JED" && to == "NJF")) price = 140.0;
        else if ((from == "NJF" && to == "ISL") || (from == "ISL" && to == "NJF")) price = 175.0;
        else if ((from == "NJF" && to == "MHD") || (from == "MHD" && to == "NJF")) price = 165.0;

        if (travelType == 2) { price *= 1.5; }
        return price; }

    void details() {
        double price = calPrice(storedFrom, storedTo);

        cout << "+------------------------+------------------------------------+\n";
        cout << "|       Flight Details   |              Date                  |\n";
        cout << "+------------------------+------------------------------------+\n";
        cout << "| Flight Type            | " << (travelType == 1 ? "OneWay" : "Return") << "                             |\n";
        cout << "| Selected Date          | " << storedDate << "                         |\n";
        if (travelType == 2) {
            cout << "| Return Date            | " << returnDate << "                         |\n";
        }
        cout << "+------------------------+------------------------------------+\n";
        cout << "| From                   | " << storedFrom << "                                |\n";
        cout << "| To                     | " << storedTo << "                                |\n";
        cout << "+------------------------+------------------------------------+\n";
        cout << "| Price                  | $" << price << "                               |\n";
        cout << "+------------------------+------------------------------------+\n";
    }

    void inputPassengerName() { cin >> passengerName1 >> passengerName2;  }

    void inputPassportNo() { cin >> passportno; }

    void inputEmail() { cin >> email; }

    void printTicket() {
        cout << "==============================================\n";
        cout << "              FLIGHT TICKET                   \n";
        cout << "==============================================\n";

        cout << "Passenger: " << passengerName1 << " " << passengerName2 << "\n";
        cout << "Passport No: " << passportno << "\n";
        cout << "Email: " << email << "\n";
        cout << "Departure: " << storedFrom << "\n";
        cout << "Destination: " << storedTo << "\n";
        cout << "Date: " << storedDate << "\n";
        if (travelType == 2) { cout << "Return Date: " << returnDate << "\n"; }
        cout << "==============================================\n";
        cout << "           Fly Beyond The Horizon             \n";
        cout << "==============================================\n"; }

        void saveTicket() {

        ofstream outFile(passportno + ".txt");

        if (outFile.is_open()) {
            outFile << "==============================================\n";
            outFile << "              FLIGHT TICKET                   \n";
            outFile << "==============================================\n";
            outFile << "Passenger: " << passengerName1 << " " << passengerName2 << "\n";
            outFile << "Passport No: " << passportno << "\n";
            outFile << "Email: " << email << "\n";
            outFile << "Departure: " << storedFrom << "\n";
            outFile << "Destination: " << storedTo << "\n";
            outFile << "Date: " << storedDate << "\n";
            if (travelType == 2) { outFile << "Return Date: " << returnDate << "\n"; }
            outFile << "==============================================\n";
            outFile << "           Fly Beyond The Horizon             \n";
            outFile << "==============================================\n";
            outFile.close();
            } else { } } };

class CLI {
private:
    string us;
    FlightBooking* currentBooking = nullptr;

public:
    void startCLI() {
        string command;
        us = username();
        getline(cin, command);
        cin.sync();

        while (true) {
            cout << "[(" << us << ")] > ";
            getline(cin, command);
            if (command.empty()) { continue; }
            else if (command == "date") {
            cout << "->";
            currentBooking->inputDate();
            getchar(); }
            else if (command == "type") {
            cout << "->";
            currentBooking->type();
            getchar(); }
            else if (command == "from") {
            cout << "->";
            currentBooking->departure();
            getchar(); }
            else if (command == "to") {
            cout << "->";
            currentBooking->arrival();
            getchar(); }
            else if (command == "show") {
            currentBooking->details();
            getchar(); }
            else if (command == "name") {
            cout << "->";
            currentBooking->inputPassengerName();
            getchar(); }
            else if (command == "passport") {
            cout << "->";
            currentBooking->inputPassportNo();
            getchar(); }
            else if (command == "email") {
            cout << "->";
            currentBooking->inputEmail();
            getchar(); }
            else if (command == "print") {
            currentBooking->printTicket();
            getchar(); }
            else if (command == "save") {
            currentBooking->saveTicket(); }
            else if (command == "new") {
            if (currentBooking != nullptr) {
            delete currentBooking; }
            currentBooking = new FlightBooking(); }
            else if (command == "clear") {
            if (currentBooking != nullptr) {
            delete currentBooking;
            currentBooking = nullptr; } }
            else if (command == "exit") { break; }
            else if (command == "help") {
                cout << "## Available commands ##" << endl;
                cout << "-> date: Enter departure date" << endl;
                cout << "-> type: Enter flight type (1: One-way, 2: Return)" << endl;
                cout << "-> from: Enter departure airport" << endl;
                cout << "-> to: Enter arrival airport" << endl;
                cout << "-> show: Display flight details" << endl;
                cout << "-> name: Enter passenger name" << endl;
                cout << "-> passport: Enter passenger passport" << endl;
                cout << "-> email: Enter passenger email" << endl;
                cout << "-> print: Print ticket" << endl;
                cout << "-> save: Save the ticket" << endl;
                cout << "-> new: Set new passenger" << endl;
                cout << "-> clear: Clear old passenger data" << endl;
                cout << "-> exit: Exit the program" << endl; }
                else { continue; }}}};

int main() {
    login userLogin;
    CLI cli;
    if (userLogin.verifyLogin() == 1) { cli.startCLI(); }
    return 0; }
