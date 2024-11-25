#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include "tcpfilesender.h"
#include "tcpfileserver.h"

class Tabwidget : public QWidget
{
    Q_OBJECT
public:
    Tabwidget(QWidget *parent = nullptr);
private:
    QTabWidget *tabWidget;
};

#endif // TABWIDGET_H
