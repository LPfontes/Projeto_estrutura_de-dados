
#ifndef LISTAQLABEL_H
#define LISTAQLABEL_H

#include "labelnode.h"

class listaLabel {

private:
    NoLabel *cabeca;
    long nElementos;
    NoLabel* getNo(long pos);
    bool insereInicioLista(QLabel* valor);
    bool insereMeioLista(long pos, QLabel* valor);

    QLabel* removeInicioLista();
    QLabel* removeNaLista(long pos);

public:
    listaLabel();
    virtual ~listaLabel();

    bool vazia();
    long tamanho();
    QLabel* elemento(long pos);

    bool insere (long pos, QLabel* valor);
    bool insere (QLabel* valor);
    QLabel* remove(long pos);

};
#endif // LISTAQLABEL_H
