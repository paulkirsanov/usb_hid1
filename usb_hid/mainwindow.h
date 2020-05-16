#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "C:\libusb\include/lusb0_usb.h"
#include <QTimer>
#include <QMessageBox>

// Device vendor and product id.
#define MY_VID 0x0483
#define MY_PID 0x5750
// Device endpoint(s)
#define EP_IN 0x81
#define EP_OUT 0x01
// Device of bytes to transfer.
#define BUF_SIZE 4
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
};

#endif // MAINWINDOW_H
