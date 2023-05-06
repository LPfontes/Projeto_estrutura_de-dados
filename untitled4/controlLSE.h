
#ifndef CONTROLLISTASLSE_H
#define CONTROLLISTASLSE_H

#include <QGridLayout>
#include <QLabel>
#include "LSE.h"
#include "resposta.h"
#include "lseframe.h"



class controllistaslse
{
public:
    controllistaslse(QFrame* frameGrid);
    resposta adicionar(QString posicao,QString valor);

    resposta remover(QString posicao);
    resposta buscarPosicao(QString posicao);
    resposta buscarValor(QString valor);
    void atualizarGrid();



private:
    LSEFrame *frames ;  // array de frames que repreentam os rentangulos
    LSE *lista;
    QGridLayout * grid;
    QFrame* frameGrid;
    int tamanho;
};

#endif // CONTROLLISTASLSE_H
