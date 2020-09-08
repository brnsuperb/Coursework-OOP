#include "auto.h"
#include "bus.h"
#include "time.h"

void bus::Init(QString s, int a,int t1, int t2, double b, QString st, int c, double d, int e)
{
    this->send_hour = t1;
    this->send_minutes = t2;
    route = s;
    many.Init(a,b,st,c,d,e);
}

bool bus::getFactor()
{
    return factor;
}


QString bus::getRoute() const
{
    return route;
}

int bus::wayTime()
{
    return many.getDistance() / 60;
}

int bus::getHour() const
{
    return this->send_hour;
}

int bus::getMinute() const
{
    return this->send_minutes;
}

void bus::setRoute(QString s)
{
    route = s;
}


void bus::setHour(int h)
{
    send_hour = h;
}
void bus::setMinute(int m)
{
    send_minutes = m;
}
