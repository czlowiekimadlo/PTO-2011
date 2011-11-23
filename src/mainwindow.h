#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imagewindow.h"
#include "windows/histogramwindow.h"

class ImageWindow;
class HistogramWindow;

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

    HistogramWindow *histogramWindow;

public slots:
    void openImageWindow();
    void destroyImageWindow();

    void updateAllWindows();

private slots:
    void on_actionOpenFile_activated();
    void on_actionSaveFile_activated();
    void on_actionShow_histogram_activated();

private:
    Ui::MainWindow *ui;

    void openHistogramWindow();
    void updateHistogramWindow();

};

#endif // MAINWINDOW_H
