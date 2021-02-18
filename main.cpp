#include <fstream>
#include <cal.h>
#include <tesseract/baseapi.h>
#include <allheaders.h>

int main() {
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    if (api->Init("/Projects/cpp/CPEPROJECT/Uics/tessdata", "eng+tha")) {
        std::cout << "Could not initialize tesseract.\n";
        exit(1);
    }

    Pix *image  = pixRead("/Projects/cpp/CPEPROJECT/Uics/images/1.png");
    
    api->SetImage(image);
    
    char * outText;
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);


    api->End();
    delete api;
    pixDestroy(&image);

    return 0;
}
