#pragma once
#include <string>
#include <cmath> 
using namespace std;

class Monitor {
public:

    Monitor(string b, string m, int resW, int resH, float size, bool curved);


    string brand;
    string model;
    int resolutionWidth;
    int resolutionHeight;
    float screenSize;
    bool isCurved;

    //6.2 // 6.3
    Monitor operator+(const Monitor& other) const; 
    Monitor operator-(const Monitor& other) const;
    Monitor operator*(const Monitor& other) const; 
    Monitor& operator=(const Monitor& other);      
    Monitor& operator+=(const Monitor& other);     
    Monitor& operator-=(const Monitor& other);   
    Monitor& operator*=(const Monitor& other);    
    int operator[](int index);

    //6.4
    template <typename T>
    float calculateDiagonal(float width, float height) {
        return sqrt(width * width + height * height);
    }

};