#include "LDE.h"
#include "janelaLDE.h"
#include "ui_janelaLDE.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QRegularExpressionValidator>
#include <QTimer>
#include "resposta.h"

LDEJanela::LDEJanela(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LDEJanela)
{
    ui->setupUi(this);

    setFocus(); // para retirar o foco dos inputs
    // css do titulo da pagina
    ui->frameTitulo->setStyleSheet("font-family: 'Inter';font-style: normal;font-weight: 400;font-size: 50px;line-height: 73px;text-align: center;color: black;");
    //css do menu de dados
    QString * css =new QString("position: absolute;width: 250px;height: 260px;left: 76px;top: 214px;background: #D9D9D9; border-radius: 20px;");
    ui->menu_dados->setStyleSheet(*css);
    ui->menu_Busca->setStyleSheet(*css);
    // validador para pemitir apenas numeros nos input
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("-?\\d*"), this);
    ui->input_numero->setValidator(validator);
    ui->input_posicao->setValidator(validator);
    ui->input_numero_busca->setValidator(validator);
    ui->input_posicao_busca->setValidator(validator);
    //definindo tamanho max das entradas de valor
    ui->input_numero->setMaxLength(9);
    ui->input_numero_busca->setMaxLength(9);
    // Placeholder dos inputs
    ui->input_numero->setPlaceholderText("Número a ser inserido");
    ui->input_posicao->setPlaceholderText("Posição");
    ui->input_numero_busca->setPlaceholderText("Número a ser buscado");
    ui->input_posicao_busca->setPlaceholderText("Posição a ser buscada");

    delete css;
    css = new QString("QLineEdit{background: #68BC61;border-radius: 20px;font-family: 'Inter';font-style: normal;font-weight: 400;font-size: 15px;line-height: 18px;text-align: center;}QLineEdit:hover{background-color: white;color: black;}");
    //css dos inputs
    ui->frameInputNumero->setStyleSheet(*css);
    ui->frameInputPosicao->setStyleSheet(*css);
    ui->frameInputNumeroBusca->setStyleSheet(*css);
    ui->frameInputPosicaoBusca->setStyleSheet(*css);
    delete css;
    css = new QString("font-family: 'Inter';font-style: normal;font-weight: 400;font-size: 14px;line-height: 16px;text-align: center;");
    ui->frameRespostaBusca->setStyleSheet(*css);

    delete css;
    //css dos butoes
    css = new QString("QPushButton { background: #7FA62C;border-radius: 10px;font-family: 'Inter';font-style: normal;font-weight: 400;font-size: 15px;line-height: 18px;text-align: center; } QPushButton:hover {background-color: white;color: black;}");
    ui->buttonInserir->setStyleSheet(*css);
    ui->buttonRemover->setStyleSheet(*css);
    ui->buttonBuscarValor->setStyleSheet(*css);
    ui->buttonBuscarPosicao->setStyleSheet(*css);

    ControlLista = new controllistaslde(ui->frameGrid);
    connect( ui->buttonInserir, &QPushButton::clicked, this, &LDEJanela::on_button_inserir_clicked);
    connect( ui->buttonRemover, &QPushButton::clicked, this, &LDEJanela::on_button_remover_clicked);
    connect( ui->buttonBuscarValor, &QPushButton::clicked, this, &LDEJanela::on_button_BuscarValor_clicked);
    connect( ui->buttonBuscarPosicao, &QPushButton::clicked, this, &LDEJanela::on_button_BuscarPosicao_clicked);
    connect(ui->pushButtonVoltar, &QPushButton::clicked, this, &QMainWindow::close);
}
LDEJanela::~LDEJanela()
{
    delete ui;
}



void LDEJanela::on_button_inserir_clicked(){
    resposta resposta =  ControlLista->adicionar(ui->input_posicao->text(),ui->input_numero->text());

    if(resposta.getMensagem() == "erro lista cheia"){
        QMessageBox::warning(this, "Aviso", "Lista cheia! Remova um elemento para adicionar outro.");


    }else if(resposta.getMensagem() == "erro posicao invalida"){
        QMessageBox::warning(this, "Aviso", "Posição Inválida");

    }else{
        if(resposta.getMensagem() == "meio lista"){
            ui->gridAdicionar->addWidget(resposta.getFrame(),1,1,1,1,Qt::AlignJustify);
            adicionar(resposta.getFrame(),resposta.getGrid(),resposta.getLDEFrame(),1,resposta.getPosicao()-1,resposta.getPosicao());
        }else if(resposta.getMensagem() == "inicio lista"){
            ui->gridAdicionar->addWidget(resposta.getFrame(),1,1,1,1,Qt::AlignJustify);
            adicionarinicio(resposta.getFrame(),resposta.getGrid(),resposta.getLDEFrame(),resposta.getPosicao());
        }else if(resposta.getMensagem()=="via fim lista"){
            ui->gridAdicionar->addWidget(resposta.getFrame(),1,1,1,1,Qt::AlignJustify);
            adicionarViaFinal(resposta.getFrame(),resposta.getGrid(),resposta.getLDEFrame(),1,resposta.getPosicao()+1,resposta.getPosicao());

        }else{
            ui->gridAdicionar->addWidget(resposta.getFrame(),1,1,1,1,Qt::AlignJustify);
            adicionarFinal(resposta.getFrame(),resposta.getGrid(),resposta.getLDEFrame(),1,resposta.getPosicao());
        }
        ui->buttonInserir->setEnabled(false);
        ui->buttonRemover->setEnabled(false);


    }


}

void LDEJanela::on_button_remover_clicked(){
    resposta resposta =  ControlLista->remover(ui->input_posicao->text());
    if(resposta.getMensagem() == "erro lista vazia"){
        QMessageBox::warning(this, "Aviso", "Lista vazia! Adicione um elemento :)");

    }else if(resposta.getMensagem() == "erro posicao invalida"){
        QMessageBox::warning(this, "Aviso", "Posição Inválida");

    }else{

        QTimer *timer = new QTimer();


        timer->setSingleShot(true); // define que só será chamado uma vez
        timer->setInterval(500); // define o intervalo em milissegundos (1 segundo)
        ui->buttonInserir->setEnabled(false); // desativando os butões de Inserir e Remover
        ui->buttonRemover->setEnabled(false);
        if(resposta.getPosicao() == resposta.getLDEFrame()->tamanho()){
            AlterarCorGridRemoverFim(resposta.getMensagem(),resposta.getLDEFrame(),1,resposta.getPosicao(),resposta.getPosicao());
            timer->start();
            ui->labelValorRemovido->setText(resposta.getMensagem());
        }else{
            AlterarCorGridRemover(resposta.getMensagem(),resposta.getLDEFrame(),1,resposta.getPosicao());
            timer->start();
            ui->labelValorRemovido->setText(resposta.getMensagem());
        }
    }

}


void LDEJanela::on_button_BuscarValor_clicked(){
    resposta resposta =  ControlLista->buscarValor(ui->input_numero_busca->text());
    ui->labelRepostaBusca->setText("");
    if(resposta.getMensagem() == "erro lista vazia"){
        QMessageBox::warning(this, "Aviso", "Lista vazia! Adicione um elemento :)");
    }else if(resposta.getMensagem() == "erro posicao invalida"){
        QMessageBox::warning(this, "Aviso", "Posição Inválida");

    }else if(resposta.getMensagem() == "Valor não encontrado."){

        AlterarCorGridProcura(resposta.getMensagem(),resposta.getLDEFrame(),1,0);
}else{
    QString *color ;

    ui->buttonInserir->setEnabled(false); // desativando os butões de Inserir e Remover
    ui->buttonRemover->setEnabled(false);
    ui->buttonBuscarPosicao->setEnabled(false);
    ui->buttonBuscarValor->setEnabled(false);

    AlterarCorGridProcura(resposta.getMensagem(),resposta.getLDEFrame(),1,resposta.getPosicao());
}


}
void LDEJanela::on_button_BuscarPosicao_clicked(){
    resposta resposta =  ControlLista->buscarPosicao(ui->input_posicao_busca->text());

    ui->labelRepostaBusca->setText("");
    if(resposta.getMensagem() == "erro lista vazia"){
        QMessageBox::warning(this, "Aviso", "Lista vazia! Adicione um elemento :)");
    }else if(resposta.getMensagem() == "erro posicao invalida"){
        QMessageBox::warning(this, "Aviso", "Posição Inválida");

    }else if(resposta.getMensagem() == "Valor não encontrado."){
        ui->labelRepostaBusca->setText(resposta.getMensagem());
    }else{
        QString *color ;

        ui->buttonInserir->setEnabled(false); // desativando os butões de Inserir e Remover
        ui->buttonRemover->setEnabled(false);
        ui->buttonBuscarPosicao->setEnabled(false);
        ui->buttonBuscarValor->setEnabled(false);
        if(resposta.getPosicao() > resposta.getLDEFrame()->tamanho() / 2){
           AlterarCorGridProcuraFim(resposta.getMensagem(),resposta.getLDEFrame(),1,resposta.getPosicao());
        }else{
            AlterarCorGridProcura(resposta.getMensagem(),resposta.getLDEFrame(),1,resposta.getPosicao());
        }

    }
}

void LDEJanela::AlterarCorGridRemover(QString mensangem,LDEFrame* frames,int i,int index){
    int tempo = 500;

    // Cores para os estados da lista
    QString* color;
    if (i <= index){
        if(index == i){
            color = new QString("background: #F55348;border-radius: 20px;");
            frames->elemento(i)->changeColor(color);
            delete color;
        }else{
            color = new QString("background: #4FC2FA;border-radius: 20px;");
            frames->elemento(i)->changeColor(color);
            delete color;

        }
        QTimer::singleShot(tempo, [=]() {
            QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
            frames->elemento(i)->changeColor(corNormal);
            // Chama a função recursivamente para o próximo frame da lista

                AlterarCorGridRemover(mensangem,frames, i+1,index);

        });
    }else{// Ativa os botões desativados anteriormente
        delete frames->remove(index);
        ui->buttonInserir->setEnabled(true);
        ui->buttonRemover->setEnabled(true);
        ui->buttonBuscarPosicao->setEnabled(true);
        ui->buttonBuscarValor->setEnabled(true);

        ControlLista->atualizarGrid();
    }


}
void LDEJanela::AlterarCorGridRemoverFim(QString mensangem,LDEFrame* frames,int i,int index,int posicao){
    int tempo = 500;

    // Cores para os estados da lista
    QString* color;
    if (i <= index){
        if(index == i){
            color = new QString("background: #F55348;border-radius: 20px;");
            frames->elemento(i)->changeColor(color);

            ControlLista->atualizarGrid();


            posicao++;
            delete color;
        }else{
            color = new QString("background: #4FC2FA;border-radius: 20px;");
            frames->elemento(i)->changeColor(color);

            ControlLista->atualizarGrid();
            delete color;

        }
        QTimer::singleShot(tempo, [=]() {
            QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
            frames->elemento(i)->changeColor(corNormal);
            // Chama a função recursivamente para o próximo frame da lista

            AlterarCorGridRemover(mensangem,frames, posicao,index);

        });
    }else{// Ativa os botões desativados anteriormente
        delete frames->remove(index);
        ui->buttonInserir->setEnabled(true);
        ui->buttonRemover->setEnabled(true);
        ui->buttonBuscarPosicao->setEnabled(true);
        ui->buttonBuscarValor->setEnabled(true);

        ControlLista->atualizarGrid();
    }

}

void LDEJanela::adicionar(Frame* frame,QGridLayout * grid,LDEFrame* frames,int posicaoAtual,int posicaoAnterior,int posicao){
    int tempo = 500;

    QString* color;
    if(posicaoAtual != posicao){
        if(posicaoAtual == posicaoAnterior){
            QTimer::singleShot(tempo, [=]() {
                QString* color = new QString("background: #68BC61;border-radius: 20px;");
                frames->elemento(posicaoAtual)->changeColor(color);
                delete color;
                ControlLista->atualizarGrid();
                QTimer::singleShot(tempo, [=]() {
                    QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
                    frames->elemento(posicaoAtual)->changeColor(corNormal);

                    QTimer::singleShot(tempo, [=]() {
                        frames->insere(posicao,new Frame(-1));
                        ControlLista->atualizarGrid();

                        QTimer::singleShot(tempo, [=]() {
                            frames->remove(posicao);
                            ControlLista->atualizarGrid();
                            frames->insere(posicao,frame);
                            ui->gridAdicionar->removeWidget(frame);
                            ControlLista->atualizarGrid();
                            QTimer::singleShot(tempo, [=]() {

                             adicionar(frame,grid,frames,posicaoAtual +1,posicaoAnterior,posicao);

                            });
                        });
                    });
                });
            });

        }else{
            color = new QString("background: #4FC2FA;border-radius: 20px;");
            frames->elemento(posicaoAtual)->changeColor(color);
            delete color;
            QTimer::singleShot(tempo, [=]() {
                QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
                frames->elemento(posicaoAtual)->changeColor(corNormal);
                // Chama a função recursivamente para o próximo frame da lista
                  adicionar(frame,grid,frames,posicaoAtual+1,posicaoAnterior,posicao);


            });
        }

    }else{
        ui->buttonInserir->setEnabled(true);
        ui->buttonRemover->setEnabled(true);
        ui->buttonBuscarPosicao->setEnabled(true);
        ui->buttonBuscarValor->setEnabled(true);
        ControlLista->atualizarGrid();

    }

}
void LDEJanela::adicionarinicio(Frame* frame,QGridLayout * grid,LDEFrame* frames,int posicao){
    int tempo = 500;
    frames->insere(posicao,new Frame(-1));
    QTimer::singleShot(tempo, [=]() {
        frames->remove(posicao);
        frames->insere(posicao,frame);
        ui->gridAdicionar->removeWidget(frame);
        ControlLista->atualizarGrid();
        ui->buttonInserir->setEnabled(true);
        ui->buttonRemover->setEnabled(true);
        ui->buttonBuscarPosicao->setEnabled(true);
        ui->buttonBuscarValor->setEnabled(true);
    });

}
void LDEJanela::adicionarFinal(Frame* frame,QGridLayout * grid,LDEFrame* frames,int posicaoAtual,int posicao){
    int tempo = 500;
    if(posicaoAtual < posicao){
        QString* color;
        color = new QString("background: #68BC61;border-radius: 20px;");
        frames->elemento(posicaoAtual)->changeColor(color);
        ControlLista->atualizarGrid();
        QTimer::singleShot(tempo, [=]() {
            frames->insere(posicao,frame);
            ui->gridAdicionar->removeWidget(frame);
            ControlLista->atualizarGrid();
        });

        delete color;


        QTimer::singleShot(tempo, [=]() {
            QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
            frames->elemento(posicaoAtual)->changeColor(corNormal);
            // Chama a função recursivamente para o próximo frame da lista
            adicionarFinal(frame,grid,frames, posicao+1,posicao);
        });
    }else{
        ui->buttonInserir->setEnabled(true);
        ui->buttonRemover->setEnabled(true);
        ui->buttonBuscarPosicao->setEnabled(true);
        ui->buttonBuscarValor->setEnabled(true);

    }


}
void LDEJanela::AlterarCorGridProcura(QString mensangem,LDEFrame* frames, int i,int index){
    int tempo = 500;

    // Cores para os estados da lista
    QString* color;
    if (i <= frames->tamanho()){
        if(index == i){
            color = new QString("background: #68BC61;border-radius: 20px;");

            ui->buttonInserir->setEnabled(true);
            ui->buttonRemover->setEnabled(true);
            ui->buttonBuscarPosicao->setEnabled(true);
            ui->buttonBuscarValor->setEnabled(true);
            ui->labelRepostaBusca->setText(mensangem);
            QTimer::singleShot(tempo, [=]() {
                QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
                frames->elemento(i)->changeColor(corNormal);


            });
        }else{
            color = new QString("background: #4FC2FA;border-radius: 20px;");
            QTimer::singleShot(tempo, [=]() {
                QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
                frames->elemento(i)->changeColor(corNormal);
                // Chama a função recursivamente para o próximo frame da lista
                AlterarCorGridProcura(mensangem,frames, i+1,index);
                if(i == frames->tamanho()){
                    ui->labelRepostaBusca->setText(mensangem);
                }
            });
        }
        frames->elemento(i)->changeColor(color);
        delete color;

    }


}
void LDEJanela::AlterarCorGridProcuraFim(QString mensangem,LDEFrame* frames, int i,int index){
    int tempo = 500;

    // Cores para os estados da lista
    QString* color;
    if(index == i){
            color = new QString("background: #68BC61;border-radius: 20px;");

            ui->buttonInserir->setEnabled(true);
            ui->buttonRemover->setEnabled(true);
            ui->buttonBuscarPosicao->setEnabled(true);
            ui->buttonBuscarValor->setEnabled(true);
            ui->labelRepostaBusca->setText(mensangem);
            QTimer::singleShot(tempo, [=]() {
                QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
                frames->elemento(i)->changeColor(corNormal);


            });
        }else{
            color = new QString("background: #4FC2FA;border-radius: 20px;");
            QTimer::singleShot(tempo, [=]() {
                QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
                frames->elemento(i)->changeColor(corNormal);
                // Chama a função recursivamente para o próximo frame da lista
                if(i == 1){
                  AlterarCorGridProcuraFim(mensangem,frames,frames->tamanho() ,index);
                }else{
                  AlterarCorGridProcuraFim(mensangem,frames, i-1,index);
                }

                if(i == frames->tamanho()){
                    ui->labelRepostaBusca->setText(mensangem);
                }
            });
        }
        frames->elemento(i)->changeColor(color);
        delete color;

    }



void LDEJanela::adicionarViaFinal(Frame* frame,QGridLayout * grid,LDEFrame* frames,int posicaoAtual,int posicaoAnterior,int posicao){

    int tempo = 500;
    QString* color;
    if(posicaoAtual != posicao-1){
        if(posicaoAtual == posicao){

            QTimer::singleShot(tempo, [=]() {
                QString* color = new QString("background: #68BC61;border-radius: 20px;");
                frames->elemento(posicaoAtual)->changeColor(color);
                delete color;
                ControlLista->atualizarGrid();
                QTimer::singleShot(tempo, [=]() {
                    QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
                    frames->elemento(posicaoAtual)->changeColor(corNormal);

                    QTimer::singleShot(tempo, [=]() {
                        frames->insere(posicao,new Frame(-1));
                        ControlLista->atualizarGrid();


                        QTimer::singleShot(tempo, [=]() {
                            frames->remove(posicao);
                            ControlLista->atualizarGrid();
                            frames->insere(posicao,frame);
                            ui->gridAdicionar->removeWidget(frame);
                            ControlLista->atualizarGrid();
                            QTimer::singleShot(tempo, [=]() {
                                if(posicaoAtual == 1){
                                    adicionarViaFinal(frame,grid,frames,frames->tamanho(),posicaoAnterior,posicao);
                                }else{
                                    adicionarViaFinal(frame,grid,frames,posicaoAtual - 1,posicaoAnterior,posicao);
                                }
                            });
                        });
                    });
                });
             });

        }else{
            color = new QString("background: #4FC2FA;border-radius: 20px;");
            frames->elemento(posicaoAtual)->changeColor(color);
            delete color;
            QTimer::singleShot(tempo, [=]() {
                QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
                frames->elemento(posicaoAtual)->changeColor(corNormal);
                // Chama a função recursivamente para o próximo frame da lista
                if(posicaoAtual == 1){
                    adicionarViaFinal(frame,grid,frames,frames->tamanho(),posicaoAnterior,posicao);
                }else{
                    adicionarViaFinal(frame,grid,frames,posicaoAtual - 1,posicaoAnterior,posicao);
                }

            });
        }

    }else{
        ui->buttonInserir->setEnabled(true);
        ui->buttonRemover->setEnabled(true);
        ui->buttonBuscarPosicao->setEnabled(true);
        ui->buttonBuscarValor->setEnabled(true);
        ControlLista->atualizarGrid();

    }


}
