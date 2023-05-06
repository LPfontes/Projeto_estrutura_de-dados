

#ifndef LSE_H_
#define LSE_H_

#include "NoLSE.h"


class LSE {

private:
    NoLSE *cabeca;
    long nElementos;

    bool insereInicioLista(long valor);
    bool insereMeioLista(long pos, long valor);

    long removeInicioLista();
    long removeNaLista(long pos);

public:
	LSE();
	virtual ~LSE();

	bool vazia();
    long tamanho();
    long elemento(long pos);
    long posicao (long valor);
    bool insere (long pos, long valor);
    bool insere (long valor);
    long remove(long pos);

};

#endif /* LSE_H_ */
