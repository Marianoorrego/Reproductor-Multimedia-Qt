/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QGroupBox *groupBox_Video;
    QPushButton *pushButton_Seek_Backward;
    QPushButton *pushButton_Play_Pause;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Seek_Forward;
    QPushButton *pushButton_Volume;
    QSlider *horizontalSlider_Volume;
    QSlider *horizontalSlider_Duration;
    QLabel *label_current_Time;
    QLabel *label_Total_Time;
    QMenuBar *menubar;
    QMenu *menuSelect_Video_File;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(821, 592);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_Video = new QGroupBox(centralwidget);
        groupBox_Video->setObjectName("groupBox_Video");
        groupBox_Video->setGeometry(QRect(0, 0, 790, 450));
        groupBox_Video->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	border:1px solid black;\n"
"}"));
        pushButton_Seek_Backward = new QPushButton(centralwidget);
        pushButton_Seek_Backward->setObjectName("pushButton_Seek_Backward");
        pushButton_Seek_Backward->setGeometry(QRect(320, 510, 51, 41));
        pushButton_Seek_Backward->setAutoExclusive(false);
        pushButton_Play_Pause = new QPushButton(centralwidget);
        pushButton_Play_Pause->setObjectName("pushButton_Play_Pause");
        pushButton_Play_Pause->setGeometry(QRect(370, 510, 51, 41));
        pushButton_Stop = new QPushButton(centralwidget);
        pushButton_Stop->setObjectName("pushButton_Stop");
        pushButton_Stop->setGeometry(QRect(270, 510, 51, 41));
        pushButton_Seek_Forward = new QPushButton(centralwidget);
        pushButton_Seek_Forward->setObjectName("pushButton_Seek_Forward");
        pushButton_Seek_Forward->setGeometry(QRect(420, 510, 51, 41));
        pushButton_Volume = new QPushButton(centralwidget);
        pushButton_Volume->setObjectName("pushButton_Volume");
        pushButton_Volume->setGeometry(QRect(480, 510, 51, 41));
        horizontalSlider_Volume = new QSlider(centralwidget);
        horizontalSlider_Volume->setObjectName("horizontalSlider_Volume");
        horizontalSlider_Volume->setGeometry(QRect(540, 520, 131, 22));
        horizontalSlider_Volume->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider_Duration = new QSlider(centralwidget);
        horizontalSlider_Duration->setObjectName("horizontalSlider_Duration");
        horizontalSlider_Duration->setGeometry(QRect(70, 470, 631, 22));
        horizontalSlider_Duration->setOrientation(Qt::Orientation::Horizontal);
        label_current_Time = new QLabel(centralwidget);
        label_current_Time->setObjectName("label_current_Time");
        label_current_Time->setGeometry(QRect(0, 470, 71, 16));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_current_Time->setFont(font);
        label_Total_Time = new QLabel(centralwidget);
        label_Total_Time->setObjectName("label_Total_Time");
        label_Total_Time->setGeometry(QRect(710, 470, 71, 16));
        label_Total_Time->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 821, 25));
        menuSelect_Video_File = new QMenu(menubar);
        menuSelect_Video_File->setObjectName("menuSelect_Video_File");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuSelect_Video_File->menuAction());
        menuSelect_Video_File->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Abrir", nullptr));
        groupBox_Video->setTitle(QString());
        pushButton_Seek_Backward->setText(QString());
        pushButton_Play_Pause->setText(QString());
        pushButton_Stop->setText(QString());
        pushButton_Seek_Forward->setText(QString());
        pushButton_Volume->setText(QString());
        label_current_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_Total_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        menuSelect_Video_File->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
