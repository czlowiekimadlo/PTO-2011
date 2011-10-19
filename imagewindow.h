#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
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
    explicit ImageWindow(MainWindow *parent);
    ~ImageWindow();
    MainWindow *mainWindow;

private:
    Ui::ImageWindow *ui;
};

#endif // IMAGEWINDOW_H
