#include "imagewindow.h"
#include "ui_imagewindow.h"

ImageWindow::ImageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);
}

ImageWindow::ImageWindow(MainWindow *parent) :
    QWidget(0),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);
    this->mainWindow = parent;
}

ImageWindow::~ImageWindow()
{
    delete ui;
    this->mainWindow->activeImage = NULL;
}
