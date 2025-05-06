#include "connexion.h"


Connection::Connection()
{

}
bool Connection::createconnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("cyrine");
    db.setPassword("123456789");
    if(db.open()) test=true;
    return test;
}
void Connection::closeConnection(){db.close();}
