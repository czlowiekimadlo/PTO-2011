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

    //connect(ui->actionTest, SIGNAL(activated()), this, SLOT(openImageWindow()));
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
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "./",
        tr("Images (*.pbm *.pgm *.ppm);;Portable bitmap (*.pbm);;Portable graymap (*.pgm);;Portable pixmap (*.ppm)")
    );
    if (fileName != NULL) {
        QImage imageObject;
        imageObject.load(fileName);
        ui->label->setPixmap(QPixmap::fromImage(imageObject));
    }
}

void MainWindow::on_actionSaveFile_activated()
{
    const QPixmap * image = ui->label->pixmap();
    if (image == 0) {
        QMessageBox::warning ( this, "Save error", "Image data is empty.");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Save File"),
        "./image.ppm",
        tr("Images (*.pbm *.pgm *.ppm);;Portable bitmap (*.pbm);;Portable graymap (*.pgm);;Portable pixmap (*.ppm)")
    );

    if (fileName != NULL) {
        if (fileName.endsWith(".pbm")) {
            image->save(fileName, "PBM");
        }
        else if (fileName.endsWith(".pgm")) {
            image->save(fileName, "PGM");
        }
        else if (fileName.endsWith(".ppm")) {
            image->save(fileName, "PPM");
        }
        else {
            QMessageBox::warning ( this, "Save error", "Unsupported file format.");
        }
    }
}

void MainWindow::openImageWindow() {
    this->destroyImageWindow();
    activeImage = new ImageWindow(this);
    activeImage->setAttribute(Qt::WA_DeleteOnClose, true);
    activeImage->show();
}

void MainWindow::destroyImageWindow() {
    if (activeImage != NULL) {
        delete activeImage;
        activeImage = NULL;
    }
}
