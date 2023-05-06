
#ifndef RESPOSTA_H
#define RESPOSTA_H

#include "LSE.h"
#include "LDE.h"

#include "ListaSeq.h"
#include "listaSeqframe.h"
#include "lseframe.h"
#include "ldeframe.h"

#include <QGridLayout>

class resposta
{
public:
    Frame* getFrame();
    QString getMensagem();
    ListaSeqFrame* getListaSeqFrame();


    LSEFrame* getLSEFrame();
    LDEFrame* getLDEFrame();

    ListaSeq* getlista();
    int getPosicao();
    int getLinha();
    int getColuna();
    LSE* getLSE();
    QGridLayout* getGrid();
    void setFrame(Frame* frame);
    void setLSE(LSE* listaLSE);
    void setMensagem(QString mensagem);
    void setListaSeqFrame(ListaSeqFrame* ListaSFrame);


    void setLSEFrame(LSEFrame* LSEframe);
    void setLDEFrame(LDEFrame* LDEframe);

    void setlista(ListaSeq* lista);
    void setPosicao(int posicao);
    void setGrid(QGridLayout* grid);
    void setLinha(int linha);
    void setColuna(int coluna);
    resposta();
private:
    Frame* frame;
    QString mensagem;
    ListaSeqFrame* ListaSFrame;
    LSEFrame* LSEframe;
    LDEFrame* LDEframe;
    ListaSeq * lista;
    LSE* listaLSE;
    LDE* listaLDE;
    QGridLayout* grid;
    int posicao;
    int coluna;
    int linha;
};

#endif // REPOSTA_H
