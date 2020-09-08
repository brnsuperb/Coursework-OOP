#ifndef TIME_H
#define TIME_H


class time//Абстрактный класс "Время"
{
protected:
    int send_hour;
    int send_minutes;
public:
    time();
    virtual int wayTime() = 0;//Виртуальная функция - "Время в пути"(в минутах)
};

#endif // TIME_H
