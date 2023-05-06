
#ifndef LISTASEQ_H_
#define LISTASEQ_H_



class ListaSeq {

private:
    long *dados;
    long nElementos;
    int Tamanho;
public:
    ListaSeq(int tamanho);
	virtual ~ListaSeq();

    bool vazia();
    bool cheia();
    long tamanho();
    long tamanhoMax();
    long elemento(long pos);
    long posicao (long valor);
    long posicao (long valor, long desloc);
    bool insere (long pos, long valor);
    long remove(long pos);


};

#endif /* LISTASEQ_H_ */
