
#ifndef LDEFRAME_H
#define LDEFRAME_H

#include "Noframe.h"


class LDEFrame {

private:
    NoFrame *inicio;
    NoFrame *fim;

    long nElementos;
    NoFrame* getNo(long pos);
    bool insereInicioLista(Frame* valor);
    bool insereMeioLista(long pos, Frame* valor);
    bool insereFimLista(Frame* valor);
    Frame*  removeInicioListaUnitaria();
    Frame* removeInicioLista();
    Frame* removeMeioLista(long pos);
    Frame* removeNaLista(long pos);
    Frame* removeFimLista();
public:
    LDEFrame();
    virtual ~LDEFrame();

    bool vazia();
    long tamanho();
    Frame* elemento(long pos);
    long posicao (Frame* dado);
    bool insere (long pos, Frame* valor);
    bool insere (Frame* valor);
    Frame* remove(long pos);

};


#endif // LDEFRAME_H
