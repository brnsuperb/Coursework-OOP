#include "graph.h"
#include "ui_graph.h"
#include "timeapi.h"
#include "QStringList"
#include "mainwindow.h"
#include "QFile"
#include "QtCore"

graph::graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);
    customPlot = new QCustomPlot(this);
    vb = new QVBoxLayout(this);

    vb->addWidget(customPlot);
    res = new QPushButton(QString::fromUtf8("Показать гистограмму"),this);
    vb->addWidget(res);
    setLayout(vb);
    // Сигналы
    connect(res,SIGNAL(clicked()),this,SLOT(rndres()));
}

void graph::getData(QStringList l)
{
    lst.clear();
    lst = l;
    count = 0;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    count5 = 0;
}

void graph::rndres()
{
    fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(fossil);
        // Установки цвета:
    QPen pen;
    pen.setWidthF(1.5);//Толщина контура столбца
    fossil->setName(QString::fromUtf8("Гистограмма")); // Легенда
    pen.setColor(QColor(50, 50, 100));// Цвет контура столбца
    fossil->setPen(pen);
    // Цвет самого столбца, четвертый параметр - прозрачность
    fossil->setBrush(QColor(50, 50, 250, 70));

    // Установки значений оси X:
        QVector<double> ticks;
        QVector<QString> labels;
        ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;

        for (int i = 0;i < lst.size();i++)
        {
            if (lst[i] == "Барнаул") count++;
            if (lst[i] == "Новосибирск") count1++;
            if (lst[i] == "Омск") count2++;
            if (lst[i] == "Томск") count3++;
            if (lst[i] == "Кемерово") count4++;
            if (lst[i] == "Красноярск") count5++;
        }
        labels << "Барнаул" << "Новосибирск" << "Омск" << "Томск" << "Кемерово" << "Красноярск";
        customPlot->xAxis->setAutoTicks(false);
        customPlot->xAxis->setAutoTickLabels(false);
        customPlot->xAxis->setTickVector(ticks);
        customPlot->xAxis->setTickVectorLabels(labels);
        customPlot->xAxis->setSubTickCount(0);
        customPlot->xAxis->setTickLength(0, 4);
        customPlot->xAxis->grid()->setVisible(true);
        customPlot->xAxis->setRange(0, 8);

        // Установки значений оси Y:
        customPlot->yAxis->setRange(0, 12.1);
        customPlot->yAxis->setPadding(5);
        customPlot->yAxis->setLabel(QString::fromUtf8("Значения элементов"));
        customPlot->yAxis->grid()->setSubGridVisible(true);
        QPen gridPen;
        gridPen.setStyle(Qt::SolidLine);
        gridPen.setColor(QColor(0, 0, 0, 25));
        customPlot->yAxis->grid()->setPen(gridPen);
        gridPen.setStyle(Qt::DotLine);
        customPlot->yAxis->grid()->setSubGridPen(gridPen);


        // Данные:
        QVector<double> fossilData;
        qsrand (1000);
        fossilData  << count
                    << count1
                    << count2
                    << count3
                    << count4
                    << count5;
        fossil->setData(ticks, fossilData);

        // Легенда:
        customPlot->legend->setVisible(true);
        customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
        customPlot->legend->setBrush(QColor(255, 255, 255, 200));
        QPen legendPen;
        legendPen.setColor(QColor(130, 130, 130, 200));
        customPlot->legend->setBorderPen(legendPen);
        QFont legendFont = font();
        legendFont.setPointSize(10);
        customPlot->legend->setFont(legendFont);
        customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        customPlot->replot();

        // Сброс всех установок графика:
        customPlot->removePlottable(fossil);
}

graph::~graph()
{
    delete ui;
}
