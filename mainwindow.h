#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imagewindow.h"

class ImageWindow;

namespace Ui {
    class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ImageWindow *activeImage;

public slots:
    void openImageWindow();
    void destroyImageWindow();

private slots:
    void on_actionOpenFile_activated();

    void on_actionSaveFile_activated();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
