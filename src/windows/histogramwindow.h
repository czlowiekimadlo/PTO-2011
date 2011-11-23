#ifndef HISTOGRAMWINDOW_H
#define HISTOGRAMWINDOW_H

#define HISTOGRAM_LUMINANCE 0
#define HISTOGRAM_RED 1
#define HISTOGRAM_GREEN 2
#define HISTOGRAM_BLUE 3

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <math.h>
#include <QColor>
#include "../mainwindow.h"

class MainWindow;

namespace Ui {
    class HistogramWindow;
}

class HistogramWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HistogramWindow(MainWindow *parent = 0);
    ~HistogramWindow();

    void refresh();

    MainWindow *mainWindow;
    QImage *image;

private slots:
    void on_modeBox_currentIndexChanged(int index);

private:
    Ui::HistogramWindow *ui;
    int mode;
    QPixmap *plot;

    void drawPlot(int *values);
    int drawLuminance(QRgb colour);
    int drawRed(QRgb colour);
    int drawGreen(QRgb colour);
    int drawBlue(QRgb colour);
};

#endif // HISTOGRAMWINDOW_H
