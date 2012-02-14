#include "contrastdialog.h"
#include "ui_contrastdialog.h"

ContrastDialog::ContrastDialog(MainWindow *parent) :
    QDialog(0),
    ui(new Ui::ContrastDialog)
{
    ui->setupUi(this);
    this->mainWindow = parent;
}

ContrastDialog::~ContrastDialog()
{
    delete ui;
}

void ContrastDialog::on_buttonBox_accepted()
{
    double value = this->ui->lineEdit->text().toDouble();

    this->mainWindow->pushCommand(new ContrastCommand(value));
}
