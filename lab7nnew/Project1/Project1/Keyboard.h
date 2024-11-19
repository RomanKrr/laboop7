#pragma once
#include"Device.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <iostream>

using namespace std;

class Keyboard : protected Device
{
public:
    string layout;
    bool isMechanical;
    int numKeys;

    static vector<Keyboard*> allKeyboards;


    Keyboard(string n, string b, int y, string dV, string sT, bool iC, int pU, string dT, int maxPower, string& desc, string l, bool m, int keys);

    static void DisplayAllKeyboards() {
        cout << "Displaying all keyboards:\n";
        for (const auto& keyboard : allKeyboards) {
            keyboard->displayKeyboardInfo();
        }
    }


    static void Service_Static(vector<Keyboard*>& keyboards);
    void displayKeyboardInfo();
    void displayStatus();

    //5.8
    void Write(ofstream& outFile);
    void Read(ifstream& inFile);

    //5.9
    //static void StaticDisplayKeyboardInfo(const Keyboard& keyboard);

    virtual void setBacklight(bool enabled) {
        cout << "Backlight " << (enabled ? "enabled." : "disabled.") << "\n";
    }

    void changeLayout(const string& newLayout) {
        layout = newLayout;
        cout << "Layout changed to: " << layout << "\n";
    }
    


    virtual ~Keyboard();
protected:
    void printDeviceStatus();
};

