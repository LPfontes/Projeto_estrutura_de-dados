
#include "frame.h"

#include <QHBoxLayout>

Frame::Frame(int index ,QWidget *parent ) : QFrame(parent) { // criando um Frame que herda da classe Qframe int index e a posicao do frame vai estar no grid

    // Define a cor inicial do frame
    if(index >= 1){
        QString* name = new  QString("frameListaElemento" + QString::number(index));
        css = new QString("background: #D9D9D9;border-radius: 20px;");
        setObjectName(*name);// definido nome do frame

        setStyleSheet(*css); // definido css do frame
        setFixedSize(90,60);// definido tamanho do frame
        linha=0;
        coluna=0;
        QHBoxLayout *layout = new QHBoxLayout(this); // criando um Layout que estara dentro do frame
        labelPosicao = new QLabel(QString::number(index));// criando label da posicao
        labelPosicao->setStyleSheet("color: #68BC61;font-family: 'Inter';font-style: normal;font-weight: 400;font-size: 14px;line-height: 16px;text-align: center;");
        label = new QLabel("vazio");// criando label do valor
        label->setStyleSheet("color: Black;font-family: 'Inter';font-style: normal;font-weight: 400;font-size: 14px;line-height: 16px;text-align: center;");
        layout->addWidget(labelPosicao);// adicionado labelPosicao ao layout
        layout->addWidget(label); // adicionado label ao layout
        layout->setAlignment(Qt::AlignVCenter); // adicionado o tipo de alinhamento do layout centralizando os objetos verticamente
    }else{
        setFixedSize(90,60);
        setStyleSheet(" background-color: rgba(0, 0, 0, 0)");
        labelPosicao = new QLabel(QString::number(index));
    }
    }



void Frame::changeColor(QString* color) { // metodo para alterar cor do frame
     setStyleSheet(*color);

}


