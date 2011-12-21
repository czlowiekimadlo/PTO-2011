#include "historywindow.h"
#include "ui_historywindow.h"

HistoryWindow::HistoryWindow(MainWindow *parent) :
    QWidget(0),
    ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);
    this->mainWindow = parent;
}

HistoryWindow::~HistoryWindow()
{
    this->mainWindow->historyWindow = NULL;
    delete ui;
}

void HistoryWindow::fill(BaseCommand * head)
{
    this->ui->listWidget->clear();

    BaseCommand * element;
    element = head;

    while (element != NULL)
    {
        this->ui->listWidget->addItem(element->label());
        element = element->next;
    }
}

void HistoryWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    if (index.row() < 0)
    {
        return;
    }

    this->mainWindow->refreshImage(index.row() + 1);
}

void HistoryWindow::on_pushButton_clicked()
{
    this->mainWindow->popCommand();
}
