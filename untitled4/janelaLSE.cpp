#include "LSE.h"
#include "janelaLSE.h"
#include "ui_janelaLSE.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QRegularExpressionValidator>
#include <QRunnable>
#include <QThreadPool>
#include <QTimer>
#include "resposta.h"

LSEJanela::LSEJanela(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LSEJanela)
{
    ui->setupUi(this);

    setFocus(); // para retirar o foco dos inputs
    //css do menu de dados
    QString * css =new QString("position: absolute;width: 250px;height: 260px;left: 76px;top: 214px;background: #D9D9D9; border-radius: 20px; border-style: outset; border-width: 2px; border-color: beige;");
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
    css = new QString("QLineEdit{background: #3ec9a7;border-radius: 20px;font-family: 'Comic Sans MS';font-style: normal;font-weight: 400;font-size: 15px;line-height: 18px;text-align: center;}QLineEdit:hover{background-color: white;color: black;}");
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
    css = new QString("QPushButton { background: #3ec9a7;border-radius: 10px;font-family: 'Comic Sans MS';font-style: normal;font-weight: 400;font-size: 15px;line-height: 18px;text-align: center; } QPushButton:hover {background-color: white;color: black;}");
    ui->buttonInserir->setStyleSheet(*css);
    ui->buttonRemover->setStyleSheet(*css);
    ui->buttonBuscarValor->setStyleSheet(*css);
    ui->buttonBuscarPosicao->setStyleSheet(*css);

    ControlLista = new controllistaslse(ui->frameGrid);
    connect( ui->buttonInserir, &QPushButton::clicked, this, &LSEJanela::on_button_inserir_clicked);
    connect( ui->buttonRemover, &QPushButton::clicked, this, &LSEJanela::on_button_remover_clicked);
    connect( ui->buttonBuscarValor, &QPushButton::clicked, this, &LSEJanela::on_button_BuscarValor_clicked);
    connect( ui->buttonBuscarPosicao, &QPushButton::clicked, this, &LSEJanela::on_button_BuscarPosicao_clicked);
    connect(ui->pushButtonVoltar, &QPushButton::clicked, this, &QMainWindow::close);
}
LSEJanela::~LSEJanela()
{
    delete ui;
}



void LSEJanela::on_button_inserir_clicked(){
    resposta resposta =  ControlLista->adicionar(ui->input_posicao->text(),ui->input_numero->text());

    if(resposta.getMensagem() == "erro lista cheia"){
        QMessageBox::warning(this, "Aviso", "Lista cheia! Remova um elemento para adicionar outro.");


    }else if(resposta.getMensagem() == "erro posicao invalida"){
        QMessageBox::warning(this, "Aviso", "Posição Inválida");

    }else{
        if(resposta.getMensagem() == "meio lista"){
            ui->gridAdicionar->addWidget(resposta.getFrame(),1,1,1,1,Qt::AlignJustify);
            adicionar(resposta.getFrame(),resposta.getGrid(),resposta.getLSEFrame(),1,resposta.getPosicao()-1,resposta.getPosicao());
        }else if(resposta.getMensagem() == "inicio lista"){
            ui->gridAdicionar->addWidget(resposta.getFrame(),1,1,1,1,Qt::AlignJustify);
            adicionarinicio(resposta.getFrame(),resposta.getGrid(),resposta.getLSEFrame(),resposta.getPosicao());
        }else{
            ui->gridAdicionar->addWidget(resposta.getFrame(),1,1,1,1,Qt::AlignJustify);
            adicionarFinal(resposta.getFrame(),resposta.getGrid(),resposta.getLSEFrame(),1,resposta.getPosicao()-1,resposta.getPosicao());
        }
        ui->buttonInserir->setEnabled(false); // desativando os butões de Inserir e Remover
        ui->buttonRemover->setEnabled(false);
        ui->buttonBuscarPosicao->setEnabled(false);
        ui->buttonBuscarValor->setEnabled(false);

    }


}

void LSEJanela::on_button_remover_clicked(){
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
        ui->buttonBuscarPosicao->setEnabled(false);
        ui->buttonBuscarValor->setEnabled(false);
        AlterarCorGridRemover(resposta.getMensagem(),resposta.getLSEFrame(),1,resposta.getPosicao());
        timer->start();
        ui->labelValorRemovido->setText(resposta.getMensagem());
    }

}


void LSEJanela::on_button_BuscarValor_clicked(){
    resposta resposta =  ControlLista->buscarValor(ui->input_numero_busca->text());
    ui->labelRepostaBusca->setText("");
    if(resposta.getMensagem() == "erro lista vazia"){
        QMessageBox::warning(this, "Aviso", "Lista vazia! Adicione um elemento :)");
    }else if(resposta.getMensagem() == "erro posicao invalida"){
        QMessageBox::warning(this, "Aviso", "Posição Inválida");

    }else if(resposta.getMensagem() == "Valor não encontrado."){

        AlterarCorGridProcura(resposta.getMensagem(),resposta.getLSEFrame(),1,0);
    }else{
    QString *color ;

    ui->buttonInserir->setEnabled(false); // desativando os butões de Inserir e Remover
    ui->buttonRemover->setEnabled(false);
    ui->buttonBuscarPosicao->setEnabled(false);
    ui->buttonBuscarValor->setEnabled(false);

    AlterarCorGridProcura(resposta.getMensagem(),resposta.getLSEFrame(),1,resposta.getPosicao());
    }


}
void LSEJanela::on_button_BuscarPosicao_clicked(){
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
        AlterarCorGridProcura(resposta.getMensagem(),resposta.getLSEFrame(),1,resposta.getPosicao());
    }


}

void LSEJanela::AlterarCorGridRemover(QString mensangem,LSEFrame* frames,int i,int index){
    int tempo = 500;

    // Cores para os estados da lista
    QString* color;
    if (i <= index){
        if(index == i){
            color = new QString("background: #F55348;border-radius: 20px;");
            frames->elemento(i)->changeColor(color);
            ControlLista->atualizarGrid();
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
            ControlLista->atualizarGrid();
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
void LSEJanela::adicionar(Frame* frame,QGridLayout * grid,LSEFrame* frames,int posicaoAtual,int posicaoAnterior,int posicao){
    int tempo = 500;

    QString* color;
    if (posicaoAtual <= posicaoAnterior){
        if(posicaoAtual == posicaoAnterior){
            color = new QString("background: #68BC61;border-radius: 20px;");
            frames->elemento(posicaoAtual)->changeColor(color);
            frames->insere(posicao,new Frame(-1));
            ControlLista->atualizarGrid();
            QTimer::singleShot(tempo, [=]() {
                frames->remove(posicao);
                ControlLista->atualizarGrid();
                frames->insere(posicao,frame);
                ui->gridAdicionar->removeWidget(frame);
                ControlLista->atualizarGrid();
            });
            delete color;
        }else{
            color = new QString("background: #4FC2FA;border-radius: 20px;");
            frames->elemento(posicaoAtual)->changeColor(color);
            delete color;

        }
        QTimer::singleShot(tempo, [=]() {
            QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
            frames->elemento(posicaoAtual)->changeColor(corNormal);
            // Chama a função recursivamente para o próximo frame da lista
            adicionar(frame,grid,frames,posicaoAtual+1,posicaoAnterior,posicao);


        });
    }else{
        ui->buttonInserir->setEnabled(true);
        ui->buttonRemover->setEnabled(true);
        ui->buttonBuscarPosicao->setEnabled(true);
        ui->buttonBuscarValor->setEnabled(true);
    }

}
void LSEJanela::adicionarinicio(Frame* frame,QGridLayout * grid,LSEFrame* frames,int posicao){
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
void LSEJanela::adicionarFinal(Frame* frame,QGridLayout * grid,LSEFrame* frames,int posicaoAtual,int posicaoAnterior,int posicao){
    int tempo = 500;

    QString* color;
    if (posicaoAtual != posicao){
       if(posicaoAtual == posicaoAnterior){
            color = new QString("background: #68BC61;border-radius: 20px;");
            frames->elemento(posicaoAtual)->changeColor(color);
            frames->insere(posicao,new Frame(-1));
            ControlLista->atualizarGrid();
            QTimer::singleShot(tempo, [=]() {
                frames->remove(posicao);
                frames->insere(posicao,frame);
                ui->gridAdicionar->removeWidget(frame);
                ControlLista->atualizarGrid();
            });
            delete color;
        }else{
            color = new QString("background: #4FC2FA;border-radius: 20px;");
            frames->elemento(posicaoAtual)->changeColor(color);
            delete color;

        }
        QTimer::singleShot(tempo, [=]() {
            QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
            frames->elemento(posicaoAtual)->changeColor(corNormal);
            // Chama a função recursivamente para o próximo frame da lista
            adicionar(frame,grid,frames,posicaoAtual+1,posicaoAnterior,posicao);


        });
    }else{
        ui->buttonInserir->setEnabled(true);
        ui->buttonRemover->setEnabled(true);
        ui->buttonBuscarPosicao->setEnabled(true);
        ui->buttonBuscarValor->setEnabled(true);
    }


}
void LSEJanela::AlterarCorGridProcura(QString mensangem,LSEFrame* frames, int i,int index){
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
                ControlLista->atualizarGrid();

            });
        }else{
            color = new QString("background: #4FC2FA;border-radius: 20px;");
            QTimer::singleShot(tempo, [=]() {
                QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
                frames->elemento(i)->changeColor(corNormal);
                ControlLista->atualizarGrid();
                // Chama a função recursivamente para o próximo frame da lista
                AlterarCorGridProcura(mensangem,frames, i+1,index);
                if(i == frames->tamanho()){
                    ui->labelRepostaBusca->setText(mensangem);
                }
            });
        }
        frames->elemento(i)->changeColor(color);
        ControlLista->atualizarGrid();
        delete color;

    }



}

