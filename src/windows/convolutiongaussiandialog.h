#ifndef CONVOLUTIONGAUSSIANDIALOG_H
#define CONVOLUTIONGAUSSIANDIALOG_H

#include <QDialog>
#include <iostream>
#include "../mainwindow.h"
#include "../commands/convolutiongaussiancommand.h"

class MainWindow;

namespace Ui {
    class ConvolutionGaussianDialog;
}

class ConvolutionGaussianDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConvolutionGaussianDialog(MainWindow *parent = 0);
    ~ConvolutionGaussianDialog();

    MainWindow *mainWindow;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConvolutionGaussianDialog *ui;
};

#endif // CONVOLUTIONGAUSSIANDIALOG_H
