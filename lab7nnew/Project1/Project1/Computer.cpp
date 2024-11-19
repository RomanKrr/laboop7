#include "Computer.h"

Computer::Computer(const Device& device, HardDrive& hardDrive)
    : device(device), hD(&hardDrive) {}


void Computer::displaySystemInfo() {
    cout << endl;
    cout << "Computer System Info:" << endl;
    device.displayInfo();
    hardDrive.displayInfo();
}

// asociate
void Computer::connectDevice(const Device& device) {
    cout << "Connecting device: " << device.name << " to the computer." << endl;
}

//12 agregation
void Computer::addDevice(const Device& device) {
    devices.push_back(device);
}
void Computer::showDevices() {
    for (const auto& device : devices) {
        cout << "Device: " << device.name << endl;
    }
}
