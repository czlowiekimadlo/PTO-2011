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
    MainWindow *mainWindow;
    QImage *primaryImage;
    QImage *secondaryImage;

private:
    void replicateImage();
    Ui::ImageWindow *ui;
    bool saved;
};

#endif // IMAGEWINDOW_H
