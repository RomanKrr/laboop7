#include "InputDevice.h"
#include <iostream> 
#include <string>

using namespace std;

InputDevice::InputDevice() {}

void InputDevice::connect() {
    cout << "Input device connected." << std::endl;
}

void InputDevice::disconnect() {
    cout << "Input device disconnected." << std::endl;
}

InputDevice::~InputDevice() {
    //cout << "InputDevice destructor called." << endl;
}