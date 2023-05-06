
#include "Nolabel.h"
#include <stdlib.h>

NoLabel::NoLabel() {
    setAnt(NULL);
    setProx(NULL);
}

NoLabel::~NoLabel() {
}

QLabel* NoLabel::getConteudo() {
    return conteudo;
}

void NoLabel::setConteudo(QLabel* conteudo) {
    this->conteudo = conteudo;
}

NoLabel *NoLabel::getProx() {
    return prox;
}

void NoLabel::setProx(NoLabel *prox) {
    this->prox = prox;
}

NoLabel *NoLabel::getAnt() {
    return ant;
}

void NoLabel::setAnt(NoLabel *ant) {
    this->ant = ant;
}


