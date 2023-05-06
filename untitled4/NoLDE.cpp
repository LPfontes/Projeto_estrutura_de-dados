/*
 * No.cpp
 *
 *  Created on: 20 de out. de 2022
 *      Author: tiagomaritan
 */

#include "NoLDE.h"
#include <stdlib.h>

NoLDE::NoLDE() {
	setAnt(NULL);
	setProx(NULL);
}

NoLDE::~NoLDE() {
}

int NoLDE::getConteudo() {
	return conteudo;
}

void NoLDE::setConteudo(int conteudo) {
	this->conteudo = conteudo;
}

NoLDE *NoLDE::getProx() {
	return prox;
}

void NoLDE::setProx(NoLDE *prox) {
	this->prox = prox;
}

NoLDE *NoLDE::getAnt() {
	return ant;
}

void NoLDE::setAnt(NoLDE *ant) {
	this->ant = ant;
}


