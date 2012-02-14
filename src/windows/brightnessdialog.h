#ifndef BRIGHTNESSDIALOG_H
#define BRIGHTNESSDIALOG_H

#include <QDialog>
#include "../mainwindow.h"
#include "../commands/brightnesscommand.h"

class MainWindow;

namespace Ui {
    class BrightnessDialog;
}

class BrightnessDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit BrightnessDialog(MainWindow *parent = 0);
    ~BrightnessDialog();

    MainWindow * mainWindow;
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::BrightnessDialog *ui;
};

#endif // BRIGHTNESSDIALOG_H
