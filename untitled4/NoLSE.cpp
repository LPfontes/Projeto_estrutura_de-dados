/*
 * No.cpp
 *
 *  Created on: 19 de out. de 2022
 *      Author: Administrador
 */

#include <stdlib.h>
#include "NoLSE.h"

NoLSE::NoLSE() {
	setConteudo(0);
	setProx(NULL);
}

NoLSE::~NoLSE() {
}


long NoLSE::getConteudo() {
	return conteudo;
}

void NoLSE::setConteudo(long conteudo) {
 this->conteudo = conteudo;
}

NoLSE *NoLSE::getProx(){
	return prox;
}

void NoLSE::setProx(NoLSE *prox) {
	this->prox = prox;
}

