#include"Device.h"
#include"HardDrive.h"
#include"Computer.h"
#include"Keyboard.h"
#include"Mouse.h"
#include <fstream>
#include <iostream> 
#include <vector> 
#include <stdexcept>
#include"Monitor.h"
#include"TemplateClass.h"
#include <algorithm>


using namespace std;
void menu(vector<Mouse*>& mice) {
    int choice;
    do {
        // Виведення меню
        cout << "\nmenu:\n";
        cout << "1. Create new\n";
        cout << "2. Delete\n";
        cout << "3. Show list\n";
        cout << "4. Exit\n";
        cout << "Choose action(1-4): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Створення нового об'єкта Mouse
            string name, brand, driverVersion, statusType;
            int year, dpi, batteryLevel;
            bool wireless;

            // Введення параметрів
            cout << "Name: ";
            cin >> name;
            cout << "Brand: ";
            cin >> brand;
            cout << "year: ";
            cin >> year;
            cout << "version: ";
            cin >> driverVersion;
            cout << "status: ";
            cin >> statusType;
            cout << "DPI: ";
            cin >> dpi;
            cout << "(0 - wired, 1 - wiredless): ";
            cin >> wireless;
            cout << "Battery: ";
            cin >> batteryLevel;

            // Створення нового об'єкта та додавання його в вектор
            Mouse* newMouse = new Mouse(name, brand, year, driverVersion, statusType, dpi, wireless, batteryLevel);
            mice.push_back(newMouse);
            cout << "Object created!\n";
            break;
        }

        case 2: {
            // Видалення об'єкта
            int index;
            cout << "index to delete (0 - " << mice.size() - 1 << "): ";
            cin >> index;

            if (index >= 0 && index < mice.size()) {
                delete mice[index];
                mice.erase(mice.begin() + index);
                cout << "Object deleted !\n";
            }
            else {
                cout << "Wrong index\n";
            }
            break;
        }

        case 3: {
            // Перегляд всіх об'єктів
            if (mice.empty()) {
                cout << "Don`t have mice.\n";
            }
            else {
                for (int i = 0; i < mice.size(); i++) {
                    cout << "Object " << i + 1 << ": ";
                    mice[i]->displayMouseInfo(); // Викликаємо функцію перегляду для кожного об'єкта
                }
            }
            break;
        }

        case 4:
            cout << "exit\n";
            break;

        default:
            cout << "Wrong.\n";
            break;
        }
    } while (choice != 4); // Меню повторюється, поки не вибрано варіант виходу
}



//5.8
void Service(Keyboard& obj, const string& filename) {
    try {
        ofstream outFile(filename, ios::app);
        if (!outFile.is_open()) {
            throw runtime_error("Could not open file for writing.");
        }
        obj.Write(outFile);
        outFile.close();

        ifstream inFile(filename);
        if (!inFile.is_open()) {
            throw runtime_error("Could not open file for reading.");
        }
        obj.Read(inFile);
        inFile.close();
    }
    catch (const ios_base::failure& e) {
        cerr << "File operation failed: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
    }
    catch (const bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
    }
    catch (...) {
        cerr << "An unknown error occurred." << endl;
    }
}


void calculateAnnualPowerUsage(const Device& device) {
    int hoursPerDay = 15;
    int daysPerYear = 365;
    int annualUsage = device.calculatePowerUsage(hoursPerDay * daysPerYear);

    cout << "Annual Power Usage for " << device.name << ": " << annualUsage << "W" << endl;

}

// 6 punkt reload f
void calculateAnnualPowerUsage(Device* device) {
    if (device == nullptr) {
        cout << "Invalid device pointer." << endl;
        return;
    }

    int hoursPerDay = 24;
    int daysPerYear = 365;
    int annualUsage = device->calculatePowerUsage(hoursPerDay * daysPerYear);

    cout << "Annual Power Usage for " << device->name << ": " << annualUsage << "W" << endl;
}

int main() {
    //6.1
    Mouse myMouse("Logitech", "MX Master", 2022, "USB", "Optical", 800, true, 75);

    cout << "Initial DPI: " << myMouse.dpi << endl;
    ++myMouse;
    myMouse++;
    --myMouse;
    myMouse--;

    //6.2
    Monitor monitor1("Dell", "UltraSharp U2723QE", 3840, 2160, 27.0, false);
    Monitor monitor2("Samsung", "Odyssey G7", 2560, 1440, 27.0, true);

    
    Monitor sumMonitor = monitor1 + monitor2;
    cout << "Sum of Monitors - Brand: " << sumMonitor.brand << endl;

    Monitor diffMonitor = monitor1 - monitor2;
    cout << "Difference of Monitors - Brand: " << diffMonitor.brand << endl;

    Monitor prodMonitor = monitor1 * monitor2;
    cout << "Product of Monitors - Resolution: " << prodMonitor.resolutionWidth << "x" << prodMonitor.resolutionHeight << endl;
    Monitor monitor3 = monitor1; 
    cout << "Assigned Monitor - Brand: " << monitor3.brand << endl;
    monitor1 += monitor2;
    cout << "After += : " << monitor1.resolutionWidth << endl;
    monitor1 -= monitor2;
    cout << "After -= : " << monitor1.resolutionWidth << endl;
    monitor1 *= monitor2;
    cout << "After *= : " << monitor1.resolutionWidth << endl;
    cout << "Resolution Width via []: " << monitor1[0] << endl;
    cout << "Resolution Height via []: " << monitor1[1] << endl;


    //6.4
    Monitor monitor123("Dell", "UltraSharp", 1920, 1080, 27.0, false);
    float diagonal = monitor123.calculateDiagonal<float>(monitor123.resolutionWidth, monitor123.resolutionHeight);
    cout << "Monitor " << monitor123.brand << " " << monitor123.model << " has diagonal: " << diagonal << " px" << endl;
    
    //6.5
    TemplateClass<string, string, int, string, string> mouse("Mouse", "Logitech", 2022, "Connected", "Wireless");
    TemplateClass<string, string, int, string, int> keyboard("Keyboard", "Corsair", 2021, "Disconnected", 100);

    mouse.displayDeviceInfo();
    keyboard.displayDeviceInfo();

    cout << "Is the mouse older than 2023? " << (mouse.isOlderThan(2023) ? "Yes" : "No") << endl;
    keyboard.updateStatus("Connected");
    cout << "Updated Keyboard Status: " << keyboard.isOlderThan(2022) << endl;

    //6.6
    Mouse myMousellast("G900", "Logitech", 2020, "v1.2", "Active", 16000, true, 80);

    // Створимо об'єкт шаблону TemplateClass, використовуючи Mouse як параметр шаблону
    TemplateClass<string, string, int, string, string> mouseDevice(
        myMouse.getDeviceType(), 
        myMouse.getBrand(), 
        myMouse.getYear(), 
        "Connected", 
        "High performance, wireless"
    );

    mouseDevice.displayDeviceInfo();



    ////////7/////
    Mouse mouse71("Logitech", "Logitech", 2022, "1.0", "Wireless", 1200, true, 85);
    Mouse mouse72("Razer", "Razer", 2021, "2.0", "Wired", 1600, false, 50);
    Mouse mouse73("SteelSeries", "SteelSeries", 2023, "3.0", "Wireless", 800, true, 75);

    // Створюємо вектор для зберігання об'єктів Mouse
    vector<Mouse*> mice7;

    
    mice7.push_back(&mouse71);
    mice7.push_back(&mouse72);
    mice7.push_back(&mouse73);

    for (vector<Mouse*>::iterator it = mice7.begin(); it != mice7.end(); ++it) {
        (*it)->printInfo();
    }

    sort(mice7.begin(), mice7.end(), [](Mouse* a, Mouse* b) {
        return a->dpi > b->dpi;  
        });

    cout << "\nAfter sorting by DPI (descending):\n";
    for (auto mouse : mice7) {
        mouse->printInfo();
    }


    auto it = find_if(mice7.begin(), mice7.end(), [](Mouse* mouse) {
        return mouse->batteryLevel == 100;  
        });

    if (it != mice7.end()) {
        cout << "\nFound mouse with 100% battery:\n";
        (*it)->printInfo(); 
    }
    else {
        cout << "\nNo mouse with 100% battery found.\n";
    }





    // Використовуємо метод at() для доступу до елементів вектора з перевіркою меж
    //try {
    //    cout << "Accessing mouse at index 1: " << endl;
    //    mice7.at(1)->displayMouseInfo(); 
    //}
    //catch (const out_of_range& e) {
    //    cerr << "Index out of range!" << endl;
    //}

 //   
	//string deviceDesc = "High-resolution display";//2
	//Device device1("Monitor", "LG", 2020, "1.0", "Working", true, 30, "Display", 150, deviceDesc);
	////device1.displayInfo();
	//HardDrive hardDrive(1000, "Crucial", "MX500", 560, 510, true, "SATA III", 7200);
	////hardDrive.displayInfo();

 //   
 //   Device device2(device1);//1

 //   calculateAnnualPowerUsage(device1);// 5- 6 
 //   calculateAnnualPowerUsage(&device1);// 5- 6 

 //   Device changedDevice = device1.changeName(device1);//7
 //   cout << endl;
 //   //cout << "Changed device name to: " << changedDevice.name << endl;
 //   cout << endl;

 //   Device simpleConst;//8 
 //   //simpleConst.displayInfo();
 //   Device scorochenConst("Roman", "Scoro");//8


 //   //9
 //   Device* d1 = new Device("Speaker", "Bose", 2020, "1.0", "Working", true, 15, "Output", 150, deviceDesc);
 //   //scorochenConst.displayInfo();


 //   //11
 //   Computer myComputer(device1, hardDrive);
 //   myComputer.connectDevice(device1);

 //   //12 
 //   myComputer.addDevice(device1);
 //   myComputer.addDevice(device2);

 //   myComputer.showDevices();

 //   //13
 //   //myComputer.displaySystemInfo();


 //   Computer myComputer1(device1, hardDrive);

 //   //Device::showDeviceCount(); //4


 //   // 4 laba

 //   Mouse *myMouse = new Mouse("Mouse", "Logitech", 2024, "1.0", "Working", 16000, true, 20);//5 and 7.2
 //   //myMouse.displayMouseInfo();
 //   delete myMouse;
 //   cin.get();


    // 7.2
    string description = "Some txt";


    //Keyboard myKeyboard("Keyboard", "Logitech", 2024, "1.0", "Working", true, 50, "Input Device", 100, description, "QWERTY", true, 104);
    //myKeyboard.displayKeyboardInfo();

    //////98907986657464567 5lllaabbbaaa

    //5.8
    Keyboard key("Keyboard111", "Logitech", 2024, "1.0", "Working", true, 50, "Input Device", 100, description, "QWERTY", true, 104);
    try {
        Service(key, "keyboard_data.txt");
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }


    //5.9
    Keyboard k("Keyboard1", "Logitech", 2024, "1.0", "Working", true, 50, "Input Device", 100, description, "QWERTY", true, 104);
    Keyboard k1("Keyboard222", "Logitech", 2024, "1.0", "Working", true, 50, "Input Device", 100, description, "QWERTY", true, 104);
    Keyboard k2("Keyboard322", "Logitech", 2024, "1.0", "Working", true, 50, "Input Device", 100, description, "QWERTY", true, 104);

    Keyboard::DisplayAllKeyboards();

    //5.6
    try {
        Keyboard keyboard1("Keyboard561", "Logitech", 2024, "1.0", "Working", true, 50, "Input Device", 100, description, "QWERTY", true, 104);
        Keyboard keyboard2("Keyboard562", "Razer", 2023, "1.1", "Working", false, 40, "Input Device", 120, description, "AZERTY", false, 105);
        Keyboard keyboard3("Keyboard563", "Corsair", 2022, "1.2", "Working", true, 60, "Input Device", 110, description, "QWERTZ", true, 106);

        keyboard1.displayKeyboardInfo();
        keyboard2.displayKeyboardInfo();
        keyboard3.displayKeyboardInfo();

        Mouse* mouse1 = nullptr;
        Mouse* mouse2 = nullptr;
        Mouse* mouse3 = nullptr;

        try {
            mouse1 = new Mouse("Mouse-1", "Logitech", 2022, "2.0", "Active", 1600, true, 100);
            if (!mouse1) throw runtime_error("Failed to allocate memory for mouse1.");
            mouse1->displayMouseInfo();
        }
        catch (const bad_alloc& e) {
            cerr << "Memory allocation error for mouse1: " << e.what() << endl;
        }

        try {
            mouse2 = new Mouse("Mouse-2", "Razer", 2021, "2.1", "Active", 2400, false, 0);
            if (!mouse2) throw runtime_error("Failed to allocate memory for mouse2.");
            mouse2->displayMouseInfo();
        }
        catch (const bad_alloc& e) {
            cerr << "Memory allocation error for mouse2: " << e.what() << endl;
        }

        try {
            mouse3 = new Mouse("Mouse-3", "HP", 2023, "3.0", "Active", 1200, true, 50);
            if (!mouse3) throw runtime_error("Failed to allocate memory for mouse3.");
            mouse3->displayMouseInfo();
        }
        catch (const bad_alloc& e) {
            cerr << "Memory allocation error for mouse3: " << e.what() << endl;
        }

        // ??????? ????????? ???????? ? ??????????? ??'??????
        try {
            mouse1->toggleWirelessMode();
            if (mouse1->batteryLevel < 0) throw invalid_argument("Battery level cannot be negative.");
            mouse1->checkBatteryStatus();
        }
        catch (const exception& e) {
            cerr << "Error with mouse1: " << e.what() << endl;
        }

        try {
            mouse2->updateDPI(-800); // ??????????? ???????? DPI
        }
        catch (const invalid_argument& e) {
            cerr << "Error updating DPI for mouse2: " << e.what() << endl;
        }

        try {
            mouse3->toggleWirelessMode();
            mouse3->checkBatteryStatus();
        }
        catch (const exception& e) {
            cerr << "Error with mouse3: " << e.what() << endl;
        }

        // ????????? ?????????? ??'?????
        delete mouse1;
        delete mouse2;
        delete mouse3;

    }
    catch (const exception& e) {
        cerr << "General error: " << e.what() << endl;
    }



    //5.7
    vector<Keyboard*> keyboards;
    vector<Mouse*> mice;

    keyboards.push_back(new Keyboard("Keyboard1", "Logitech", 2024, "1.0", "Working", true, 50, "Input Device", 100, description, "QWERTY", false, 104));
    keyboards.push_back(new Keyboard("Keyboard2", "Razer", 2023, "1.1", "Working", false, 40, "Input Device", 120, description, "AZERTY", true, 105));
    keyboards.push_back(new Keyboard("Keyboard3", "Corsair", 2022, "1.2", "Working", true, 60, "Input Device", 110, description, "QWERTZ", true, 106));

    mice.push_back(new Mouse("Mouse-1111111111111", "Logitech", 2022, "2.0", "Active", 1600, true, 100));
    mice.push_back(new Mouse("Mouse-2222222222222", "Razer", 2021, "2.1", "Active", 2400, false, 0));
    mice.push_back(new Mouse("Mouse-3333333333333", "HP", 2023, "3.0", "Active", 1200, true, 50));

    try {
        cout << "Calling Service_Static..." << endl;
        Keyboard::Service_Static(keyboards);
    }
    catch (const exception& e) {
        cerr << "Error in Service_Static: " << e.what() << endl;
    }

    try {
        cout << "Calling Service_Dinamic..." << endl;
        Mouse::Service_Dinamic(mice);
    }   
    catch (const exception& e) {
        cerr << "Error in Service_Dinamic: " << e.what() << endl;
    }

    for (auto keyboard : keyboards) {
        delete keyboard;
    }
    for (auto mouse : mice) {
        delete mouse;
    }

    //last
    InputDevice* devi1 = new Mouse("Mouse last", "Logitech", 2022, "2.0", "Active", 1600, true, 100);
    devi1->connect();

    //pre-last
    vector<Mouse*> micey; // Вектор для зберігання об'єктів мишей
    menu(mice); // Викликаємо меню для роботи з об'єктами
    // Очищаємо пам'ять перед виходом з програми
    for (Mouse* mouse : mice) {
        delete mouse;
    }

    return 0;
}


/*Mouse* mouse1 = new Mouse("Mouse1", "Logitech", 2024, "2.0", "Working", 1600, true, 100);
Mouse* mouse2 = new Mouse("Mouse2", "Razer", 2023, "2.1", "Working", 1200, false, 80);
Mouse* mouse3 = new Mouse("Mouse3", "Corsair", 2022, "2.2", "Working", 1800, true, 90);*/