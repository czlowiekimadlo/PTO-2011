#ifndef MORPHOLOGYDIALOG_H
#define MORPHOLOGYDIALOG_H

#include <QDialog>
#include "../mainwindow.h"
#include "../commands/morpferosioncommand.h"
#include "../commands/morphdilationcommand.h"

namespace Ui {
class MorphologyDialog;
}

class MorphologyDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MorphologyDialog(MainWindow *parent = 0);
    ~MorphologyDialog();

    MainWindow *mainwindow;
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::MorphologyDialog *ui;
};

#endif // MORPHOLOGYDIALOG_H
