#include "connection.h"
#include <QDebug>
#include <QMessageBox>



Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données
    db.setUserName("shahd");//inserer nom de l'utilisateur
    db.setPassword("123456789");//inserer mot de passe de cet utilisateur
    if (db.open()) {
        test = true;
        QMessageBox::information(nullptr, "Connexion réussie", "Connexion à la base de données réussie !");
    } else {
        QMessageBox::critical(nullptr, "Erreur de connexion", "Échec de la connexion à la base de données : " + db.lastError().text());
    }


    if (db.open())
        test=true;





    return  test;
}
