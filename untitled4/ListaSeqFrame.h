
#ifndef LISTASEQFRAME_H_
#define LISTASEQFRAME_H_

#include"frame.h"

class ListaSeqFrame {

private:
    Frame **dados;
    long nElementos;
    int Tamanho;
public:
    ListaSeqFrame(int tamanho);
    virtual ~ListaSeqFrame();

    bool vazia();
    bool cheia();
    long tamanho();
    long tamanhoMax();
    Frame* elemento(long pos);
    long posicao (Frame* valor);
    long posicao (Frame* valor, long desloc);
    bool insere (long pos, Frame* valor);
    Frame* remove(long pos);


};

#endif /* LISTASEQFRAME_H_ */
