#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "qhostaddress.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket=new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 7755);
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
         packet.src_port=7755;
         packet.dst_port=ui->lineEdit_2->text().toInt();
         packet.crc=0;
         packet.message=ui->textEdit_3->toPlainText();
         packet.length=packet.getLength();
         out<<packet.toByteArray();
         qDebug()<<packet.toByteArray();
         qDebug()<<ui->textEdit_3->toPlainText();
         QHostAddress adress=QHostAddress("172.18.7.15");
         socket->writeDatagram(data, QHostAddress::LocalHost, qint16(10000));
}
