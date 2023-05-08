#include "janelaSeq.h"
#include "ui_janelaSeq.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QRegularExpressionValidator>
#include <QRunnable>
#include <QThreadPool>
#include <QTimer>

#include "resposta.h"
#include "frame.h"
#include <Windows.h>



ListaSeqJanela::ListaSeqJanela(QWidget *parent) : // construtor da ListaSeqJanela aqui sao definidos os css e outros
                                                  //caracteristicas dos objetos da interface do usuario contida em  ui_listaseqjanela
    QMainWindow(parent),
    ui(new Ui::ListaSeqJanela)
{
    ui->setupUi(this);
    this->setWindowTitle("Lista Sequencial");
    this->setWindowIcon(QIcon(":/assets/img/list.png"));
    this->setIconSize(QSize(32, 32));
                                                            //ui->label->setPixmap(QPixmap(":/assets/img/icon.png")); exemplo de como adicionar uma imagens
    setFocus(); // para retirar o foco dos inputs
    //css do menu de dados
    QString * css =new QString("position: absolute;width: 250px;height: 260px;left: 76px;top: 214px;background-color: #D9D9D9; border-radius: 20px; border-style: outset; border-width: 2px; border-color: beige;");
    ui->menu_dados->setStyleSheet(*css);
    ui->menu_Busca->setStyleSheet(*css);

    // validador para pemitir apenas numeros nos input
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("-?\\d*"), this);
    ui->input_numero->setValidator(validator);
    ui->input_posicao->setValidator(validator);
    ui->input_numero_busca->setValidator(validator);
    ui->input_posicao_busca->setValidator(validator);
    ui->InputTamanhoLista->setValidator(validator);
    //definindo tamanho max das entradas de valor
    ui->input_numero->setMaxLength(9);
    ui->input_numero_busca->setMaxLength(9);
    ui->InputTamanhoLista->setMaxLength(9);
    // Placeholder dos inputs
    ui->input_numero->setPlaceholderText("Número a ser inserido");
    ui->input_posicao->setPlaceholderText("Posição");
    ui->input_numero_busca->setPlaceholderText("Número a ser buscado");
    ui->input_posicao_busca->setPlaceholderText("Posição a ser buscada");
    ui->InputTamanhoLista->setPlaceholderText("Tamanho da lista");
    delete css;
    css = new QString("QLineEdit{background: #3ec9a7;border-radius: 20px;font-family: 'Comic Sans MS';font-style: normal;font-weight: 400;font-size: 15px;line-height: 18px;text-align: center;}QLineEdit:hover{background-color: white;color: black;}");
    //css dos inputs
    ui->frameInputNumero->setStyleSheet(*css);
    ui->frameInputPosicao->setStyleSheet(*css);
    ui->frameInputNumeroBusca->setStyleSheet(*css);
    ui->frameInputPosicaoBusca->setStyleSheet(*css);
    ui->InputTamanhoLista->setStyleSheet(*css);
    delete css;
    css = new QString("font-family: 'Inter';font-style: normal;font-weight: 400;font-size: 14px;line-height: 16px;text-align: center;");
    ui->frameRespostaBusca->setStyleSheet(*css);

    delete css;
    //css dos butões
    css = new QString("QPushButton { background: #3ec9a7;border-radius: 10px;font-family: 'Comic Sans MS';font-style: normal;font-weight: 400;font-size: 15px;line-height: 18px;text-align: center; } QPushButton:hover {background-color: white;color: black;}");
    ui->buttonInserir->setStyleSheet(*css);
    ui->buttonRemover->setStyleSheet(*css);
    ui->buttonBuscarValor->setStyleSheet(*css);
    ui->buttonBuscarPosicao->setStyleSheet(*css);
    ui->buttonCriaLista->setStyleSheet(*css);
    ui->buttonInserir->setEnabled(false); // desativando os butões de Inserir e Remover
    ui->buttonRemover->setEnabled(false);
    ui->buttonBuscarValor->setEnabled(false);
    ui->buttonBuscarPosicao->setEnabled(false);
    //conectado os metodos da janela com os butões
    connect( ui->buttonInserir, &QPushButton::clicked, this, &ListaSeqJanela::on_button_inserir_clicked);
    connect( ui->buttonRemover, &QPushButton::clicked, this, &ListaSeqJanela::on_button_remover_clicked);
    connect( ui->buttonBuscarValor, &QPushButton::clicked, this, &ListaSeqJanela::on_button_BuscarValor_clicked);
    connect( ui->buttonBuscarPosicao, &QPushButton::clicked, this, &ListaSeqJanela::on_button_BuscarPosicao_clicked);
    connect(ui->pushButtonVoltar, &QPushButton::clicked, this, &QMainWindow::close);
    connect(ui->buttonCriaLista,&QPushButton::clicked,this,&ListaSeqJanela::on_button_CriarLista_clicked);
    //crinado lista que um objeto que controla a relação entre as lista utilizadas
    lista = new controlListasSeq(ui->frameGrid);

}

ListaSeqJanela::~ListaSeqJanela()
{
    delete ui;
}
void ListaSeqJanela::on_button_CriarLista_clicked(){ // método que cria a lista de frames
    int tamanho = ui->InputTamanhoLista->text().toInt(); // pegando o valor contido no InputTamanhoLista
    if(tamanho > 0){ // verificado se é um valor valido
        lista->criarLista(ui->InputTamanhoLista->text().toInt());
        ui->buttonInserir->setEnabled(true); // desativando os butões de Inserir e Remover
        ui->buttonRemover->setEnabled(true);
        ui->buttonBuscarValor->setEnabled(true);
        ui->buttonBuscarPosicao->setEnabled(true);
    }else{
        QMessageBox::warning(this, "Aviso", "Valor Inválida");
    }

}




void ListaSeqJanela::on_button_inserir_clicked(){ // método que insere o valor do input_numero na posicão input_posicao


        resposta resposta =  lista->adicionar(ui->input_posicao->text(),ui->input_numero->text());

        if(resposta.getMensagem() == "erro lista cheia"){
            QMessageBox::warning(this, "Aviso", "Lista cheia! Remova um elemento para adicionar outro.");


        }else if(resposta.getMensagem() == "erro posicao invalida"){
            QMessageBox::warning(this, "Aviso", "Posição Inválida");

        }else{
            frame = resposta.getFrame();// pegado o endereço do frame passado na resposta da lista->adicionar
            QTimer *timer = new QTimer();// defindo um timer que ira executar um codigo depois de um determinado tempo para criar o efeito de mundaça de cor do frame
            QString *color = new QString("background: #68BC61;border-radius: 20px;");
            frame->changeColor(color); // mundado a cor do frame para verde
            delete color;
            timer->setSingleShot(true); // define que só será chamado uma vez
            timer->setInterval(500); // define o intervalo
            ui->buttonInserir->setEnabled(false); // desativando os butões de Inserir e Remover
            ui->buttonRemover->setEnabled(false);

            AlterarCor(frame,timer);
            timer->start();
        }

}

void ListaSeqJanela::on_button_remover_clicked(){
    resposta resposta =  lista->remover(ui->input_posicao->text());

    if(resposta.getMensagem() == "erro lista vazia"){
            QMessageBox::warning(this, "Aviso", "Lista vazia! Adicione um elemento :)");

    }else if(resposta.getMensagem() == "erro posicao invalida"){
            QMessageBox::warning(this, "Aviso", "Posição Inválida");

    }else{
            frame = resposta.getFrame();
            QTimer *timer = new QTimer();
            QString *color = new QString("background: #F55348;border-radius: 20px;");
            frame->changeColor(color);
            delete color;
            timer->setSingleShot(true); // define que só será chamado uma vez
            timer->setInterval(500); // define o intervalo em milissegundos (1 segundo)
            ui->buttonInserir->setEnabled(false); // desativando os butões de Inserir e Remover
            ui->buttonRemover->setEnabled(false);
            AlterarCor(frame,timer);
            timer->start();
            ui->labelValorRemovido->setText(resposta.getMensagem());

    }



}


void ListaSeqJanela::on_button_BuscarValor_clicked(){ // método de busca por valor
    resposta resposta =  lista->buscarValor(ui->input_numero_busca->text());
    ui->labelRepostaBusca->setText("");
    if(resposta.getMensagem() == "erro lista vazia"){
            QMessageBox::warning(this, "Aviso", "Lista vazia! Adicione um elemento :)");
    }else if(resposta.getMensagem() == "erro posicao invalida"){
            QMessageBox::warning(this, "Aviso", "Posição Inválida");

    }else{
    QString *color ;

      ui->buttonInserir->setEnabled(false); // desativando os butões de Inserir e Remover
      ui->buttonRemover->setEnabled(false);
      ui->buttonBuscarPosicao->setEnabled(false);
      ui->buttonBuscarValor->setEnabled(false);
      AlterarCorGrid(resposta.getMensagem(),resposta.getListaSeqFrame(),resposta.getlista(),1,1);
    }
}
void ListaSeqJanela::on_button_BuscarPosicao_clicked(){ // método de busca na Posicão
      resposta resposta =  lista->buscarPosicao(ui->input_posicao_busca->text());

      if(resposta.getMensagem() == "erro lista vazia"){
            QMessageBox::warning(this, "Aviso", "Lista vazia! Adicione um elemento :)");
      }else if(resposta.getMensagem() == "erro posicao invalida"){
            QMessageBox::warning(this, "Aviso", "Posição Inválida");

      }else if(resposta.getMensagem() != "Posicão vazia."){
      ui->labelRepostaBusca->setText(resposta.getMensagem());
      frame = resposta.getFrame();
      QTimer *timer = new QTimer();
      QString *color = new QString("background: #68BC61;border-radius: 20px;");
      frame->changeColor(color);
      delete color;
      timer->setSingleShot(true); // define que só será chamado uma vez
      timer->setInterval(500); // define o intervalo em milissegundos (1 segundo)
      ui->buttonInserir->setEnabled(false); // desativando os butões de Inserir e Remover
      ui->buttonRemover->setEnabled(false);
      AlterarCor(frame,timer);
      timer->start();
      }

}
void ListaSeqJanela::AlterarCor(Frame* frame, QTimer* timer){
    QObject::connect(timer, &QTimer::timeout, [=]() {
        QString *color = new QString("background: #D9D9D9;border-radius: 20px;");
        frame->changeColor(color); // chamando o método changeColor com a nova cor
        ui->buttonInserir->setEnabled(true);// reativando os butões de Inserir e Remover
        ui->buttonRemover->setEnabled(true);
        delete color;
    });

}
void ListaSeqJanela::AlterarCorGrid(QString mensangem,ListaSeqFrame* frames, ListaSeq* lista, int i,int index)
{
    int tempo = 500;

    // Cores para os estados da lista
    QString* color;
    if (i <= lista->tamanhoMax()){
        if(lista->elemento(index) == i){
                color = new QString("background: #68BC61;border-radius: 20px;");
                index++;
        }else{
                color = new QString("background: #4FC2FA;border-radius: 20px;");
        }
            frames->elemento(i)->changeColor(color);
        delete color;
        QTimer::singleShot(tempo, [=]() {
        QString* corNormal = new QString("background: #D9D9D9;border-radius: 20px;");
        frames->elemento(i)->changeColor(corNormal);
        // Chama a função recursivamente para o próximo frame da lista
        AlterarCorGrid(mensangem,frames, lista, i+1,index);
        });
    }else{// Ativa os botões desativados anteriormente
            ui->buttonInserir->setEnabled(true);
            ui->buttonRemover->setEnabled(true);
            ui->buttonBuscarPosicao->setEnabled(true);
            ui->buttonBuscarValor->setEnabled(true);
            ui->labelRepostaBusca->setText(mensangem);
    }

}
