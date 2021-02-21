#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <tesseract/baseapi.h>
#include <allheaders.h>
#pragma once

namespace ical {

class calendar {
    public:
        std::string timezone, DTSTART, DTEND, freq, weekstop, untillD, byday, location, Ename;
        
        // Default constructor
        calendar();
        // Constructor
        calendar(std::string TZ, std::string WT, std::string f) {
            timezone = TZ;
            weekstop = WT;
            freq = f;
        }

        // function to creat iCal event. (filename, [Eventname,Day,Time frame,Location])
        void createEvent(std::ofstream &file, std::string s, int mode = 0) {   
            if (mode == 0) parseInfo(s);
            if (mode == 1) ocr_parser(s);
            file << "BEGIN:VEVENT" << '\n';
            file << "DTSTART:" << DTSTART << '\n';
            file << "DTEND:" << DTEND << '\n';
            file << "RRULE:FREQ=" << freq << ";WKST=" << weekstop << ";UNTIL=" << untillD << ";BYDAY=" << byday << '\n';
            file << "DTSTAMP:" << getTstamp() + "000000" << '\n';
            file << "LOCATION:" << location << '\n';
            file << "SUMMARY:" << Ename << '\n';
            file << "END:VEVENT" << '\n';

        }
        
        // function to create iCal Header.
        void calHeader(std::ofstream &file) {
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
        void calFooter(std::ofstream &file) {
            file << "END:VCALENDAR";
        }

    private:       
        // parser for with-ocr branch **need more work (make it better or cleaner).
        void ocr_parser(std::string text) {
            std::string nums, addr, name, time, day;
            std::istringstream iss(text);
            bool flag = 0;

            iss >> nums >> addr;
            for (size_t i = 9; i < (text.size() - 2); i++) {
                name += text[i];
                if (text[i+2] == '.') break;     
            }

            for (size_t i = (text.size()-1); i > 0; i--) {
                if (text[i] == ' ') {
                    if (flag == 1) break;
                    if (i != text.size()-1) flag = 1;
                }
                if (flag == 0) {
                    if (text[i] != ' ') time += text[i];
                }
                if (flag == 1) {
                    if (text[i] != ' ') day += text[i];
                }
            }
            time = std::string(time.rbegin(), time.rend());
            day = std::string(day.rbegin(), day.rend());
            
            Ename = name + addr;
            byday = checkbyday(day);
            DTSTART = checkDT(time, 0);
            DTEND = checkDT(time, 1);
        }


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
            for (auto & c : s) c = (char) toupper(c);
            if (s == "MTH") return "MO,TH";
            if (s == "TUF") return "FR,TU";
            if (s == "WE") return "WE";
            if (s == "SA") return "SA";
            if (s == "SU") return "SU";
            if (s == "TU") return "TU";
            return "";       
        }

        // function to get Timestamp (when the function was called) in iCal format.
        std::string getTstamp() {
            time_t t = time(0);
            tm* now = localtime(&t);
            std::string Tstamp;
            if ((now->tm_mon+1) < 10) Tstamp = std::to_string(now->tm_year+1900) + "0" + std::to_string(now->tm_mon+1) + std::to_string(now->tm_mday) + "T";
            else Tstamp = std::to_string(now->tm_year+1900) + std::to_string(now->tm_mon+1) + std::to_string(now->tm_mday) + "T";
            return Tstamp;
        }

        // function that check the inputs and return Date/Time in iCal format.
        std::string checkDT(std::string s, int pos) {
            std::vector<std::string> arr = split(s, '-');
            return getTstamp() + arr[pos] + "00";
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

// all this shit could be cleaner and better.
class image_process {
    public:
        // Function to convert char* to vector<string> by splitting char* on '\\n'
        std::vector<std::string> tostrVector(char * in) {
            std::vector<std::string> text;
            size_t i = 0, j = 0;

            while (in[i] != '\0') {
                if (in[i] == '\n') {
                    size_t line_size = &in[i] - &in[j];
                    std::string t = "";
                    // this work but there are overflow in this j-1 when j = 0, maybe need a better way to write this.
                    for (size_t a = j; a < line_size + (j-1); a++) t.push_back(in[a]);
                    text.push_back(t);
                    j = i+1;
                }
                i++;
            }

            return text;
        }

        // Function to process img and return vector of string.
        std::vector<std::string> process_Image(const char* imgPath) {
            char * outText;
            Pix *image  = pixRead(imgPath);
            std::vector<std::string> out;

            tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
            if (api->Init("/Projects/cpp/CPEPROJECT/Uics/tessdata", "eng")) {
                std::cout << "Could not initialize tesseract.\n";
                exit(1);
            }

            api->SetImage(image);
            outText = api->GetUTF8Text();
            out = tostrVector(outText);

            delete [] outText;
            api->End();
            delete api;
            pixDestroy(&image);

            return out;
        }

        // simple func to create event using vector of process_image()
        void img_events(std::ofstream &file, const char* imgPath, calendar obj) {
            std::vector<std::string> in = process_Image(imgPath);
            for (size_t i = 0; i < in.size(); i++) {   
                obj.createEvent(file, in[i], 1);
            }
        }

};

} // end namespace ical 