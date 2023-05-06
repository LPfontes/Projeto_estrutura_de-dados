
#ifndef LSEFRAME_H
#define LSEFRAME_H

#include "Noframe.h"


class LSEFrame {

private:
    NoFrame *cabeca;
    long nElementos;
    NoFrame* getNo(long pos);
    bool insereInicioLista(Frame* valor);
    bool insereMeioLista(long pos, Frame* valor);
    bool insereFimLista(Frame* valor);
    Frame* removeInicioLista();
    Frame* removeNaLista(long pos);

public:
    LSEFrame();
    virtual ~LSEFrame();

    bool vazia();
    long tamanho();
    Frame* elemento(long pos);
    long posicao (Frame* valor);
    bool insere (long pos, Frame* valor);
    bool insere (Frame* valor);
    Frame* remove(long pos);

};


#endif // LSEFRAME_H
