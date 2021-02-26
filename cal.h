#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#pragma once

namespace ical {
    // function to create iCal Header.
    void calHeader(std::ofstream& file, std::string timezone = "") {
        file << "BEGIN:VCALENDAR" << '\n';
        file << "PRODID:-//Uics Project//Schedule//EN" << '\n';
        file << "VERSION:2.0" << '\n';
        file << "CALSCALE:GREGORIAN" << '\n';
        file << "METHOD:PUBLISH" << '\n';
        file << "BEGIN:VTIMEZONE" << '\n';
        file << "TZID:Asia/Bangkok" << '\n';
        file << "BEGIN:STANDARD" << '\n';
        file << "TZOFFSETFROM:+0700" << '\n';
        file << "TZOFFSETTO:+0700" << '\n';
        file << "TZNAME:+07" << '\n';
        file << "DTSTART:19700101T000000" << '\n';
        file << "END:STANDARD" << '\n';
        file << "END:VTIMEZONE" << '\n';
    }

    // function to create iCal Footer.
    void calFooter(std::ofstream& file) {
        file << "END:VCALENDAR";
    }

    // function to get Timestamp (when the function was called) in iCal format.
    std::string getTstamp() {
        time_t t = time(0);
        tm* now = localtime(&t);
        std::string Tstamp;
        if ((now->tm_mon + 1) < 10) Tstamp = std::to_string(now->tm_year + 1900) + "0" + std::to_string(now->tm_mon + 1) + std::to_string(now->tm_mday) + "T";
        else Tstamp = std::to_string(now->tm_year + 1900) + std::to_string(now->tm_mon + 1) + std::to_string(now->tm_mday) + "T";
        return Tstamp;
    }
    
    std::string intTostrD2(int val)
    {
        if (val < 10) return "0" + std::to_string(val);
        else return std::to_string(val);
    }

    // function that check the inputs and return Date/Time in iCal format.
    std::string checkDT(unsigned short hr, unsigned short min, unsigned short sec) {
        return getTstamp() + intTostrD2(hr) + intTostrD2(min) + intTostrD2(sec);
    }
    

    // function to parse byday to iCal format
    std::string checkbyday(unsigned int DayBinary) {
        //Binary represend each day.
        //First digit (2^0) represent Monday and increasing to Sunday.
        std::string Day = "";
        bool isSeperate = false;
        if (DayBinary & 1) { Day += "MO"; isSeperate = true;}
        DayBinary = DayBinary >> 1;
        if (DayBinary & 1) { if (isSeperate) Day += ","; Day += "TU"; isSeperate = true;}
        DayBinary = DayBinary >> 1;
        if (DayBinary & 1) { if (isSeperate) Day += ","; Day += "WE"; isSeperate = true; }
        DayBinary = DayBinary >> 1;
        if (DayBinary & 1) { if (isSeperate) Day += ","; Day += "TH"; isSeperate = true; }
        DayBinary = DayBinary >> 1;
        if (DayBinary & 1) { if (isSeperate) Day += ","; Day += "FR"; isSeperate = true; }
        DayBinary = DayBinary >> 1;
        if (DayBinary & 1) { if (isSeperate) Day += ","; Day += "SA"; isSeperate = true; }
        DayBinary = DayBinary >> 1;
        if (DayBinary & 1) { if (isSeperate) Day += ","; Day += "SU"; isSeperate = true; }
        DayBinary = DayBinary >> 1;
        return Day;
    }

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
        std::string startD = getTstamp() + "000000";
        
        // default constructor
        event() {
            weekstop = "SU";
            freq = "WEEKLY";
        }
        // constructor 
        event(std::string WT, std::string f) {
            weekstop = WT;
            freq = f;
        }

    private:
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version) {
            ar & freq;
            ar & weekstop;
            ar & name;
            ar & location;
            ar & day;
            ar & DTstart;
            ar & DTend;
            ar & untillD;
            ar & startD;
        }

        // function to split string.
        std::vector<std::string> split(std::string s, char delimeter) {
            std::vector<std::string> sArr;
            std::string token;
            std::istringstream tokenStream(s);
            while (std::getline(tokenStream, token, delimeter)) {
                sArr.push_back(token);
            }
            return sArr;
        }

}; //end calendar class

    // function to creat iCal event.
    void createEvent(event event, std::ofstream &file) {
        file << "BEGIN:VEVENT" << '\n';
        file << "DTSTART:" << event.DTstart << '\n';
        file << "DTEND:" << event.DTend << '\n';
        file << "RRULE:FREQ=" << event.freq << ";WKST=" << event.weekstop << ";UNTIL=" << event.untillD << ";BYDAY=" << event.day << '\n';
        file << "DTSTAMP:" << event.startD << '\n';
        file << "LOCATION:" << event.location << '\n';
        file << "SUMMARY:" << event.name << '\n';
        file << "END:VEVENT" << '\n';
    }

    void saveEvent(std::vector<event> list, std::ofstream &file) {
        file << list.size() << '\n';
        boost::archive::text_oarchive archive(file);
        for (size_t i = 0; i < list.size(); i++) {
            archive << list[i];
        }
    }

    void loadEvent(std::vector<event> &list, std::ifstream &file) {      
        size_t listSize = 0;
        file >> listSize;
        boost::archive::text_iarchive archive(file);
        event EVENT;
        for (size_t i = 0; i < listSize; i++) {
            archive >> EVENT;
            list.push_back(EVENT);
        }
    }

    void exportEvent(std::vector<event> list, std::ofstream &file) {
        calHeader(file);
        for (size_t i = 0; i < list.size(); i++) {
            createEvent(list[i], file);
        }
        calFooter(file);
    }

} // end namespace ical 

