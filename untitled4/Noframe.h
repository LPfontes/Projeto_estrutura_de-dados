
#ifndef NOFRAME_H
#define NOFRAME_H

#include "frame.h"

class NoFrame {

private:
    Frame* conteudo;
    NoFrame *ant;
    NoFrame *prox;

public:
    NoFrame();
    virtual ~NoFrame();
    Frame* getConteudo();
    NoFrame  *getProx();
    NoFrame *getAnt();

    void setConteudo(Frame* conteudo);
    void setProx(NoFrame *prox);
    void setAnt(NoFrame *ant);

};

#endif /* NOFRAME_H */


