#ifndef HISTOGRAMSTRETCHDIALOG_H
#define HISTOGRAMSTRETCHDIALOG_H

#include <QDialog>
#include "../mainwindow.h"
#include "../commands/histogramstretchcommand.h"

namespace Ui {
    class HistogramStretchDialog;
}

class HistogramStretchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistogramStretchDialog(MainWindow *parent = 0);
    ~HistogramStretchDialog();

    MainWindow *mainwindow;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::HistogramStretchDialog *ui;
};

#endif // HISTOGRAMSTRETCHDIALOG_H
