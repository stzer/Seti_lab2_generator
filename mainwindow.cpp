#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "qhostaddress.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this, SLOT(sendPacket()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendPacket()
{
    qDebug()<<"PushButton!";
    initSocket();
}

void MainWindow::initSocket()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    udp_header packet;
    //out << qint64(0);
    //out << qint8(type);
    out << ui->textEdit_3->toPlainText();
    //out.device()->seek(qint64(0));
    //out << qint64(data.size() - sizeof(qint64));
    QUdpSocket *socket = new QUdpSocket(this);
    packet.src_port=socket->localPort();
    packet.dst_port=ui->lineEdit_2->text().toInt();
    QByteArray *byteArray=new QByteArray(ui->textEdit_3->toPlainText().toStdString().c_str());
    packet.length=byteArray->length();
    QByteArray _temp=packet.toByteArray();
    QHostAddress adress(ui->lineEdit->text());
    qint16 port(ui->lineEdit_2->text().toInt());
    socket->writeDatagram(_temp, adress, port);
}
