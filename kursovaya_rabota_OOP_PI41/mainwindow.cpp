#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bus.h"
#include "time.h"
#include "auto.h"
#include "QFile"
#include "QFileDialog"
#include <algorithm>
#include "QStringList"
#include "QDataStream"

#include <QDialog>
#include <QMainWindow>
#include <graph.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_2->setColumnCount(10);
    //ui->tableWidget_2->setRowCount(3);
    QStringList column_2;
    column_2 << "Направление" << "Цена билета" << "Номер автобуса" << "Марка автобуса" << "Время\nотправления" << "Всего мест" << "Осталось мест" << "Расстояние"<< "Время в\nпути,часов" << "Отмена";
    ui->tableWidget_2->setHorizontalHeaderLabels(column_2);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->pushButton->setEnabled(false);
    gr = new graph(this);
    connect(this,SIGNAL(sendData(QStringList)),gr,SLOT(getData(QStringList)));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toTable()
{
    ui->pushButton->setEnabled(true);
    Row_Count = ui->tableWidget_2->currentRow();
    QString s = ui->tableWidget_2->item(Row_Count,0)->text();
    ui->lineEdit->setText(s);
    s = ui->tableWidget_2->item(Row_Count,1)->text();
    ui->lineEdit_2->setText(s);
    s = ui->tableWidget_2->item(Row_Count,2)->text();
    ui->lineEdit_3->setText(s);
    s = ui->tableWidget_2->item(Row_Count,3)->text();
    ui->lineEdit_4->setText(s);
    s = ui->tableWidget_2->item(Row_Count,4)->text();
    ui->lineEdit_7->setText(s);
    s = ui->tableWidget_2->item(Row_Count,6)->text();
    ui->lineEdit_6->setText(s);
    s = ui->tableWidget_2->item(Row_Count,5)->text();
    ui->lineEdit_5->setText(s);
    s = ui->tableWidget_2->item(Row_Count,7)->text();
    ui->lineEdit_8->setText(s);
}

void MainWindow::on_pushButton_3_clicked()//Кнопка "Добавить рейс"
{
    int i = ui->tableWidget_2->rowCount();
    QTableWidgetItem *it;
    QString s = ui->lineEdit->text();
    ui->tableWidget_2->insertRow(i);
    it = new QTableWidgetItem(s);
    ui->tableWidget_2->setItem(i,0,it);
    QString str = s;

    s = ui->lineEdit_2->text();
    it = new QTableWidgetItem(s);
    ui->tableWidget_2->setItem(i,1,it);
    double pr = s.toDouble();

    s = ui->lineEdit_3->text();
    it = new QTableWidgetItem(s);
    ui->tableWidget_2->setItem(i,2,it);
    int num = s.toInt();

    s = ui->lineEdit_4->text();
    it = new QTableWidgetItem(s);
    ui->tableWidget_2->setItem(i,3,it);
    QString str1 = s;

    s = ui->lineEdit_5->text();
    it = new QTableWidgetItem(s);
    ui->tableWidget_2->setItem(i,5,it);
    int gen_p = s.toInt();

    s = ui->lineEdit_6->text();
    it = new QTableWidgetItem(s);
    ui->tableWidget_2->setItem(i,6,it);
    int l_p = s.toInt();


    s = ui->lineEdit_7->text();
    it = new QTableWidgetItem(s);
    ui->tableWidget_2->setItem(i,4,it);
    int t1;
    int t2;
    QStringList ls = s.split(":");
    t1 = ls[0].toInt();
    t2 = ls[1].toInt();


    s = ui->lineEdit_8->text();
    it = new QTableWidgetItem(s);
    ui->tableWidget_2->setItem(i,7,it);
    double dist = s.toDouble();

    bus B;
    B.Init(str,num,t1,t2,dist,str1,gen_p,pr,l_p);
    container.push_back(B);

    s = QString::number(B.wayTime(),'f',1);
    it = new QTableWidgetItem(s);
    ui->tableWidget_2->setItem(i,8,it);

    if (l_p > gen_p - 10)
    {
        s = "Отменен";
        it = new QTableWidgetItem(s);
        ui->tableWidget_2->setItem(i,9,it);
    }
    ui->label_21->setText("Маршрут добавлен");
}

void MainWindow::on_action_triggered()//Пункт меню "Новый"
{

    while(ui->tableWidget_2->rowCount() > 0)
        {
            ui->tableWidget_2->removeRow(0);
        }

        QString s,st,brand;
        QTableWidgetItem *it;
        int r;
        double y;
        int place;
        int generalPlace;
        int busNumber;
        int hour;
        int minute;
        int hour1;
        int minute1;
        int time_in_way;
        int dist;
        int factor;
        for (int i = 0;i < 10;i++)
        {
            int k = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(i);
            r = qrand() % 4;
            if(r == 1)
                st = "Барнаул";
            else if(r == 2)
                st = "Новосибирск";
            else
                st = "Омск";
            it = new QTableWidgetItem(st);
            ui->tableWidget_2->setItem(i,0,it);

            y = qrand() % 1000;
            s = QString::number(y,'f',1);
            it = new QTableWidgetItem(s);
            ui->tableWidget_2->setItem(i,1,it);

            busNumber = qrand() % 1000;
            s = QString::number(busNumber,'f',0);
            it = new QTableWidgetItem(s);
            ui->tableWidget_2->setItem(i,2,it);

            brand = "Mercedes";
            it = new QTableWidgetItem(brand);
            ui->tableWidget_2->setItem(i,3,it);

            hour = qrand() % 24;
            minute = qrand() % 60;
            QString a,b;

            if (hour < 10)
                a = "0" + QString::number(hour,'f',0);
            else
                a = QString::number(hour,'f',0);
            if (minute < 10)
                b = "0" + QString::number(minute,'f',0);
            else
                b = QString::number(minute,'f',0);

            s = a + ":" + b;
            it = new QTableWidgetItem(s);
            ui->tableWidget_2->setItem(i,4,it);

            generalPlace = qrand() % 50;
            s = QString::number(generalPlace,'f',0);
            it = new QTableWidgetItem(s);
            ui->tableWidget_2->setItem(i,5,it);

            place = qrand() % 30;
            s = QString::number(place,'f',0);
            it = new QTableWidgetItem(s);
            ui->tableWidget_2->setItem(i,6,it);

            dist = qrand() % 400;
            s = QString::number(dist,'f',0);
            it = new QTableWidgetItem(s);
            ui->tableWidget_2->setItem(i,7,it);

            if (place <= 20)
            {
                it = new QTableWidgetItem("Отменен");
                ui->tableWidget_2->setItem(i,9,it);
            }

            bus B;
            B.Init(st,busNumber,hour,minute,dist,brand,generalPlace,y,place);
            container.push_back(B);
            double x = B.wayTime();
            s = QString::number(x,'f',1);
            it = new QTableWidgetItem(s);
            ui->tableWidget_2->setItem(i,8,it);


        }
        ui->action->setEnabled(false);
}

void MainWindow::on_pushButton_clicked()//Кнопка "Редактировать"
{
    QString s = ui->lineEdit->text();
    ui->tableWidget_2->item(Row_Count,0)->setText(s);
    QString str;

    s = ui->lineEdit_2->text();
    ui->tableWidget_2->item(Row_Count,1)->setText(s);
    double pr;

    s = ui->lineEdit_3->text();
    ui->tableWidget_2->item(Row_Count,2)->setText(s);
    int num;


    s = ui->lineEdit_4->text();
    ui->tableWidget_2->item(Row_Count,3)->setText(s);
    QString str1;

    s = ui->lineEdit_5->text();
    ui->tableWidget_2->item(Row_Count,5)->setText(s);
    int gen_p;



    s = ui->lineEdit_6->text();
    ui->tableWidget_2->item(Row_Count,6)->setText(s);
    int l_p;


    s = ui->lineEdit_7->text();
    ui->tableWidget_2->item(Row_Count,4)->setText(s);
    int t1;
    int t2;


    s = ui->lineEdit_8->text();
    ui->tableWidget_2->item(Row_Count,7)->setText(s);
    double dist;

    container.clear();
    for (int j = 0;j < ui->tableWidget_2->rowCount();j++)
    {
        bus B;
        str = ui->tableWidget_2->item(j,0)->text();
        s = ui->tableWidget_2->item(j,1)->text();
        pr = s.toDouble();
        s = ui->tableWidget_2->item(j,2)->text();
        num = s.toInt();
        str1 = ui->tableWidget_2->item(j,3)->text();
        s = ui->tableWidget_2->item(j,4)->text();
        QStringList ls = s.split(":");
        t1 = ls[0].toInt();
        t2 = ls[1].toInt();
        s = ui->tableWidget_2->item(j,5)->text();
        gen_p = s.toInt();
        s = ui->tableWidget_2->item(j,6)->text();
        l_p = s.toInt();
        s = ui->tableWidget_2->item(j,7)->text();
        dist = s.toDouble();
        B.Init(str,num,t1,t2,dist,str1,gen_p,pr,l_p);
        container.push_back(B);
    }
    ui->label_21->setText("Запись отредактирована");
}

void MainWindow::on_pushButton_4_clicked()//"Поиск"
{

    while(ui->tableWidget_2->rowCount() > 0) ui->tableWidget_2->removeRow(0);

    QString s,s1;
    QString s_num;
    QString sp1,sp2;
    QString d1,d2;
    for(int i = 0;i < container.size();i++)
    {
        int counter = 0;
        QString t = ui->lineEdit_9->text();
        if (t == container[i].getRoute() || (t == "")) counter++;

        s = ui->lineEdit_10->text();
        s1 = ui->lineEdit_11->text();
        if ((container[i].many.getPrice() >= s.toDouble() && container[i].many.getPrice() <= s1.toDouble())||(s == "" && s1 == ""))
            counter++;

        s_num = ui->lineEdit_12->text();
        if (container[i].many.getNumber() == s_num.toInt() || (s_num == "")) counter++;

        sp1 = ui->lineEdit_13->text();
        sp2 = ui->lineEdit_14->text();

        if ((container[i].many.getAllamount() >= sp1.toInt() && container[i].many.getAllamount() <= sp2.toInt())||sp1 == "" || sp2 == "")
             counter++;

        d1 = ui->lineEdit_15->text();
        d2 = ui->lineEdit_16->text();
        if ((container[i].many.getDistance() >= d1.toInt() && container[i].many.getDistance() <= d2.toInt())||d1 == "" || d2 == "")
            counter++;

        if (counter == 5)
        {
            int k = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(k);
            QTableWidgetItem *it;
            t = container[i].getRoute();
            it = new QTableWidgetItem(t);
            ui->tableWidget_2->setItem(k,0,it);

            QString str = QString::number(container[i].many.getPrice(),'f',1);
            it = new QTableWidgetItem(str);
            ui->tableWidget_2->setItem(k,1,it);

            str = QString::number(container[i].many.getNumber(),'f',0);
            it = new QTableWidgetItem(str);
            ui->tableWidget_2->setItem(k,2,it);

            str = container[i].many.getBrand();
            it = new QTableWidgetItem(str);
            ui->tableWidget_2->setItem(k,3,it);

            str = QString::number(container[i].getHour(),'f',0) + ":" + QString::number(container[i].getMinute(),'f',0);
            it = new QTableWidgetItem(str);
            ui->tableWidget_2->setItem(k,4,it);

            int count = container[i].many.getAllamount();
            str = QString::number(container[i].many.getAllamount(),'f',0);
            it = new QTableWidgetItem(str);
            ui->tableWidget_2->setItem(k,5,it);

            int count1 = container[i].many.getLeftPlace();
            str = QString::number(container[i].many.getLeftPlace(),'f',0);
            it = new QTableWidgetItem(str);
            ui->tableWidget_2->setItem(k,6,it);

            str = QString::number(container[i].many.getDistance(),'f',1);
            it = new QTableWidgetItem(str);
            ui->tableWidget_2->setItem(k,7,it);

            str = QString::number(container[i].wayTime(),'f',1);
            it = new QTableWidgetItem(str);
            ui->tableWidget_2->setItem(k,8,it);
            if (count1 > count - 10)
            {
                it = new QTableWidgetItem("Отменен");
                ui->tableWidget_2->setItem(k,9,it);
            }
        }
    }
}

void MainWindow::on_pushButton_5_clicked()//"Сбросить поиск"
{
    QString s,s1;
    QString s_num;
    QString sp1,sp2;
    QString d1,d2,t;
    while(ui->tableWidget_2->rowCount() > 0) ui->tableWidget_2->removeRow(0);

    for (int i = 0;i < container.size();i++)
    {
    int k = ui->tableWidget_2->rowCount();
    ui->tableWidget_2->insertRow(k);
    QTableWidgetItem *it;
    t = container[i].getRoute();
    it = new QTableWidgetItem(t);
    ui->tableWidget_2->setItem(k,0,it);

    QString str = QString::number(container[i].many.getPrice(),'f',1);
    it = new QTableWidgetItem(str);
    ui->tableWidget_2->setItem(k,1,it);

    str = QString::number(container[i].many.getNumber(),'f',0);
    it = new QTableWidgetItem(str);
    ui->tableWidget_2->setItem(k,2,it);

    str = container[i].many.getBrand();
    it = new QTableWidgetItem(str);
    ui->tableWidget_2->setItem(k,3,it);

    str = QString::number(container[i].getHour(),'f',0) + ":" + QString::number(container[i].getMinute(),'f',0);
    it = new QTableWidgetItem(str);
    ui->tableWidget_2->setItem(k,4,it);

    int count = container[i].many.getAllamount();
    str = QString::number(container[i].many.getAllamount(),'f',0);
    it = new QTableWidgetItem(str);
    ui->tableWidget_2->setItem(k,5,it);

    int count1 = container[i].many.getLeftPlace();
    str = QString::number(container[i].many.getLeftPlace(),'f',0);
    it = new QTableWidgetItem(str);
    ui->tableWidget_2->setItem(k,6,it);

    str = QString::number(container[i].many.getDistance(),'f',1);
    it = new QTableWidgetItem(str);
    ui->tableWidget_2->setItem(k,7,it);

    str = QString::number(container[i].wayTime(),'f',1);
    it = new QTableWidgetItem(str);
    ui->tableWidget_2->setItem(k,8,it);

    if (count1 > count - 10)
    {
        it = new QTableWidgetItem("Отменен");
        ui->tableWidget_2->setItem(k,9,it);
    }
    }
}

void MainWindow::on_action_2_triggered()
{
    QString filename = QFileDialog::getSaveFileName(
                    this,               //В текущем виджете
                    tr("Выбрать файл"), //Заголовок
                    QDir::currentPath(), //Открыть диалог в текущей директории
                    tr("Binary files(*.bin)")  //Маска файлов
                    );
    if (!filename.isNull())
    {
        QFile file(filename);
        QDataStream stream(&file);
        file.open(QIODevice::WriteOnly);
        stream << container;
        file.close();
    }
}

void MainWindow::on_pushButton_2_clicked()//"Удалить выбранную запись"
{
    int num = ui->tableWidget_2->currentRow();
    ui->tableWidget_2->removeRow(num);
    container.clear();
    QString s,s1,s2,s3,s4,s5,s6,s7,s8;
    for (int i = 0;i < ui->tableWidget_2->rowCount();i++)
    {
        s = ui->tableWidget_2->item(Row_Count,0)->text();
        s1 = ui->tableWidget_2->item(Row_Count,1)->text();
        s2 = ui->tableWidget_2->item(Row_Count,2)->text();
        s3 = ui->tableWidget_2->item(Row_Count,3)->text();
        s4 = ui->tableWidget_2->item(Row_Count,4)->text();
        s5 = ui->tableWidget_2->item(Row_Count,6)->text();
        s6 = ui->tableWidget_2->item(Row_Count,5)->text();
        s7 = ui->tableWidget_2->item(Row_Count,7)->text();
        bus B;
        int price = s1.toInt();
        int number = s2.toInt();
        int t1;
        int t2;
        QStringList ls = s4.split(":");
        t1 = ls[0].toInt();
        t2 = ls[1].toInt();
        int all = s5.toInt();
        int left = s6.toInt();
        int dist = s7.toInt();
        B.Init(s,number,t1,t2,dist,s3,all,price,left);
        container.push_back(B);
    }
    ui->label_21->setText("Запись удалена");
}

void MainWindow::on_action_6_triggered()
{
    for (int i = 0;i < ui->tableWidget_2->rowCount();i++)
    {
        QString s = container[i].getRoute();
        list << s;
    }
    gr->setModal(true);
    gr->show();
    emit sendData(list);
}

QDataStream& operator << (QDataStream &d,const bus &u)
{
    QString s = QString::number(u.getHour()) + ":" + QString::number(u.getMinute());
    d << u.getRoute() << u.many.getPrice() << u.many.getNumber() << u.many.getBrand() << s << u.many.getAllamount() << u.many.getLeftPlace() << u.many.getDistance();
    return d;
}

QDataStream& operator >> (QDataStream& d, bus& u)
{
    QString s,s1,s2;
    double price,distance;
    int number;
    int all,left;
    d >> s >> price >> number >> s1 >> s2 >> all >> left >> distance;
    u.setRoute(s);
    u.many.setPrice(price);
    u.many.setNumber(number);
    u.many.setBrand(s1);
    QStringList lst = s2.split(":");
    int t1 = lst[0].toInt();
    int t2 = lst[1].toInt();
    u.setHour(t1);
    u.setMinute(t2);
    u.many.setAll(all);
    u.many.setLeft(left);
    u.many.setDistance(distance);
    return d;
}

void MainWindow::on_action_3_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
                this,               //В текущем виджете
                tr("Выбрать файл"), //Заголовок
                QDir::currentPath(), //Открыть диалог в текущей директории
                tr("Binary files(*.bin)")  //Маска файлов
                );
    if (!filename.isNull())//Если файл выбран
    {
        QFile file(filename);
        QDataStream stream(&file);
        file.open(QIODevice::ReadOnly);
        container.clear();
        stream >> container;
        file.close();
        //ui->tableWidget_2->
        while(ui->tableWidget_2->rowCount() > 0)
            {
                ui->tableWidget_2->removeRow(0);
            }

        for(int i = 0;i < container.size();i++)
        {
        int k = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(k);
        QTableWidgetItem *it;
        QString t = container[i].getRoute();
        it = new QTableWidgetItem(t);
        ui->tableWidget_2->setItem(k,0,it);

        QString str = QString::number(container[i].many.getPrice(),'f',1);
        it = new QTableWidgetItem(str);
        ui->tableWidget_2->setItem(k,1,it);

        str = QString::number(container[i].many.getNumber(),'f',0);
        it = new QTableWidgetItem(str);
        ui->tableWidget_2->setItem(k,2,it);

        str = container[i].many.getBrand();
        it = new QTableWidgetItem(str);
        ui->tableWidget_2->setItem(k,3,it);

        str = QString::number(container[i].getHour(),'f',0) + ":" + QString::number(container[i].getMinute(),'f',0);
        it = new QTableWidgetItem(str);
        ui->tableWidget_2->setItem(k,4,it);

        int count = container[i].many.getAllamount();
        str = QString::number(container[i].many.getAllamount(),'f',0);
        it = new QTableWidgetItem(str);
        ui->tableWidget_2->setItem(k,5,it);

        int count1 = container[i].many.getLeftPlace();
        str = QString::number(container[i].many.getLeftPlace(),'f',0);
        it = new QTableWidgetItem(str);
        ui->tableWidget_2->setItem(k,6,it);

        str = QString::number(container[i].many.getDistance(),'f',1);
        it = new QTableWidgetItem(str);
        ui->tableWidget_2->setItem(k,7,it);

        str = QString::number(container[i].wayTime(),'f',1);
        it = new QTableWidgetItem(str);
        ui->tableWidget_2->setItem(k,8,it);
        if (count1 > count - 10)
        {
            it = new QTableWidgetItem("Отменен");
            ui->tableWidget_2->setItem(k,9,it);
        }
        }
     }
}

void MainWindow::on_action_5_triggered()
{
    close();
}
