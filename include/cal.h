#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <tesseract/baseapi.h>
#include <allheaders.h>

typedef std::string str;
typedef std::vector<std::string> strVector;

namespace ical {

    // function to get Timestamp (when the function was called) in iCal format.
    str getTstamp(); 

    str intTostrD2(int val);
    // function that check the inputs and return Date/Time in iCal format.
    str checkDT(unsigned short hr, unsigned short min, unsigned short sec);
    str checkDT(str s, int pos);
   
    // function to parse byday to iCal format
    str checkbyday(unsigned int DayBinary);
    bool checkbyday(unsigned int DayBinary, unsigned short Day);
    str checkbyday(str s);

    // ultilty fucntion
    int modifyBit(int n, int p, int b);


    class event {

        public:
            str freq;
            str weekstop;
            str subjectName;
            str subjectID;
            str location;
            str day;
            unsigned int dayBinary;
            str DTstart;
            str DTend;
            str exdate;
            str startD = getTstamp() + "000000"; // this should has DTstamp name, I fucked up
            str untillD;
            str note;

            // default constructor
            event();

            // constructor 
            event(str WT, str f);
            
            // parser for with-ocr branch **need more work (make it better or cleaner).
            void ocr_parser(str text);

            void reset_exdate();

            void set_exdate(str start, str end);

            void append_exdate(str date);

            void set_range(str start, str end);

            void set_DT(str start, str end);

            void set_D(str date);

            str get_D();

            str get_startTime();

            str get_endTime();

            void set_dayBinary();

        private:
            friend class boost::serialization::access;
            template<class Archive>
            void serialize(Archive & ar, const unsigned int version) {
                ar & freq;
                ar & weekstop;
                ar & subjectName;
                ar & subjectID;
                ar & location;
                ar & day;
                ar & DTstart;
                ar & DTend;
                ar & untillD;
                ar & exdate;
                ar & startD;
                ar & note;
            }
    }; //end event class

    // function to set exam period for event obj
    bool Is_inarr(str in, strVector arr);
    str exdate(str start, str end);

    // function to split string.
    strVector split(str s, char delimeter);

    // function to create iCal Header.
    void calHeader(std::ofstream& file, str timezone = "");

    // function to create iCal Footer.
    void calFooter(std::ofstream& file);

    // function to creat iCal event.
    void createEvent(const event event, std::ofstream &file);
    
    //
    void saveEvent(std::vector<event> list, std::ofstream &file);
    
    //
    void loadEvent(std::vector<event> &list, std::ifstream &file);
    
    //
    void exportEvent(std::vector<event> list, std::ofstream &file);

    // Function to convert char* to vector<string> by splitting char* on '\\n'
    strVector tostrVector(char *&in); 

    // Function to process img and return vector of string.
    strVector process_Image(const char *imgPath, const char *datapath = "..\\resources\\tessdata");

    //
    bool ocr_to_event(strVector in, std::vector<event> &out);

} // end namespace ical 