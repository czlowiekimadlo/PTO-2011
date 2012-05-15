#include "imagewindow.h"
#include "ui_imagewindow.h"

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
                        "./image.jpg",
                        tr("Images (*.pbm *.pgm *.ppm *.jpg *.jpeg);;JPEG (*.jpeg *.jpg);;Portable bitmap (*.pbm);;Portable graymap (*.pgm);;Portable pixmap (*.ppm)")
                    );
            if (fileName != NULL) {
                this->saveFile(fileName);
            }
        }
    }

    delete ui;
    this->mainWindow->flushCommands();
    this->mainWindow->closeHistogramWindow();
    this->mainWindow->activeImage = NULL;
    if (this->primaryImage != NULL) delete this->primaryImage;
    if (this->secondaryImage != NULL) delete this->secondaryImage;
}

void ImageWindow::openFile(QString fileName) {
    ImageFormat *format = NULL;

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
        else if (fileName.endsWith(".jpg") || fileName.endsWith(".jpeg")) {
            format = new JPGFormat();
        }
        else if (fileName.endsWith(".cmyk")) {
            format = new CMYKFormat();
        }
        else {
            QMessageBox::warning ( this, "Open error", "Unsupported file format.");
            return;
        }

        if (format == NULL) {
            return;
        }

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
    ImageFormat *format;

    if (this->primaryImage == NULL) {
        QMessageBox::warning ( this, "Save error", "No image to save.");
        return;
    }

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
        else if (fileName.endsWith(".cmyk")) {
            format = new CMYKFormat();
        }
        else if (fileName.endsWith(".jpg") || fileName.endsWith(".jpeg")) {
            format = new JPGFormat();
        }
        else {
            QMessageBox::warning ( this, "Save error", "Unsupported file format.");
            return;
        }

        try {
            format->saveFile(fileName, this->primaryImage);
            this->saved = true;
        }
        catch (...) {
            QMessageBox::warning ( this, "Save error", "Error while saving file.");
        }
        delete format;
    }
}

void ImageWindow::replicateImage() {
    this->secondaryImage = new QImage(*this->primaryImage);
}

void ImageWindow::refreshImage()
{
    ui->label->setPixmap(QPixmap::fromImage(*this->primaryImage));
}

void ImageWindow::setSaved(bool status)
{
    this->saved = status;
}
