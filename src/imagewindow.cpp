#include "imagewindow.h"
#include "ui_imagewindow.h"
#include "formats/imageFormat.h"
#include "formats/pbmformat.h"
#include "formats/pgmformat.h"
#include "formats/ppmformat.h"

ImageWindow::ImageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);
}

ImageWindow::ImageWindow(MainWindow *parent, QString fileName) :
    QWidget(0),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);
    this->mainWindow = parent;
    this->primaryImage = NULL;
    this->secondaryImage = NULL;
    this->saved = true;
}

ImageWindow::~ImageWindow()
{
    int status;
    QString fileName;

    if (!this->saved) {
        status = QMessageBox::information(this, "Unsaved image", "You have unsaved changes. Save now?", "Save", "Cancel", QString::null, 0, 1);
        if (status == 0) {
            fileName = QFileDialog::getSaveFileName(
                        this,
                        tr("Save File"),
                        "./image.ppm",
                        tr("Images (*.pbm *.pgm *.ppm);;Portable bitmap (*.pbm);;Portable graymap (*.pgm);;Portable pixmap (*.ppm)")
                    );
            if (fileName != NULL) {
                this->saveFile(fileName);
            }
        }
    }

    delete ui;
    this->mainWindow->activeImage = NULL;
    if (this->primaryImage != NULL) delete this->primaryImage;
    if (this->secondaryImage != NULL) delete this->secondaryImage;
}

void ImageWindow::openFile(QString fileName) {
    ImageFormat *format;

    if (fileName != NULL) {
        if (fileName.endsWith(".pbm")) {
            format = new PBMFormat();
        }
        else if (fileName.endsWith(".pgm")) {
            format = new PGMFormat();
        }
        else if (fileName.endsWith(".ppm")) {
            format = new PPMFormat();
        }
        else {
            QMessageBox::warning ( this, "Save error", "Unsupported file format.");
            return;
        }

        //QMessageBox::warning ( this, "Info", "Loading file.");
        try {
            if (this->primaryImage != NULL) delete this->primaryImage;
            this->primaryImage = NULL;

            this->primaryImage = format->loadFile(fileName);
            this->replicateImage();

            this->setFixedSize(this->primaryImage->width(), this->primaryImage->height());

            ui->label->setPixmap(QPixmap::fromImage(*this->primaryImage));
        }
        catch (...) {
            QMessageBox::warning ( this, "Open error", "Error while opening file.");
            this->close();
        }

        delete format;
    }
}

void ImageWindow::saveFile(QString fileName) {
    this->saved = true;
    QMessageBox::warning ( this, "Save error", "Not yet implemented.");
}

void ImageWindow::replicateImage() {

}
