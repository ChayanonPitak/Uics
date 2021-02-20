#include <fstream>
#include <cal.h>
#include <tesseract/baseapi.h>
#include <allheaders.h>

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

int main() {
    
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    if (api->Init("/Projects/cpp/CPEPROJECT/Uics/tessdata", "eng")) {
        std::cout << "Could not initialize tesseract.\n";
        exit(1);
    }

    // get a.tif from team to test
    Pix *image  = pixRead("/Projects/cpp/CPEPROJECT/Uics/images/a.tif");
    api->SetImage(image);
    
    char * outText;
    outText = api->GetUTF8Text();

    std::vector<std::string> texts = tostrVector(outText);
    //for (std::string text:texts) std::cout << text << '\n';
    

    // testing code
    std::ofstream file("../calender.ics", std::ios::app);
    if (!file) std::cout << "ERROR OPENING FILE FOR OUTPUT\n";
    ical::calendar Event("Asia/Bangkok", "SU", "WEEKLY");
    Event.calHeader(file);
    Event.untillD = "20210228T000000Z";
    Event.createEvent(file, texts[0], 1); // testing first line on image.
    Event.calFooter(file);
    
    delete [] outText;
    api->End();
    delete api;
    pixDestroy(&image);
    
    return 0;

}
