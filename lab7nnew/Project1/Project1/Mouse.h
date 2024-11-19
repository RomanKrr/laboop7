#pragma once
#include"InputDevice.h"
#include"Device.h"
#include <vector>
#include "Mouse.h"

class Mouse : public Device, public InputDevice 
{
public:
	int dpi;
	bool wireless;
	int batteryLevel;

	Mouse(string n, string b, int y, string dV, string sT, int d, bool w, int bL);

	using Device::displayInfo;
	using Device::showDeviceCount;

	void displayMouseInfo();

	static void Service_Dinamic(vector<Mouse*>& mice);

	string getDeviceType() const override {
		return "Mouse"; 
	}

	void toggleWirelessMode();
	void updateDPI(int dpi);

	void checkBatteryStatus();

	void connect() override {
		cout << "Mouse connected." << endl;
	}

	//6.1
	Mouse& operator++();
	Mouse operator++(int);
	Mouse& operator--();
	Mouse operator--(int);

	void printInfo() const {
		cout << "DPI: " << dpi << ", Wireless: " << (wireless ? "Yes" : "No")
			<< ", Battery Level: " << batteryLevel << "%" << endl;
	}

	virtual ~Mouse();
};


