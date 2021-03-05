#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#pragma once

namespace ical {
    //Functions
    void calHeader(std::ofstream& file, std::string timezone);
    void calFooter(std::ofstream& file);
    std::string getTstamp();
    std::string intTostrD2(int val);
    std::string checkDT(unsigned short hr, unsigned short min, unsigned short sec);
    std::string checkbyday(unsigned int DayBinary);

class event {
    public:
        std::string freq;
        std::string weekstop;
        std::string name;
        std::string location;
        std::string day;
        std::string DTstart;
        std::string DTend;
        std::string untillD;
        std::string startD;
        
        // Constructor
        event();
        event(std::string WT, std::string f);

    private:
        //Functions
        std::vector<std::string> split(std::string s, char delimeter);

}; //end calendar class

    //Function
    void createEvent(std::ofstream& file, event event);
}

