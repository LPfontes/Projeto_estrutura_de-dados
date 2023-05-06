#include <QMessageBox>
#include"LSE.h"
#include <QThread>
#include <QTimer>
#include "controlLSE.h"


controllistaslse::controllistaslse(QFrame* frameGrid)
{
    this->frameGrid = frameGrid;
    lista = new LSE();
    this->grid = nullptr;
    frames = new LSEFrame();

}
resposta controllistaslse::adicionar(QString posicao,QString valor){

    int Posicao = posicao.toInt();
    long Valor = valor.toInt();
    resposta resposta;
    int pos;
    if(lista->vazia()){
        if(Posicao < 0 ||  Posicao > 1){
            resposta.setMensagem(QString("erro posicao invalida"));
            return resposta;
        }

            pos = 1;
            resposta.setMensagem("inicio lista");



    }else{
        if(Posicao < 0 ||  Posicao > lista->tamanho() + 1){
            resposta.setMensagem(QString("erro posicao invalida"));
            return resposta;
        }
        if(Posicao == 0){
            pos = lista->tamanho() + 1;
            resposta.setMensagem("fim lista");

        }else if(Posicao != 1){
            pos = Posicao;
            resposta.setMensagem("meio lista");
        }else{
            pos = Posicao;
            resposta.setMensagem("inicio lista");
        }
    }

    Frame * frame = new Frame(1);
    QString * string = new QString(QString::number(Valor));
    frame->label->setText(*string);
    resposta.setFrame(frame);



    lista->insere(pos,Valor);

    resposta.setGrid(grid);
    resposta.setLSEFrame(frames);
    resposta.setPosicao(pos);


     return resposta;
    }



 resposta controllistaslse::remover(QString posicao){
    int Posicao = posicao.toInt();
    resposta resposta;
    if(lista->vazia()){
        resposta.setMensagem(QString("erro lista vazia"));
        return resposta;
    }
    if(Posicao < 0 || Posicao > lista->tamanho() ){
        resposta.setMensagem(QString("erro posicao invalida"));
        return resposta;
    }
    if(Posicao == 0){ // se o valor de posição nao tiver sido definida sera removido o ultimo elemento
        int pos = lista->tamanho();
        QString * string_valor_removido = new QString(QString::number(lista->remove(pos)));

        resposta.setLSEFrame(frames);
        resposta.setPosicao(pos);
           resposta.setMensagem("Valor removido "+*string_valor_removido);


    }else{

        QString * string_valor_removido = new QString(QString::number(lista->remove(Posicao)));
        int max = lista->tamanho();

        resposta.setLSEFrame(frames);
        resposta.setPosicao(Posicao);
        resposta.setMensagem("Valor removido "+*string_valor_removido);

    }
    return resposta;
 }



resposta controllistaslse::buscarPosicao(QString posicao){
    resposta resposta;
    int Posicao = posicao.toInt();
    long valor;

    if(lista->vazia()){
        resposta.setMensagem(QString("erro lista vazia"));
        return resposta;
    }
    if(Posicao < 0 || Posicao > lista->tamanho() ){
        resposta.setMensagem(QString("erro posicao invalida"));
        return resposta;
    }
    valor = lista->elemento(Posicao);
    QString *stringValor;
    if(valor != -1){
    stringValor = new QString("Elemento contido na posição " + posicao  + "<br>" + QString::number(valor));
    resposta.setLSEFrame(frames);
    resposta.setPosicao(Posicao);

    }else{
    stringValor = new QString("Posicão vazia.");
    }

    resposta.setMensagem(*stringValor);
    return resposta;

}

resposta controllistaslse::buscarValor(QString valor){
    resposta resposta;
    if(lista->vazia()){
        resposta.setMensagem(QString("erro lista vazia"));
        return resposta;
    }
    QString *stringValor;
    long Valor = valor.toInt();
    long posicao;
    posicao = lista->posicao(Valor);

    if(posicao >= 1){

        stringValor = new QString("Elemento "+ valor + " contido na posição " + QString::number(posicao));
        resposta.setLSEFrame(frames);
        resposta.setPosicao(posicao);
    }else{
        stringValor = new QString("Valor não encontrado.");
        resposta.setLSEFrame(frames);

    }
    resposta.setMensagem(*stringValor);
    return resposta;
}
void controllistaslse::atualizarGrid(){
    if(grid != nullptr){
        QLayoutItem* child;
        while ((child = grid->takeAt(0)) != nullptr) {
            grid->removeWidget( child->widget()); // deleta o widget associado ao item do layout

        }
    }else{
        grid = new QGridLayout();
        frameGrid->setLayout(grid);

    }
        for (int i = 1, linha = 1,coluna = 1,cont = 0; i <= frames->tamanho(); ++i,cont++,coluna++) {
        if(cont == 8){
            linha++;
            coluna = 1;
            cont = 0;
        }
        frames->elemento(i)->labelPosicao->setText(QString::number(i));
        frames->elemento(i)->coluna = coluna;
        frames->elemento(i)->linha = linha;

        grid->addWidget(frames->elemento(i),linha,coluna,1,1,Qt::AlignJustify); // adicionado os frames ao grid da janela

    }


}

