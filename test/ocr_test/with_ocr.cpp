#include <fstream>
#include <cal.h>

int main() {

    std::cout << "HEKKI WORLD";
    
    // this is just a testing code
    std::ofstream file("../calender.ics", std::ios::app);
    if (!file) std::cout << "ERROR OPENING FILE FOR OUTPUT\n";
    
    ical::calendar Event("Asia/Bangkok", "SU", "WEEKLY");
    ical::image_process proc;
    Event.calHeader(file);
    Event.untillD = "20210228T000000Z";
    proc.img_events(file, "/Projects/cpp/CPEPROJECT/Uics/test/ocr_test/images/a.tif", Event);   
    Event.calFooter(file);
    
    return 0;
}
