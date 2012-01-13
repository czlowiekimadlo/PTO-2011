#include "convolutionlinearwindow.h"
#include "ui_convolutionlinearwindow.h"

ConvolutionLinearWindow::ConvolutionLinearWindow(MainWindow *parent) :
    QDialog(0),
    ui(new Ui::ConvolutionLinearWindow)
{
    ui->setupUi(this);
    this->mainWindow = parent;
}

ConvolutionLinearWindow::~ConvolutionLinearWindow()
{
    delete ui;
}

void ConvolutionLinearWindow::on_buttonBox_accepted()
{
    int radius = this->ui->lineEdit->text().toInt();

    this->mainWindow->pushCommand(new ConvolutionLinearCommand(radius));
}
