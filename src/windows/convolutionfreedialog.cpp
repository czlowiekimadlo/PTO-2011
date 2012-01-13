#include "convolutionfreedialog.h"
#include "ui_convolutionfreedialog.h"

ConvolutionFreeDialog::ConvolutionFreeDialog(MainWindow *parent) :
    QDialog(0),
    ui(new Ui::ConvolutionFreeDialog)
{
    ui->setupUi(this);
    this->mainWindow = parent;
}

ConvolutionFreeDialog::~ConvolutionFreeDialog()
{
    delete ui;
}

void ConvolutionFreeDialog::on_buttonBox_accepted()
{
    int w = this->ui->mWidth->text().toInt();
    int h = this->ui->mHeight->text().toInt();
    int x = this->ui->mX->text().toInt();
    int y = this->ui->mY->text().toInt();
    QString m = this->ui->mat->toPlainText();

    this->mainWindow->pushCommand(new ConvolutionFreeCommand(w, h, x, y, m));
}
