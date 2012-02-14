#include "gammadialog.h"
#include "ui_gammadialog.h"


GammaDialog::GammaDialog(MainWindow *parent) :
    QDialog(0),
    ui(new Ui::GammaDialog)
{
    ui->setupUi(this);
    this->mainWindow = parent;
}

GammaDialog::~GammaDialog()
{
    delete ui;
}

void GammaDialog::on_buttonBox_accepted()
{
    double value = this->ui->lineEdit->text().toDouble();

    this->mainWindow->pushCommand(new GammaCommand(value));
}
