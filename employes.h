#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe {
public:
    Employe();
    Employe(int matricule, QString nom, QString prenom, QString email, QString mdp,QString role);
    Employe(int matricule, const QString &nom, const QString &prenom);
    bool ajouter();
    bool supprimer(int matricule);
    bool modifier();
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercherParMatricule(int matricule);
    QSqlQueryModel* trierParMatricule();
    bool authentifier(int matricule, const QString &mdp);



    int getCin() { return matricule; }
    QString getNom() { return nom; }
    QString getPrenom() { return prenom; }
    QString getEmail() { return email; }
    QString getRole() { return role; }


private:
    int matricule;
    QString nom, prenom, email, mdp,role;


};

#endif // EMPLOYE_H
