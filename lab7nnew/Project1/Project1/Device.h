#pragma once
#include <string>

using namespace std;

class Device	
{
public:
	string name;
	string brand;
	int year;
	string getBrand() const { return brand; }
	int getYear() const { return year; }
// 2 
	const int maxPowerUsage;
	string& description;
// 4  
	static int deviceCount;


	void displayInfo();// 2,2
	static void showDeviceCount();
	int calculatePowerUsage(int hours) const;
	
//7
	Device changeName(Device& device);

// 1
	Device();//without param
	Device(string n, string b, int y, string dV, string sT, bool iC, int pU, string dT, int maxPower, string& desc);//with param
	Device(const Device& m);//copy

//8 
	Device(string n, string b);

// 3  
	~Device();
	//2.2
protected:
	string status;
	void showStatus();

	//2.2
private:
	void showDriverVersoin();

private:
	string driverVersion;
	bool isConnected;
	int powerUsage;
	string deviceType;
};

