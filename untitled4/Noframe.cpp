
#include "Noframe.h"

#include <stdlib.h>

NoFrame::NoFrame() {
    setAnt(NULL);
    setProx(NULL);
}

NoFrame::~NoFrame() {
}

Frame* NoFrame::getConteudo() {
    return conteudo;
}

void NoFrame::setConteudo(Frame*  conteudo) {
    this->conteudo = conteudo;
}

NoFrame *NoFrame::getProx() {
    return prox;
}

void NoFrame::setProx(NoFrame *prox) {
    this->prox = prox;
}

NoFrame *NoFrame::getAnt() {
    return ant;
}

void NoFrame::setAnt(NoFrame *ant) {
    this->ant = ant;
}
