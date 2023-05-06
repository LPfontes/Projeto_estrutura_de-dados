#ifndef LISTASEQJANELA_H
#define LISTASEQJANELA_H

#include <QMainWindow>
#include "controlSeq.h"
#include <QThreadPool>
QT_BEGIN_NAMESPACE
namespace Ui { class ListaSeqJanela; }
QT_END_NAMESPACE

class ListaSeqJanela : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListaSeqJanela(QWidget *parent = nullptr);
    ~ListaSeqJanela();
    void on_button_inserir_clicked();
    void on_button_remover_clicked();
    void on_button_BuscarValor_clicked();
    void on_button_BuscarPosicao_clicked();
    void on_button_CriarLista_clicked();
    void AlterarCor(Frame* frame, QTimer* timer);
    void AlterarCorGrid(QString mensangem,ListaSeqFrame* frames,ListaSeq* lista,int i,int index);

private:
    Ui::ListaSeqJanela *ui;
    controlListasSeq* lista;

    Frame* frame;
};

#endif // LISTASEQJANELA_H
