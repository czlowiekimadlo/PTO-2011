#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    activeImage = NULL;
    histogramWindow = NULL;
    //this->setAttribute(Qt::WA_DeleteOnClose, true);
}

MainWindow::~MainWindow()
{
    //this->destroyImageWindow();

    if (activeImage != NULL)
    {
        delete activeImage;
    }
    if (histogramWindow != NULL)
    {
        delete histogramWindow;
    }
    delete ui;
}

void MainWindow::on_actionOpenFile_activated()
{
    this->openImageWindow();
}

void MainWindow::on_actionSaveFile_activated()
{
    QString fileName;

    if (activeImage != NULL) {
        fileName = QFileDialog::getSaveFileName(
                    this,
                    tr("Save File"),
                    "./image.jpg",
                    tr("Images (*.pbm *.pgm *.ppm *.jpg *.jpeg);;JPEG (*.jpeg *.jpg);;Portable bitmap (*.pbm);;Portable graymap (*.pgm);;Portable pixmap (*.ppm)")
                );

        if (fileName != NULL) {
            activeImage->saveFile(fileName);
        }
    }
    else {
        QMessageBox::warning ( this, "Save error", "There is no image to save.");
    }

}

void MainWindow::openImageWindow() {
    this->destroyImageWindow();

    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "./",
        tr("Images (*.pbm *.pgm *.ppm *.jpg *.jpeg);;JPEG (*.jpeg *.jpg);;Portable bitmap (*.pbm);;Portable graymap (*.pgm);;Portable pixmap (*.ppm)")
    );

    if (fileName != NULL) {
        activeImage = new ImageWindow(this, fileName);
        activeImage->setAttribute(Qt::WA_DeleteOnClose, true);
        activeImage->openFile(fileName);
        activeImage->setWindowTitle(fileName);
        activeImage->show();
    }
}

void MainWindow::destroyImageWindow() {
    if (activeImage != NULL) {
        delete activeImage;
        activeImage = NULL;
    }
}

void MainWindow::on_actionShow_histogram_activated()
{
    this->openHistogramWindow();
}

void MainWindow::updateAllWindows()
{
    this->updateHistogramWindow();
}

void MainWindow::openHistogramWindow()
{
    if (activeImage == NULL) {
        QMessageBox::warning ( this, "Histogram error", "There is no image.");
        return;
    }

    if (histogramWindow == NULL)
    {
        histogramWindow = new HistogramWindow(this);
        histogramWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        histogramWindow->setWindowTitle("Image histogram");
        this->updateHistogramWindow();
        histogramWindow->show();
    }
}

void MainWindow::updateHistogramWindow()
{
    if (histogramWindow != NULL && activeImage != NULL)
    {
        histogramWindow->image = activeImage->primaryImage;
        histogramWindow->refresh();
    }
}


