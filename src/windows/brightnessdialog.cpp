#include "brightnessdialog.h"
#include "ui_brightnessdialog.h"

BrightnessDialog::BrightnessDialog(MainWindow *parent) :
    QDialog(0),
    ui(new Ui::BrightnessDialog)
{
    ui->setupUi(this);
    this->mainWindow = parent;
}

BrightnessDialog::~BrightnessDialog()
{
    delete ui;
}

void BrightnessDialog::on_buttonBox_accepted()
{
    int value = this->ui->lineEdit->text().toInt();

    this->mainWindow->pushCommand(new BrightnessCommand(value));
}
