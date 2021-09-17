#include "mainwindow.h"
#include "ui_mainwindow.h"

usb_dev_handle *dev = NULL;
usb_dev_handle *open_dev(void);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setStyleSheet("QPushButton{ background-color: white; "
                                    "border-style: outset;"
                                    "border-width: 2px;"
                                    "border-radius: 10px;"
                                    "border-color: rgb(224, 0, 0);"
                                    "padding: 6px }");

    ui->pushButton_2->setStyleSheet("QPushButton{ background-color: white; "
                                    "border-style: outset;"
                                    "border-width: 2px;"
                                    "border-radius: 10px;"
                                    "border-color: rgb(224, 0, 0);"
                                    "padding: 6px }");

    Timer.setInterval(1000);
    connect(&Timer, SIGNAL(timeout()), this, SLOT(ReadyCheck()));
    Timer.start();
    usb_init();
    usb_find_busses();
    usb_find_devices();

    if(!(dev = open_dev()))
    {
        printf("error opening device: \n%s\n", usb_strerror());
        QMessageBox::information(NULL, "Error", "Устройство не обнаруженно");
        return;
    }
    else
    {
        printf("success: device %04X:%04X opened\n", MY_VID, MY_PID);
        connect_status = true;
    }

    if (usb_set_configuration(dev, MY_CONFIG) < 0)
    {
        printf("error setting config #%d: %s\n", MY_CONFIG, usb_strerror());
        usb_close(dev);
        QMessageBox::information(NULL, "Error", "error setting config");
        return;
    }
    else
    {
        printf("success: set configuration #%d\n", MY_CONFIG);
    }

    if (usb_claim_interface(dev, 0) < 0)
    {
        printf("error claiming interface #%d:\n%s\n", MY_INTF, usb_strerror());
        usb_close(dev);
        QMessageBox::information(NULL, "Error", "error claiming interface");
        return;
    }
    else
    {
        printf("success: claim_interface #%d\n", MY_INTF);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReadyCheck()
{
    int ret = 0;
    char str[5] = {};

    char USB_data[BUF_SIZE];
    if (!dev)
    {
        ui->label->setStyleSheet("background-color: red");
        usb_close(dev);
        printf("Done.\n");
    }

    ret = usb_bulk_read(dev, EP_IN, USB_data, BUF_SIZE, 100);

    if (ret < 0)
    {
        printf("error reading:\n%s\n", usb_strerror());
        ui->label->setText("Not connection");
        ui->label->setStyleSheet("background-color: red");
        ui->Lab_VID_PID_num->setText("-");
        ui->Lab_VID_PID_num->setStyleSheet("color: rgb(0, 0, 0)");
        ui->label_2->setText("-");
        ui->label_2->setStyleSheet("color: rgb(0, 0, 0)");
        ui->label_3->setText("-");
        ui->label_3->setStyleSheet("color: rgb(0, 0, 0)");
        ui->label_4->setText("-");
        ui->label_4->setStyleSheet("color: rgb(0, 0, 0)");
    }
    else
    {
        printf("success: bulk read %d bytes\n", ret);
        ui->label->setText("Connect");
        ui->label->setStyleSheet("background-color: green");

        ui->Lab_VID_PID_num->setText("0x" + QString::number(MY_VID, 16) + " 0x" + QString::number(MY_PID, 16));
        ui->Lab_VID_PID_num->setStyleSheet("color: rgb(100, 0, 0)");

        ui->label_2->setText("0x" + QString::number(USB_data[0], 'i', 0));
        ui->label_2->setStyleSheet("color: rgb(100, 0, 0)");

        ui->label_3->setText("0x" + QString::number(USB_data[1], 'i', 0));
        ui->label_3->setStyleSheet("color: rgb(100, 0, 0)");

        double y = (USB_data[2] << 8) + USB_data[3];                                                                    // description adc value
        double x = y * 3 / 4096;
        sprintf(str, "%0.2f", x);
        ui->label_4->setText(str);
        ui->label_4->setStyleSheet("color: rgb(100, 0, 0)");
    }
}

usb_dev_handle * open_dev(void)
{
    struct usb_bus *bus;
    struct usb_device *dev_local;

    for (bus = usb_get_busses(); bus; bus = bus->next)
    {
        for (dev_local = bus->devices; dev_local; dev_local = dev_local->next)
        {
            if (dev_local->descriptor.idVendor == MY_VID
                    && dev_local->descriptor.idProduct == MY_PID)
            {
                dev = usb_open(dev_local);
                return usb_open(dev_local);
            }
        }
    }
    return NULL;
}

void MainWindow::on_pushButton_clicked()
{
    int ret = 0;
    char data = 1;

    ret = usb_bulk_write(dev, EP_OUT, &data, 1, 500);
    if (ret < 0)
    {
        printf("No sended data!\n");
    }
    else
    {
        printf("Sended data!\n");

        ui->pushButton->setStyleSheet("QPushButton{ background-color: green; "
                                        "border-style: outset;"
                                        "border-width: 2px;"
                                        "border-radius: 10px;"
                                        "border-color: rgb(224, 0, 0);"
                                        "padding: 6px }");

        ui->pushButton_2->setStyleSheet("QPushButton{ background-color: white; "
                                        "border-style: outset;"
                                        "border-width: 2px;"
                                        "border-radius: 10px;"
                                        "border-color: rgb(224, 0, 0);"
                                        "padding: 6px }");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int ret = 0;
    char data = 0;

    ret = usb_bulk_write(dev, EP_OUT, &data, 1, 500);
    if (ret < 0)
    {
        printf("No sended data!\n");
    }
    else
    {
        printf("Sended data!\n");

        ui->pushButton->setStyleSheet("QPushButton{ background-color: white; "
                                        "border-style: outset;"
                                        "border-width: 2px;"
                                        "border-radius: 10px;"
                                        "border-color: rgb(224, 0, 0);"
                                        "padding: 6px }");

        ui->pushButton_2->setStyleSheet("QPushButton{ background-color: red; "
                                        "border-style: outset;"
                                        "border-width: 2px;"
                                        "border-radius: 10px;"
                                        "border-color: rgb(224, 0, 0);"
                                        "padding: 6px }");
    }
}
