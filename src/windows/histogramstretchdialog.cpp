#include "histogramstretchdialog.h"
#include "ui_histogramstretchdialog.h"

HistogramStretchDialog::HistogramStretchDialog(MainWindow *parent) :
    QDialog(0),
    ui(new Ui::HistogramStretchDialog)
{
    ui->setupUi(this);
    this->mainwindow = parent;
}

HistogramStretchDialog::~HistogramStretchDialog()
{
    delete ui;
}

void HistogramStretchDialog::on_buttonBox_accepted()
{
    this->mainwindow->pushCommand(new HistogramStretchCommand(
                                      this->ui->checkRed->isChecked(),
                                      this->ui->checkGreen->isChecked(),
                                      this->ui->checkBlue->isChecked()
                                      ));
}
