/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QLabel *Lab_VID_PID_num;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(406, 260);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 20, 91, 41));
        Lab_VID_PID_num = new QLabel(centralwidget);
        Lab_VID_PID_num->setObjectName(QString::fromUtf8("Lab_VID_PID_num"));
        Lab_VID_PID_num->setGeometry(QRect(30, 80, 91, 31));
        Lab_VID_PID_num->setFrameShape(QFrame::Box);
        Lab_VID_PID_num->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 91, 41));
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 20, 91, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 80, 91, 41));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(280, 80, 91, 41));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(170, 140, 91, 41));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(280, 140, 91, 41));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(170, 200, 91, 41));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(280, 200, 91, 41));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 140, 91, 41));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(30, 200, 91, 41));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gripper", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        Lab_VID_PID_num->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Not connected", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "On", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Up", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Left", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
