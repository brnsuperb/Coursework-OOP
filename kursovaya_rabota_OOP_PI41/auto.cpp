#include "auto.h"
#include "bus.h"
#include "time.h"

void Auto::Init(int num, double len, QString br, int a_am, double pr, int am)//Конструктор с параметрами
{
    number = num;
    distance = len;
    brand = br;
    all_amount = a_am;
    price = pr;
    leftPlace = am;
}



double Auto::getDistance() const
{
    return distance;
}

int Auto::getNumber() const
{
    return number;
}

int Auto::getAllamount() const
{
    return all_amount;
}

int Auto::getLeftPlace() const
{
    return leftPlace;
}
QString Auto::getBrand() const
{
    return brand;
}

double Auto::getPrice() const
{
    return price;
}

void Auto::setPrice(double pr)
{
    price = pr;
}

void Auto::setAll(int a)
{
    all_amount = a;
}

void Auto::setLeft(int l)
{
    leftPlace = l;
}

void Auto::setBrand(QString b)
{
    brand = b;
}

void Auto::setDistance(double d)
{
    distance = d;
}

void Auto::setNumber(int n)
{
    number = n;
}
