
#include "listaqlabel.h"
#include <QLabel>

#include <stdlib.h>

listaLabel::listaLabel() {
    cabeca = NULL;
    nElementos = 0;
}

listaLabel::~listaLabel() {
}


/** Verifica se a Lista está vazia */
bool listaLabel::vazia() {
    return (nElementos == 0);
}


/**Obtém o tamanho da Lista*/
long listaLabel::tamanho() {
    //return nElementos;

    NoLabel *aux = cabeca;
    long cont = 0;
    while(aux != NULL){
        aux = aux->getProx();
        cont++;
    }
    return cont;
}

/** Obtém o i-ésimo elemento de uma lista
      Retorna o valor encontrado. */
QLabel* listaLabel::elemento (long pos) {
    if (vazia())
        return nullptr; // Consulta falhou


    if ((pos < 1) || (pos > tamanho()))
        return nullptr; // Posicao invalida

    NoLabel *aux = cabeca;

    // Percorre a lista do 1o elemento até pos
    for (long i =1; i < pos; i++){
        // modifica "aux" para apontar para o proximo elemento da lista
        aux = aux->getProx();
    }

    return aux->getConteudo();
}

/**Retorna a posição de um elemento pesquisado.
        Retorna -1 caso não seja encontrado */


    /** Insere nó em lista vazia */
bool listaLabel::insereInicioLista(QLabel* valor) {
    // Aloca memoria para novo no
    NoLabel *novoNo = new NoLabel();

    // Insere novo elemento na cabeca da lista
    novoNo->setConteudo(valor);

    novoNo->setProx(cabeca);
    cabeca = novoNo;
    nElementos++;
    return true;
}

/** Insere nó no meio da lista */
bool listaLabel::insereMeioLista(long pos, QLabel* valor){

    // Aloca memoria para novo no
    NoLabel *novoNo = new NoLabel();
    novoNo->setConteudo(valor);

    // Localiza a pos. ANTERIOR onde será inserido o novo nó
    NoLabel *aux = cabeca;
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
bool listaLabel::insere(long pos, QLabel* valor) {
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
bool listaLabel::insere(QLabel* valor) {

    if(vazia()){
        return insereInicioLista(valor);
    }else
        return insereMeioLista(nElementos+1, valor);
}
/** Remove elemento do início da lista */
QLabel* listaLabel::removeInicioLista(){

    NoLabel *p = cabeca;

    // Dado recebe o dado removido
    QLabel* valorRemovido = p->getConteudo();

    // Retira o 1o elemento da lista (p)
    cabeca = p->getProx();
    nElementos--;

    // Remove o objeto apontado por p
    delete p;

    return valorRemovido;
}

    /** Remove elemento no meio da lista */
QLabel* listaLabel::removeNaLista(long pos){
    // Localiza os nó a ser removido (atual) e o seu
    // antecessor (antecessor)
    NoLabel *antecessor = cabeca;
    for(long i = 1; i < pos-1; i++) {
        antecessor = antecessor->getProx();
    }

    NoLabel *atual = antecessor->getProx();

    // Guarda o valor a ser removido
    QLabel* valorRemovido = atual->getConteudo();

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
QLabel* listaLabel::remove(long pos) {
    if (vazia())
        return nullptr; // Lista vazia

    if ((pos <= 0) || (pos > nElementos))
        return nullptr; // Posicao invalida

    if (pos == 1)
        return removeInicioLista();
    else
        return removeNaLista(pos);
}

NoLabel* listaLabel::getNo(long pos){
    NoLabel* aux = cabeca;
    for (int var = 0; var < pos; ++var) {
        aux = aux->getProx();
    }

    return aux;
}


