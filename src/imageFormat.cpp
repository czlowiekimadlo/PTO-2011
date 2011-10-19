#include "src/imageFormat.h"

ImageFormat::ImageFormat(QString *fileName = NULL) {
    if (fileName != NULL) {
        this->loadFile(fileName);
    }
}
