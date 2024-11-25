#ifndef TCPFILESERVER_H
#define TCPFILESERVER_H

#include <QDialog>
#include <QtNetwork>
#include <QtWidgets>

class TcpFileServer : public QDialog
{
    Q_OBJECT

public:
    TcpFileServer(QWidget *parent = nullptr);
    ~TcpFileServer();
public slots:
    void start();
    void acceptConnection();
    void updateServeProgress();
    void displayError(QAbstractSocket::SocketError socketError);
private:
    QProgressBar     *serverProgressBar;
    QLabel           *serverStatusLabel;
    QLabel           *IPLabel;
    QLineEdit        *IPEdit;
    QLabel           *PortLabel;
    QLineEdit        *PortEdit;
    QPushButton      *startButton;
    QPushButton      *quitButton;
    QDialogButtonBox *buttonBox;

    QTcpServer       tcpServer;
    QTcpSocket       *tcpServerConnection;
    qint64           totalBytes;
    qint64           byteReceived;
    qint64           fileNameSize;
    QString          fileName;
    QFile            *localFile;
    QByteArray       inBlock;
};
#endif // TCPFILESERVER_H
