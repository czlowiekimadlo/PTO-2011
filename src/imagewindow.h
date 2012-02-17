#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QPixmap>
#include <QImage>
#include <QFileDialog>
#include "mainwindow.h"
#include "formats/imageFormat.h"
#include "formats/pbmformat.h"
#include "formats/pgmformat.h"
#include "formats/ppmformat.h"
#include "formats/jpgformat.h"
#include "formats/cmykformat.h"
#include "windows/histogramwindow.h"

class MainWindow;

namespace Ui {
    class ImageWindow;
}

class ImageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ImageWindow(QWidget *parent = 0);
    explicit ImageWindow(MainWindow *parent, QString fileName = NULL);
    ~ImageWindow();
    void openFile(QString fileName);
    void saveFile(QString fileName);
    void refreshImage();
    void setSaved(bool);
    MainWindow *mainWindow;
    QImage *primaryImage;
    QImage *secondaryImage;

private:
    void replicateImage();
    Ui::ImageWindow *ui;
    bool saved;
};

#endif // IMAGEWINDOW_H
