#pragma once
#include <string>
#include <fstream>
#include <iostream> 

using namespace::std;

class InputDevice {
public:
    InputDevice();

    virtual void connect();
    virtual void disconnect();

    //5.3
    virtual string getDeviceType() const = 0;

    virtual void testConnection() {
        cout << "Testing connection...\n";
    }

    virtual void reset() {
        cout << "Resetting device settings to default.\n";
    }

    virtual void updateFirmware() {
        cout << "Updating firmware...\n";
    }

    virtual ~InputDevice();
};

//
//void Keyboard::inputDetails() const {
//	std::cout << "Keyboard details: Layout: " << layout
//		<< ", Mechanical: " << (isMechanical ? "Yes" : "No")
//		<< ", Number of keys: " << numKeys << std::endl;
//}
//
//void Mouse::inputDetails() const {
//	std::cout << "Mouse details: DPI: " << dpi
//		<< ", Wireless: " << (wireless ? "Yes" : "No") << std::endl;
//}