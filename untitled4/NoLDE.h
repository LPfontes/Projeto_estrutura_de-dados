/*
 * No.h
 *
 *  Created on: 20 de out. de 2022
 *      Author: tiagomaritan
 */

#ifndef NOLDE_H_
#define NOLDE_H_

class NoLDE {

private:
	int conteudo;
	NoLDE *ant;
	NoLDE *prox;

public:
	NoLDE();
	virtual ~NoLDE();

	int getConteudo();
	NoLDE *getProx();
	NoLDE *getAnt();

	void setConteudo(int conteudo);
	void setProx(NoLDE *prox);
	void setAnt(NoLDE *ant);

};

#endif /* NOLDE_H_ */
