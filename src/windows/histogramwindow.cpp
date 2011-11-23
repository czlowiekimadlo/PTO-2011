#include "histogramwindow.h"
#include "ui_histogramwindow.h"
#include <iostream>

HistogramWindow::HistogramWindow(MainWindow *parent) :
    QWidget(0),
    ui(new Ui::HistogramWindow)
{
    ui->setupUi(this);
    this->mainWindow = parent;
    this->mode = HISTOGRAM_LUMINANCE;
    this->image = NULL;
    this->plot = new QPixmap(256, 200);
}

HistogramWindow::~HistogramWindow()
{
    delete ui;
    this->mainWindow->histogramWindow = NULL;
}

void HistogramWindow::refresh()
{
    int x,y;
    int value;
    QRgb colour;
    int values[256];
    for (int i = 0; i < 256; i++) values[i] = 0;

    this->plot->fill(Qt::white);

    if (this->image != NULL)
    {
        x = this->image->width();
        y = this->image->height();

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                colour = this->image->pixel(i,j);

                switch (this->mode)
                {
                case HISTOGRAM_LUMINANCE:
                    value = this->drawLuminance(colour);
                    break;

                case HISTOGRAM_RED:
                    value = this->drawRed(colour);
                    break;

                case HISTOGRAM_GREEN:
                    value = this->drawGreen(colour);
                    break;

                case HISTOGRAM_BLUE:
                    value = this->drawBlue(colour);
                    break;
                }

                values[value]++;
            }
        }

        this->drawPlot(values);
    }

    this->ui->label->setPixmap(*this->plot);
}

void HistogramWindow::drawPlot(int *values)
{
    double scale;
    int max;
    QImage *tmpImage = new QImage(this->plot->size(), QImage::Format_RGB32);
    QColor white;
    QColor black;

    //setup colors
    white.setNamedColor("#FFF");
    black.setNamedColor("#000");

    tmpImage->fill(white.rgb());

    max = values[0];
    for (int i = 1; i < 256; i++)
    {
        if (values[i] > max) max = values[i];
    }

    scale = 200.0 / (double)max;

    for (int i = 0; i < 256; i++)
    {
        max = round(values[i] * scale);
        if (max > 200) max = 200;
        for (int j = 200 - max; j < 200; j++)
        {
            tmpImage->setPixel(i,j,black.rgb());
        }
    }

    if (!this->plot->convertFromImage(*tmpImage))
    {
        std::cout << "ups..." << std::endl;
    }

    delete tmpImage;
}

int HistogramWindow::drawLuminance(QRgb colour)
{
    int luminance;
    luminance = round(0.299 * qRed(colour) + 0.587 * qGreen(colour) + 0.114 * qBlue(colour));
    if (luminance > 255) luminance = 255;
    return luminance;
}

int HistogramWindow::drawRed(QRgb colour)
{
    return qRed(colour);
}

int HistogramWindow::drawGreen(QRgb colour)
{
    return qGreen(colour);
}

int HistogramWindow::drawBlue(QRgb colour)
{
    return qBlue(colour);
}

void HistogramWindow::on_modeBox_currentIndexChanged(int index)
{
    this->mode = index;
    this->refresh();
}
