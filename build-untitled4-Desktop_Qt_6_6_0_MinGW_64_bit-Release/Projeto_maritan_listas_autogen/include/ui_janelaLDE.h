/********************************************************************************
** Form generated from reading UI file 'janelaLDE.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELALDE_H
#define UI_JANELALDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LDEJanela
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *LayoutTitulo;
    QFrame *frameTitulo;
    QLabel *titulo_pagina;
    QFrame *line_7;
    QPushButton *pushButtonVoltar;
    QFrame *menu_Busca;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *Layout_menu_dados_2;
    QFrame *frameInputNumeroBusca;
    QLineEdit *input_numero_busca;
    QFrame *frame_2;
    QPushButton *buttonBuscarValor;
    QFrame *frameInputPosicaoBusca;
    QLineEdit *input_posicao_busca;
    QFrame *frameButtonBuscaPos;
    QPushButton *buttonBuscarPosicao;
    QHBoxLayout *horizontalLayout_11;
    QFrame *frameRespostaBusca;
    QLabel *labelRepostaBusca;
    QFrame *menu_dados;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Layout_menu_dados;
    QFrame *frameInputNumero;
    QLineEdit *input_numero;
    QFrame *frameInputPosicao;
    QLineEdit *input_posicao;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *buttonInserir;
    QPushButton *buttonRemover;
    QHBoxLayout *horizontalLayout_12;
    QFrame *frameValorRemovido;
    QLabel *labelValorRemovido;
    QFrame *frameGrid;
    QFrame *frameAdicionar;
    QWidget *gridLayoutWidget;
    QGridLayout *gridAdicionar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LDEJanela)
    {
        if (LDEJanela->objectName().isEmpty())
            LDEJanela->setObjectName("LDEJanela");
        LDEJanela->setWindowModality(Qt::WindowModal);
        LDEJanela->resize(1260, 903);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LDEJanela->sizePolicy().hasHeightForWidth());
        LDEJanela->setSizePolicy(sizePolicy);
        LDEJanela->setMinimumSize(QSize(100, 100));
        centralwidget = new QWidget(LDEJanela);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(320, 10, 751, 80));
        LayoutTitulo = new QVBoxLayout(verticalLayoutWidget_2);
        LayoutTitulo->setObjectName("LayoutTitulo");
        LayoutTitulo->setContentsMargins(0, 0, 0, 0);
        frameTitulo = new QFrame(verticalLayoutWidget_2);
        frameTitulo->setObjectName("frameTitulo");
        frameTitulo->setFrameShape(QFrame::StyledPanel);
        frameTitulo->setFrameShadow(QFrame::Raised);
        titulo_pagina = new QLabel(frameTitulo);
        titulo_pagina->setObjectName("titulo_pagina");
        titulo_pagina->setGeometry(QRect(0, 0, 751, 61));
        titulo_pagina->setAlignment(Qt::AlignCenter);
        line_7 = new QFrame(frameTitulo);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(0, 60, 769, 3));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        LayoutTitulo->addWidget(frameTitulo);

        pushButtonVoltar = new QPushButton(centralwidget);
        pushButtonVoltar->setObjectName("pushButtonVoltar");
        pushButtonVoltar->setGeometry(QRect(30, 10, 91, 81));
        menu_Busca = new QFrame(centralwidget);
        menu_Busca->setObjectName("menu_Busca");
        menu_Busca->setGeometry(QRect(30, 400, 281, 301));
        menu_Busca->setLayoutDirection(Qt::LeftToRight);
        menu_Busca->setFrameShape(QFrame::StyledPanel);
        menu_Busca->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_3 = new QWidget(menu_Busca);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(30, 20, 221, 261));
        Layout_menu_dados_2 = new QVBoxLayout(verticalLayoutWidget_3);
        Layout_menu_dados_2->setSpacing(6);
        Layout_menu_dados_2->setObjectName("Layout_menu_dados_2");
        Layout_menu_dados_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        Layout_menu_dados_2->setContentsMargins(0, 0, 0, 0);
        frameInputNumeroBusca = new QFrame(verticalLayoutWidget_3);
        frameInputNumeroBusca->setObjectName("frameInputNumeroBusca");
        frameInputNumeroBusca->setMinimumSize(QSize(188, 45));
        frameInputNumeroBusca->setMaximumSize(QSize(242, 45));
        frameInputNumeroBusca->setFrameShape(QFrame::StyledPanel);
        frameInputNumeroBusca->setFrameShadow(QFrame::Raised);
        input_numero_busca = new QLineEdit(frameInputNumeroBusca);
        input_numero_busca->setObjectName("input_numero_busca");
        input_numero_busca->setGeometry(QRect(0, 0, 221, 45));
        input_numero_busca->setMinimumSize(QSize(188, 45));
        input_numero_busca->setMaximumSize(QSize(242, 45));
        input_numero_busca->setFrame(true);
        input_numero_busca->setAlignment(Qt::AlignCenter);

        Layout_menu_dados_2->addWidget(frameInputNumeroBusca);

        frame_2 = new QFrame(verticalLayoutWidget_3);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        buttonBuscarValor = new QPushButton(frame_2);
        buttonBuscarValor->setObjectName("buttonBuscarValor");
        buttonBuscarValor->setGeometry(QRect(50, 0, 121, 30));
        buttonBuscarValor->setMaximumSize(QSize(150, 30));

        Layout_menu_dados_2->addWidget(frame_2);

        frameInputPosicaoBusca = new QFrame(verticalLayoutWidget_3);
        frameInputPosicaoBusca->setObjectName("frameInputPosicaoBusca");
        frameInputPosicaoBusca->setMinimumSize(QSize(188, 45));
        frameInputPosicaoBusca->setMaximumSize(QSize(242, 45));
        frameInputPosicaoBusca->setFrameShape(QFrame::StyledPanel);
        frameInputPosicaoBusca->setFrameShadow(QFrame::Raised);
        input_posicao_busca = new QLineEdit(frameInputPosicaoBusca);
        input_posicao_busca->setObjectName("input_posicao_busca");
        input_posicao_busca->setGeometry(QRect(0, 0, 221, 45));
        input_posicao_busca->setMinimumSize(QSize(188, 45));
        input_posicao_busca->setMaximumSize(QSize(242, 45));
        input_posicao_busca->setAlignment(Qt::AlignCenter);

        Layout_menu_dados_2->addWidget(frameInputPosicaoBusca);

        frameButtonBuscaPos = new QFrame(verticalLayoutWidget_3);
        frameButtonBuscaPos->setObjectName("frameButtonBuscaPos");
        frameButtonBuscaPos->setFrameShape(QFrame::StyledPanel);
        frameButtonBuscaPos->setFrameShadow(QFrame::Raised);
        buttonBuscarPosicao = new QPushButton(frameButtonBuscaPos);
        buttonBuscarPosicao->setObjectName("buttonBuscarPosicao");
        buttonBuscarPosicao->setGeometry(QRect(50, 0, 121, 31));
        buttonBuscarPosicao->setMaximumSize(QSize(200, 40));

        Layout_menu_dados_2->addWidget(frameButtonBuscaPos);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        frameRespostaBusca = new QFrame(verticalLayoutWidget_3);
        frameRespostaBusca->setObjectName("frameRespostaBusca");
        frameRespostaBusca->setFrameShape(QFrame::StyledPanel);
        frameRespostaBusca->setFrameShadow(QFrame::Raised);
        labelRepostaBusca = new QLabel(frameRespostaBusca);
        labelRepostaBusca->setObjectName("labelRepostaBusca");
        labelRepostaBusca->setGeometry(QRect(0, 0, 221, 51));
        labelRepostaBusca->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(frameRespostaBusca);


        Layout_menu_dados_2->addLayout(horizontalLayout_11);

        menu_dados = new QFrame(centralwidget);
        menu_dados->setObjectName("menu_dados");
        menu_dados->setGeometry(QRect(30, 110, 281, 271));
        menu_dados->setLayoutDirection(Qt::LeftToRight);
        menu_dados->setFrameShape(QFrame::StyledPanel);
        menu_dados->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(menu_dados);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 10, 221, 231));
        Layout_menu_dados = new QVBoxLayout(verticalLayoutWidget);
        Layout_menu_dados->setObjectName("Layout_menu_dados");
        Layout_menu_dados->setSizeConstraint(QLayout::SetDefaultConstraint);
        Layout_menu_dados->setContentsMargins(0, 0, 0, 0);
        frameInputNumero = new QFrame(verticalLayoutWidget);
        frameInputNumero->setObjectName("frameInputNumero");
        frameInputNumero->setMinimumSize(QSize(188, 45));
        frameInputNumero->setMaximumSize(QSize(242, 45));
        frameInputNumero->setFrameShape(QFrame::StyledPanel);
        frameInputNumero->setFrameShadow(QFrame::Raised);
        input_numero = new QLineEdit(frameInputNumero);
        input_numero->setObjectName("input_numero");
        input_numero->setGeometry(QRect(0, 0, 221, 45));
        input_numero->setMinimumSize(QSize(188, 45));
        input_numero->setMaximumSize(QSize(242, 45));
        input_numero->setFrame(true);
        input_numero->setAlignment(Qt::AlignCenter);

        Layout_menu_dados->addWidget(frameInputNumero);

        frameInputPosicao = new QFrame(verticalLayoutWidget);
        frameInputPosicao->setObjectName("frameInputPosicao");
        frameInputPosicao->setMinimumSize(QSize(188, 45));
        frameInputPosicao->setMaximumSize(QSize(242, 45));
        frameInputPosicao->setFrameShape(QFrame::StyledPanel);
        frameInputPosicao->setFrameShadow(QFrame::Raised);
        input_posicao = new QLineEdit(frameInputPosicao);
        input_posicao->setObjectName("input_posicao");
        input_posicao->setGeometry(QRect(0, 0, 221, 45));
        input_posicao->setMinimumSize(QSize(188, 45));
        input_posicao->setMaximumSize(QSize(242, 45));
        input_posicao->setAlignment(Qt::AlignCenter);

        Layout_menu_dados->addWidget(frameInputPosicao);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        buttonInserir = new QPushButton(verticalLayoutWidget);
        buttonInserir->setObjectName("buttonInserir");
        buttonInserir->setMaximumSize(QSize(90, 40));

        horizontalLayout_10->addWidget(buttonInserir);

        buttonRemover = new QPushButton(verticalLayoutWidget);
        buttonRemover->setObjectName("buttonRemover");
        buttonRemover->setMaximumSize(QSize(90, 40));

        horizontalLayout_10->addWidget(buttonRemover);


        verticalLayout_3->addLayout(horizontalLayout_10);


        Layout_menu_dados->addLayout(verticalLayout_3);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        frameValorRemovido = new QFrame(verticalLayoutWidget);
        frameValorRemovido->setObjectName("frameValorRemovido");
        frameValorRemovido->setFrameShape(QFrame::StyledPanel);
        frameValorRemovido->setFrameShadow(QFrame::Raised);
        labelValorRemovido = new QLabel(frameValorRemovido);
        labelValorRemovido->setObjectName("labelValorRemovido");
        labelValorRemovido->setGeometry(QRect(0, 0, 221, 71));
        labelValorRemovido->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(frameValorRemovido);


        Layout_menu_dados->addLayout(horizontalLayout_12);

        frameGrid = new QFrame(centralwidget);
        frameGrid->setObjectName("frameGrid");
        frameGrid->setGeometry(QRect(330, 170, 751, 611));
        sizePolicy.setHeightForWidth(frameGrid->sizePolicy().hasHeightForWidth());
        frameGrid->setSizePolicy(sizePolicy);
        frameGrid->setMaximumSize(QSize(2500, 2500));
        frameGrid->setFrameShape(QFrame::StyledPanel);
        frameGrid->setFrameShadow(QFrame::Raised);
        frameAdicionar = new QFrame(centralwidget);
        frameAdicionar->setObjectName("frameAdicionar");
        frameAdicionar->setGeometry(QRect(640, 90, 120, 80));
        frameAdicionar->setFrameShape(QFrame::StyledPanel);
        frameAdicionar->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(frameAdicionar);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 121, 81));
        gridAdicionar = new QGridLayout(gridLayoutWidget);
        gridAdicionar->setObjectName("gridAdicionar");
        gridAdicionar->setContentsMargins(0, 0, 0, 0);
        LDEJanela->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LDEJanela);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1260, 21));
        LDEJanela->setMenuBar(menubar);
        statusbar = new QStatusBar(LDEJanela);
        statusbar->setObjectName("statusbar");
        LDEJanela->setStatusBar(statusbar);

        retranslateUi(LDEJanela);

        QMetaObject::connectSlotsByName(LDEJanela);
    } // setupUi

    void retranslateUi(QMainWindow *LDEJanela)
    {
        LDEJanela->setWindowTitle(QCoreApplication::translate("LDEJanela", "MainWindow", nullptr));
        titulo_pagina->setText(QCoreApplication::translate("LDEJanela", "lista Duplamente Encadeada", nullptr));
        pushButtonVoltar->setText(QCoreApplication::translate("LDEJanela", "Voltar", nullptr));
        input_numero_busca->setInputMask(QString());
        input_numero_busca->setText(QString());
        buttonBuscarValor->setText(QCoreApplication::translate("LDEJanela", "Procurar", nullptr));
        input_posicao_busca->setInputMask(QString());
        input_posicao_busca->setText(QString());
        buttonBuscarPosicao->setText(QCoreApplication::translate("LDEJanela", "buscar", nullptr));
        labelRepostaBusca->setText(QString());
        input_numero->setInputMask(QString());
        input_numero->setText(QString());
        input_posicao->setInputMask(QString());
        input_posicao->setText(QString());
        buttonInserir->setText(QCoreApplication::translate("LDEJanela", "Inserir", nullptr));
        buttonRemover->setText(QCoreApplication::translate("LDEJanela", "Remover", nullptr));
        labelValorRemovido->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LDEJanela: public Ui_LDEJanela {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELALDE_H
