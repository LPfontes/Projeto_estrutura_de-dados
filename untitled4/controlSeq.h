
#ifndef CONTROLLISTASSEQ_H
#define CONTROLLISTASSEQ_H

#include <QGridLayout>
#include <QLabel>
#include "ListaSeq.h"
#include "resposta.h"
#include "listaSeqFrame.h"


class controlListasSeq
{
public:
    controlListasSeq(QFrame* frameGrid);
    resposta adicionar(QString posicao,QString valor);
    resposta remover(QString posicao);
    resposta buscarPosicao(QString posicao);
    resposta buscarValor(QString valor);
    void criarLista(int tamanho);

private:
    ListaSeqFrame *frames ;  // array de frames que repreentam os rentangulos
    ListaSeq *lista;
    QGridLayout * grid;
    QFrame* frameGrid;
    int tamanho;
};


#endif // CONTROLLISTASSEQ_H
