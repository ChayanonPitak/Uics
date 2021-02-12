#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
using namespace std; 

class calEvent {
    public:
        string timezone, DTSTART, DTEND, freq, weekstop, untillD, byday, location, Ename;
        // this is for testing purpose only need REAL UUID generator.
        string UUID = "53688870-6D46-11EB-8572-0800200C9A66";

        void createEvent(ofstream &file, string s) {   
            parseInfo(s);
            file << "BEGIN:VEVENT" << '\n';
            file << "DTSTART; TZID=" << timezone << ":" << DTSTART << '\n';
            file << "DTEND; TZID=" << timezone << ":" << DTEND << '\n';
            file << "RRULE:FREQ=" << freq << ";WKST=" << weekstop << ";UNTIL=" << untillD << ";BYDAY=" << byday << '\n';
            file << "DTSTAMP:" << getTstamp() + "000000" << '\n';
            file << "UID:" << UUID << '\n';
            file << "LOCATION:" << location << '\n';
            file << "SUMMARY:" << Ename << '\n';
            file << "END:VEVENT" << '\n';

        }

    private:
        void parseInfo(string s) {
            vector<string> sArr = split(s, ','); 
            Ename = sArr[0];
            byday = checkbyday(sArr[1]);
            DTSTART = checkDT(sArr[2], 0);
            DTEND = checkDT(sArr[2], 1);
            location = sArr[3];
        }
     
        string checkbyday(string s) {
            if (s == "Mth") return "MO,TH";
            if (s == "TuF") return "FR,TU";
            if (s == "We") return "WE";
            if (s == "Sa") return "SA";
            if (s == "Su") return "SU";
            return "";       
        }

        string getTstamp() {
            time_t t = time(0);
            tm* now = localtime(&t);
            string Tstamp;
            if ((now->tm_mon+1) < 10) Tstamp = to_string(now->tm_year+1900) + "0" + to_string(now->tm_mon+1) + to_string(now->tm_mday) + "T";
            else Tstamp = to_string(now->tm_year+1900) + to_string(now->tm_mon+1) + to_string(now->tm_mday) + "T";
            return Tstamp;
        }

        string checkDT(string s, int pos) {
            vector<string> arr = split(s, '-');
            time_t t = time(0);

            return getTstamp() + arr[pos].erase(arr[pos].find(':'), 1) + "00";
        }

        vector<string> split(string s, char delimeter) {
            vector<string> sArr;
            string token;
            istringstream tokenStream(s);
            while (getline(tokenStream, token, delimeter)) {
                sArr.push_back(token);
            }
            return sArr; 
        }
};


void calHeader(ofstream &file) {
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

void calFooter(ofstream &file) {
    file << "END:VCALENDAR";
}


int main() {
    ofstream file("calendar.ics", ios::app);   
    calEvent Event;
    calHeader(file);

    Event.timezone = "Asia/Bangkok";
    Event.weekstop = "SU";
    Event.freq = "WEEKLY";
    Event.untillD = "20210228T000000Z";
    Event.createEvent(file, "TEST,Sa,09:30-11:00,somewhere");

    calFooter(file);
}