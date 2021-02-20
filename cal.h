#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#pragma once

namespace ical {

    class calendar {

    public:
        std::string timezone, DTSTART, DTEND, freq, weekstop, untillD, byday, location, Ename;
        // this is for testing purpose only need REAL UUID generator.
        std::string UUID = "53688870-6D46-11EB-8572-0800200C9A66";

        // function to creat iCal event.

        void createEvent(std::ofstream& file, std::string name, std::string location,unsigned int DayBinary, unsigned short StartHr, unsigned short StartMin, unsigned short StartSec, unsigned short EndHr, unsigned short EndMin, unsigned int EndSec) {
            file << "BEGIN:VEVENT" << '\n';
            file << "DTSTART:" << checkDT(StartHr, StartMin, StartSec) << '\n';
            file << "DTEND:" << checkDT(EndHr, EndMin, EndSec) << '\n';
            file << "RRULE:FREQ=" << freq << ";WKST=" << weekstop << ";UNTIL=" << untillD << ";BYDAY=" << checkbyday(DayBinary) << '\n';
            file << "DTSTAMP:" << getTstamp() + "000000" << '\n';
            file << "UID:" << UUID << '\n';
            file << "LOCATION:" << location << '\n';
            file << "SUMMARY:" << name << '\n';
            file << "END:VEVENT" << '\n';

        }

        // function to create iCal Header.
        void calHeader(std::ofstream& file) {
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

    private:
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

        // function to get Timestamp (when the function was called) in iCal format.
        std::string getTstamp() {
            time_t t = time(0);
            tm* now = localtime(&t);
            std::string Tstamp;
            if ((now->tm_mon + 1) < 10) Tstamp = std::to_string(now->tm_year + 1900) + "0" + std::to_string(now->tm_mon + 1) + std::to_string(now->tm_mday) + "T";
            else Tstamp = std::to_string(now->tm_year + 1900) + std::to_string(now->tm_mon + 1) + std::to_string(now->tm_mday) + "T";
            return Tstamp;
        }

        // function that check the inputs and return Date/Time in iCal format.
        std::string checkDT(unsigned short hr, unsigned short min, unsigned short sec) {
            return getTstamp() + intTostrD2(hr) + intTostrD2(min) + intTostrD2(sec);
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

        std::string intTostrD2(int val)
        {
            if (val < 10) return "0" + std::to_string(val);
            else return std::to_string(val);
        }
    };

} // end namespace ical 