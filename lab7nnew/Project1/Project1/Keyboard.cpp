#include "Keyboard.h"
#include <vector>
#include <fstream>
#include <exception>
#include <iostream>

using namespace std;
vector<Keyboard*> Keyboard::allKeyboards;

//5.2
void Keyboard::Write(ofstream& outFile) {
    if (!outFile) {
        throw ios_base::failure("Failed to open file for writing.");
    }
    // ????????? ???? ?????????? ? ????
    outFile << layout << " "
        << isMechanical << " "
        << numKeys << " pariryri"
        << endl;
}

void Keyboard::Read(ifstream& inFile) {
    if (!inFile) {
        throw ios_base::failure("Failed to open file for reading.");
    }
    // ???????? ???? ?????????? ? ?????
    inFile >> layout
        >> isMechanical
        >> numKeys;
}
void Keyboard::Service_Static(vector<Keyboard*>& keyboards) {
    for (auto it = keyboards.begin(); it != keyboards.end(); ) {
        if (!(*it)->isMechanical) {
            delete* it;  
            it = keyboards.erase(it); 
            cout << "Non-mechanical keyboard removed." << endl;
        }
        else {
            ++it;
        }
    }
}


Keyboard::Keyboard(string n, string b, int y, string dV, string sT, bool iC, int pU, string dT, int maxPower, string& desc, string l, bool m, int keys)
    : Device(n, b, y, dV, sT, iC, pU, dT, maxPower, desc), layout(l), isMechanical(m), numKeys(keys) {
    allKeyboards.push_back(this);
}

Keyboard::~Keyboard() {
    //cout << "Keyboard destructor called." << endl;
}

void Keyboard::displayKeyboardInfo() {
    displayInfo();
    cout << "Keyboard layout: " << layout << endl;
    cout << "Mechanical: " << (isMechanical ? "Yes" : "No") << endl;
    cout << "Number of keys: " << numKeys << endl;
    cout << endl;
}

//void Keyboard::StaticDisplayKeyboardInfo(const Keyboard& keyboard) {
//    cout << endl;
//    cout << endl;
//    cout << endl;
//    cout << endl;
//    cout << endl;
//    cout << "Keyboard Information:" << endl;
//    cout << "Name: " << keyboard.name << endl;
//    cout << "Brand: " << keyboard.brand << endl;
//}

void Keyboard::printDeviceStatus() {
    cout << endl;
    cout << "Status: " << Device::status << endl;
}

void Keyboard::displayStatus() {
    printDeviceStatus();
    showStatus();
}

//
//void Keyboard::displayMenu() {
//    cout << "\n--- Keyboard Management Menu ---\n";
//    cout << "1. Create a new keyboard\n";
//    cout << "2. Display all keyboards\n";
//    cout << "3. Remove a keyboard by index\n";
//    cout << "4. Change layout of a keyboard by index\n";
//    cout << "5. Remove all non-mechanical keyboards\n";
//    cout << "6. Exit\n";
//    cout << "Choose an option: ";
//}