#ifndef CONVOLUTIONFREEDIALOG_H
#define CONVOLUTIONFREEDIALOG_H

#include <QDialog>
#include "../mainwindow.h"
#include "../commands/convolutionfreecommand.h"

class MainWindow;

namespace Ui {
    class ConvolutionFreeDialog;
}

class ConvolutionFreeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConvolutionFreeDialog(MainWindow *parent = 0);
    ~ConvolutionFreeDialog();

    MainWindow *mainWindow;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConvolutionFreeDialog *ui;
};

#endif // CONVOLUTIONFREEDIALOG_H
