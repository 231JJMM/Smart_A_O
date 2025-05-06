// ressource.h

#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <string>
#include <QPieSlice>
#include <QtCharts>
#include <QtSql/QSqlQueryModel>
#include <QChartView>
#include <QString> // Assurez-vous que QString est inclus

class Ressource
{
private:
    QString REFERENCE, PRIX, NOM, QUANTITE, ETAT;
    QString TEMPERATUREMIN;  // Nouveau membre
    QString TEMPERATUREMAX;  // Nouveau membre

public:
    // Constructeurs
    Ressource();
    // Constructeur mis à jour pour inclure les températures
    Ressource(QString reference, QString prix, QString nom, QString quantite, QString etat, QString tempMin, QString tempMax);

    // Getters
    QString getREFERENCE() const;
    QString getPRIX() const;
    QString getNOM() const;
    QString getQUANTITE() const;
    QString getETAT() const;
    QString getTEMPERATUREMIN() const; // Nouveau getter
    QString getTEMPERATUREMAX() const; // Nouveau getter

    // Setters
    void setREFERENCE(QString reference);
    void setPRIX(QString prix);
    void setNOM(QString nom);
    void setQUANTITE(QString quantite);
    void setETAT(QString etat);
    void setTEMPERATUREMIN(QString tempMin); // Nouveau setter
    void setTEMPERATUREMAX(QString tempMax); // Nouveau setter

    // Méthodes CRUD
    bool ajouter(); // Pas de changement de signature ici
    QSqlQueryModel* afficher(); // Sera modifié pour afficher les nouvelles colonnes
    bool supprimer(QString reference);
    bool modifier(QString reference); // La logique interne utilisera les nouvelles données

    // Autres méthodes
    void afficherDiagramme_ressource_Stat();
    QChartView* DiagrammeCirculaire();
    QSqlQueryModel * rechercherRessource(QString recherche);
    QSqlQueryModel * tri_par_quantite();
    QSqlQueryModel * tri_par_prix();
    // Potentiellement ajouter des tris/recherches par température plus tard
};

#endif // RESSOURCE_H
