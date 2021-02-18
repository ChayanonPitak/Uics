#include <fstream>
#include <cal.h>
#include <tesseract/baseapi.h>
#include <allheaders.h>

int main() {
    char *outText;
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    if (api->Init("/Projects/cpp/CPEPROJECT/Uics/tessdata", "eng")) {
        std::cout << "Could not initialize tesseract.\n";
        exit(1);
    }

    Pix *image  = pixRead("/Projects/cpp/CPEPROJECT/Uics/Untitled.png");
    api->SetImage(image);
    outText = api->GetUTF8Text();
    std::cout << "OCR output:\n" << outText;
    api->End();
    delete api;
    delete [] outText;
    pixDestroy(&image);

    return 0;
}
