﻿#ifndef DLGCURRENTVALUE_H
#define DLGCURRENTVALUE_H

#include <QDialog>
#include <QVector>

namespace Ui {
class dlgCurrentValue;
}

class QTimer;
class CLoop;
class QCPBars;
class QCustomPlot;
class dlgCurrentValue : public QDialog
{
    Q_OBJECT

public:
    explicit dlgCurrentValue(const CLoop* loop, QWidget *parent = 0);
    ~dlgCurrentValue();
private:
    void initCustomPlot(QCustomPlot *customPlot);
    void connectLoopDevice(const CLoop *loop, bool enable);
    void updateCurrentValue();
private slots:
    void timerUpdate();
    void loopDeviceStatusChanged(short status, unsigned char oldValue, unsigned char newValue, unsigned int time);
private:
    Ui::dlgCurrentValue *ui;
    QTimer* m_timer;
    const CLoop* m_loop;
    QCPBars* m_bars;
    QVector<double> m_x;
    bool m_needUpdate;
};

#endif // DLGCURRENTVALUE_H