#include <fstream>
#include <cal.h>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

int main() {
    // Testing driver code below
    using namespace std;
    vector<ical::event> lists;
    ical::event EVENT;

    /*
    for (size_t i = 0; i < 5; i++) {
        EVENT.subjectName = to_string(i);
        lists.push_back(EVENT);
    }
    ofstream ofs("../test");

    ical::saveEvent(lists, ofs);
    */

    ifstream ifs("../test");

    ical::loadEvent(lists, ifs);

    for (size_t i = 0; i < lists.size(); i++) {
        cout << lists[i].name << " ";
    } 


    return 0;
}
