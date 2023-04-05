#include <iostream>
#include "icb_gui.h"
#include <chrono>
#include <thread>
void ICGUI_Create() {

}

void ICGUI_main()
{

}

#include <iostream>

class SevenSegmentDisplay {
public:
    SevenSegmentDisplay() {
        for (int i = 0; i < 7; i++) {
            segments[i] = ' ';
        }
    }
    void setNumber(int number) {
        switch (number) {
        case 0:
            segments[0] = segments[1] = segments[2] = segments[4] = segments[5] = segments[6] = true;
            break;
        case 1:
            segments[1] = segments[2] = true;
            break;
        case 2:
            segments[0] = segments[1] = segments[3] = segments[4] = segments[6] = true;
            break;
        case 3:
            segments[0] = segments[1] = segments[2] = segments[3] = segments[6] = true;
            break;
        case 4:
            segments[1] = segments[2] = segments[5] = segments[6] = true;
            break;
        case 5:
            segments[0] = segments[2] = segments[3] = segments[5] = segments[6] = true;
            break;
        case 6:
            segments[0] = segments[2] = segments[3] = segments[4] = segments[5] = segments[6] = true;
            break;
        case 7:
            segments[0] = segments[1] = segments[2] = true;
            break;
        case 8:
            segments[0] = segments[1] = segments[2] = segments[3] = segments[4] = segments[5] = segments[6] = true;
            break;
        case 9:
            segments[0] = segments[1] = segments[2] = segments[5] = segments[6] = true;
            break;
        }
    }

    void clear() {
        for (int i = 0; i < 7; i++) {
            segments[i] = ' ';
        }
    }
    void display() {
        for (int i = 0; i < 7; i++) {
            if (segments[i]) {
                std::cout << '#';
            }
            else {
                std::cout << ' ';
            }
            if (i == 2 || i == 4) {
                std::cout << '\n';
            }
        }
        std::cout << '\n';
    }
private:
    bool segments[7];
};

int main() {
    SevenSegmentDisplay display;

    while (true) {
        time_t now = time(nullptr);
        struct tm* timeinfo = localtime(&now);

        int hour = timeinfo->tm_hour;
        int minute = timeinfo->tm_min;

        display.clear();
        display.setNumber(hour / 10);
        display.display();

        display.clear();
        display.setNumber(hour % 10);
        display.display();

        display.clear();
        display.setNumber(10); // iki nokta için
        display.display();

        display.clear();
        display.setNumber(minute / 10);
        display.display();

        display.clear();
        display.setNumber(minute % 10);
        display.display();

        break;
    }

    return 0;
}