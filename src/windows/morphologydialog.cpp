#include "morphologydialog.h"
#include "ui_morphologydialog.h"

MorphologyDialog::MorphologyDialog(MainWindow *parent) :
    QDialog(0),
    ui(new Ui::MorphologyDialog)
{
    ui->setupUi(this);
    this->mainwindow = parent;
}

MorphologyDialog::~MorphologyDialog()
{
    delete ui;
}


void MorphologyDialog::on_buttonBox_accepted()
{
    int w = this->ui->sizeX->text().toInt();
    int h = this->ui->sizeY->text().toInt();
    int x = this->ui->anchorX->text().toInt();
    int y = this->ui->anchorY->text().toInt();
    QString m = this->ui->mask->toPlainText();
    int o = this->ui->operation->currentRow();

    switch(o) {
    case 0:
        this->mainwindow->pushCommand(new MorpfErosionCommand(w, h, x, y, m));
        break;
    case 1:
        this->mainwindow->pushCommand(new MorphDilationCommand(w, h, x, y, m));
        break;
    case 2:
        this->mainwindow->pushCommand(new MorpfErosionCommand(w, h, x, y, m));
        this->mainwindow->pushCommand(new MorphDilationCommand(w, h, x, y, m));
        break;
    case 3:
        this->mainwindow->pushCommand(new MorphDilationCommand(w, h, x, y, m));
        this->mainwindow->pushCommand(new MorpfErosionCommand(w, h, x, y, m));
        break;
    }
}
