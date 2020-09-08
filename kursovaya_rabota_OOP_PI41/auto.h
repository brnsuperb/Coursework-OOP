#ifndef AUTO_H
#define AUTO_H
#include <QString>
#include <iostream>
#include <time.h>

class Auto
{
private:
    int number;       //Номер автобуса
    double distance;  //Расстояние
    QString brand;    //Марка автобуса
    int all_amount;       //Общее количество мест
    double price;//Стоимость билета
    int leftPlace;//Осталось билетов

public:
    void Init(int num, double len, QString br, int a_am, double pr ,int am);
    double getDistance() const;
    QString getBrand() const;
    int getAllamount() const;
    double getPrice() const;
    int getLeftPlace() const;
    int getNumber() const;

    void setNumber(int n);
    void setDistance(double d);
    void setBrand(QString b);
    void setAll(int a);
    void setLeft(int l);
    void setPrice(double pr);

};

#endif // AUTO_H
