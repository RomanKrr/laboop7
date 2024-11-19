#pragma once
#include <iostream>
#include "Device.h"
#include "HardDrive.h"
#include <vector>

using namespace std;

class Computer {
public:
    Computer(const Device& device, HardDrive& hardDrive);
    //??????? ???????? 

    void displaySystemInfo();
    void connectDevice(const Device& device);

    void addDevice(const Device& device);
    void showDevices();

private:
    Device device;//compose
    HardDrive hardDrive;// compose
    HardDrive *hD;// ????????
    vector<Device> devices;// agreg
};
