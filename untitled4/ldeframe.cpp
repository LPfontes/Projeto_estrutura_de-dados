
#include "ldeframe.h"


#include <stdlib.h>

LDEFrame::LDEFrame() {
    inicio = NULL;
    fim = NULL;
    nElementos = 0;
}

LDEFrame::~LDEFrame() {
}

/** Verifica se a Lista está vazia */
bool LDEFrame::vazia() {
    if (nElementos == 0)
        return true;
    else
         return false;
}

/**Obtém o tamanho da Lista*/
long LDEFrame::tamanho() {
    return nElementos;
}

/** Obtém o i-ésimo elemento de uma lista
    Retorna o valor encontrado. */
Frame* LDEFrame::elemento (long pos) {
    NoFrame *aux = inicio;
    long cont = 1;

    if (vazia())
        return nullptr; // Consulta falhou

    if ((pos < 1) || (pos > tamanho()))
        return nullptr; // Posicao invalida

    // Percorre a lista do 1o elemento até pos
    while (cont < pos){
        // modifica "aux" para apontar para o proximo elemento da lista
        aux = aux->getProx();
        cont++;
    }

    return aux->getConteudo();
}

/**Retorna a posição de um elemento pesquisado.
    Retorna 0 caso não seja encontrado */
long LDEFrame::posicao (Frame* dado) {
    long cont = 1;
    NoFrame *aux;

    /* Lista vazia */
if (vazia())
    return -1;

/* Percorre a lista do inicio ao fim até encontrar o elemento*/
    aux = inicio;
    while (aux != NULL) {
        /* Se encontrar o elemento, retorna sua posicao n;*/
if (aux->getConteudo() == dado)
    return cont;

/* modifica "aux" para apontar para o proximo elemento da lista */
aux = aux->getProx();
cont++;
}

return -1;
}

/** Insere nó em lista vazia */
bool LDEFrame::insereInicioLista(Frame* valor) {

    // Aloca memoria para novo no
    NoFrame *novoNo = new NoFrame();

    // Insere novo elemento na cabeca da lista
    novoNo->setConteudo(valor);
    novoNo->setProx(inicio);

    novoNo->setAnt(NULL); // Nova instrucao
    if (vazia())
        fim = novoNo; // Nova instrucao
    else
        inicio->setAnt(novoNo); // Nova instrucao

    inicio = novoNo;
    nElementos++;
    return true;
}

/** Insere nó no meio da lista */
bool LDEFrame::insereMeioLista(long pos, Frame* dado){

    long cont = 1;

    // Aloca memoria para novo no
    NoFrame *novoNo = new NoFrame();
    novoNo->setConteudo(dado);

    // Localiza a pos. onde será inserido o novo nó
    NoFrame *aux = inicio;
    while ((cont < pos-1) && (aux != NULL)){
        aux = aux->getProx();
        cont++;
    }

    if (aux == NULL)   // pos. inválida
        return false;

    // Insere novo elemento apos aux
    novoNo->setAnt(aux); // Nova instrucao
    novoNo->setProx(aux->getProx());

    aux->getProx()->setAnt(novoNo); // Nova instrucao

    aux->setProx(novoNo);

    nElementos++;
    return true;
}

/** Insere nó no fim da lista */
bool LDEFrame::insereFimLista(Frame* dado){
    // Aloca memoria para novo no
    NoFrame *novoNo = new NoFrame();
    novoNo->setConteudo(dado);
    novoNo->setProx(NULL);

    fim->setProx(novoNo);

    novoNo->setAnt(fim);  // Nova instrucao
    fim->setProx(novoNo); // Nova instrucao
    fim = novoNo; 		// Nova instrucao

    nElementos++;
    return true;
}

/**Insere um elemento em uma determinada posição
    Retorna true se conseguir inserir e false caso contrario */
bool LDEFrame::insere(long pos,Frame* dado) {

    if ((vazia()) && (pos != 1))
        return false; // lista vazia mas posicao inv

    // inserção no início da lista (ou lista vazia)
    if (pos == 1)
        return insereInicioLista(dado);
    /* inserção no fim da lista */
    else if (pos == nElementos+1)
        return insereFimLista(dado);
    /* inserção no meio da lista */
    else
        return insereMeioLista(pos, dado);
}

/** Remove elemento do início de uma lista unitária */
Frame* LDEFrame::removeInicioListaUnitaria(){
    Frame* dado = inicio->getConteudo();

    delete inicio;

    inicio = NULL;
    fim = NULL;
    nElementos--;
    return dado;
}

/** Remove elemento do início da lista */
Frame* LDEFrame::removeInicioLista(){
    NoFrame *p = inicio;

    // Dado recebe o dado removido
    Frame* dado = p->getConteudo();

    // Retira o 1o elemento da lista (p)
    inicio = p->getProx();
    p->getProx()->setAnt(NULL);  // Nova instrucao

    nElementos--;

    // Libera a memoria da regiao apontada por p
    delete p;

    return dado;
}

/** Remove elemento no meio da lista */
Frame* LDEFrame::removeMeioLista(long pos){
    NoFrame *p = inicio;
    long n = 1;

    // Localiza o nó que será removido
    while((n <= pos-1) && (p != NULL)){
        p = p->getProx();
        n++;
    }

    if (p == NULL)
        return nullptr; // pos. inválida

    Frame* dado = p->getConteudo();
    p->getAnt()->setProx(p->getProx());
    p->getProx()->setAnt(p->getAnt());

    nElementos--;

    // Libera a memoria da regiao apontada por p
    delete p;

    return dado;
}

/** Remove elemento do início da lista */
Frame* LDEFrame::removeFimLista(){
    NoFrame *p = fim;
    Frame* dado = p->getConteudo();

    fim->getAnt()->setProx(NULL);
    fim = fim->getAnt();
    nElementos--;

    delete p;

    return dado;
}


/**Remove um elemento de uma determinada posição
    Retorna o valor a ser removido.
    -1 se a posição for inválida ou a lista estiver vazia*/
Frame* LDEFrame::remove(long pos) {
    // Lista vazia
    if (vazia())
        return nullptr;

    // Remoção do elemento da cabeça da lista
    if ((pos == 1) && (tamanho() == 1))
        return removeInicioListaUnitaria();
    else if (pos == 1)
        return removeInicioLista();
    // Remocao no fim da lista
    else if (pos == tamanho())
        return removeFimLista();
    // Remoção em outro lugar da lista
    else
        return removeMeioLista(pos);
}
