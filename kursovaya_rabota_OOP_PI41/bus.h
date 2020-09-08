#ifndef BUS_H
#define BUS_H
#include "auto.h"
#include "time.h"


class bus: public time//Основной класс - наследник time
{
private:

    QString route;//Направление
    bool factor;//Отменен - не отменен
public:
    Auto many;//Объекты вспомогательного класса
    void Init(QString s, int a,int t1, int t2, double b, QString st, int c, double d, int e);
    int wayTime();       //Перегрузка функции - считает время в пути
    QString getRoute() const;
    int getHour() const;
    int getMinute() const;
    bool getFactor();
    //void setFactor(bool f);
    void setRoute(QString s);
    void setHour(int h);
    void setMinute(int m);
};

#endif // BUS_H
