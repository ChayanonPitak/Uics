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
        void createEvent(std::ofstream& file, std::string s) {
            parseInfo(s);
            file << "BEGIN:VEVENT" << '\n';
            file << "DTSTART:" << DTSTART << '\n';
            file << "DTEND:" << DTEND << '\n';
            file << "RRULE:FREQ=" << freq << ";WKST=" << weekstop << ";UNTIL=" << untillD << ";BYDAY=" << byday << '\n';
            file << "DTSTAMP:" << getTstamp() + "000000" << '\n';
            file << "UID:" << UUID << '\n';
            file << "LOCATION:" << location << '\n';
            file << "SUMMARY:" << Ename << '\n';
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

        // function to parse info from string and assign it to object.
        void parseInfo(std::string s) {
            std::vector<std::string> sArr = split(s, ',');
            Ename = sArr[0];
            byday = checkbyday(sArr[1]);
            DTSTART = checkDT(sArr[2], 0);
            DTEND = checkDT(sArr[2], 1);
            location = sArr[3];
        }

        // function to parse byday to iCal format **need more work.
        std::string checkbyday(std::string s) {
            if (s == "Mth") return "MO,TH";
            if (s == "TuF") return "FR,TU";
            if (s == "We") return "WE";
            if (s == "Sa") return "SA";
            if (s == "Su") return "SU";
            return "";
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
        std::string checkDT(std::string s, int pos) {
            std::vector<std::string> arr = split(s, '-');
            return getTstamp() + arr[pos].erase(arr[pos].find(':'), 1) + "00";
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
    };

} // end namespace ical 