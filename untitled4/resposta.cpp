
#include "resposta.h"

resposta::resposta()
{

}

Frame* resposta::getFrame(){
    return frame;
}

QString resposta::getMensagem(){
    return mensagem;
}

void resposta::setFrame(Frame* frame){
    this->frame = frame;
}

void resposta::setMensagem(QString mensagem){
    this->mensagem = mensagem;
}
void resposta::setListaSeqFrame(ListaSeqFrame* ListaSFrame){
    this->ListaSFrame = ListaSFrame;
}

ListaSeqFrame* resposta::getListaSeqFrame(){
    return ListaSFrame;
}
void resposta::setlista(ListaSeq* lista){
    int tamanho = lista->tamanhoMax();
    this->lista = new ListaSeq(tamanho);
    for (int i = 1; i <=tamanho ; ++i) {
        this->lista->insere(i,lista->elemento(i));

    }
}
ListaSeq*  resposta::getlista(){
    return lista;
}
LSEFrame* resposta::getLSEFrame(){
    return LSEframe;
}

LDEFrame* resposta::getLDEFrame(){
    return LDEframe;
}


int resposta::getPosicao(){
    return posicao;
}
void resposta::setPosicao(int posicao){
    this->posicao = posicao;

}
void resposta::setGrid(QGridLayout* grid){
    this->grid = grid;
}

void resposta::setLinha(int linha){
    this->linha = linha;
}

void resposta::setColuna(int coluna){
    this->coluna =coluna;
}
int resposta::getLinha(){
    return linha;
}

int resposta::getColuna(){
    return coluna;
}

QGridLayout* resposta::getGrid(){
    return grid;
}
LSE* resposta::getLSE(){
    return listaLSE;
}
void resposta::setLSE(LSE* listaLSE){
    this->listaLSE = listaLSE;
}

void resposta::setLSEFrame(LSEFrame* LSEframe){
    this->LSEframe = LSEframe;
}

void resposta::setLDEFrame(LDEFrame* LDEframe){
    this->LDEframe = LDEframe;
}


