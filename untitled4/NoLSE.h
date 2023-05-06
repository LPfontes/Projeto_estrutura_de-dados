/*
 * No.h
 *
 *  Created on: 19 de out. de 2022
 *      Author: Administrador
 */

#ifndef NOLSE_H_
#define NOLSE_H_

class NoLSE {

private:
    long conteudo;
	NoLSE *prox;

public:
	NoLSE();
	virtual ~NoLSE();

    long getConteudo();
	NoLSE *getProx();

    void setConteudo(long conteudo);
	void setProx(NoLSE *prox);


};

#endif /* NOLSE_H_ */
