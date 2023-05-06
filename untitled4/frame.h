
#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include <QLabel>

class Frame : public QFrame { // classe frame que herda de QFrame que contem um QLabel e uma QString

public:
    Frame(int index ,QWidget *parent = nullptr);
    QLabel* label; // label contem a QString que vai mostrar o valor contido na lista na janela
    QString* css;// css do frame
    QLabel *labelPosicao;
    int linha,coluna;
public slots:
void changeColor(QString* color); // metodo para alterar a cor do frame
};
#endif // FRAME_H
