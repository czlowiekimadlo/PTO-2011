#ifndef CONTRASTDIALOG_H
#define CONTRASTDIALOG_H

#include <QDialog>
#include "../mainwindow.h"
#include "../commands/contrastcommand.h"

class MainWindow;

namespace Ui {
    class ContrastDialog;
}

class ContrastDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ContrastDialog(MainWindow *parent = 0);
    ~ContrastDialog();

    MainWindow *mainWindow;
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::ContrastDialog *ui;
};

#endif // CONTRASTDIALOG_H
