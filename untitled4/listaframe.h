
#ifndef LISTAFRAME_H
#define LISTAFRAME_H

#include "Noframe.h"


class ListaFrame {

private:
    NoFrame *cabeca;
    long nElementos;
    NoFrame* getNo(long pos);
    bool insereInicioLista(Frame* valor);
    bool insereMeioLista(long pos, Frame* valor);

    Frame* removeInicioLista();
    Frame* removeNaLista(long pos);

public:
    ListaFrame();
    virtual ~ListaFrame();

    bool vazia();
    long tamanho();
    Frame* elemento(long pos);

    bool insere (long pos, Frame* valor);
    bool insere (Frame* valor);
    Frame* remove(long pos);

};


#endif // LISTAFRAME_H
