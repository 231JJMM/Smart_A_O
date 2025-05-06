#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include "QTranslator"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection();
    MainWindow w;


    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    QTranslator T;
    QStringList languages;
    languages <<"French"<<"English";
    const QString lang=QInputDialog::getItem(NULL,"Select language ","Language",languages);
    if (lang=="English")

    {
        T.load(":/new/traduction/anglais.qm");
    }
    if (lang !="French")
    {
        a.installTranslator(&T);
    }
    w.show();

    return a.exec();
}
