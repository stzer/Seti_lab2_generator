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
    socket= new QUdpSocket(this);
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
    QByteArray datagram=QByteArray(ui->textEdit_3->toPlainText().toStdString().c_str());
    socket->writeDatagram(datagram.data(),datagram.size(),QHostAddress(ui->lineEdit->text()), ui->lineEdit_2->text().toInt());
}
