
#include "mainwindow.h"
#include <QApplication>
#include <QIcon>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    QString qssFilePath = ":/assets/img/styles.qss";
//    QString qssFilePath = QCoreApplication::applicationDirPath() + "/styles.qss";
    QFile qssFile( qssFilePath );
    qssFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(qssFile.readAll());

    a.setStyleSheet(styleSheet);



    window.show();

    return a.exec();
}
