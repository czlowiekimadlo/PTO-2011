#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imagewindow.h"
#include "windows/histogramwindow.h"
#include "windows/historywindow.h"
#include "windows/histogramevendialog.h"
#include "commands/commandqueue.h"
#include "commands/basecommand.h"
#include "commands/openfilecommand.h"

class ImageWindow;
class HistogramWindow;
class HistoryWindow;
class CommandQueue;
class OpenFileCommand;

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

private:
    Ui::MainWindow *ui;

    void openHistogramWindow();
    void updateHistogramWindow();
    void openHistoryWindow();
    void openHistogramEvenDialog();

};

#endif // MAINWINDOW_H
