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
}

MainWindow::~MainWindow()
{
    delete ui;
    if (activeImage != NULL) {
        delete activeImage;
    }
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
                    "./image.ppm",
                    tr("Images (*.pbm *.pgm *.ppm);;Portable bitmap (*.pbm);;Portable graymap (*.pgm);;Portable pixmap (*.ppm)")
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
        tr("Images (*.pbm *.pgm *.ppm);;Portable bitmap (*.pbm);;Portable graymap (*.pgm);;Portable pixmap (*.ppm)")
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
