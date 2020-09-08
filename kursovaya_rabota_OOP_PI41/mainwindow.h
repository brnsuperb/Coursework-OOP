#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "bus.h"
#include "time.h"
#include "auto.h"
#include <algorithm>
#include <QVector>
#include <QDialog>
#include <QMainWindow>
#include "graph.h"
#include "QFile"
#include "QtCore"
#include "QDataStream"



namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector<bus> container;//Контейнер для хранения данных
    int Row_Count;
    QStringList list;
    friend QDataStream& operator >> (QDataStream &d, bus &u);
    friend QDataStream& operator << (QDataStream &d,const bus &u);
signals:
    void sendData(QStringList);

private slots:
    void on_pushButton_3_clicked();
    void toTable();
    void on_action_triggered();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_action_2_triggered();

    void on_pushButton_2_clicked();

    void on_action_6_triggered();

    void on_action_3_triggered();

    void on_action_5_triggered();

private:
    Ui::MainWindow *ui;
    graph *gr;
};

#endif // MAINWINDOW_H
