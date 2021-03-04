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
    str checkbyday(str s);


    class event {

        public:
            str freq;
            str weekstop;
            str name;
            str location;
            str day;
            str DTstart;
            str DTend;
            str untillD;
            str exdate;
            str startD = getTstamp() + "000000";
            
            // default constructor
            event();

            // constructor 
            event(str WT, str f);
            
            // parser for with-ocr branch **need more work (make it better or cleaner).
            void ocr_parser(str text);

            //
            void set_exdate(str start, str end);

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
                ar & exdate;
                ar & startD;
            }
    }; //end event class

    // function to split string.
    strVector split(str s, char delimeter);

    // function to create iCal Header.
    void calHeader(std::ofstream& file, str timezone);

    // function to create iCal Footer.
    void calFooter(std::ofstream& file);

    // function to creat iCal event.
    void createEvent(event event, std::ofstream &file);
    
    //
    void saveEvent(std::vector<event> list, std::ofstream &file);
    
    //
    void loadEvent(std::vector<event> &list, std::ifstream &file);
    
    //
    void exportEvent(std::vector<event> list, std::ofstream &file);

    // Function to convert char* to vector<string> by splitting char* on '\\n'
    strVector tostrVector(char *in); 

    // Function to process img and return vector of string.
    strVector process_Image(const char *imgPath, const char *datapath);

    //
    void ocr_to_event(strVector in, std::vector<event> &out);

} // end namespace ical 