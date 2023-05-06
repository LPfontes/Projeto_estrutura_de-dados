
#ifndef LABELNODE_H
#define LABELNODE_H

#include <QLabel>


class NoLabel {

private:
    QLabel* conteudo;
    NoLabel *ant;
    NoLabel *prox;

public:
    NoLabel();
    virtual ~NoLabel();
    QLabel* getConteudo();
    NoLabel  *getProx();
    NoLabel *getAnt();

    void setConteudo(QLabel* conteudo);
    void setProx(NoLabel *prox);
    void setAnt(NoLabel *ant);

};
#endif // LABELNODE_H
