#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <qcustomplot.h>
#include "QVBoxLayout"
#include "QPushButton"
#include "QStringList"

namespace Ui {
class graph;
}

class graph : public QDialog
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = 0);
    ~graph();
    QStringList lst;
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;

private:
    Ui::graph *ui;
    QVBoxLayout *vb;
    QCustomPlot *customPlot;
    QPushButton *res;
    QCPBars *fossil;

public slots:
    void getData(QStringList);
private slots:
    void rndres();

};

#endif // GRAPH_H
