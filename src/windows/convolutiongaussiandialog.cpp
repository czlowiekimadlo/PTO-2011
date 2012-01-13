#include "convolutiongaussiandialog.h"
#include "ui_convolutiongaussiandialog.h"

ConvolutionGaussianDialog::ConvolutionGaussianDialog(MainWindow *parent) :
    QDialog(0),
    ui(new Ui::ConvolutionGaussianDialog)
{
    ui->setupUi(this);
    this->mainWindow = parent;
}

ConvolutionGaussianDialog::~ConvolutionGaussianDialog()
{
    delete ui;
}

void ConvolutionGaussianDialog::on_buttonBox_accepted()
{
    int radius = this->ui->lineEdit->text().toInt();

    this->mainWindow->pushCommand(new ConvolutionGaussianCommand(radius));
}
