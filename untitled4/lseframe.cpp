
#include "lseframe.h"


#include <stdlib.h>

LSEFrame::LSEFrame() {
    cabeca = NULL;
    nElementos = 0;
}

LSEFrame::~LSEFrame() {
}


/** Verifica se a Lista está vazia */
bool LSEFrame::vazia() {
    return (nElementos == 0);
}


/**Obtém o tamanho da Lista*/
long LSEFrame::tamanho() {
    //return nElementos;

    NoFrame *aux = cabeca;
    long cont = 0;
    while(aux != NULL){
        aux = aux->getProx();
        cont++;
    }
    return cont;
}

/** Obtém o i-ésimo elemento de uma lista
      Retorna o valor encontrado. */
Frame* LSEFrame::elemento (long pos) {
    if (vazia())
        return nullptr; // Consulta falhou


    if ((pos < 1) || (pos > tamanho()))
        return nullptr; // Posicao invalida

    NoFrame *aux = cabeca;

    // Percorre a lista do 1o elemento até pos
    for (long i =1; i < pos; i++){
        // modifica "aux" para apontar para o proximo elemento da lista
        aux = aux->getProx();
    }

    return aux->getConteudo();
}


    /** Insere nó em lista vazia */
bool LSEFrame::insereInicioLista(Frame* valor) {
    // Aloca memoria para novo no
    NoFrame *novoNo = new NoFrame();

    // Insere novo elemento na cabeca da lista
    novoNo->setConteudo(valor);

    novoNo->setProx(cabeca);
    cabeca = novoNo;
    nElementos++;
    return true;
}

/** Insere nó no meio da lista */
bool LSEFrame::insereMeioLista(long pos, Frame* valor){

    // Aloca memoria para novo no
    NoFrame *novoNo = new NoFrame();
    novoNo->setConteudo(valor);

    // Localiza a pos. ANTERIOR onde será inserido o novo nó
    NoFrame *aux = cabeca;
    for (long i =1; i < pos-1; i++){
        // modifica "aux" para apontar para o proximo elemento da lista
        aux = aux->getProx();
    }

    // Insere novo elemento apos aux
    novoNo->setProx(aux->getProx());
    aux->setProx(novoNo);

    nElementos++;
    return true;
}


/**Insere um elemento em uma determinada posição
        Retorna true se conseguir inserir e
        false caso contrario */
bool LSEFrame::insere(long pos, Frame* valor) {
    if ((vazia()) && (pos != 1))
        return false; /* lista vazia mas posicao inv*/

    if ((pos <= 0) || pos > (nElementos+1))
        return false; // posicao invalida

    /* inserção no início da lista (ou lista vazia)*/
    if (pos == 1)
        return insereInicioLista(valor);
    else
        return insereMeioLista(pos, valor);
}
bool LSEFrame::insere(Frame* valor) {

    if(vazia()){
        return insereInicioLista(valor);
    }else
        return insereMeioLista(nElementos+1, valor);
}
/** Remove elemento do início da lista */
Frame* LSEFrame::removeInicioLista(){

    NoFrame *p = cabeca;

    // Dado recebe o dado removido
    Frame* valorRemovido = p->getConteudo();

    // Retira o 1o elemento da lista (p)
    cabeca = p->getProx();
    nElementos--;

    // Remove o objeto apontado por p
    delete p;

    return valorRemovido;
}

    /** Remove elemento no meio da lista */
Frame* LSEFrame::removeNaLista(long pos){
    // Localiza os nó a ser removido (atual) e o seu
    // antecessor (antecessor)
    NoFrame *antecessor = cabeca;
    for(long i = 1; i < pos-1; i++) {
        antecessor = antecessor->getProx();
    }

    NoFrame *atual = antecessor->getProx();

    // Guarda o valor a ser removido
    Frame* valorRemovido = atual->getConteudo();

    // Faz o campo prox de antecessor apontar pro prox de atual
    //No aux = atual.getProx();
    //antecessor.setProx(aux);
    antecessor->setProx(atual->getProx());

    // Decrementa o numero de elementos
    nElementos--;

    // Libera a area de memoria do no atual
    delete atual;

    return valorRemovido;
}

/**Remove um elemento de uma determinada posição
     Retorna o valor a ser removido.
    -1 se a posição for inválida ou a lista estiver vazia*/
Frame* LSEFrame::remove(long pos) {
    if (vazia())
        return nullptr; // Lista vazia

    if ((pos <= 0) || (pos > nElementos))
        return nullptr; // Posicao invalida

    if (pos == 1)
        return removeInicioLista();
    else
        return removeNaLista(pos);
}

NoFrame* LSEFrame::getNo(long pos){
    NoFrame* aux = cabeca;
    for (int var = 0; var < pos; ++var) {
        aux = aux->getProx();
    }

    return aux;
}
