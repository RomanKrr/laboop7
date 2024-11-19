#include "Mouse.h"
#include <iostream> 
#include <string>
#include <vector>

using namespace std;

void Mouse::Service_Dinamic(vector<Mouse*>& mice) {
    for (auto it = mice.begin(); it != mice.end(); ) {
        if (!(*it)->wireless) {
            delete* it;  
            it = mice.erase(it);
            cout << "Wired mouse removed." << endl;
        }
        else {
            ++it;
        }
    }
}

string defaultDescription = "Default description";
Mouse::Mouse(string n, string b, int y, string dV, string sT, int d, bool w, int bL)
    : Device(n, b, y, dV, sT, true, 100, "Input", 50, defaultDescription), dpi(d), wireless(w), batteryLevel(bL)
{
    //cout << "Mouse Constructor multiple imitation" << endl;
}

Mouse::~Mouse() {
    //cout << "Mouse destructor called." << endl;
}

void Mouse::displayMouseInfo() {
    std::cout << "Mouse: " << name << ", Brand: " << brand << ", DPI: " << dpi   << "\n";

}

void Mouse::checkBatteryStatus() {
    if (wireless) {
        cout << "Battery level: " << batteryLevel << "%" << endl;
        if (batteryLevel < 20) {
            cout << "Warning: Battery is low!" << endl;
        }
    }
    else {
        cout << "Wired mouse - no battery required." << endl;
    }
    cout << endl;

}

void Mouse::updateDPI(int dpi) {
    if (dpi < 0) throw invalid_argument("DPI cannot be negative.");
    this->dpi = dpi;
    cout << "DPI updated to: " << dpi << endl;
}

void Mouse::toggleWirelessMode() {
    wireless = !wireless;
    cout << (wireless ? "Now using wireless mode." : "Now using wired mode.") << endl;
}


//6.1
Mouse& Mouse::operator++() {
    dpi += 100;
    cout << "DPI increased to: " << dpi << endl;
    return *this;
}

Mouse Mouse::operator++(int) {
    Mouse temp = *this;
    ++(*this);
    return temp;
}

Mouse& Mouse::operator--() {
    if (dpi > 100) {
        dpi -= 100;
        cout << "DPI decreased to: " << dpi << endl;
    }
    else {
        cout << "DPI cannot be less than 0. Current DPI: " << dpi << endl;
    }
    return *this;
}

Mouse Mouse::operator--(int) {
    Mouse temp = *this;
    --(*this);
    return temp;
}

