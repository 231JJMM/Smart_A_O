#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>

#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

class Connection {
public:
    Connection();
    bool createconnect();  // Nom de la méthode pour la connexion
};


#endif // CONNECTION_H

