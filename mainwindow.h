#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include "udppacket.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void sendPacket();

private:
    Ui::MainWindow *ui;
    void initSocket();
    QUdpSocket *socket ;

};

#endif // MAINWINDOW_H
