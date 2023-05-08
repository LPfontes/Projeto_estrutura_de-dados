#ifndef LDEJANELA_H
#define LDEJANELA_H

#include <QMainWindow>
#include "controlLDE.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LDEJanela; }
QT_END_NAMESPACE

class LDEJanela : public QMainWindow
{
    Q_OBJECT

public:
    explicit LDEJanela(QWidget *parent = nullptr);
    ~LDEJanela();
    void on_button_inserir_clicked();
    void on_button_remover_clicked();
    void on_button_BuscarValor_clicked();
    void on_button_BuscarPosicao_clicked();


    void RemoverViaInicio(QString mensangem,LDEFrame* frames,int i,int index);
    void RemoverViaFim(QString mensangem,LDEFrame* frames,int i,int index);

    void adicionar(Frame* frame,QGridLayout * grid,LDEFrame* frames,int posicaoAtual,int posicaoAnterior,int posicao);

    void adicionarinicio(Frame* frame,QGridLayout * grid,LDEFrame* frames,int posicao);

    void adicionarFinal(Frame* frame,QGridLayout * grid,LDEFrame* frames,int posicaoAtual,int posicao);

    void adicionarViaFinal(Frame* frame,QGridLayout * grid,LDEFrame* frames,int posicaoAtual,int posicaoAnterior,int posicao);

    void AlterarCorGridProcura(QString mensangem,LDEFrame* frames, int i,int index);

    void AlterarCorGridProcuraFim(QString mensangem,LDEFrame* frames, int i,int index);

    void AlterarCorGridRemoverFim(QString mensangem,LDEFrame* frames,int i,int index,int posicao);




private:
    Ui::LDEJanela *ui;
    controllistaslde* ControlLista;
    Frame* frame;;
};


#endif // LDEJANELA_H
