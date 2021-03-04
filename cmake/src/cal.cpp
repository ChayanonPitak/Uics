#include <cal.h>

namespace ical {

    // function to get Timestamp (when the function was called) in iCal format.
    str getTstamp() {
        time_t t = time(0);
        tm* now = localtime(&t);
        str Tstamp;
        if ((now->tm_mon + 1) < 10) Tstamp = std::to_string(now->tm_year + 1900) + "0" + std::to_string(now->tm_mon + 1) + std::to_string(now->tm_mday) + "T";
        else Tstamp = std::to_string(now->tm_year + 1900) + std::to_string(now->tm_mon + 1) + std::to_string(now->tm_mday) + "T";
        return Tstamp;
    }

    // function to split string.
    strVector split(str s, char delimeter) {
        strVector sArr;
        str token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimeter)) {
            sArr.push_back(token);
        }
        return sArr;
    }

    str intTostrD2(int val)
    {
        if (val < 10) return "0" + std::to_string(val);
        else return std::to_string(val);
    }

    // function that check the inputs and return Date/Time in iCal format.
    str checkDT(unsigned short hr, unsigned short min, unsigned short sec) {
        return getTstamp() + intTostrD2(hr) + intTostrD2(min) + intTostrD2(sec);
    }
    
    // function that check the inputs and return Date/Time in iCal format.
    str checkDT(str s, int pos) {
        strVector arr = split(s, '-');
        return getTstamp() + arr[pos] + "00";
    }
    

    // function to parse byday to iCal format
    str checkbyday(unsigned int DayBinary) {
        //Binary represend each day.
        //First digit (2^0) represent Monday and increasing to Sunday.
        str Day = "";
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

    // function to parse byday to iCal format **need more work.
    str checkbyday(str s) {
        for (auto & c : s) c = (char) toupper(c);
        if (s == "MTH") return "MO,TH";
        if (s == "TUF") return "FR,TU";
        if (s == "WE") return "WE";
        if (s == "SA") return "SA";
        if (s == "SU") return "SU";
        if (s == "TU") return "TU";
        return "";       
    }


    event::event() {
        weekstop = "SU";
        freq = "WEEKLY";
    }
    // constructor 
    event::event(str WT, str f) {
        weekstop = WT;
        freq = f;
    }

    // parser for with-ocr branch **need more work (make it better or cleaner).
    void event::ocr_parser(str text) {
        str nums, addr, Ename, time, byday;
        std::istringstream iss(text);
        bool flag = 0;

        iss >> nums >> addr;
        for (size_t i = 9; i < (text.size() - 2); i++) {
            Ename += text[i];
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

        time = str(time.rbegin(), time.rend());
        day = str(day.rbegin(), day.rend());
        
        name = Ename + addr;
        day = checkbyday(byday);
        DTstart = checkDT(time, 0);
        DTend = checkDT(time, 1);
    }

    void event::set_exdate(str start, str end) {

    }

    // function to create iCal Header.
    void calHeader(std::ofstream& file, str timezone = "") {
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


    // function to creat iCal event.
    void createEvent(event event, std::ofstream &file) {
        file << "BEGIN:VEVENT" << '\n';
        file << "DTSTART:" << event.DTstart << '\n';
        file << "DTEND:" << event.DTend << '\n';
        file << "EXDATE:" << event.exdate << '\n';
        file << "RRULE:FREQ=" << event.freq << ";WKST=" << event.weekstop << ";UNTIL=" << event.untillD << ";BYDAY=" << event.day << '\n';
        file << "DTSTAMP:" << event.startD << '\n';
        file << "LOCATION:" << event.location << '\n';
        file << "SUMMARY:" << event.name << '\n';
        file << "END:VEVENT" << '\n';
    }

    //
    void saveEvent(std::vector<event> list, std::ofstream &file) {
        file << list.size() << '\n';
        boost::archive::text_oarchive archive(file);
        for (size_t i = 0; i < list.size(); i++) {
            archive << list[i];
        }
    }

    //
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

    //
    void exportEvent(std::vector<event> list, std::ofstream &file) {
        calHeader(file);
        for (size_t i = 0; i < list.size(); i++) {
            createEvent(list[i], file);
        }
        calFooter(file);
    }

    // Function to convert char* to vector<string> by splitting char* on '\\n'
    strVector tostrVector(char * in) {
        strVector text;
        size_t i = 0, j = 0;

        while (in[i] != '\0') {
            if (in[i] == '\n') {
                size_t line_size = &in[i] - &in[j];
                str t = "";
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
    strVector process_Image(const char* imgPath, const char * datapath) {
        char * outText;
        Pix *image  = pixRead(imgPath);
        strVector out;

        tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
        if (api->Init(datapath, "eng")) {
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

    //
    void ocr_to_event(strVector in, std::vector<event> &out) {
        event EVENT;
        for (size_t i = 0; i < in.size(); i++) {
            EVENT.ocr_parser(in[i]);
            out.push_back(EVENT);
        }
    }


} // end namespace ical 
