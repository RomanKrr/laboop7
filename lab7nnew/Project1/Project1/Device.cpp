#include "Device.h"
#include <string>
#include <iostream> 

using namespace std;

int Device::deviceCount = 0;
//without param
Device::Device()
	: name("unknown"), brand("unknown"), year(0), driverVersion("0.0"),
	status("unknown"), isConnected(false), powerUsage(0), deviceType("unknown"),
	maxPowerUsage(100), description(*(new string("No description"))) 
{
	deviceCount++;
}
//with param
Device::Device(string n, string b, int y, string dV, string sT, bool iC, int pU, string dT, int maxPower, string& desc)
	: name(n), brand(b), year(y), driverVersion(dV), status(sT), isConnected(iC), powerUsage(pU),
	deviceType(dT), maxPowerUsage(maxPower), description(desc) 
{
	deviceCount++;
}
//copy 
Device::Device(const Device& m)
	: name(m.name), brand(m.brand), year(m.year), driverVersion(m.driverVersion),
	status(m.status), isConnected(m.isConnected), powerUsage(m.powerUsage),
	deviceType(m.deviceType), maxPowerUsage(m.maxPowerUsage), description(m.description)
{
	//std::cout << "Copy constructor called" << std::endl;
	deviceCount++;
}


// 8 
Device::Device(string n, string b) 
: name(n), brand(b), year(0), driverVersion("0.0"),
status("unknown"), isConnected(false), powerUsage(0),
deviceType("unknown"), maxPowerUsage(100), description(*(new string("No description")))
{
	deviceCount++;
}

// 3 punkt
Device::~Device() {
	//cout << "Device object with brand: " << brand << " is being destroyed." << endl;
}

void Device::displayInfo() {
	cout << "Device name: " << name << endl;
	cout << "Device brand: " << brand << endl;
	cout << "Year of Production" << year << endl;
	cout << "Driver version: " << driverVersion << endl;
	cout << "Status: " << status << endl;
	cout << "Connected: " << (isConnected ? "Yes" : "No") << endl;
	cout << "Power Usage: " << powerUsage << "W" << endl;
	cout << "Device type: " << deviceType << endl;
	cout << "Max Power Usage: " << maxPowerUsage << "W" << endl;
	cout << "Description: " << description << endl;
}

void Device::showDeviceCount() {
	cout << "Count of devices: " << deviceCount << endl;
	cout << endl;
}

int Device::calculatePowerUsage(int hours) const {
	return powerUsage * hours;
}

Device Device::changeName(Device& device) {
	Device newDevice = device;
	newDevice.name = "ChangedName";
	return newDevice;
}

// laba 4

void Device::showDriverVersoin() {
	cout << "driver version is: " << driverVersion << endl;
}

void Device::showStatus() {
	cout << "Status of device is: " << status << endl;
}