#include "histogramevendialog.h"
#include "ui_histogramevendialog.h"

HistogramEvenDialog::HistogramEvenDialog(MainWindow *parent) :
    QDialog(0),
    ui(new Ui::HistogramEvenDialog)
{
    ui->setupUi(this);
    this->mainwindow = parent;
}

HistogramEvenDialog::~HistogramEvenDialog()
{
    delete ui;
}

void HistogramEvenDialog::on_buttonBox_accepted()
{
    this->mainwindow->pushCommand(new HistogramEvenCommand(
                                      this->ui->checkRed->isChecked(),
                                      this->ui->checkGreen->isChecked(),
                                      this->ui->checkBlue->isChecked()
                                      ));
}
