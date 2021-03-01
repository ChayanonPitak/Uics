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

namespace ical {

    // function to get Timestamp (when the function was called) in iCal format.
    std::string getTstamp(); 

    std::string intTostrD2(int val);
    // function that check the inputs and return Date/Time in iCal format.
    std::string checkDT(unsigned short hr, unsigned short min, unsigned short sec);
    std::string checkDT(std::string s, int pos);

    
    // function to parse byday to iCal format
    std::string checkbyday(unsigned int DayBinary);
    std::string checkbyday(std::string s);


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
            event();
            // constructor 
            event(std::string WT, std::string f);
            
            // parser for with-ocr branch **need more work (make it better or cleaner).
            void ocr_parser(std::string text);

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
    }; //end calendar class

    // function to split string.
    std::vector<std::string> split(std::string s, char delimeter);

    // function to create iCal Header.
    void calHeader(std::ofstream& file, std::string timezone);

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
    std::vector<std::string> tostrVector(char * in); 

    // Function to process img and return vector of string.
    std::vector<std::string> process_Image(const char* imgPath, const char * datapath);

    //
    void ocr_to_event(std::vector<std::string> in, std::vector<event> out);

} // end namespace ical 