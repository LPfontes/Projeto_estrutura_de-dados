
#ifndef CONTROLLISTASLDE_H
#define CONTROLLISTASLDE_H

#include <QGridLayout>
#include <QLabel>
#include "LDE.h"
#include "resposta.h"
#include "ldeframe.h"



class controllistaslde
{
public:
    controllistaslde(QFrame* frameGrid);
    resposta adicionar(QString posicao,QString valor);

    resposta remover(QString posicao);
    resposta buscarPosicao(QString posicao);
    resposta buscarValor(QString valor);
    void atualizarGrid();



private:
    LDEFrame *frames ;  // array de frames que repreentam os rentangulos
    LDE *lista;
    QGridLayout * grid;
    QFrame* frameGrid;
    int tamanho;
};

#endif // CONTROLLISTASLDE_H
