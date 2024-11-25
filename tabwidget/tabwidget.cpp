#include "tabwidget.h"

Tabwidget::Tabwidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    tabWidget = new QTabWidget;
    tabWidget->addTab(new TcpFileSender, "檔案傳送");
    tabWidget->addTab(new TcpFileServer, "接收檔案");
    layout->addWidget(tabWidget);
    setLayout(layout);
}
