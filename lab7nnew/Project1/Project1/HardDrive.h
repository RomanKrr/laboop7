#pragma once
    #include <string>

    using namespace std;

class HardDrive
{
public:
    int capacity;
    string brand;
    string model;

    HardDrive();
    HardDrive(int c, string b, string m, int rS, int wS, bool hs, string cT, int sR);
    HardDrive(const HardDrive& h);

    ~HardDrive();

    void displayInfo();

private:
    int readSpeed;
    int writeSpeed;
    bool healthStatus;
    string connectionType;
    int spindleRotation;
};

