#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "C:\libusb\include/lusb0_usb.h"
#include <QTimer>
#include <QMessageBox>
#include <lusb0_usb.h>
#include <QDebug>

// Device vendor and product id.
#define MY_VID 0x0483
#define MY_PID 0x5711
// Device endpoint(s)
#define EP1_IN 0x81
#define EP1_OUT 0x01
// Device of bytes to transfer.
#define BUF_SIZE_READ 2
// Device of bytes to transfer.
#define BUF_SIZE_WRITE 9
// Device configuration and interface id.
#define MY_CONFIG 1
#define MY_INTF 0

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool connect_status;
    QTimer Timer;

private slots:
    void ReadyCheck(void);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
};

#endif // MAINWINDOW_H
