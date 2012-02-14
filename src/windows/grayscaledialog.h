#ifndef GRAYSCALEDIALOG_H
#define GRAYSCALEDIALOG_H

#include <QDialog>
#include "../mainwindow.h"
#include "../commands/grayscalecommand.h"

class MainWindow;

namespace Ui {
    class GrayscaleDialog;
}

class GrayscaleDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit GrayscaleDialog(MainWindow *parent = 0);
    ~GrayscaleDialog();

    MainWindow * mainWindow;
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::GrayscaleDialog *ui;
};

#endif // GRAYSCALEDIALOG_H
