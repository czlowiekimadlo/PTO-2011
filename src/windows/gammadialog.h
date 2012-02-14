#ifndef GAMMADIALOG_H
#define GAMMADIALOG_H

#include <QDialog>
#include "../mainwindow.h"
#include "../commands/gammacommand.h"

class MainWindow;

namespace Ui {
    class GammaDialog;
}

class GammaDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit GammaDialog(MainWindow *parent = 0);
    ~GammaDialog();

    MainWindow *mainWindow;
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::GammaDialog *ui;
};

#endif // GAMMADIALOG_H
