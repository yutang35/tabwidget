#include "tcpfileserver.h"

TcpFileServer::TcpFileServer(QWidget *parent)
    : QDialog(parent)
{
    totalBytes = 0;
    byteReceived = 0;
    fileNameSize = 0;
    serverProgressBar = new QProgressBar;
    serverStatusLabel = new QLabel(tr("伺服器端就緒"));
    startButton = new QPushButton(tr("接收"));
    quitButton = new QPushButton(tr("退出"));
    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(serverProgressBar);
    mainLayout->addWidget(serverStatusLabel);
    QHBoxLayout *ipLayout = new QHBoxLayout;
    IPLabel = new QLabel(QStringLiteral("IP:"));
    IPEdit = new QLineEdit;
    ipLayout->addWidget(IPLabel);
    ipLayout->addWidget(IPEdit);
    QHBoxLayout *portLayout = new QHBoxLayout;
    PortLabel = new QLabel(QStringLiteral("Port:"));
    PortEdit = new QLineEdit;
    ipLayout->addWidget(PortLabel);
    ipLayout->addWidget(PortEdit);
    mainLayout->addLayout(ipLayout);
    mainLayout->addLayout(portLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("接收檔案"));
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    connect(&tcpServer, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}

TcpFileServer::~TcpFileServer() {}
void TcpFileServer::start()
{
    startButton->setEnabled(false);
    byteReceived = 0;
    fileNameSize = 0;
    while(!tcpServer.isListening() &&
           !tcpServer.listen(QHostAddress::AnyIPv4, 16689))
    {
        QMessageBox::StandardButton ret = QMessageBox::critical(this,
                                                                tr("迴圈"),
                                                                tr("無法啟動伺服器: %1.").arg(tcpServer.errorString()),
                                                                QMessageBox::Retry | QMessageBox::Cancel);
        if (ret == QMessageBox::Cancel) return;
    }
    serverStatusLabel->setText(tr("監聽中..."));
}
void TcpFileServer::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection, SIGNAL(readyRead()),
            this, SLOT(updateServeProgress()));
    connect(tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    serverStatusLabel->setText(tr("接受連線"));
    tcpServer.close();
}
void TcpFileServer::updateServeProgress()
{
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_6);
    if(byteReceived <= sizeof(qint64)*2)
    {
        if((fileNameSize == 0) && (tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2))
        {
            in >> totalBytes >> fileNameSize;
            byteReceived += sizeof(qint64)*2;
        }
        if((fileNameSize != 0) && (tcpServerConnection->bytesAvailable() >= fileNameSize))
        {
            in >> fileName;
            byteReceived += fileNameSize;
            localFile = new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly))
            {
                QMessageBox::warning(this, tr("應用程式"),
                                     tr("無法讀取檔案 %1: \n%2.").arg(fileName).arg(localFile->errorString()));
                return;
            }
        }else{
            return;
        }
    }
    if (byteReceived < totalBytes)
    {
        byteReceived += tcpServerConnection->bytesAvailable();
        inBlock = tcpServerConnection->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }

    serverProgressBar->setMaximum(totalBytes);
    serverProgressBar->setValue(byteReceived);
    qDebug() << byteReceived;
    serverStatusLabel->setText(tr("已接收 %1 Bytes").arg(byteReceived));

    if(byteReceived == totalBytes)
    {
        tcpServerConnection->close();
        startButton->setEnabled(true);
        localFile->fileName();
        localFile->close();
        start();
    }
}
void TcpFileServer::displayError(QAbstractSocket::SocketError socketError)
{
    if(socketError == QTcpSocket::RemoteHostClosedError)
        return;

    QMessageBox::information(this, tr("網路錯誤"), tr("產生如下錯誤: %1.").arg(tcpServerConnection->errorString()));

    tcpServerConnection->close();
    serverProgressBar->reset();
    serverStatusLabel->setText(tr("伺服器就緒"));
    startButton->setEnabled(true);

}
