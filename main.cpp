#include <fstream>
#include <cal.h>


int main() {
    // Testing driver code below
    std::ofstream file("calendar.ics", std::ios::app);   
    ical::calendar Event;
    Event.calHeader(file);
    Event.timezone = "Asia/Bangkok";
    Event.weekstop = "SU";
    Event.freq = "WEEKLY";
    Event.untillD = "20210228T000000Z";
    Event.createEvent(file, "TEST,Sa,09:30-11:00,somewhere"); // the second parameter is in this [Eventname,Day,Time frame,Location] format.
    Event.calFooter(file);
}
