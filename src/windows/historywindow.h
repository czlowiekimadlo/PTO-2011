#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>
#include <iostream>
#include "../mainwindow.h"
#include "../commands/basecommand.h"

class MainWindow;
class BaseCommand;

namespace Ui {
    class HistoryWindow;
}

class HistoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryWindow(MainWindow *parent = 0);
    ~HistoryWindow();
    void fill(BaseCommand *);

    MainWindow *mainWindow;

private slots:
    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::HistoryWindow *ui;
};

#endif // HISTORYWINDOW_H
