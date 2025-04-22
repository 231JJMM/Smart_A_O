
#include "employes.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

// Constructeur par défaut
Employe::Employe() {
    matricule = 0;
    nom = "";
    prenom = "";
    email = "";
    mdp = "";
}

// Constructeur avec paramètres (pour 5 paramètres)
Employe::Employe(int matricule, QString nom, QString prenom, QString email, QString mdp,QString role)
    : matricule(matricule), nom(nom), prenom(prenom), email(email), mdp(mdp),role(role) {}

// Constructeur avec 3 paramètres (comme celui utilisé dans MainWindow)
Employe::Employe(int matricule, const QString &nom, const QString &prenom)
    : matricule(matricule), nom(nom), prenom(prenom), email(""), mdp(""),role("") {}

// Ajouter un employé
bool Employe::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (MATRICULE, NOM, PRENOM, EMAIL, MDP,ROLE) "
                  "VALUES (:matricule, :nom, :prenom, :email, :mdp, :role)");
    query.bindValue(":matricule", matricule);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":mdp", mdp);
    query.bindValue(":role", role);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout de l'employé : " << query.lastError().text();
        return false;
    }

    return true;
}

// Supprimer un employé par son matricule
bool Employe::supprimer(int matricule) {
    // Vérifier si l'employé existe avant de le supprimer
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE MATRICULE = :matricule");
    checkQuery.bindValue(":matricule", matricule);

    if (!checkQuery.exec()) {
        qDebug() << "Erreur lors de la requête de vérification : " << checkQuery.lastError().text();
        return false;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count == 0) {
        qDebug() << "Aucun employé trouvé avec le matricule " << matricule;
        return false; // L'employé n'existe pas
    }

    // L'employé existe, procéder à la suppression
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYES WHERE MATRICULE = :matricule");
    query.bindValue(":matricule", matricule);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la suppression de l'employé : " << query.lastError().text();
        return false;
    }

    return true;
}

// Afficher les employés
QSqlQueryModel* Employe::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT MATRICULE, NOM, PRENOM, EMAIL ,ROLE FROM EMPLOYES");

    // Définition des en-têtes de colonnes (facultatif mais recommandé)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("role"));

    return model;
}

// Modifier un employé
bool Employe::modifier() {
    qDebug() << "Matricule: " << matricule;
    qDebug() << "Nom: " << nom;
    qDebug() << "Prénom: " << prenom;
    qDebug() << "Email: " << email;
    qDebug() << "Mot de passe: " << mdp;

    // Vérification si l'employé existe
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE MATRICULE = :matricule");
    checkQuery.bindValue(":matricule", matricule);

    if (!checkQuery.exec()) {
        qDebug() << "Erreur lors de la requête de vérification : " << checkQuery.lastError().text();
        return false;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count == 0) {
        qDebug() << "Aucun employé trouvé avec le matricule " << matricule;
        return false; // L'employé n'existe pas
    }

    // Si l'employé existe, continuez avec la modification
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYES SET NOM = :nom, PRENOM = :prenom, EMAIL = :email, MDP = :mdp "
                  "WHERE MATRICULE = :matricule");

    query.bindValue(":matricule", matricule);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":mdp", mdp);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'exécution de la requête : " << query.lastError().text(); // Affiche l'erreur
        qDebug() << "Requête SQL : " << query.lastQuery();  // Affiche la requête exacte
        return false;
    }

    qDebug() << "Modification réussie.";
    return true;
}

// Dans le fichier employes.cpp

QSqlQueryModel* Employe::rechercherParMatricule(int matricule) {
    QSqlQueryModel* model = new QSqlQueryModel();

    QString queryStr = QString("SELECT MATRICULE, NOM, PRENOM, EMAIL FROM EMPLOYES WHERE MATRICULE = :matricule");

    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":matricule", matricule);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la recherche : " << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);  // Associer le résultat de la requête au modèle

    // Définir les en-têtes de colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));

    return model;
}
QSqlQueryModel* Employe::trierParMatricule() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT MATRICULE, NOM, PRENOM, EMAIL FROM EMPLOYES ORDER BY MATRICULE ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));

    return model;
}

bool Employe::authentifier(int matricule, const QString &mdp)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE MATRICULE = :matricule AND MDP = :mdp");
    query.bindValue(":matricule", matricule);
    query.bindValue(":mdp", mdp);

    if (query.exec() && query.next()) {
        return true;  // L'employé existe
    }
    return false;  // Aucun résultat trouvé
}
