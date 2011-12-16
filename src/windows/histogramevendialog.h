#ifndef HISTOGRAMEVENDIALOG_H
#define HISTOGRAMEVENDIALOG_H

#include <QDialog>
#include "../mainwindow.h"
#include "../commands/histogramevencommand.h"

namespace Ui {
    class HistogramEvenDialog;
}

class HistogramEvenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistogramEvenDialog(MainWindow *parent = 0);
    ~HistogramEvenDialog();

    MainWindow *mainwindow;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::HistogramEvenDialog *ui;
};

#endif // HISTOGRAMEVENDIALOG_H
