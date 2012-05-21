#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imagewindow.h"
#include "windows/histogramwindow.h"
#include "windows/historywindow.h"
#include "windows/histogramevendialog.h"
#include "windows/histogramstretchdialog.h"
#include "windows/convolutionlinearwindow.h"
#include "windows/convolutiongaussiandialog.h"
#include "windows/convolutionfreedialog.h"
#include "windows/grayscaledialog.h"
#include "windows/brightnessdialog.h"
#include "windows/contrastdialog.h"
#include "windows/gammadialog.h"
#include "windows/morphologydialog.h"
#include "commands/commandqueue.h"
#include "commands/basecommand.h"
#include "commands/openfilecommand.h"
#include "commands/edgegradientcommand.h"
#include "commands/edgesobelcommand.h"
#include "commands/edgerobertscommand.h"
#include "commands/edgeprewittcommand.h"
#include "commands/edgelaplasiancommand.h"
#include "commands/edgelogcommand.h"
#include "commands/edgedogcommand.h"
#include "commands/edgezeropasscommand.h"
#include "commands/noisemediancommand.h"
#include "commands/binarycommand.h"

class ImageWindow;
class HistogramWindow;
class HistoryWindow;
class CommandQueue;
class OpenFileCommand;
class ConvolutionLinearWindow;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void pushCommand(BaseCommand *);
    void popCommand();
    void flushCommands();
    void refreshImage();
    void refreshImage(int);
    void closeHistogramWindow();

    CommandQueue * commandQueue;
    ImageWindow *activeImage;
    HistogramWindow *histogramWindow;
    HistoryWindow * historyWindow;

public slots:
    void openImageWindow();
    void destroyImageWindow();
    void updateAllWindows();

private slots:
    void on_actionOpenFile_activated();
    void on_actionSaveFile_activated();
    void on_actionShow_histogram_activated();
    void on_actionShow_history_activated();
    void on_actionEven_activated();
    void on_actionStretch_activated();
    void on_actionUndo_triggered();
    void on_actionLinear_triggered();
    void on_actionGaussian_triggered();
    void on_actionFree_triggered();
    void on_actionGrayscale_activated();
    void on_actionBrightness_triggered();
    void on_actionContrast_triggered();
    void on_actionGamma_triggered();
    void on_actionGradient_triggered();
    void on_actionSobel_triggered();
    void on_actionRoberts_triggered();
    void on_actionPrevitt_triggered();
    void on_actionLaplasian_triggered();
    void on_actionLoG_triggered();
    void on_actionDoG_triggered();
    void on_actionZero_pass_triggered();
    void on_actionMedian_triggered();
    void on_actionMorphology_triggered();
    void on_actionBinary_triggered();

private:
    Ui::MainWindow *ui;

    void openHistogramWindow();
    void updateHistogramWindow();
    void openHistoryWindow();
    void openHistogramEvenDialog();
    void openHisgotramStretchDialog();

};

#endif // MAINWINDOW_H
