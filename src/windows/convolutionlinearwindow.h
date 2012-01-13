#ifndef CONVOLUTIONLINEARWINDOW_H
#define CONVOLUTIONLINEARWINDOW_H

#include <QDialog>
#include "../mainwindow.h"
#include "../commands/convolutionlinearcommand.h"

class MainWindow;

namespace Ui {
    class ConvolutionLinearWindow;
}

class ConvolutionLinearWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConvolutionLinearWindow(MainWindow *parent = 0);
    ~ConvolutionLinearWindow();

    MainWindow *mainWindow;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConvolutionLinearWindow *ui;
};

#endif // CONVOLUTIONLINEARWINDOW_H

