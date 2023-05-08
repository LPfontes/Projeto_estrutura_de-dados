
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonListaSeq, &QPushButton::clicked, this, &MainWindow::onbuttonListaSeq_clicked);
    connect(ui->buttonLSE, &QPushButton::clicked, this, &MainWindow::onbuttonListaLSE_clicked);
    connect(ui->buttonLDE, &QPushButton::clicked, this, &MainWindow::onbuttonListaLDE_clicked);
    this->setWindowTitle("Listas ");
    this->setWindowIcon(QIcon(":/assets/img/list.png"));
    QString qssFilePath = QString(":/assets/img/styles.qss") ;
    //    QString qssFilePath = QCoreApplication::applicationDirPath() + "/styles.qss";
    QFile qssFile( qssFilePath );
    qssFile.open(QFile::ReadOnly);
    styleSheet =new QString(QLatin1String(qssFile.readAll())) ;
    this->setStyleSheet(*styleSheet);

}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::onbuttonListaSeq_clicked()
{
    ListaSeqJanela *janelaSeq  = new ListaSeqJanela(); // criando uma nova janela da lista sequencial
    janelaSeq->setStyleSheet(*styleSheet);
    janelaSeq->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(janelaSeq, &QMainWindow::destroyed, this, &QMainWindow::show); //conectado a nova janela a janela principal caso a nova janela seja fechada a janela principal reaparece.
    janelaSeq ->show();
    hide(); // colocando a janela principal em modo escondido
}
void MainWindow::onbuttonListaLDE_clicked()
{
    LDEJanela *janelaLDE  = new LDEJanela(); // criando uma nova janela da lista sequencial

    janelaLDE->setStyleSheet(*styleSheet);
    janelaLDE->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(janelaLDE, &QMainWindow::destroyed, this, &QMainWindow::show); //conectado a nova janela a janela principal caso a nova janela seja fechada a janela principal reaparece.
    janelaLDE ->show();
    hide(); // colocando a janela principal em modo escondido
}
void MainWindow::onbuttonListaLSE_clicked()
{
    LSEJanela *janelaLSE  = new LSEJanela(); // criando uma nova janela da lista sequencial
    janelaLSE->setStyleSheet(*styleSheet);
    janelaLSE->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(janelaLSE, &QMainWindow::destroyed, this, &QMainWindow::show); //conectado a nova janela a janela principal caso a nova janela seja fechada a janela principal reaparece.
    janelaLSE ->show();
    hide(); // colocando a janela principal em modo escondido
}
