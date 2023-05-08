/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *buttonListaSeq;
    QPushButton *buttonLSE;
    QPushButton *buttonLDE;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(160, 30, 509, 399));
        frame->setMaximumSize(QSize(900, 500));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 491, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(600, 70));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        buttonListaSeq = new QPushButton(verticalLayoutWidget);
        buttonListaSeq->setObjectName("buttonListaSeq");
        buttonListaSeq->setMaximumSize(QSize(600, 70));

        verticalLayout->addWidget(buttonListaSeq);

        buttonLSE = new QPushButton(verticalLayoutWidget);
        buttonLSE->setObjectName("buttonLSE");
        buttonLSE->setMaximumSize(QSize(600, 70));

        verticalLayout->addWidget(buttonLSE);

        buttonLDE = new QPushButton(verticalLayoutWidget);
        buttonLDE->setObjectName("buttonLDE");
        buttonLDE->setMaximumSize(QSize(600, 70));

        verticalLayout->addWidget(buttonLDE);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Modelos de Lista", nullptr));
        buttonListaSeq->setText(QCoreApplication::translate("MainWindow", "Lista Sequencial", nullptr));
        buttonLSE->setText(QCoreApplication::translate("MainWindow", "Lista Simplesmente Encadeada", nullptr));
        buttonLDE->setText(QCoreApplication::translate("MainWindow", "Lista Duplamente Encadeada", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
