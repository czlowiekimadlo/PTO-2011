#include "grayscaledialog.h"
#include "ui_grayscaledialog.h"

GrayscaleDialog::GrayscaleDialog(MainWindow *parent) :
    QDialog(0),
    ui(new Ui::GrayscaleDialog)
{
    ui->setupUi(this);
    this->mainWindow = parent;
}

GrayscaleDialog::~GrayscaleDialog()
{
    delete ui;
}

void GrayscaleDialog::on_buttonBox_accepted()
{
    int r, g, b;

    r = this->ui->lineEdit->text().toInt();
    g = this->ui->lineEdit_2->text().toInt();
    b = this->ui->lineEdit_3->text().toInt();

    this->mainWindow->pushCommand(new GrayscaleCommand(r, g, b));
}
