
#include "controlSeq.h"
#include <QMessageBox>
#include"LSE.h"
#include <QThread>

controlListasSeq::controlListasSeq(QFrame* frameGrid)
{
    this->frameGrid = frameGrid;
    lista = nullptr;
    grid = new QGridLayout();


}
void controlListasSeq::criarLista(int tamanho){

    if(lista != nullptr){
        delete lista;

    }
    lista = new ListaSeq(tamanho);
    frames = new ListaSeqFrame(tamanho);
    if(grid != nullptr){
        QLayoutItem* child;
        while ((child = grid->takeAt(0)) != nullptr) {
            delete child->widget(); // deleta o widget associado ao item do layout
            delete child; // deleta o item do layout
        }
        if(!frames->vazia()){
            int max = frames->tamanho();
            for (int i = 1; i <= max; ++i) {
                frames->remove(1);
            }
        }

    }

    for (int i = 1; i<= tamanho; ++i) {

        frames->insere(i,new Frame(i,nullptr));

    }


    for (int i = 1, linha = 1,coluna = 1,cont = 0; i <= tamanho; ++i,cont++,coluna++) {
        if(cont == 8){
            linha++;
            coluna = 1;
            cont = 0;
        }
            grid->addWidget(frames->elemento(i),linha,coluna,1,1,Qt::AlignJustify); // adicionado os frames ao grid da janela
        }





    frameGrid->setLayout(grid);
    this->tamanho = tamanho;
}



resposta controlListasSeq::adicionar(QString posicao,QString valor){
    int Posicao = posicao.toInt();
    long Valor = valor.toInt();
    resposta resposta;
    if(lista->cheia()){
        resposta.setMensagem(QString("erro lista cheia"));
        return resposta;


    }

    if(Posicao < 0 || Posicao > tamanho || Posicao > lista->tamanho() + 1){
        resposta.setMensagem(QString("erro posicao invalida"));
        return resposta;
    }

    if(Posicao == 0){ // se Posicao não tiver sido definida sera adicionada um elemento no final da lista
        int pos = lista->tamanho() + 1;
        resposta.setFrame(frames->elemento(pos));
        lista->insere(pos,Valor);
        QString * string = new QString(QString::number(Valor));
        frames->elemento(pos)->label->setText(*string);
    }else{
        lista->insere(Posicao,Valor);
        resposta.setFrame(frames->elemento(Posicao));
        for (int i = 0; i < lista->tamanho(); ++i) {
            QString * string = new QString(QString::number(lista->elemento(i + 1)));
            frames->elemento(i+1)->label->setText(*string);
            delete string;
        }
    }
    resposta.setMensagem(QString("achei"));

    return resposta;
}

 resposta controlListasSeq::remover(QString posicao){
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
    frames->elemento(pos)->label->setText("vazio");
    resposta.setFrame(frames->elemento(pos));
    resposta.setMensagem("Valor removido " + *string_valor_removido);


    }else{
         frames->elemento(lista->tamanho())->label->setText("vazio");
         QString * string_valor_removido = new QString(QString::number(lista->remove(Posicao)));
         int max = lista->tamanho();
         for (int i = 0; i < max ; ++i) {
            frames->elemento(i+1)->label->setText(QString::number(lista->elemento(i+1)));
         }

        resposta.setFrame(frames->elemento(Posicao));
        resposta.setMensagem("Valor removido " + *string_valor_removido);

    }
    return resposta;
 }


resposta controlListasSeq::buscarPosicao(QString posicao){
    resposta resposta;
    int Posicao = posicao.toInt();
    long valor;

    if(lista->vazia()){
        resposta.setMensagem(QString("erro lista vazia"));
        return resposta;
    }
    if(Posicao < 0 || Posicao > lista->tamanhoMax() ){
        resposta.setMensagem(QString("erro posicao invalida"));
        return resposta;
    }
    valor = lista->elemento(Posicao);
    QString *stringValor;
    if(valor != -1){
    stringValor = new QString("Elemento contido na posição " + posicao  + "<br>" + QString::number(valor));
    resposta.setFrame(frames->elemento(Posicao));
    }else{
    stringValor = new QString("Posicão vazia.");
    }

    resposta.setMensagem(*stringValor);
    return resposta;

}

resposta controlListasSeq::buscarValor(QString valor){
    resposta resposta;
    if(lista->vazia()){
        resposta.setMensagem(QString("erro lista vazia"));
        return resposta;
    }
    QString *stringValor;
    long intValor = valor.toInt();
    int deslocamento = 0;
    ListaSeq Posicao(lista->tamanho());
    long posicao;
    int i = 1;
    while(1){

        posicao = lista->posicao(intValor,deslocamento);
        if(posicao != -1){
            Posicao.insere(i,posicao);
            deslocamento = posicao ;
            i++;
        }else{
            break;
        }
    }
    if(!Posicao.vazia()){
        int max = Posicao.tamanho();
        for (int i = 0; i < max; ++i) {
            if(i == 0){
                if(Posicao.tamanho() > 1){
                    stringValor = new QString("Elemento "+ valor +"<br>"+ " contido nas posiçãos "+"<br>"+ QString::number(Posicao.elemento(i+1)));
                }else{
                    stringValor = new QString("Elemento "+ valor +"<br>"+ " contido na posição "+"<br>" + QString::number(Posicao.elemento(i+1)));
                }
            }else if(i != Posicao.tamanho() - 1){
                stringValor = new QString(*stringValor +" , " + QString::number(Posicao.elemento(i+1)));
            }else{
                stringValor = new QString(*stringValor +" e " + QString::number(Posicao.elemento(i+1)));
            }
        }
    }else{
        stringValor = new QString("Valor não encontrado.");
    }
    resposta.setListaSeqFrame(frames);
    resposta.setlista(&Posicao);
    resposta.setMensagem(*stringValor);
    return resposta;
}
