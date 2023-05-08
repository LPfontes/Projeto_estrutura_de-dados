
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "janelaSeq.h"
#include "janelaLDE.h"
#include "janelaLSE.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onbuttonListaSeq_clicked();
    void onbuttonListaLDE_clicked();
    void onbuttonListaLSE_clicked();
private:
    Ui::MainWindow *ui;
    QString* styleSheet;
};

#endif // MAINWINDOW_H
