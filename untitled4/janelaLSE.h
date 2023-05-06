#ifndef LSEJANELA_H
#define LSEJANELA_H

#include <QMainWindow>
#include "controlLSE.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LSEJanela; }
QT_END_NAMESPACE

class LSEJanela : public QMainWindow
{
    Q_OBJECT

public:
    explicit LSEJanela(QWidget *parent = nullptr);
    ~LSEJanela();
    void on_button_inserir_clicked();
    void on_button_remover_clicked();
    void on_button_BuscarValor_clicked();
    void on_button_BuscarPosicao_clicked();

    void AlterarCorGridRemover(QString mensangem,LSEFrame* frames,int i,int index);
    void adicionar(Frame* frame,QGridLayout * grid,LSEFrame* frames,int i,int index,int posicao);
    void adicionarinicio(Frame* frame,QGridLayout * grid,LSEFrame* frames,int posicao);
    void adicionarFinal(Frame* frame,QGridLayout * grid,LSEFrame* frames,int i,int index,int posicao);
    void AlterarCorGridProcura(QString mensangem,LSEFrame* frames, int i,int index);

private:
    Ui::LSEJanela *ui;
    controllistaslse* ControlLista;
    Frame* frame;;
};

#endif // LSEJANELA_H
