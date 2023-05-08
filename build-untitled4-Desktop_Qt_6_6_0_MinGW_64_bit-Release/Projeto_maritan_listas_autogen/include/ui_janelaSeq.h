/********************************************************************************
** Form generated from reading UI file 'janelaSeq.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELASEQ_H
#define UI_JANELASEQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListaSeqJanela
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *LayoutTitulo;
    QFrame *frameTitulo;
    QLabel *titulo_pagina;
    QFrame *line_7;
    QFrame *menu_dados;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Layout_menu_dados;
    QFrame *frameCriarLista;
    QFrame *frameInputTamanhoLista_2;
    QLineEdit *InputTamanhoLista;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonCriaLista;
    QSpacerItem *horizontalSpacer_2;
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
    QPushButton *pushButtonVoltar;
    QFrame *menu_Busca;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *Layout_menu_dados_2;
    QFrame *frameInputNumeroBusca;
    QLineEdit *input_numero_busca;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *buttonBuscarValor;
    QSpacerItem *horizontalSpacer_10;
    QFrame *frameInputPosicaoBusca;
    QLineEdit *input_posicao_busca;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *buttonBuscarPosicao;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_11;
    QFrame *frameRespostaBusca;
    QLabel *labelRepostaBusca;
    QFrame *frameGrid;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ListaSeqJanela)
    {
        if (ListaSeqJanela->objectName().isEmpty())
            ListaSeqJanela->setObjectName("ListaSeqJanela");
        ListaSeqJanela->resize(1147, 777);
        ListaSeqJanela->setMinimumSize(QSize(100, 100));
        ListaSeqJanela->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(ListaSeqJanela);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(350, 10, 741, 80));
        LayoutTitulo = new QVBoxLayout(verticalLayoutWidget_2);
        LayoutTitulo->setObjectName("LayoutTitulo");
        LayoutTitulo->setContentsMargins(0, 0, 0, 0);
        frameTitulo = new QFrame(verticalLayoutWidget_2);
        frameTitulo->setObjectName("frameTitulo");
        frameTitulo->setFrameShape(QFrame::StyledPanel);
        frameTitulo->setFrameShadow(QFrame::Raised);
        titulo_pagina = new QLabel(frameTitulo);
        titulo_pagina->setObjectName("titulo_pagina");
        titulo_pagina->setGeometry(QRect(20, 10, 711, 51));
        QFont font;
        font.setPointSize(9);
        font.setKerning(false);
        titulo_pagina->setFont(font);
        titulo_pagina->setAlignment(Qt::AlignCenter);
        line_7 = new QFrame(frameTitulo);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(0, 60, 769, 3));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        LayoutTitulo->addWidget(frameTitulo);

        menu_dados = new QFrame(centralwidget);
        menu_dados->setObjectName("menu_dados");
        menu_dados->setGeometry(QRect(50, 100, 281, 321));
        menu_dados->setLayoutDirection(Qt::LeftToRight);
        menu_dados->setFrameShape(QFrame::StyledPanel);
        menu_dados->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(menu_dados);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 10, 221, 291));
        Layout_menu_dados = new QVBoxLayout(verticalLayoutWidget);
        Layout_menu_dados->setObjectName("Layout_menu_dados");
        Layout_menu_dados->setSizeConstraint(QLayout::SetDefaultConstraint);
        Layout_menu_dados->setContentsMargins(0, 0, 0, 0);
        frameCriarLista = new QFrame(verticalLayoutWidget);
        frameCriarLista->setObjectName("frameCriarLista");
        frameCriarLista->setFrameShape(QFrame::StyledPanel);
        frameCriarLista->setFrameShadow(QFrame::Raised);
        frameInputTamanhoLista_2 = new QFrame(frameCriarLista);
        frameInputTamanhoLista_2->setObjectName("frameInputTamanhoLista_2");
        frameInputTamanhoLista_2->setGeometry(QRect(0, 0, 221, 45));
        frameInputTamanhoLista_2->setMinimumSize(QSize(188, 45));
        frameInputTamanhoLista_2->setMaximumSize(QSize(242, 45));
        frameInputTamanhoLista_2->setFrameShape(QFrame::StyledPanel);
        frameInputTamanhoLista_2->setFrameShadow(QFrame::Raised);
        InputTamanhoLista = new QLineEdit(frameInputTamanhoLista_2);
        InputTamanhoLista->setObjectName("InputTamanhoLista");
        InputTamanhoLista->setGeometry(QRect(0, 0, 221, 45));
        InputTamanhoLista->setMinimumSize(QSize(188, 45));
        InputTamanhoLista->setMaximumSize(QSize(242, 45));
        InputTamanhoLista->setFrame(true);
        InputTamanhoLista->setAlignment(Qt::AlignCenter);

        Layout_menu_dados->addWidget(frameCriarLista);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonCriaLista = new QPushButton(verticalLayoutWidget);
        buttonCriaLista->setObjectName("buttonCriaLista");
        buttonCriaLista->setMaximumSize(QSize(90, 40));

        horizontalLayout->addWidget(buttonCriaLista);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        Layout_menu_dados->addLayout(horizontalLayout);

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
        labelValorRemovido->setGeometry(QRect(0, 0, 221, 41));
        labelValorRemovido->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(frameValorRemovido);


        Layout_menu_dados->addLayout(horizontalLayout_12);

        pushButtonVoltar = new QPushButton(centralwidget);
        pushButtonVoltar->setObjectName("pushButtonVoltar");
        pushButtonVoltar->setGeometry(QRect(50, 10, 91, 81));
        menu_Busca = new QFrame(centralwidget);
        menu_Busca->setObjectName("menu_Busca");
        menu_Busca->setGeometry(QRect(50, 430, 281, 301));
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

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        buttonBuscarValor = new QPushButton(verticalLayoutWidget_3);
        buttonBuscarValor->setObjectName("buttonBuscarValor");
        buttonBuscarValor->setMaximumSize(QSize(150, 30));

        horizontalLayout_5->addWidget(buttonBuscarValor);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        Layout_menu_dados_2->addLayout(horizontalLayout_5);

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

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        buttonBuscarPosicao = new QPushButton(verticalLayoutWidget_3);
        buttonBuscarPosicao->setObjectName("buttonBuscarPosicao");
        buttonBuscarPosicao->setMaximumSize(QSize(200, 40));

        horizontalLayout_6->addWidget(buttonBuscarPosicao);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);


        Layout_menu_dados_2->addLayout(horizontalLayout_6);

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

        frameGrid = new QFrame(centralwidget);
        frameGrid->setObjectName("frameGrid");
        frameGrid->setGeometry(QRect(350, 100, 741, 631));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameGrid->sizePolicy().hasHeightForWidth());
        frameGrid->setSizePolicy(sizePolicy);
        frameGrid->setFrameShape(QFrame::StyledPanel);
        frameGrid->setFrameShadow(QFrame::Raised);
        ListaSeqJanela->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ListaSeqJanela);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1147, 17));
        ListaSeqJanela->setMenuBar(menubar);
        statusbar = new QStatusBar(ListaSeqJanela);
        statusbar->setObjectName("statusbar");
        ListaSeqJanela->setStatusBar(statusbar);

        retranslateUi(ListaSeqJanela);

        QMetaObject::connectSlotsByName(ListaSeqJanela);
    } // setupUi

    void retranslateUi(QMainWindow *ListaSeqJanela)
    {
        ListaSeqJanela->setWindowTitle(QCoreApplication::translate("ListaSeqJanela", "MainWindow", nullptr));
        titulo_pagina->setText(QCoreApplication::translate("ListaSeqJanela", "Lista Sequencial", nullptr));
        InputTamanhoLista->setInputMask(QString());
        InputTamanhoLista->setText(QString());
        buttonCriaLista->setText(QCoreApplication::translate("ListaSeqJanela", "Criar ", nullptr));
        input_numero->setInputMask(QString());
        input_numero->setText(QString());
        input_posicao->setInputMask(QString());
        input_posicao->setText(QString());
        buttonInserir->setText(QCoreApplication::translate("ListaSeqJanela", "Inserir", nullptr));
        buttonRemover->setText(QCoreApplication::translate("ListaSeqJanela", "Remover", nullptr));
        labelValorRemovido->setText(QString());
        pushButtonVoltar->setText(QCoreApplication::translate("ListaSeqJanela", "Voltar", nullptr));
        input_numero_busca->setInputMask(QString());
        input_numero_busca->setText(QString());
        buttonBuscarValor->setText(QCoreApplication::translate("ListaSeqJanela", "Procurar", nullptr));
        input_posicao_busca->setInputMask(QString());
        input_posicao_busca->setText(QString());
        buttonBuscarPosicao->setText(QCoreApplication::translate("ListaSeqJanela", "Buscar", nullptr));
        labelRepostaBusca->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListaSeqJanela: public Ui_ListaSeqJanela {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELASEQ_H
