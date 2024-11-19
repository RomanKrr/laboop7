#include "HardDrive.h"
#include <iostream> 
#include <string>

using namespace std;

HardDrive::HardDrive() : capacity(0), brand("unknown"), model("unknown"), readSpeed(0),
writeSpeed(0), healthStatus(false), connectionType("unknown"), spindleRotation(0) {}

HardDrive::HardDrive(int c, string b, string m, int rS, int wS, bool hS, string connT, int sR)
    : capacity(c), brand(b), model(m), readSpeed(rS), writeSpeed(wS),
    healthStatus(hS), connectionType(connT), spindleRotation(sR) {}

HardDrive::HardDrive(const HardDrive& h)
    : capacity(h.capacity), brand(h.brand), model(h.model),
    readSpeed(h.readSpeed), writeSpeed(h.writeSpeed), healthStatus(h.healthStatus),
    connectionType(h.connectionType), spindleRotation(h.spindleRotation) {}

HardDrive::~HardDrive() {
    cout << "Device object with brand: " << brand << " is being destroyed." << endl;
}
void HardDrive::displayInfo() {
    cout << "Capacity: " << capacity << "GB" << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Read Speed: " << readSpeed << "MB/s" << endl;
    cout << "Write Speed: " << writeSpeed << "MB/s" << endl;
    cout << "Health Status: " << (healthStatus ? "Good" : "Bad") << endl;
    cout << "Connection Type: " << connectionType << endl;
    cout << "Spindle Rotation: " << spindleRotation << "RPM" << endl;
    cout << endl;
}
